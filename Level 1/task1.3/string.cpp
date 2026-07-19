#include <iostream>
#include <string>
using namespace std;

string reversing(string s){
    for(int i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-1-i]);
    }
    return s;
}

bool is_palindrome(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}

int count_vowels(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
        s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            count++;
        }
    }
    return count;
}
int main() {
    string word,reve_word; cin>>word;
    reve_word=reversing(word);
    
    reverse(word.begin(),word.end()); 
    if(reve_word==word){
        cout<<"Function is working!\n";
    }
    
    string to_check="sas";
    is_palindrome(to_check)? cout<<"it is palindrome" : cout<<"it is not palindrome";
    return 0;  
}