#ifndef STACK_LINKED_H_INCLUDED
#define STACK_LINKED_H_INCLUDED

typedef int StackEntry ;

typedef struct stacknode{
        StackEntry entry ;
        struct stacknode *next ;
}StackNode;

typedef struct stack {
    StackNode *top ;
    int Size ;
}Stack ;


void CreateStack (Stack *ps);
int Push (StackEntry e , Stack *Ps);
int StackFull (Stack *ps);
void Pop (StackEntry *pe , Stack *ps);
int StackEmpty (Stack *ps);
void StackTop (StackEntry *pe ,Stack *ps);
int StackSize (Stack *ps);
void ClearStack (Stack *ps);
void TraverseStack (Stack *ps , void(*pf)(StackEnry));




#endif // STACK_LINKED_H_INCLUDED
