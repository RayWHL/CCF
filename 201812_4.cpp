  /*kruskal AC*/
//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//struct  edge
//{
//	int from;
//	int to;
//	int d;
//	bool operator <(const edge temp) const
//	{
//		return d < temp.d;
//	}
//};
//
//edge Edge[500001];
//int FS[100001];
//int n, m, root;
//
//int FindSet(int n)
//{
//	if (FS[n] == n)
//		return n;
//	else
//		return FS[n]= FindSet(FS[n]);
//}
//
//void unionset(int n1, int n2)
//{
//	FS[n2] = n1;
//}
//
//void kruskal()
//{
//	int i;
//	int node = 0;
//	for (i = 0; i < m; ++i)
//	{
//		int f1 = FindSet(Edge[i].from);
//		int f2 = FindSet(Edge[i].to);
//		if (f1 != f2)
//		{
//			++node;
//			unionset(f1, f2);
//			if (node == n - 1)
//			{
//				cout << Edge[i].d;
//				return;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> root;
//	//scanf("%d %d %d",&n,&m,&root);
//	for (int i = 0; i < m; ++i)
//	{
//		//scanf("%d %d %d", &(Edge[i].from), &(Edge[i].to), &(Edge[i].d));
//		cin >> Edge[i].from >> Edge[i].to >> Edge[i].d;
//		
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		FS[i] = i;
//	}
//	sort(Edge, Edge+m);
//	kruskal();
//	return 0;
//}

/* PRIM AC*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>

using namespace std;

struct  edge
{
	int d;
	int from;
	int to;
	
	edge *next;
};

bool operator >(edge a,edge b) 
{
	return a.d > b.d;
}

struct node
{
	int i;
	edge *next;
};

node NODE[500001];
int n, m, root;
set <int> node_deal;    //加入过的点
priority_queue <edge, vector<edge>,greater<edge>> q;

void addedge(int a, int b, int c)
{
	edge *temp = new edge;
	temp->from = a;
	temp->to = b;
	temp->d = c;
	temp->next = NODE[a].next;
	NODE[a].next = temp;
}

void prim()
{
	int out = 0;
	int no = 0;
	edge *temp, e1;
	temp = NODE[root].next;
	node_deal.insert(root);
	for (; temp; temp = temp->next)
	{
		q.push(*temp);
	}
	while (!q.empty())
	{
		e1 = q.top();
		q.pop();
		if (node_deal.find(e1.to) == node_deal.end())
		{
			++no;
			node_deal.insert(e1.to);
			if (e1.d > out)
				out = e1.d;
			if (no == n - 1)
			{
				printf("%d", out);
				return;
			}
			for (temp = NODE[e1.to].next; temp; temp = temp->next)
			{
				q.push(*temp);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> root;
	int a, b, c;
	//scanf("%d %d %d", &n, &m, &root);
	for (int i = 1; i <= n; ++i)
	{
		NODE[i].i = i;
		NODE[i].next = NULL;
	}
	for (int i = 0; i < m; ++i)
	{
		//scanf("%d %d %d", &(a), &(b), &(c));
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
		//cin >> Edge[i].from >> Edge[i].to >> Edge[i].d;
	}
	prim();

	return 0;
}
