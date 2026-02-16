#include <stdio.h>

int main() {
    int n=10,arr[n],even[10],odd[10],oddCount=0,evenCount=0;
    printf("ENter elements:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if (arr[i]%2==0){
            even[evenCount++]=arr[i];
        }
        else{
            odd[oddCount++]=arr[i];
        }
    }
    printf("Odd numbers: [");
    for(int i=0;i<oddCount;i++){
        printf(" %d, ",odd[i]);
    }
    printf("]\n Even Numbers:[");
    for(int i=0;i<evenCount;i++){
        printf(" %d, ",even[i]);
    }
    printf("]");
    return 0;
}