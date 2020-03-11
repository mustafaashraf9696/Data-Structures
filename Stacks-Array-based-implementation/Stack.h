#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define  MAXSTACK 100
typedef int StackEntry   ;


typedef struct stack {
int top ;
StackEntry entry [MAXSTACK];
}Stack;

//Stack Implementation


void CreateStack (Stack *ps);
int Push (StackEntry e , Stack *Ps);
int StackFull (Stack *ps);
void Pop (StackEntry *pe , Stack *ps);
int StackEmpety (Stack *ps);
void StackTop (StackEntry *pe ,Stack *ps);
int StackSize (Stack *ps);
void ClearStack (Stack *ps);
void TraverseStack (Stack *ps , void(*pf)(StackEnry));


#endif // STACK_H_INCLUDED
