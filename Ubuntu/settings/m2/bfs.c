#include <stdio.h>
#define N 4
int a[N][N] = {{1, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
int q[N] = {0, 0, 0, 0}, visited[N] = {0, 0, 0, 0};
int f = 0, r = -1;
void bfs(int v) {
	for (int i = 0; i < N; i++)
		if (a[v][i] && !visited[i]) q[++r] = i;
	if (f <= r) {
		visited[q[f]] = 1;
		bfs(q[f++]);
	}
}
int main() {
	// Starting vertex
	int v = 0;
	bfs(v);
	printf("\nThe nodes which are reachable are:\n");
	for (int i = 0; i < N; i++) {
		if (visited[i])
			printf("%d\t", i);
		else {
			printf("\nBfs is not possible. Not all nodes are reachable");
			break;
		}
	}
}