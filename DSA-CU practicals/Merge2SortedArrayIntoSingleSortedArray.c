#include <stdio.h>

int main() {
    int arr1[5]={1,3,5,7,9};
    int arr2[5]={2,6,8,12,18};
    int i=0,j=0,k=0,c[10];

    while(i<5 || j<5){
    if(arr1[i] < arr2[j])
        c[k++] = arr1[i++];
    else
        c[k++] = arr2[j++];
    }

    for(int i=0; i<10; i++){
        printf(" %d ", c[i]);
    }


    return 0;
}