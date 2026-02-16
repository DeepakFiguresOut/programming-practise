#include <stdio.h>

int main() {
    int arr[5]={1,5,3,21,8}, n=5, largest=arr[0], sLargest=arr[1];
    

    if (arr[0] < arr[1]) {
        largest = arr[1];  
        sLargest = arr[0];
    }
    
    for(int i=2; i<n; i++) {  
        if(arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > sLargest && arr[i] != largest) {
            sLargest = arr[i];  
        }
    }
    printf("Second Largest: %d\n", sLargest);
    return 0;
}
