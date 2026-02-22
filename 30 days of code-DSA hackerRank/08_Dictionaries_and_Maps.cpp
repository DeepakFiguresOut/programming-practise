
// link: https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> phonebook;
    int n, phone_number;

    cin >> n;
    string name;

    // Store entries
    for(int i = 0; i < n; i++){
        cin >> name >> phone_number;
        phonebook[name] = phone_number;
    }

    // Read queries until EOF
    while(cin >> name){
        auto it = phonebook.find(name);

        if(it != phonebook.end()){
            cout << it->first << "=" << it->second << "\n";
        }
        else{
            cout << "Not found\n";
        }
    }

    return 0;
}
