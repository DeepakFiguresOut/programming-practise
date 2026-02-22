// link : https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     int i,j,n;
//     cin>>n;
//     string str;
//     for(i=0;i<n;i++){
//         cin>>str;
//         for(j=0;j<str.length();j=j+2){
//             cout<<str[j];
//         }
//         cout<<" ";
//         for(j=1;j<str.length();j=j+2){
//             cout<<str[j];
//         }
//         cout<<endl;
//         }
//     return 0;
// }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int i,j,n;
    cin>>n;
    string str;
    for(i=0;i<n;i++){
        cin>>str;
        string odd,even;
        for(j=0;j<str.length();j=j+2){
            even+=str[j];
            if(j+1<str.size())
                odd+=str[j+1];            
        }
        cout<<even<< " "<<odd<<endl;
        
        }
    return 0;
}