//write a program to count the occurenes of a target elemtn entered by the user (lower bound to upper bound)
#include <stdio.h>

int main() {
    int arr[10] = {3,5,5,5,6,7,7,8,8,8};
    int n = 10, ub = -1, lb = -1, count = 0, target;

    printf("Enter target element: ");
    scanf("%d", &target);

    for(int i = 0; i < n; i++){
        if (arr[i] == target){
            if(lb == -1){
                lb = i;   // first occurrence
            }
            ub = i;       // last occurrence 
            count++;
        }
    }

    if(count > 0){
        printf("Count: %d\n", count);
        printf("Lower Bound (first index): %d\n", lb);
        printf("Upper Bound (last index): %d\n", ub);
    } else {
        printf("Element not found in array.\n");
    }

    return 0;
}
