#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define  MAXSTACK 100
typedef int StackEntery   ;


typedef struct stack {
int top ;
StackEntery entery [MAXSTACK];
}Stack;

//Stack Implementation


void CreateStack (Stack *ps);
int Push (StackEntery e , Stack *Ps);
int StackFull (Stack *ps);
void Pop (StackEntery *pe , Stack *ps);
int StackEmpety (Stack *ps);
void StackTop (StackEntery *pe ,Stack *ps);
int StackSize (Stack *ps);
void ClearStack (Stack *ps);
void TraverseStack (Stack *ps , void(*pf)(StackEnery));


#endif // STACK_H_INCLUDED
