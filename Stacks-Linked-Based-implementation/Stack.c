#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Stack_Linked.h"

void CreateStack (Stack *ps){
    ps -> top = NULL ;
    ps -> Size = 0;
}


int Push (StackEntry e , Stack *ps){
    StackNode *pn = (StackNode*)malloc(sizeof(StackEntry));
    pn -> entry = e ;
    pn -> next = ps -> top ;
    ps -> top = pn ;
    ps -> Size ++ ;
}


int StackFull (Stack *ps){
    return 0 ;
}

void Pop (StackEntry *pe , Stack *ps){
    *pe = ps -> top -> entry ;
    StackNode *pn ;
    pn = ps -> top ;
    ps -> top = ps -> top -> next ;
    free(pn);
    ps -> Size --;
}

int StackEmpty (Stack *ps){
return !ps -> top ;
}

void StackTop (StackEntry *pe ,Stack *ps){
    *pe = ps -> top -> entry;
}


int StackSize (Stack *ps){
    return ps -> Size ;
}

void ClearStack (Stack *ps){
    StackNode *pn = ps -> top ;

    while(pn){
    pn = pn -> next ;
    free(ps -> top);
    ps -> top = pn ;
    }
    ps -> Size = 0;
}

void TraverseStack (Stack *ps , void(*pf)(StackEntry)){
    StackNode *pn = ps -> top ;
    while (pn){
        (*pf)(pn -> entry);
        pn = pn -> next ;
    }
}
