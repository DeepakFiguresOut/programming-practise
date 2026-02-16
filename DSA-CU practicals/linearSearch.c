#include <stdio.h>
int linearSearch();
int main() {
    int arr[5]={1,5,3,21,8},n=5,key=1;
    int position =linearSearch(arr,n,key);
    if(position==-1){
        printf("not found");
    }
    else{
        printf("position: %d",position);
        
    }
    return 0;
}
int linearSearch(int arr[],int len,int key){
    for(int i=0;i<len;i++){
        if (arr[i]==key){
            return i;
        }   
}
    return -1;
}