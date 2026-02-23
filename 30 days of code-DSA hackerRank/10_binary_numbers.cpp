// link: https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    int remainder,number,maxcount=0,currentcount=0;
    string binary;
    binary="";
    while(n!=0){
        remainder=n%2;
        n= n/2;
        binary+=to_string(remainder);
    }
    reverse(binary.begin(), binary.end());

    for(char c:binary){
        if (c=='1'){
            currentcount+=1;
            maxcount=max(currentcount,maxcount);
        }
        else{
            currentcount=0;
        }
    }
    cout<<maxcount<<endl;
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
