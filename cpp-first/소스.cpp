#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char ch;
	struct _Node* link;
}Node;

Node* insertNode(Node* pList, char newch);
void PrintList(Node* pList);

int main() {
	Node* pList = NULL;

	Node* ptr;

	pList = insertNode(pList, 'A');
	pList = insertNode(pList, 'B');
	pList = insertNode(pList, 'C');
	pList = insertNode(pList, 'D');
	pList = insertNode(pList, 'E');
	pList = insertNode(pList, 'F');
	pList = insertNode(pList, 'G');
	pList = insertNode(pList, 'H');
	pList = insertNode(pList, 'I');
	pList = insertNode(pList, 'J');
	pList = insertNode(pList, 'K');
	pList = insertNode(pList, 'L');
	pList = insertNode(pList, 'M');
	pList = insertNode(pList, 'N');
	pList = insertNode(pList, 'O');
	pList = insertNode(pList, 'P');
	pList = insertNode(pList, 'Q');
	pList = insertNode(pList, 'R');
	pList = insertNode(pList, 'S');
	pList = insertNode(pList, 'T');
	pList = insertNode(pList, 'U');
	pList = insertNode(pList, 'V');
	pList = insertNode(pList, 'W');
	pList = insertNode(pList, 'X');
	pList = insertNode(pList, 'Y');
	pList = insertNode(pList, 'Z');

	PrintList(pList);

	return 0;
}

Node* insertNode(Node* pList, char newch) {

	Node* newNode;
	Node* trace = pList;
	Node* prevNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode -> ch = newch;
	newNode->link = NULL;

	if (pList == NULL || pList->ch > newch) {
		newNode -> link = pList;
		pList = newNode;
	}
	else {
		while (trace != NULL && trace->ch < newch) {
			prevNode = trace;
			trace = trace->link;
		}

		newNode -> link = prevNode -> link;
		prevNode -> link = newNode;
	}

	return pList;

}

void PrintList(Node* pList) {
	Node* trace = pList;

	while (trace != NULL) {
		printf("%c ", trace->ch);
		trace = trace->link;
	}
}