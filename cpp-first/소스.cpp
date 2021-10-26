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
	newNode -> link = NULL;

}

void PrintList(Node* pList) {

}