#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX 100

void InitStack();
void Push(int Data);
int Pop();
bool IsEmpty();
int Top();
bool Check(const char* str);
char str[MAX];
int Stack[MAX];
int top;
int cnt;

int main() {

	void InitStack();

	scanf("%s", str);

	printf("Top: %d\n", Top());
	printf("Popped: %d\n", Pop());

	while (!IsEmpty()) {

		printf("Popped: %d\n", Pop());

	}

	if (IsEmpty()) {
		printf("empty stack.\n");
	}
	*/

	return 0;

}

void InitStack() {

	cnt = 0;
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

	top--;
	tmp = Stack[top];
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

bool Check(const char* str) {

	bool result = true;

	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == '(') Push(str[i]);
		else {
			if (IsEmpty()) result = false;
			else Pop();
		}
	}

	if (!IsEmpty()) result = false;

	return result;
}