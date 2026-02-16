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
    cout<<"Enter Number of nodes: ";
    cin>>n;
    struct node {
        int data;
        struct node *next;
    };
    
    struct node *head=NULL;
    struct node *newnode = NULL;
    struct node *temp=NULL;
    for (i=0;i<n;i++){
        cout<<"Enter " << i+1<<" th node:"<<" ";
        cin>> data;
        cout<<endl;
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
