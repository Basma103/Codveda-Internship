#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

#define FILESYSTEM "All_files.txt"
struct NewFile {
    string name;
    string content;
    int size;
};

bool isFileEmpty(string filetxt) {
    ifstream test_empty(filetxt);
    if (!test_empty || test_empty.peek() == EOF) {
        return  true;
    }
    test_empty.close();
    return false;
}
void display_files() {
    ifstream infile(FILESYSTEM);
    string line;
    if (isFileEmpty(FILESYSTEM)) {
        ofstream outfile(FILESYSTEM);
        outfile<< "================ SYSTEM FILES ================\n";
        outfile<< left << setw(25) << "File Name" << "Size (Bytes)" << "\n";
        outfile << "-------------------------------------------\n";
    }
    if (infile.is_open()) {
        while (getline(infile,line)) {
            cout << line << "\n";
        }
    }
    infile.close();
}

bool exist(string file) {
    ifstream infile(FILESYSTEM);
    string line;
    while (getline(infile,line)) {
        string name;
        infile>>name;
        if (name == file) {
            return true;
        }
    }
    infile.close();
    return false;
}

void Create_file(string fileName) {
    if (exist(fileName)) {
        cout << "File already exists.\n";
    }else {
        NewFile file; fstream outfile(FILESYSTEM,ios::app);
        file.name=fileName;
        cout<<"1.write in the new file\n2.quit\n"; int n; cin>>n;
        if (n==1) {
            cout<<"Enter file content: ";
            cin.ignore();
            getline(cin,file.content);
        }
        file.size =file.content.length();
        outfile<< left << setw(25) << file.name << file.size << "\n";
        outfile.close();
        cout<<"File created successfully.\n";
        ofstream file_out(file.name);
        file_out<<file.content;
        file_out.close();
    }

}
void ReadFile() {
    ifstream infile(FILESYSTEM);
    string fileName;
    cout<<"Enter File name: ";cin>>fileName;
    if (!exist(fileName)) {
        cout<<"File doesn't exists.\n";
    }else {
        if (isFileEmpty(fileName)){cout<<"File "<<fileName<<" is Empty!\n";}
        else {
            cout<<"Content of file "<<fileName<<"\n";
            string content;
            ifstream Read(fileName);
            while (getline(Read,content)) {
                cout<<content<<"\n";
            }
        }
    }
    infile.close();
}

void DeleteFile() {
    string fileName;
    cout<<"Enter File name: ";cin>>fileName;
    if (!exist(fileName)) {
        cout<<"File doesn't exists.\n";
    }else {

        ifstream infile(FILESYSTEM);
        ofstream temp("temp.txt", ios::app);
        string line;
        while (getline(infile,line)) {
            stringstream ss(line); string name;
            ss>>name;
            if (name == fileName) {
                cout<<"File deleted successfully.\n";
                remove(fileName.c_str());// to delete the file from the computer's hard drive
            }else {
                temp<<line<<"\n";
            }
        }

        temp.close();
        infile.close();
        remove(FILESYSTEM);
        rename("temp.txt",FILESYSTEM);
    }
}

int main() {
    int choice;
    do {
        cout<<"------------------------------------------\nEnter your choice\n";
        cout<<"1.Display All files\n";
        cout<<"2.Create new file\n";
        cout<<"3.Read file\n";
        cout<<"4.Delete file\n";
        cout<<"5.Quit\n";
        cin>>choice;

        switch (choice) {
            case 1: {
                display_files();
                break;
            }
            case 2: {
                cout<<"Enter the name of the file to be Create: ";
                string file; cin>>file;
                Create_file(file);
                break;
            }
            case 3: {
                cout<<"Reading Mood\n";
                ReadFile();
                break;
            }
            case 4: {
                DeleteFile();
                break;
            }
            case 5: {
                cout<<"Good Bye\n";
                break;
            }
            default: cout<<"invalid choice\n";
        }
    }
    while (choice!=5);

    return 0;
}