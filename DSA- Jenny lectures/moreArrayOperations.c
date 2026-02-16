#include <stdio.h>
void reverse();
void removeDuplicates();

int main() {
    // reverse();
    removeDuplicates();
    
}

void reverse(){
    int arr[5]={1,2,3,4,5},n=5,temp;
    for(int i=0;i<n/2;i++){
    temp=arr[i];
    arr[i]=arr[(n-1)-i];
    arr[(n-1)-i]=temp;
    }

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}

void removeDuplicates(){
    int arr[4]={1,2,3,1},n=4;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if (arr[i]==arr[j]){
            for(int k=j;k<n-1;k++){
                arr[k]=arr[k+1];
                }
                n--;

        }
        }
    }
    for(int i=0;i<n;i++){
    printf("{%d}",arr[i]);
    }
}