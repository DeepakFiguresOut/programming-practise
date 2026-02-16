#include <stdio.h>
#include <stdlib.h>
void TestFunc();

int main() {
    TestFunc();
    return 0;
}

void TestFunc(){
    int *ptr,length; 

    printf("Enter no. of elements");
    scanf("%d",&length);
    ptr=(int*) malloc(length*sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
    }
    for(int i=0;i<length;i++){
        printf("Enter %dth element\n",i);
        scanf("%d",&ptr[i]);

    }

    for(int i=0;i<length;i++){
        printf("%dth element:%d",i,ptr[i]);
    }
}