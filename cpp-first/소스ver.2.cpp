/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char ch;
	struct _Node* link;
}Node;

Node* insertNode(Node* pList, char newch);
void PrintList(Node* pList);
Node* SearchNode(Node* pList, char ch, int* pIndex);
Node* deleteNode(Node* pList, char ch);
Node* freeList(Node* pList);

int main() {
	Node* pList = NULL;
	Node* ptr;
	int index;

	printf("(1) insert : A, B, E, D\n");
	pList = insertNode(pList, 'A');
	pList = insertNode(pList, 'B');
	pList = insertNode(pList, 'E');
	pList = insertNode(pList, 'D');
	PrintList(pList);

	printf("\n(2) search: D\n");
	ptr = SearchNode(pList, 'D', &index);
	printf("%c를 [%d]번째에서 찾았습니다.", ptr->ch, index + 1);

	printf("\n(3) insert : C\n");
	pList = insertNode(pList, 'C');
	PrintList(pList);

	printf("\n(4) delete:B\n");
	pList = deleteNode(pList, 'B');
	PrintList(pList);

	printf("\n(5) deldet:ALL");
	pList = freeList(pList);
	PrintList(pList);

	return 0;
}

Node* insertNode(Node* pList, char newch) {

	Node* newNode;
	Node* trace = pList;
	Node* prevNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->ch = newch;
	newNode->link = NULL;

	if (pList == NULL || pList->ch > newch) {
		newNode->link = pList;
		pList = newNode;
	}
	else {
		while (trace != NULL && trace->ch < newch) {
			prevNode = trace;
			trace = trace->link;
		}

		newNode->link = prevNode->link;
		prevNode->link = newNode;
	}

	return pList;
}

void PrintList(Node* pList) {

	Node* trace = pList;

	if (trace == NULL) {
		printf("\n리스트 안에 값이 없습니다.");
	}

	while (trace != NULL) {

		printf("%c ", trace->ch);

		trace = trace->link;

	}
}

Node* SearchNode(Node* pList, char ch, int* pIndex) {

	Node* trace = pList;
	*pIndex = 0;

	while (trace != NULL) {

		if (trace->ch == ch) break;

		trace = trace->link;

		*pIndex = *pIndex + 1;

	}

	return trace;

}

Node* deleteNode(Node* pList, char ch) {

	Node* trace = pList;
	Node* prevNode = NULL;

	while (trace != NULL && trace->ch != ch) {
		
		prevNode = trace;
		trace = trace->link;

	}

	if (trace != NULL) {
		if (prevNode == NULL) {
			pList = pList->link;
		}
		else {
			prevNode->link = trace->link;
		}
	}

	free(trace);

	return pList;

}

Node* freeList(Node* pList) {

	Node* saveLink = NULL;

	while (pList != NULL) {

		saveLink = pList->link;
		free(pList);
		pList = saveLink;

	}

	return pList;

}
//*/