#include <iostream>
#include <string>
using namespace std;
void bubble_sort(int arr[], int size) {// in best case it will be O(size),worst case if it sorted reveresly it will be O(size^2)

    for(int i=0;i<size;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(arr[j+1]<arr[j]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int binary_search(int arr[], int low, int high, int key) {// TC for BS: O(log(size)) -->it searchs by remove a half which value is cant be there
        int mid=(low+high)/2;
        if(arr[mid]==key) {
            return mid;
        }
        if(arr[mid]<key) {
            binary_search(arr,low,mid-1,key);
        }
        else {
            binary_search(arr,mid+1,high,key);
        }
        return -1;
}
int linear_search(int arr[],int size, int key) {// it costs me to search all over the loop so it is O(size)
    for(int i=0;i<size;i++) {
        if(arr[i]==key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1};
    bubble_sort(arr,9);// sorted array
    for(int i=0;i<9;i++) {
        cout<<arr[i]<<" ";
    }cout<<"\n";
    cout<<binary_search(arr,0,8,5)<<endl;
    return 0;
}