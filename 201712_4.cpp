//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <functional>
//#include <math.h>
//
//using namespace std;
//
//struct  edge
//{
//	int type;	// 0大道  1小道
//	int d;
//	int to;
//
//	edge *next;
//};
//
//struct node
//{
//	int i;
//	long long int val;
//	int pri_len;
//
//	edge *next;
//
//	bool operator > (const node temp) const
//	{
//		if (val != temp.val)
//			return val > temp.val;
//		else
//			return pri_len > temp.val;
//	}
//};
//
//node NODE[500];
//int visit[500];
//int n, m;
//
//int max_int = 0x3f3f3f3f3f3f3f;
//
//priority_queue <node, vector<node>, greater<node>> q;  //最小优先队列 存在重复的顶点
//
//void addedge(int t, int a, int b, int c)
//{
//	edge *temp = new edge;
//	temp->type = t;
//	temp->to = b;
//	temp->d = c;
//	temp->next = NODE[a].next;
//	NODE[a].next = temp;
//}
//
//void dijistra()
//{
//	q.push(NODE[0]);
//	while (!q.empty())
//	{
//		node temp = q.top();
//		q.pop();
//		if (visit[temp.i])
//			continue;
//		visit[temp.i] = 1;
//		//cout << temp.i << endl;
//		for (edge *p = temp.next; p; p = p->next)
//		{
//			if (visit[p->to] == 0)
//			{
//				//如果是小路
//				if (temp.pri_len != 0)
//				{
//					//此条也是小道
//					if (p->type == 1)
//					{
//						long long int v = pow(temp.pri_len + p->d, 2) + temp.val - pow(temp.pri_len, 2);
//						if (NODE[p->to].val > v)
//						{
//							NODE[p->to].val = pow(temp.pri_len + p->d, 2) + temp.val - pow(temp.pri_len, 2);
//							NODE[p->to].pri_len = temp.pri_len + p->d;
//							q.push(NODE[p->to]);
//						}
//					}
//					else
//					{
//						if (NODE[p->to].val > temp.val + p->d);
//						{
//							NODE[p->to].val = temp.val + p->d;
//							NODE[p->to].pri_len = 0;
//							q.push(NODE[p->to]);
//						}
//					}
//				}
//				else
//				{
//					if (p->type == 1)
//					{
//						if (NODE[p->to].val > temp.val + pow(p->d, 2));
//						{
//							NODE[p->to].val = temp.val + pow(p->d, 2);
//							NODE[p->to].pri_len = p->d;
//							q.push(NODE[p->to]);
//						}
//					}
//					else
//					{
//						if (NODE[p->to].val > temp.val + p->d)
//						{
//							NODE[p->to].val = temp.val + p->d;
//							NODE[p->to].pri_len = 0;
//							q.push(NODE[p->to]);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int t, a, b, c;
//	cin >> n >> m;
//	for (int i = 0; i < n; ++i)
//	{
//		NODE[i].i = i;
//		NODE[i].pri_len = 0;
//		NODE[i].val = max_int;
//	}
//	NODE[0].val = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> t >> a >> b >> c;
//		addedge(t, a - 1, b - 1, c);
//		addedge(t, b - 1, a - 1, c);
//	}
//	dijistra();
//	cout << NODE[n - 1].val << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

long long int max_int = 0x3f3f3f3f3f3f3f;

int n, m;

long long int d0[500][500];

long long int d[500][500];
long long int dk[500][500];
long long int vv[500]; //到0距离
int flag[500];	//前一段是大路还是小路
vector<int> q;

int visit[500];

struct node
{
	int i;
	long long int val;
	bool operator > (const node temp) const
	{
		return val > temp.val;
	}
};

priority_queue <node, vector<node>, greater<node>> qq;  //最小优先队列 存在重复的顶点

void floyd_warshall()
{
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				d[i][j] = dk[i][j];
		}*/
	}
}

void spfa()
{
	q.push_back(0);
	while (!q.empty())
	{
		int num = q[0];
		q.erase(q.begin());
		for (int i = 0; i < n; ++i)
		{
			//大路d0
			if (vv[num] + d0[num][i] < vv[i])
			{
				vv[i] = vv[num] + d0[num][i];
				flag[i] = 0;
				if (find(q.begin(), q.end(), i) == q.end())
				{
					q.push_back(i);
				}
			}
			//小路
			if (flag[num] != 1)
			{
				if (vv[num] + d[num][i] * d[num][i] < vv[i])
				{
					vv[i] = vv[num] + d[num][i] * d[num][i];
					flag[i] = 1;
					if (find(q.begin(), q.end(), i) == q.end())
					{
						q.push_back(i);
					}
				}
			}
		}
	}
}


void dijistra()
{
	node temp;
	temp.i = 0;
	temp.val = 0;
	qq.push(temp);
	while (!qq.empty())
	{
		temp = qq.top();
		qq.pop();
		if (visit[temp.i] == 1)
			continue;
		visit[temp.i] = 1;
		for (int i = 0; i < n; ++i)
		{
			//大路
			if (d0[temp.i][i] + vv[temp.i] < vv[i])
			{
				vv[i] = d0[temp.i][i] + vv[temp.i];
				flag[i] = 0;
				node t;
				t.i = i;
				t.val = vv[i];
				qq.push(t);
			}
			
			//小路
			if (flag[temp.i] != 1)
			{
				if (vv[temp.i] + d[temp.i][i] * d[temp.i][i] < vv[i])
				{
					vv[i] = vv[temp.i] + d[temp.i][i] * d[temp.i][i];
					flag[i] = 1;
					node t;
					t.i = i;
					t.val = vv[i];
					qq.push(t);
				}
			}
		}
	}
}

int main()
{
	int t, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		visit[i] = 0;
		vv[i] = max_int;
		for (int j = 0; j < n; ++j)
		{
			d[i][j] = max_int;
			d0[i][j] = max_int;
			if (i == j)
			{
				d[i][j] = 0;
				d0[i][j] = 0;
			}
		}
	}
	vv[0] = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> t >> a >> b >> c;
		if (t == 1)
		{
			d[a - 1][b - 1] = c;
			d[b - 1][a - 1] = c;
		}
		else if (t == 0)
		{
			d0[a - 1][b - 1] = c;
			d0[b - 1][a - 1] = c;
		}
	}
	//计算出所有点通过小路的距离，没平方
	floyd_warshall();

	//spfa();
	dijistra();
	cout << vv[n - 1] << endl;
	return 0;

}