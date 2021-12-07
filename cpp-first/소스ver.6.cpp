#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 100

void InitQueue();
void Enqueue(int num);
int Dequeue();
int Front();
int Back();
bool IsEmpty();

int Queue[MAX];
int begin, end;

int main() {

	InitQueue();

	int num;
	char str[MAX];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {

		scanf("%s", str);

		if (strncmp(str, "Enqueue", 7) == 0) {

			int temp = (int)str[7] - 48;

			Enqueue(temp);

		}

		else if (strcmp(str, "Dequeue") == 0) {

			printf("%d\n", Dequeue());

		}

		else if (strcmp(str, "Size") == 0) {

			printf("%d\n", end - begin);

		}

		else if (strcmp(str, "IsEmpty") == 0) {

			if (IsEmpty()) {

				printf("1\n");

			}

			else {

				printf("0\n");

			}

		}

		else if (strcmp(str, "Front") == 0) {

			printf("%d\n", Front());

		}

		else if (strcmp(str, "Back") == 0) {

			printf("%d\n", Back());

		}

	}

}

void InitQueue() {

	begin = 0;
	end = 0;

	for (int i = 0; i < MAX; i++) {

		Queue[i] = 0;

	}

}

void Enqueue(int num) {

	if (end >= MAX) {

		printf("Queue overflow\n");
		return;

	}

	Queue[end++] = num;

}

int Dequeue() {

	if (IsEmpty()) {

		return -1;

	}

	return Queue[begin++];

}

int Front() {

	return Queue[begin];

}

int Back() {

	return Queue[end - 1];

}

bool IsEmpty() {

	return (begin == end);

}