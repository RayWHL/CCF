#pragma warning(disable : 4996)

#include <stdio.h>

struct edge
{
	int to;
	edge *next;
};

struct node
{
	int i;
	int color;	//°×1£¬»Ò2£¬ºÚ3
	edge *next;
};

int n, m;
node head[1005];
int out[1005][1005] = { 0 };

void addedge(int a, int b)
{
	edge *temp = new edge;
	temp->to = b;
	temp->next = head[a].next;
	head[a].next = temp;
}

void DFS(int k)
{
	head[k].color = 2;
	edge *p = head[k].next;
	for (; p; p = p->next)
	{
		if (head[p->to].color == 1)
		{
			DFS(p->to);
		}
	}
	head[k].color = 3;
}

void DFSvisit()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			head[i].i = i;
			head[i].color = 1;
		}
		DFS(k);
		for (int i = 1; i <= n; ++i)
		{
			if (head[i].color == 3)
			{
				out[k][i] = 1;
				out[i][k] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		head[i].i = i;
		head[i].color = 1;
		head[i].next = NULL;
	}
	for (int i = 1; i <= m; ++i)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		addedge(temp1, temp2);
	}
	DFSvisit();
	int outnumber = 0;
	for (int i = 1; i <= n; ++i)
	{
		int flag = 1;
		for (int j = 1; j <= n; ++j)
		{
			if (out[i][j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			++outnumber;
		}
	}
	printf("%d", outnumber);
	return 0;
}