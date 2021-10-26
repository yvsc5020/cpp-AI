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
	pList = insertNode(pList, 'D');
	pList = insertNode(pList, 'E');
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