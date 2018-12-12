#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int m, n;

struct edge
{
	int i;
	int d;
	struct edge *next;
};

struct node
{
	int i;
	int d;
	edge *next;
};


priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;

vector <node> head;
vector<bool> visit;
int MAXN = 0xffffff;

void AddEdge(int a,int b,int c)
{
	for (int i = 0; i < head.size(); ++i)
	{
		if (head[i].i == a)
		{
			edge *temp = new edge;
			temp->next = head[i].next;
			temp->i = b;
			temp->d = c;
			head[i].next = temp;
			break;
		}
	}
}


int findmin()
{
	int out = MAXN;
	int outi = -1;

	for (int i = 0; i < head.size(); ++i)
	{
		if (visit[i] == false)
		{
			if (head[i].d < out)
			{
				out = head[i].d;
				outi = i;
			}
		}
	}
	return outi;
}

void dijkstra()
{
	q.push({ 0,0 });
	int number;
	while (!q.empty())
	{
		number = q.top().second;
		q.pop();
		if (visit[number])
			continue;
		visit[number] = true;
		edge *ptemp = head[number].next;
		for (; ptemp; ptemp = ptemp->next)
		{
			if(visit[ptemp->i-1] == false)
			{
				if (head[ptemp->i-1].d > ptemp->d)
				{
					head[ptemp->i-1].d = max(ptemp->d, head[number].d);
					q.push({ head[ptemp->i-1].d ,ptemp->i-1 });
				}
				
			}
		}
		if (number == n - 1)
		{
			break;
		}

	}

}


int main()
{
	cin >> n >> m;
	int tempa, tempb, tempc;
	for (int i = 0; i < n; ++i)
	{
		node temp;
		temp.next = NULL;
		temp.i = i + 1;
		temp.d = MAXN;
		head.push_back(temp);
		visit.push_back(false);
		//q.push({ MAXN,i + 1 });
	}
	head[0].d = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> tempa >> tempb >> tempc;
		AddEdge(tempa, tempb, tempc);
		AddEdge(tempb, tempa, tempc);
	}
	dijkstra();
	cout << head[n - 1].d;
	return 0;
}