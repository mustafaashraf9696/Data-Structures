#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAXLIST 100 

typedef int ListEntry;

typedef struct list {
	ListEntry entry[MAXLIST];
	int Size;
}List;

void CreateList(List* pl) {
	pl->Size = 0;
}

int ListEmpty(List* pl) {
	return !pl->Size;
}

int ListFull(List* pl) {
	return (pl->Size == MAXLIST);
}

int ListSize(List* pl) {
	return pl->Size;
}

void DestroyList(List* pl) {
	pl->Size = 0;
}

void InsertList(int p, ListEntry e, List* pl) {
	int i;
	for (i = pl->Size - 1; i >= p; i--)
		pl->entry[i + 1] = pl->entry[i];
	pl->entry[p] = e;
	pl->Size++;
}

void DeleteList(int p, ListEntry* pe, List* pl) {
	int i; 
	*pe = pl->entry[p];
	for (i = p; i <= pl->Size; i++)
		pl->entry[i-1] = pl->entry[i];
	pl->Size--;
}

void RetriveList(int p, ListEntry* pe, List* pl) {
	*pe = pl->entry[p];
}

void ReplaceList(int p, ListEntry e, List* pl) {
	pl->entry[p] = e;
}

void TraverseList(List* pl, void(*pf)(ListEntry)) {
	for (int i = 0; i < pl->Size; i++)
		(*pf)(pl->entry[i]);
}

int main() {
	int p=0;
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

	return 0;
}
