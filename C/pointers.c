#include <stdio.h>
void learningPointers();
void testFunc();
void nullPointers();
void voidPointers();
void wildPointers();
void danglingPointers();
void constantPointers();
void pointerToConstant();
void functionPointer();
void doublepointer();
int main() {

    //learningPointers();
    // testFunc();
    //nullPointers();
    // voidPointers();
    // wildPointers();
    // danglingPointers();
    //constantPointers();
    //pointerToConstant();
    //functionPointer();
    doublepointer();
return 0;
}

void testFunc(){
    char* name= "Deepak";
    printf("name");
}
void nullPointers(){
    int *ptr=NULL; // null pointer does not store any value
    printf("null ptr stores address - %p\n add. of null pointer-%p \n ",ptr,&ptr);
}

void voidPointers(){
    void *ptr;
    int a= 5;
    ptr=&a;
    printf("void ptr stores address - %p\n dereferencing- %d\n add. of null pointer-%p \n ",ptr,*(int*)ptr,&ptr); //*(int*)ptr -type casting
}

void wildPointers(){
    int *ptr;  
    printf("void ptr stores address - %p\n dereferencing- %d\n add. of null pointer-%p \n ", ptr, *(int*)ptr, &ptr);
}

void danglingPointers(){
    int *ptr;
    {
        int a=5;
        ptr=&a;
    }
    printf("void ptr stores address - %p\n dereferencing- %d\n add. of null pointer-%p \n ", ptr, *(int*)ptr, &ptr);
}
void constantPointers(){
    int a,b;
    a=7;
    b=6;
    int *const ptra=&a;
    printf("%p\n  value- %d\n",ptra, *ptra);
    // ptra=&b;  -> not possible
    // printf("%p\n value- %d\n",ptra, *ptra);
    
}

void pointerToConstant(){
    int a=5;
    const int *ptra=&a;
    printf("%p\n %d\n",ptra,a);
    // *ptra=6; does not  work
    printf("%p\n %d\n",ptra,a);
}

int add(int a, int b){
    return  a+b;
}
void functionPointer(){
    

    int (*funcPtr)(int, int) = add;  // Pointer to function taking int, int and returning int
    int sum = funcPtr(2, 3);          // Call function via pointer
    printf("%d\n", sum);

}

void doublepointer() {
    int x = 1;
    int *ptrX = &x;
    int **ptrPtr = &ptrX;  // Address of ptrX, not ptrX itself

    printf("value of ptrX: %p\n deref: %d\n", ptrX, *ptrX);
    printf("value of ptrPtr: %p\n deref: %p\n double deref: %d\n", 
           ptrPtr, *ptrPtr, **ptrPtr);
}



void learningPointers(){
    int a =5;
    float b=2.5;
    char name='D';

    int *ptra=&a;   
    printf("address of a : %p \n value of pointer : %p \n value of a:%d \n ",&a,ptra, a );
    printf("value of a using dereferencing: %d \n",*ptra);
    printf("address of ptr a: %p",&ptra);
    
    printf("\n---\n");
    float *ptrb= &b;
    printf("address of b : %p \n value of pointer : %p \n value of b:%0.2f \n ",&b,ptrb, b );
    printf("value of b using dereferencing: %0.2f \n",*ptrb);
    printf("address of ptr a: %p",&ptrb);

    printf("\n---\n");

    char *ptrName=&name;
    printf("address of name : %p \n value of name : %p \n value of name:%c \n ",&name,ptrName, name );
    printf("value of name using dereferencing: %c \n",*ptrName);
    printf("address of ptr name: %p\n",&ptrName);

}