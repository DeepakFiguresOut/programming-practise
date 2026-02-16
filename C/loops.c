// for loop
// while loop
// do while loop

// print table of 2 using for loop


#include <stdio.h>
void tableUsingForloop();
void tableUsingWhileLoop();
void tableusingDoWhileLoop();
 void combination();

int main() {
    //tableUsingForloop();
    //tableUsingWhileLoop();
    //tableusingDoWhileLoop();
    //combination();

    //count to 10
    int count =1;
    check:
        printf("%d\n",count);
        count++;
        if (count<=10){
            goto check;
        }


    return 0;
}

void tableUsingForloop(){
    int num =2;
    int upperlimit=10;
    for (int i=0;i<=upperlimit;i++){
    printf("%d x %d = %d\n", num,i,num*i);
    }
}

void tableUsingWhileLoop(){
    int num =2;
    int upperlimit=10;
    int i=1;
    while (i<=upperlimit){
        printf("%d x %d = %d\n", num,i,num*i);
        i++;
    }
}

void tableusingDoWhileLoop(){
    int num =2;
    int upperlimit=10;
    int i=1;
    do{
        printf("%d x %d = %d\n", num,i,num*i);
        i++;
    }while(i<=upperlimit);
}

// print every combination of 2 digits;
 void combination(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            printf("%d%d\n",i,j);
        }
    }
 }

