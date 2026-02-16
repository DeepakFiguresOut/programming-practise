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
    struct node *connector=NULL;
    for (i=0;i<n;i++){
        cin>> data;
        struct node *current=(struct node*)malloc(sizeof(struct node));
        current->data=data;
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
    connector=head;

    //inserting at the beginning
    connector=head;
    cin>>data;
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current-> data=data;
    current-> next=head;
    head=current;


    //printing the node data
    connector=head;
    while(connector!=NULL){
        cout<<connector->data<<" ";
        connector=connector->next;
    }
    return 0;
}