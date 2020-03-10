#ifndef STACK_LINKED_H_INCLUDED
#define STACK_LINKED_H_INCLUDED

typedef int StackEntery ;

typedef struct stacknode{
        StackEntery entery ;
        struct stacknode *next ;
}StackNode;

typedef struct stack {
    StackNode *top ;
    int Size ;
}Stack ;


void CreateStack (Stack *ps);
int Push (StackEntery e , Stack *Ps);
int StackFull (Stack *ps);
void Pop (StackEntery *pe , Stack *ps);
int StackEmpety (Stack *ps);
void StackTop (StackEntery *pe ,Stack *ps);
int StackSize (Stack *ps);
void ClearStack (Stack *ps);
void TraverseStack (Stack *ps , void(*pf)(StackEnery));




#endif // STACK_LINKED_H_INCLUDED
