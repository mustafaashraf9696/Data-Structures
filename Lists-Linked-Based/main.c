#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int ListEntry;

typedef struct listnode {
	ListEntry entry;
	struct listnode* next;
}ListNode;

typedef struct list {
	ListNode* head;
	int Size;
}List;

void CreateList(List* pl) {
	pl->head = NULL;
	pl->Size = 0;
}

int ListEmpty(List* pl) {
	return !pl->Size;
}

int ListFull(List* pl) {
	return 0;
}

int ListSize(List* pl) {
	return pl->Size;
}

void DestroyList(List* pl) {
	ListNode* q;
	while (pl->head){
		q = pl->head->next;
		free(pl->head);
		pl->head = q;
	}
	pl->Size = 0;
}

void TraverseList(List* pl, void (*pf)(ListEntry)) {
	ListNode* q = pl->head;
	while (q){
		(*pf)(q->entry);
		q = q->next;
	}
}

void InsertList(int pos, ListEntry e, List* pl) {
	int i;
	ListNode* newnode;
	ListNode* q;
	newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->entry = e;
	newnode->next = NULL;									//Not Needed Step 
	if (pos == 0) {
		newnode->next = pl->head;
		pl->head = newnode;
	}
	else {
		for (q = pl->head, i = 0; i < (pos - 1); i++)
			q = q->next;		// pos -1 ->Node
		newnode->next = q->next; // newnode -> next = pos 
		q->next = newnode; 
	}
	pl->Size++;
}

void DeleteList(int pos , ListEntry* pe ,List* pl){
	ListNode* q; // pointer to node whth position pos 
	ListNode* temp;//pointer to node in for loop 
	int i;
	if (pos==0){
		*pe = pl->head->entry;
		q = pl->head;
		pl->head = pl->head->next;
		free(q);
	}
	else{
		for (q = pl->head, i = 0; i < pl->Size - 1; i++)
			q = q->next;
		*pe = q->next->entry;//Value at pos 
		temp = q->next->next;//pos+1
		free(q->next);//free pos
		q->next = temp;
	}
	pl->Size--;
}

void RetrieveList(int pos, ListEntry* pe, List* pl) {
	ListNode* q;
	int i;
	for (q = pl->head, i = 0; i <= pos; i++)
		q = q->next;
	*pe = q->entry; 
}

void ReplaceList(int pos, ListEntry e, List* pl) {
	ListNode* q;
	int i;
	for (q = pl->head, i = 0; i <= pos; i++)
		q = q->next;
	q->entry = e;

}



void main() {
	int p = 0;
	List l;
	CreateList(&l);
	while (p < 10)
	{
		if (p <= ListSize(&l)) {
			InsertList(p, 5, &l);
			printf("Position is %d \n", p);
			printf("Size is : %d \n", ListSize(&l));
			p++;
		}
	}
};
