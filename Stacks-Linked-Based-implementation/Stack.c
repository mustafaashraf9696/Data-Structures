#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Stack_Linked.h"

void CreateStack (Stack *ps){
    ps -> top = NULL ;
    ps -> Size = 0;
}


int Push (StackEntery e , Stack *ps){
    StackNode *pn = (StackNode*)malloc(sizeof(StackEntery));
    pn -> entery = e ;
    pn -> next = ps -> top ;
    ps -> top = pn ;
    ps -> Size ++ ;
}


int StackFull (Stack *ps){
    return 0 ;
}

void Pop (StackEntery *pe , Stack *ps){
    *pe = ps -> top -> entery ;
    StackNode *pn ;
    pn = ps -> top ;
    ps -> top = ps -> top -> next ;
    free(pn);
    ps -> Size --;
}

int StackEmpety (Stack *ps){
return !ps -> top ;
}

void StackTop (StackEntery *pe ,Stack *ps){
    *pe = ps -> top -> entery;
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

void TraverseStack (Stack *ps , void(*pf)(StackEnery)){
    StackNode *pn = ps -> top ;
    while (pn){
        (*pf)(pn -> entery);
        pn = pn -> next ;
    }
}
