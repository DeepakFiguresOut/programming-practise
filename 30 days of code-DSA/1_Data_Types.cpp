// Objective

// Today, we're discussing data types. Check out the Tutorial tab for learning materials and an instructional video!

// Task

// Complete the code in the editor below. The variables i, d, and s are already declared and initialized for you. You must:

// Declare 3 variables:

// one of type int

// one of type double

// one of type String

// Read 3 lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your 3 variables.

// Use the + operator to perform the following operations:

// Print the sum of i plus your int variable on a new line.

// Print the sum of d plus your double variable to a scale of 1 decimal place on a new line.

// Concatenate s with the string you read as input and print the result on a new line.

// Note:
// If you are using a language that doesn't support using + for string concatenation (e.g., C), you can just print one variable immediately following the other on the same line. The string provided in your editor must be printed first, immediately followed by the string you read as input.

// Input Format

// The first line contains an integer that you must sum with i.

// The second line contains a double that you must sum with d.

// The third line contains a string that you must concatenate with s.

// Output Format

// Print:

// The sum of both integers on the first line.

// The sum of both doubles (scaled to 1 decimal place) on the second line.

// The two concatenated strings on the third line.

// Sample Input
// 12
// 4.0
// is the best place to learn and practice coding!

// Sample Output
// 16
// 8.0
// HackerRank is the best place to learn and practice coding!

// Explanation

// When we sum the integers 4 and 12, we get 16.

// When we sum the floating-point numbers 4.0 and 4.0, we get 8.0.

// When we concatenate HackerRank with is the best place to learn and practice coding!, we get:

// HackerRank is the best place to learn and practice coding!


// link : https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true 

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int num1;
    double num2;
    string str;
    
    // Read and save an integer, double, and String to your variables.
    cin>>num1;
    cin>>num2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, str); // read full line
    
    // Print the sum of both integer variables on a new line.
    cout<<fixed<<setprecision(1);
    cout<<num1+i<<endl;

    // Print the sum of the double variables on a new line.
        cout<<num2+d<<endl;
    // Concatenate and print the String variables on a new line
        cout<<s+str<<endl;
    // The 's' variable above should be printed first.


    return 0;
}