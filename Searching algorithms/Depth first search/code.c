#include <stdio.h>

#define N 7   // брой върхове

int G[N][N] = {
	//  1  2  3  4  5  6  7 
	   {0, 1, 1, 0, 0, 0, 0}, //1
	   {1, 0, 1, 1, 0, 0, 0}, //2
	   {1, 1, 0, 1, 1, 0, 1}, //3
	   {0, 1, 1, 0, 1, 1, 1}, //4
	   {0, 0, 1, 1, 0, 0, 0}, //5
	   {0, 0, 0, 1, 0, 0, 0}, //6
	   {0, 0, 1, 1, 0, 0, 0}  //7
};

int visited[N] = { 0 };

void DFS(int v)
{
	visited[v] = 1;
	printf("%d ", v + 1);   // +1 защото индексите са 0–6, а върховете 1–7
	for (int i = 0; i < N; i++)
	{
		if (G[v][i] == 1 && !visited[i])
		{
			DFS(i);
		}
	}
}

void isVertexCycles(int v, int parent) {
	visited[v] = 1;
	int hasCycle = 0;
	for (int i = 0; i < N; i++)
	{
		if (G[v][i] == 1)
		{
			if (!visited[i])
			{
				isVertexCycles(i, v);
			}
			else if (i != parent)
			{
				hasCycle = 1;
			}
		}
	}
}

void isCompleteVertex(int n, int adj[N][N]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				if (adj[i][j] != 0)
					return 0;
			}
			else
			{
				if (adj[i][j] != 1)
					return 0;
			}
		}
	}
}

int main()
{
	int n;
	printf("Ot koi varh da zapochnem (1-7):");
	scanf_s("%d", &n);
	printf("Zapochnav DFS ot varh % d:\n", n);
	DFS(n - 1);
	printf("\n");

	return 0;
}