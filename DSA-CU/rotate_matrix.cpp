#include <iostream>
using namespace std;

int main() {
    int n = 3, i, j, temp;

    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    //  Transpose
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // swap row
    for(i = 0; i < n; i++){
        for(j = 0; j < n/2; j++){
            temp = arr[i][j];
            arr[i][j] = arr[i][n - j - 1];
            arr[i][n - j - 1] = temp;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
