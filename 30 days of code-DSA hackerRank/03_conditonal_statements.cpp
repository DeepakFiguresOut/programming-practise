// Objective
// In this challenge, we learn about conditional statements. Check out the Tutorial tab for learning materials and an instructional video.

// Task
// Given an integer, , perform the following conditional actions:

// If  is odd, print Weird
// If  is even and in the inclusive range of  to , print Not Weird
// If  is even and in the inclusive range of  to , print Weird
// If  is even and greater than , print Not Weird
// Complete the stub code provided in your editor to print whether or not  is weird.

// Input Format

// A single line containing a positive integer, .

// Constraints

// Output Format

// Print Weird if the number is weird; otherwise, print Not Weird.

// Sample Input 0

// 3
// Sample Output 0

// Weird
// Sample Input 1

// 24
// Sample Output 1

// Not Weird
// Explanation

// Sample Case 0: 
//  is odd and odd numbers are weird, so we print Weird.

// Sample Case 1: 
//  and  is even, so it is not weird. Thus, we print Not Weird.

//  link:   https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    if(N%2==1){
        cout<<"Weird";
    }
    else {
        if(N>2 and N<5){
            cout<<"Not Weird";
        }
        else if(N>=6 and N<=20){
            cout<<"Weird";
        }
        else if(N>20){
            cout<<"Not Weird";
        }
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
