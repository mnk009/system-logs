#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct job_struct {
	char id;
	int dead;
	int profit;
} Job;

int min(int a, int b) { return (a < b) ? a : b; }
bool comparison(Job a, Job b) { return (a.profit > b.profit); }

void printJobScheduling(Job arr[], int n) {
	qsort(arr, n, sizeof(arr[0]), comparison);

	int result[n];
	bool slot[n];
	for (int i = 0; i < n; i++) slot[i] = false;

	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slot[i]) printf("%c ", arr[result[i]].id);
	printf("\n");
}

int main() {
	Job arr[] = {
		{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Following is maximum profit sequence of jobs\n");
	printJobScheduling(arr, n);
	return 0;
}