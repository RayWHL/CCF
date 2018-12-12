#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

struct edge
{
	int from;
	int to;
	int d;

	bool operator <(const edge temp) const
	{
		return d < temp.d;
	}
};

edge Edge[200000];
int FS[100000];

int FindSet(int n)
{
	if (FS[n] == n)
		return n;
	else
		return FindSet(FS[n]);
}

void UnionSet(int n1,int n2)
{
	FS[n2] = n1;
	/*int p1 = FindSet(n1);
	int p2 = FindSet(n2);
	if (p1 == p2)
		return;
	else
		FS[p2] = p1;*/
}

int checkend()
{
	return FindSet(0) == FindSet(n - 1);
}

void kruskal()
{
	int i;
	for (i = 0; i < m; ++i)
	{
		int f1 = FindSet(Edge[i].from - 1);
		int f2 = FindSet(Edge[i].to - 1);
		if (f1!=f2)
		{
			UnionSet(f1,f2);
			if (checkend() == 1)
			{
				printf("%d", Edge[i].d);
				return;
			}
		}
		
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &(Edge[i].from), &(Edge[i].to), &(Edge[i].d));
	}
	for (int i = 0; i < n; ++i)
	{
		FS[i] = i;
	}
	sort(Edge, Edge + m);
	kruskal();
	return 0;
}
