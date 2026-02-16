#include <stdio.h>
void faltukibakchodi();
 void traverseUsingPointers();

int main() {
    
    // printf("%d",arr[2]);
    // printf("%d",2[arr]);
    faltukibakchodi();
    // traverseUsingPointers();
    return 0;
}

void faltukibakchodi(){
    int a=8;
    // int* ptr =a; //error bitch. u cant store int value in ptr
        int arr[]={1,2,3,3,4,5,6,7,8};
    int*ptr=&arr[0];
    printf("%d",arr[5]);
}
 void traverseUsingPointers(){
    int arr[]={1,2,3,3,4,5,6,7,8};
    int *ptr =&arr[0];
    for(int i=0;i<8;i++){
        printf("%d\t",*arr+i);
    }
 }