#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i ,num,pos,u,l;
    cin >> n;
    vector <int> arr; 
    for(i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    cin>>pos;
    arr.erase(arr.begin()+pos-1);
    cin>> l>>u ;
    arr.erase(arr.begin()+l-1,arr.begin()+u-1);
    
    cout<<arr.size()<<"\n";
    for(size_t i=0;i<arr.size();i++){
        cout << arr[i]<< " ";
    }
    return 0;
}
