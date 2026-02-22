// divide the array in two parts. Sorted subarray and unsorted subarray
// find the smallest element in the unsorted sublist and  with first element of unsorted sublist 

// 


// 

#include <iostream>

int main() {
    // Code implementation goes here
    using namespace std;
    int temp, arr[5]={1,5,3,2,5},n=5;
    int minindex=0,min=arr[0];    

    for(int j=0;j<n-1;j++){
        //for loop to find min in unsorted array
        for(int i=0;i<n-1;i++){
            if(arr[i]<min){
                min=arr[i];
                minindex=i;
                //swap
                temp=min;
                arr[i]=arr[minindex];
                arr[minindex]=temp;
                minindex++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    
return 0;
}
