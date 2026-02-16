#include <stdio.h>
int binarySearch();
int main() {
    int arr[5]={1,5,7,56,456}, n=5, key=5,pos;
    pos= binarySearch(arr,n,key);
    printf("Position : %d\n",pos);
    return 0;
}

int binarySearch(int arr[],int len,int key){
    int  lb=0, ub=len-1, mid,position;
    while(lb <= ub) {
        int mid =(ub+ lb) / 2; 
        
        if(key == arr[mid]) {
            position = mid + 1; 
            return position;  
        }
        else if(key < arr[mid]) {
            ub = mid - 1;
        }
        else { 
            lb = mid + 1;  
        }
    }
    
    return -1;
}
