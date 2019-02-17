#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

struct edge
{
	int i; //顶点序号
	edge *next;
};

struct node
{
	int x, y;
	int i;	//顶点序号,从1开始
	int color; //BFS中颜色，白1灰2黑3
	int d;	//中转路由器个数
	int number;	//路径上经历可变路由器数目
	int type;	//0为固定，1为可变
	edge *next;	//邻接链表
};

node head[201];		//顶点
int n, m, k, r;
queue <int> qnode;

void addedge(int a, int b)
{
	edge *temp = new edge;
	temp->i = b;
	temp->next = head[a].next;
	head[a].next = temp;
}

void BFS()
{
	int temp;
	head[1].color = 2;
	head[1].d = -1;
	qnode.push(1);
	while (!qnode.empty())
	{
		temp = qnode.front();
		qnode.pop();
		edge *edgetemp;
		for (edgetemp = head[temp].next; edgetemp; edgetemp = edgetemp->next)
		{
			if (edgetemp->i == 2)
			{
				printf("%d\n", (head[temp].d + 1));
				return;
			}
			if (head[edgetemp->i].color == 1)
			{
				head[edgetemp->i].color = 2;
				head[edgetemp->i].d = head[temp].d + 1;

				if (head[edgetemp->i].type == 1)
					head[edgetemp->i].number = head[temp].number + 1;
				
				if(head[edgetemp->i].number<=k)
					qnode.push(edgetemp->i);
			}
		}
		head[temp].color = 3;
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &r);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &(head[i].x), &(head[i].y));
		head[i].type = 0;
		head[i].color = 1;
		head[i].i = i;
		head[i].d = 0;
		head[i].next = NULL;
		head[i].number = 0;
	}
	for (int i=n+1; i <= n + m; ++i)
	{
		scanf("%d %d", &(head[i].x), &(head[i].y));
		head[i].type = 1;
		head[i].type = 0;
		head[i].color = 1;
		head[i].i = i;
		head[i].d = 200;
		head[i].next = NULL;
		head[i].number = 0;
	} 
	for (int i = 1; i <= n + m; ++i)
	{
		for (int j = 1; j <= m + n; ++j)
		{
			if (i != j)
			{
				double distance = pow((head[i].x - head[j].x), 2) + pow((head[i].y - head[j].y), 2);
				if (distance <=pow(r,2))
				{
					addedge(i, j);
					addedge(j, i);
				}
			}
		}
	}

	BFS();
	return 0;
}


