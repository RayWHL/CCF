#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct edge
{
	int i;
	int d;
	edge *next;
};

struct  node
{
	int i;
	long long int d;
	int pri;
	int last_len;
	edge *next;
};

int n, m;
long long output;
priority_queue <pair<long long int, int>, vector <pair<long long int, int>>, greater<pair<long long int, int>>> q;

vector <node> head;
vector <bool> visit;
bool shorest[10001][10001] = { false };

int MAXN = 0x3f3f3f3f;

void addedge(int a, int b, int c)
{
	edge *temp = new edge;
	temp->i = b;
	temp->d = c;
	temp->next = head[a].next;
	head[a].next = temp;
}

void dijkstra()
{
	q.push({ 0,1 });
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
			if (visit[ptemp->i] == false)
			{
				if (head[ptemp->i].d > head[number].d + ptemp->d)
				{
					head[ptemp->i].d = head[number].d + ptemp->d;
					head[ptemp->i].pri = number;
					head[ptemp->i].last_len = ptemp->d;
					q.push({ head[ptemp->i].d, ptemp->i });
				}
				else if (head[ptemp->i].d == head[number].d + ptemp->d)
				{
					if (ptemp->d < head[ptemp->i].last_len)
					{
						head[ptemp->i].pri = number;
						head[ptemp->i].last_len = ptemp->d;
					}
				}

			}
		}
	}
}

int main()
{
	int tempa, tempb, tempc;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
	{
		node temp;
		temp.next = NULL;
		temp.i = i;
		temp.d = MAXN;
		temp.pri = 0;
		temp.last_len = MAXN;
		head.push_back(temp);
		visit.push_back(false);
	}
	head[1].d = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> tempa >> tempb >> tempc;
		addedge(tempa, tempb, tempc);
		addedge(tempb, tempa, tempc);
	}
	dijkstra();
	for (int i = 2; i <= n; ++i)
	{
		int to = i;
		int prior_node;
		while (true)
		{
			prior_node = head[to].pri;

			if (shorest[prior_node][to] == false)
			{
				output += head[to].last_len;
				shorest[prior_node][to] = true;
			}

			if (prior_node == 1)
				break;
			else
			{
				to = prior_node;
			}

		}
	}
	cout << output;
	return 0;
}