#include <stdio.h>
#include <stdlib.h>

void TestFunc() {
    int *ptr, length;
    
    printf("Enter no. of elements: ");
    scanf("%d", &length);
    
    ptr = (int*)malloc(length * sizeof(int));  // Allocate memory!
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Input loop - FIXED: i++ not i++;
    for(int i = 0; i < length; i++) {  // ← Correct syntax
        printf("Enter %dth element: ", i);
        scanf("%d", &ptr[i]);
    }
    
    // Output loop - FIXED
    for(int i = 0; i < length; i++) {  // ← Correct syntax
        printf("%dth element: %d\n", i, ptr[i]);
    }
    
    free(ptr);  // Clean up
}

int main() {
    TestFunc();
    return 0;
}
