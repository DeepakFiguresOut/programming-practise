#include <stdio.h>
void deletionFromSortedArray();
void deletionFromUnsortedArray();
int main() {
    // deletionFromSortedArray();
    deletionFromUnsortedArray();
    return 0;
}
void deletionFromSortedArray(){
    int arr[50],size,position;  
    printf("enter size of arr:");
    scanf("%d",&size);
    if(size>50){
        printf("overflow error!\n");
    }
    else{
        // insertion using traversal- populating the array
        for(int i=0;i<size;i++){
            printf("enter %dth element:",i);
            scanf("%d",&arr[i]);
        }

        // retrieving elements using traversal
        for(int i=0;i<size;i++){
            printf("%d\t",arr[i]);
        }
    }

    
    printf("enter the postition to delete:");
    scanf("%d",&position);

    if((position<1)|| (position>size)){
        printf("position error! ..");
    }
    else{
        for(int i=position-1;i<size;i++){
        arr[i]=arr[i+1];
    }
    // arr[size-1]=0;
    size--;
    for(int i=0;i<50;i++){
        printf("%d\t",arr[i]);
    }
    }
}
void deletionFromUnsortedArray(){
    int arr[50],size,position;  
    printf("enter size of arr:");
    scanf("%d",&size);
    if(size>50){
        printf("overflow error!\n");
    }
    else{
        // insertion using traversal- populating the array
        for(int i=0;i<size;i++){
            printf("enter %dth element:",i);
            scanf("%d",&arr[i]);
        }

        // retrieving elements using traversal
        for(int i=0;i<size;i++){
            printf("%d\t",arr[i]);
        }
    }

    printf("enter position to delete:");
    scanf("%d",&position);
    
    arr[position-1]=arr[size-1];
    arr[size-1]=0; 
    size--;
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}