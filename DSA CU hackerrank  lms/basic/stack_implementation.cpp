#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int choice,size,n,data;

    cin>>size;
    vector<int> v;
    cin>>n;
    
    while(n--){
        cin>>choice;
        if(choice==1){
            if(v.size()>=size){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                cin>>data;
                v.push_back(data);
                cout<<"Pushed "<<data<<endl;
            }
        }
        else if(choice==2){
            if(v.size()==0){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                data=v.back();
                v.pop_back();
                cout<<"Popped "<<data<<endl;
            }
            
        }
        else if(choice==3){
            if(v.size()==0){
                cout<<"Stack is empty";
            }
            else{
                for (auto it = v.end()-1; it >= v.begin(); --it) {
                        cout << *it << " ";
                    }

            }
        }
    }
        
    
    return 0;
}
