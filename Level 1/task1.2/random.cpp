#include <iostream>
#include <random>
using namespace std;

int main() {

    random_device rd; // to pick number randomly
    uniform_int_distribution<int> dist(1, 999); // to limit the range to guess
    int num = dist(rd);

    int guess,counter=1;
    cout<<"Enter your guess: "; cin>>guess;

    while(guess!=num){
        counter++;
        if(guess<num){
            cout<<"to low\n";
            cin>>guess;
        }
        else if(num<guess){
            cout<<"to high\n";
            cin>>guess;
        }
        else{
            break;
        }
    }
    cout<<"you guessed the random number after "<<counter<<" times!\n";
    return 0;
}