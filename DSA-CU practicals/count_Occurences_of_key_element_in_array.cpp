#include <iostream>
using namespace std;
int main(){

    int arr[6]={10,20,20,45,70,20};
    int key=20,n=6,i,found=0;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            if(!found) cout<<"\n"<<" Element found at position: ";
            cout<<i+1<<", ";
            found=1;
        }
    }
    if(!found){
        cout<<" not found";
    }
    return 0;
}