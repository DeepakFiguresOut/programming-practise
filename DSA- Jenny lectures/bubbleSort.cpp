#include <iostream>
using namespace std;
int bubbleSort(int arr[],int n);
int main() {
    int arr[5]={16,4,5,6,8},n=5,i;
    bubbleSort(arr,n);
    for(i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
    return 0;
}
int bubbleSort(int arr[],int n){
    int sorted,i,j,temp;
    for(i=0;i<n-1;i++){
        sorted=1;
        cout<<"pass:"<<i+1<< "\n";
        for(j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorted=0;
            }
        }
        if(sorted){
            break ;
        }
    } 
}