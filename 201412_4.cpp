#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long price;

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

edge input_edge[100000];
int n, m;

int FS[1001];

int find_set(int n)
{
	if (FS[n] == n)
	{
		return n;
	}
	else
	{
		return find_set(FS[n]);
	}
}

void UnionSet(int n1, int n2)
{
	FS[n2] = n1;
}

int checkend()
{
	return find_set(1) == find_set(n);
}

void kruskal()
{
	int node = 0;
	for (int i = 0; i < m; ++i)
	{
		int f1 = find_set(input_edge[i].from);
		int f2 = find_set(input_edge[i].to);
		if (f1 != f2)
		{
			UnionSet(f1, f2);
			++node;
			price += input_edge[i].d;
			if (checkend() == 1 && node==n-1)
			{
				printf("%lld", price);
				return;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> input_edge[i].from >> input_edge[i].to >> input_edge[i].d;
	}
	for (int i = 1; i <= n; ++i)
	{
		FS[i] = i;
	}
	sort(input_edge, input_edge + m);
	kruskal();

	return 0;
}