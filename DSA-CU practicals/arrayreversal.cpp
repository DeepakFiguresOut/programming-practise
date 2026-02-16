#include <iostream>
using namespace std;

int main() {
    int arr[5]={1,2,4,6,8},i,n=5,temp;
    for(i=0;i<5/2;i++){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(i=0;i<5;i++){
        cout << arr[i]<<"\n";
    }
    return 0;
}