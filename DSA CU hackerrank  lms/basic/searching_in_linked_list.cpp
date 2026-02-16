// You are working on a package tracking system for a logistics company. Packages are tracked using a unique ID, and these IDs are stored in a linked list in the order the packages were registered.

// Your task is to implement a function that searches for a package in the list by its ID. If the package is found, return its position (1-based index) in the list. If it is not found, return -1.

// Input Format

// The first line contains an integer nn, the number of package IDs in the linked list.
// The second line contains nn space-separated integers representing the package IDs.
// The third line contains an integer targettarget, the package ID to search for.
// Constraints

// 1≤n≤104 (number of packages)
// Each package ID is a unique integer between 11 and 10^6.
// target will also be between 11 and 106106.
// Output Format

// Print a single integer representing the position of the package if found, or -1 if not found.

// Sample Input 0

// 5
// 101 202 303 404 505
// 303
// Sample Output 0

// 3
// Explanation 0

// The linked list contains the package IDs: 101 -> 202 -> 303 -> 404 -> 505. The target ID is 303, which is at position 3 in the list.


// link:https://www.hackerrank.com/contests/integration-2026/challenges/searching-in-linked-list
#include <cmath> 
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n,i,package_id,key,index=0,found=0;
    cin>>n;
    struct node {
        int id;
        struct node *next;
    };
    
    struct node *head=NULL;
    struct node *connector=NULL;
    for (i=0;i<n;i++){
        cin>> package_id;
        struct node *current=(struct node*)malloc(sizeof(struct node));
        current->id=package_id;
        current->next=NULL;
        if (head==NULL){
            head=current;
            connector=current;
        }
        else {
            connector->next=current;
            connector=current;
        }
    }
    cin>>key;
    connector=head;
    while(connector!=NULL){
        if(connector->id==key){
            cout<<index+1;
            found=1;
        }
        connector=connector->next;
        index++;
        
        
    }
    if(!found){
        cout<<-1;
    }
    return 0;}