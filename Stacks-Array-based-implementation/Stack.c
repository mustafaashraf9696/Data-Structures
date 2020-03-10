#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Stack.h"



void CreateStack (Stack *ps){
ps -> top = 0 ;
}
// Initialize Stack

int Push (StackEntery e , Stack *ps){
if (ps -> top == MAXSTACK)
    return 0 ;
else{
    ps -> entery [ps -> top++] = e ;
    return 1 ;
    }
}

int StackFull (Stack *ps){
if (ps -> top == MAXSTACK)
    return 1 ;
else
    return 0 ;
}

void Pop (StackEntery *pe , Stack *ps){
if (ps -> top == 0)
    return 0 ;
else {
    pe = ps -> entery[--ps->top];
    return 1 ;
    }
}

int StackEmpety (Stack *ps){
return (!(ps -> top));
}

void StackTop (StackEntery *pe ,Stack *ps){
*pe = ps->entery[ps->top-1];
}


int StackSize (Stack *ps){
return ps->top ;
}

void ClearStack (Stack *ps){
ps ->top = 0 ;
}

void TraverseStack (Stack *ps , void(*pf)(StackEnery)){
for (int i = ps->top ; i >= 0 ; i--){
    (*pf)(ps->entery[i-1]);
    }
}
