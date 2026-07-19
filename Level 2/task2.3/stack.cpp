#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct node {
    T data;
    node* next;
};

template <typename T>
class Stack {
    int counter;
    node<T> * top;

public:
    Stack() {
        counter = 0;
        top = NULL;
    }
    void push(T val) {
        node<T>* temp=new node<T>;
        temp->data = val;
        temp->next = top;
        top=temp;
        counter++;
    }
    T pop() {
        if (isEmpty()) {
            cout<<"Stack is empty, Can not pop elements\n";
            return -1;
        }
        node<T>* temp=top;
        T val=temp->data;
        top=top->next;
        counter--;
        delete temp;
        return val;
    }
    T Top() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }
    bool isEmpty() {
        return counter==0;
    }

    void display() {
        cout<<"Displaying the stack: ";
        node<T>* temp=top;
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    int size() {
        return counter;
    }
};


int main() {

    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.pop();
    s.display();

    Stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.display();
    s2.pop();
    s2.display();
    cout<<"deleted value= "<<s2.pop()<<"\n";
    cout<<"deleted value= "<<s2.pop()<<"\n";
    cout<<"deleted value= "<<s2.pop()<<"\n";
    s2.display();
    s2.pop();
    s2.pop();

    return 0;
}