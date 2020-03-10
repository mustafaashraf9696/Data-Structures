#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Stack_Linked.h"

int main (){
    Stack x ;
    CreateStack(&x);
    Push(5,&x);
    int y;
    StackTop(&y,&x);
    printf("Top Value is %d",y);


return 0 ;
}
