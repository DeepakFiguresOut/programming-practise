// divide the array in two parts. Sorted subarray and unsorted subarray
// find the smallest element in the unsorted sublist and  with first element of unsorted sublist 

// 


// 

#include <iostream>

int main() {
    // Code implementation goes here
    using namespace std;
    int temp, arr[5]={1,5,3,2,5},n=5;


    for(int i=0;i<n-1;i++){
        int minIndex = i;
        // for loop to find index of min element and replace

        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[minIndex]){
                minIndex =j;
            }
            //swap arr[i] <-> arr[minIndex]
            temp=arr[j];
            arr[j]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
