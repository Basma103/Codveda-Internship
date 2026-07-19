#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    int *grades;
};

bool isFileEmpty(string filetxt) {
    bool is_empty = false;
    ifstream test_empty(filetxt);
    if (!test_empty || test_empty.peek() == EOF) {
        is_empty = true;
    }
    return is_empty;
}

void printheader(string filetxt) {
    if (isFileEmpty(filetxt)) {
        ofstream file;
        file.open(filetxt,ios::app);
        file.clear();
        file << "-----------------------------------------------------------\n";
        file << left << setw(15) << "Name" << "| "
             << setw(15) << "       ID" << "| "
             << "           Grades\n";
        file << "-----------------------------------------------------------\n";
    }
}

bool id_already_exist(string check_id,string filename){
    string searching;
    fstream file;
    file.open(filename,ios::in);
        while(getline(file,searching)) {
            stringstream ss(searching);
            string currentName;
            string currentID;

            ss >> currentName; // Extracts the first word (Name)
            ss >> currentID;   // Extracts the second word (ID)

            // 3. Perform an EXACT match check
            if (currentID == check_id) {
                return true;
            }
        }
    file.close();
    return false;
}

void CreateRecord(string filetxt,Student student) {
    printheader(filetxt);
    ofstream file;
    file.open(filetxt,ios::app);

    cout<<"Enter name: "; cin>>student.name;
    cout<<"Enter id: "; cin>>student.id;

    while(id_already_exist(student.id,"list.txt")) {// check if id is repeated
        cout<<"ID already exist!\n";
        cout<<"Enter id: ";
        cin>>student.id;
    }

    file<<left << setw(18)<<student.name<<setw(20)<<student.id<<"[";
    cout<<"Enter grades: "; student.grades=new int[5];
    for (int i = 0; i < 4; i++) {
        cin>>student.grades[i];
        file<<student.grades[i]<<",";
    }
    cin>>student.grades[4];
    file<<student.grades[4]<<"]\n";
    delete[] student.grades;
    file.close();
cout<<"Created Record Successfully!\n";
}

void printfile(string filetxt) {
    ifstream file; string line;
    file.open(filetxt,ios::in);
    if (isFileEmpty(filetxt)) {
        printheader(filetxt);
    }
    if(file.is_open()) {
        while(getline(file,line)){
            cout<<line<<"\n";
        }
    }
    file.close();

}

void DeleteRecord(string ID_To_Delete) {
    ifstream list("list.txt");
    ofstream temp("temp.txt", ios::app);

    string line; bool found=false;
    string targetName;

    if(list.is_open()) {
        while (getline(list, line)) {
            if (line.empty() || line.find("---") != std::string::npos || line.find("ID") != std::string::npos) { //skip header
                temp << line << "\n";
                continue;
            }

            // 2. Parse data rows using a space-delimited stringstream
            stringstream ss(line);
            string currentName;
            string currentID;

            ss >> currentName; // Extracts the first word (Name)
            ss >> currentID;   // Extracts the second word (ID)

            // 3. Perform an EXACT match check
            if (currentID == ID_To_Delete) {
                cout << "Successfully deleted student with ID: "<<currentID<<"\n";
                found=true;
                continue; // Skip writing this line to the temp file
            }

            // Keep all other student data lines intact
            temp << line << "\n";
        }
    }
    if (!found) {
        cout<<"student not found!\n";
    }
    temp.close();
    list.close();
    remove("list.txt");
    rename("temp.txt", "list.txt");
}

void UpdateRecord(string ID_To_Update) {
    ifstream list("list.txt");
    ofstream temp("temp.txt", ios::app);
    string line;
    if (!id_already_exist(ID_To_Update,"list.txt")) {
        cout<<"Record not found!\n";
        return;
    }else {
        if (list.is_open()) {
            while(getline(list,line)) {
                stringstream ss(line);
                string currentName, currentID;
                ss >> currentName >> currentID;

                if (currentID != ID_To_Update) {
                    temp << line << "\n";
                } else {//found it
                    cout<<"1.update name\n2.update grades\n";int updateNumber; cin>>updateNumber;
                    if (updateNumber==1) {
                        cout<<"Enter new name: ";
                        string new_name; cin>>new_name;
                        temp<<left << setw(18)<<new_name<<setw(20)<<ID_To_Update;
                                    for (int i=0;i<line.length();i++) {
                                        int j=i;
                                        while(line[i]=='[' && line[j]!=']') {
                                            temp<<line[j];
                                            j++;
                                        }
                                    }
                                    temp<<"\n";
                                    cout << "Record updated successfully!\n";
                                }else if (updateNumber==2) {
                                    string old_name= line.substr(0, line.find(' '));
                                    temp<<left << setw(18)<<old_name<<setw(20)<<ID_To_Update<<'[';

                                    cout<<"Enter new grades: ";
                                    int grade;
                                    for (int i=0;i<4;i++) {
                                        cin>>grade;
                                        temp<<grade<<",";
                                    }
                                    cin>>grade;
                                    temp<<grade<<"]\n";
                                    cout << "Record updated successfully!\n";
                                }else {
                                    cout<<"invalid choice!\n: ";
                                }

                            }

                        }

                    }



    }

    temp.close();
    list.close();
    remove("list.txt");
    rename("temp.txt", "list.txt");
}
int main() {
   int choice;

    do {
        cout<<"1. Create new record\n";
        cout<<"2. Read records information\n";
        cout<<"3. Delete record\n";
        cout<<"4. Update record\n";
        cout<<"5. Exit\n";
        cout<<"----------------------------------\n";
        cout<<"choose operation: "; cin>>choice;
        switch(choice){
            case 1: {
                Student s;
                CreateRecord("list.txt",s);
                break;
            }
            case 2: {
                printfile("list.txt");
                break;
            }
            case 3: {
                string targetId,targetName;
                cout<<"Enter ID to delete: ";cin>>targetId;
                DeleteRecord(targetId);
                break;
            }
            case 4: {// update
                string targetID; cout<<"Enter ID to Update information: ";cin>>targetID;
                UpdateRecord(targetID);
                break;
            }
            case 5: {
                cout<<"Exiting...\n";
                break;
            }
            default:
                cout<<"Invalid Choice\n";
                break;
        }

    }
    while(choice!=5);

    return 0;
}