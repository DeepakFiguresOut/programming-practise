#include <iostream>
using namespace std;
// find sum of diagonal elements, find transpose
int main() {
    int rows, columns, i, j;

    cout << "Enter number of Rows and Columns: ";
    cin >> rows >> columns;

    int arr[rows][coulmns]; 
    int transposed[rows][coulmns];

    cout << "Enter matrix elements:\n";
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            cin >> arr[i][j];
        }
    }
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            transposed[j][i]=arr[i][j];
        }
    }
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            cout<<transposed[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
