#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char ch;
	struct _Node* link;
}Node;

int main() {
	Node* pList = NULL;
	Node* prt;
	int index;

	printf("(1)Insert : A B C D\n");
	pList = InsertNode(pList, 'A');
	pList = InsertNode(pList, 'B');
	pList = InsertNode(pList, 'C');
	pList = InsertNode(pList, 'D');
	PrintList(pList);

	printf("(2)Insert : C\n");
	pList = InsertNode(pList, 'C');
	PrintList(pList);

	printf("(3)Search : C\n");
	
}