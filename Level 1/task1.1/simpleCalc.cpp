#include <iostream>
using namespace std;
void simple_calculator(double x,double y,char o){
    if(o=='+'){
        cout<<"the sum = "<<x+y<<"\n";
    }
    else if(o=='-'){
        cout<<"the subtract = "<<x-y<<"\n";
    }
    else if(o=='*'){
        cout<<"the multiplication = "<<x*y<<"\n";
    }
    else if (o=='/'){
        if(y==0){
            cout<<"undefined\n";
        }else{
            cout<<"the division = "<<x/y<<"\n";
        }
    }
    else {
        cout<<"invalid operation\n";
    }
}
int main() {
    double num1,num2;
    cout<<"Enter first number: ";
    cin>>num1;

    cout<<"\nEnter second number: ";
    cin>>num2;

    cout<<"\nEnter the operator: ";
    char opr; cin>>opr;

    cout<<"\nanswer: ";
    simple_calculator(num1,num2,opr);
    return 0;
}