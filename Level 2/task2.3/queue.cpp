#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct node {
    T data;
    node* next;
};

template <typename T>
class Queue {
    int counter;
    T *data;
    node<T> *front, *rear;
public:
    Queue() {
        counter=0;
        front=NULL;
        rear=front;
    }
    void enqueue(T val) {
        node<T> *temp = new node<T>;
        temp->data = val;
        temp->next = NULL;
        if(front==NULL) {
            front=temp;
            rear=temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
        counter++;
    }
    T dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty, Can not dequeue elements\n";
            return -1;
        }
        T val = front->data;
        node<T> *temp = front;
        front = front->next;
        delete temp;
        counter--;
        return val;
    }
    T Front() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return counter==0;
    }
    int size(){
        return counter;
    }
    void display() {
        cout<<"Displaying the Queue: ";
        node<T> *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<"\n";
    }
};

int main() {
    Queue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.display();
    int val=q1.dequeue();
    q1.display();
    cout<<"deleted value= "<<val<<"\n";
    cout<<"the front of queue: "<<q1.Front()<<"\n";


    return 0;
}