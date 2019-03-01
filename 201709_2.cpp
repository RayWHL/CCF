#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct key_time
{
	int time;
	int key;
	int type; //0»¹1È¡
	bool operator <(const key_time temp) const
	{
		if (time != temp.time)
			return time < temp.time;
		else if (type == temp.type)
			return key < temp.key;
		else return type < temp.type;
	}
};

key_time node[2002];
int n, k;
int status[1001];

int main()
{
	int key, from, t;
	key_time temp1, temp2;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> key >> from >> t;
		node[2 * i].key = key;
		node[2 * i].time = from;
		node[2 * i].type = 1;

		node[2 * i + 1].key = key;
		node[2 * i + 1].time = from + t;
		node[2 * i + 1].type = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		status[i] = i;
	}
	sort(node, node + 2 * k);

	for (int i = 0; i < 2 * k; ++i)
	{
		if (node[i].type == 0)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (status[j] == 0)
				{
					status[j] = node[i].key;
					break;
				}
			}
		}
		else
		{
			for (int j = 1; j <= n; ++j)
			{
				if (status[j] == node[i].key)
					status[j] = 0;
			}
			
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", status[i]);
	}
	return 0;
}