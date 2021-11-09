//*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	char name[20];
	struct _Node* link;
}Node;

Node* insertNode(Node* pList, const char* newName);
void PrintList(Node* pList);
Node* SearchNode(Node* pList, const char* seName, int* pIndex);
Node* deleteNode(Node* pList, const char* delName);
Node* freeList(Node* pList);

int main() {
	Node* pList = NULL;
	Node* ptr;
	int index;

	printf("(1) insert : 볼펜, 화이트보드, 연필깎기\n");
	pList = insertNode(pList, "볼펜");
	pList = insertNode(pList, "화이트보드");
	pList = insertNode(pList, "연필깎기");
	PrintList(pList);

	printf("\n(2) insert : 샤프\n");
	pList = insertNode(pList, "샤프");
	PrintList(pList);

	printf("\n(3) search : 화이트보드\n");
	ptr = SearchNode(pList, "화이트보드", &index);
	printf("%s를 [%d]번째에서 찾았습니다.", ptr->name, index + 1);

	printf("\n(4) delete : 볼펜\n");
	pList = deleteNode(pList, "볼펜");
	PrintList(pList);

	printf("\n(5) deldet:ALL");
	pList = freeList(pList);
	PrintList(pList);

	return 0;
}

Node* insertNode(Node* pList, const char* newName) {

	Node* newNode;
	Node* trace = pList;
	Node* prevNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	strcpy_s(newNode->name, newName);
	newNode->link = NULL;

	if (pList == NULL || strcmp(pList->name , newName) > 0) {
		newNode->link = pList;
		pList = newNode;
	}
	else {
		while (trace != NULL && strcmp(trace->name, newName) < 0) {
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
		printf("\n리스트 안에 값이 없습니다.\n");
	}

	printf("List = (");

	while (trace != NULL) {

		printf("%s", trace->name);

		trace = trace->link;

		if (trace != NULL) {
			printf(", ");
		}

	}

	printf(")");

}

Node* SearchNode(Node* pList, const char* seName, int* pIndex) {

	Node* trace = pList;
	*pIndex = 0;

	while (trace != NULL) {

		if (strcmp(trace->name, seName) == 0) break;

		trace = trace->link;

		*pIndex = *pIndex + 1;

	}

	return trace;

}

Node* deleteNode(Node* pList, const char* delName) {

	Node* trace = pList;
	Node* prevNode = NULL;

	while (trace != NULL && strcmp(trace->name, delName) != 0) {

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