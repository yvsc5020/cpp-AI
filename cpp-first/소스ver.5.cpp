/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX 100

void InitStack();
void Push(int Data);
int Pop();
bool IsEmpty();
int Top();

int Stack[MAX];
int top;

int main() {

	char str[100];
	int ans = 0;

	scanf("%s", str);

	for (int i = 0; str[i] != NULL; i++) {

		if (str[i] == '(') Push(i);

		else {

			if (Top() + 1 == i) {

				Pop();
				ans += top;

			}

			else {

				Pop();
				ans++;

			}

		}
		// 콜라맛 나는 사이다? 이거 못참지 이거 "히트"다
	}

	printf("%d", ans);

	return 0;

}

void InitStack() {

	top = 0;
	for (int i = 0; i < MAX; i++) Stack[i] = 0;

}

void Push(int Data) {

	if (top >= MAX) {

		printf("Stack Overflow\n");
		return;

	}

	Stack[top++] = Data;

}

int Pop() {

	if (top < 0) {

		printf("Stack Underflow\n");
		return -1;

	}

	return Stack[--top];

}

bool IsEmpty() {

	return (top == 0);

}

int Top() {

	return Stack[top - 1];

}
//*/