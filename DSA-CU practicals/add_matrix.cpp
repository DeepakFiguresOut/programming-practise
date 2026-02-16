#include <iostream>
using namespace std;

int main() {
    int rows, columns, i, j;

    cout << "Enter number of Rows and Columns: ";
    cin >> rows >> columns;

    int arr1[rows][columns]; 
    int arr2[rows][columns]; 
    int sum[rows][columns];
    cout << "Enter matrix elements: for array 1\n";
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            cin >> arr1[i][j];
        }
    }


    cout << "Enter matrix elements: for array 2\n";

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            cin >> arr2[i][j];
        }
    }
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            sum[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    cout<<"Sum array"<<"\n"; 
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}