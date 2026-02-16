// customer service system uses a queue to manage customers waiting for service. Each customer is added to the queue in the order they arrive. You are tasked with implementing such a program.

// Input Format

// The first line contains an integer nn, the number of integers to insert. Each of the next nn lines contains an integer datadata.

// Constraints

// The number of integers to insert will not exceed 1064.
// Each integer datadata will be between −10^3 and 10^3.
// If the linked list is initially empty, the head parameter will be NULL.
// Output Format

// Print the elements of the updated linked list, separated by spaces, after inserting all the integers.

// Sample Input 0

// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 0

// 1 2 3 4 5
// link : https://www.hackerrank.com/contests/integration-2026/challenges/insertion-in-linked-list-1-1/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n,i,data;
    cin>>n;
    struct node {
        int data;
        struct node *next;
    };
    
    struct node *head=NULL;
    struct node *newnode = NULL;
    struct node *temp=NULL;
    for (i=0;i<n;i++){
        cin>> data;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if (head==NULL){
            head=newnode;
            temp=newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
