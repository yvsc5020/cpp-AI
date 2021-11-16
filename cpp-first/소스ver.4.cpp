#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void InitStack();
void Push(int Data);
int Pop();
bool IsEmpty();
int Top();

int Stack[MAX];
int top;

int main(){

	void InitStack();

	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Push(6);

	printf("Top: %d\n", Top());
	printf("Popped: %d\n", Pop());

	while (!IsEmpty()) {

		printf("Popped: %d\n", Pop());

	}

	if (IsEmpty()) {
		printf("빈 스택입니다.\n");
	}

	return 0;

}

void InitStack() {

	top = 0;

	for (int i = 0; i < MAX; i++) {

		Stack[i] = 0;

	}

}

void Push(int Data) {

	if (top >= MAX) {
		
		printf("Stack Overflow\n");

		return;

	}

	Stack[top++] = Data;

}

int Pop() {

	int tmp;

	tmp = Stack[top--];
	Stack[top] = NULL;
	
	return tmp;

}

bool IsEmpty() {

	if (top < 1) {

		return true;

	}

	else {
		
		return false;

	}

}

int Top() {

	return Stack[top - 1];

}