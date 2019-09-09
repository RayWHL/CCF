#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int to;
	int val;
	edge *next;
};

struct node
{
	int val;
	edge *next;
};

node input[302];
int a[300];
int n;

int min_int = -0x3f3f3f3f;

void addedge(int a, int b, int c)
{
	edge *e = (edge *)malloc(sizeof(edge));
	e->to = b;
	e->val = c;
	e->next = input[a].next;
	input[a].next = e;
}

void bellman_folyd()
{
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 2; ++j)
		{
			for (edge *p = input[j].next; p; p = p->next)
			{
				if (input[j].val + p->val > input[p->to].val)
					input[p->to].val = input[j].val + p->val;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	//源点n+1（第n+2个点
	for (int i = 0; i < n + 1; ++i)
	{
		input[i].val = min_int;
		addedge(n + 1, i, 0);
	}
	input[n + 1].val = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		addedge(i, i + 3, 3 * a[i + 1]);
		addedge(i + 3, i, -2 - 3 * a[i + 1]);
	}
	addedge(0, 2, 2*a[0]);
	addedge(2, 0, -2 * a[0] - 1);
	addedge(n - 2, n, 2 * a[n - 1]);
	addedge(n, n - 2, -1 - 2 * a[n - 1]);
	for (int i = 0; i < n; ++i)
		addedge(i, i + 1, 1);
	
	bellman_folyd();
	for (int i = 0; i < n-1; ++i)
	{
		cout << input[i + 1].val - input[i].val << " ";
	}
	cout <<input[n].val-input[n-1].val<< endl;
	return 0;
}