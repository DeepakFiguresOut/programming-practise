#include <stdio.h>

void traversal();
void insertion();
int main(){
    // traversal();
    insertion();
    return 0;

    }


void traversal(){
    int arr[50],size;
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
        for(int i;i<size;i++){
            printf("%d\t",arr[i]);
        }
    }

}

void insertion(){

 int arr[50],size,element,position;
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
    
    printf("enter the element to insert:");
    scanf("%d",&element);
    
    printf("enter the postition to insert:");
    scanf("%d",&position);

    for(int i=size;i>=position-1;i--){
        arr[i+1]=arr[i];
    }
    arr[position-1]=element;
    size++;
    
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }


}