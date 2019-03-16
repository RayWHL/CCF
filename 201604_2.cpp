#include <iostream>

using namespace std;

int from;
int graph[15][10];
int input[4][4];
int line_youxiao;

int deal_block(int best)
{
	int flag = 0;
	for (int i = 0; i < line_youxiao; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (input[i][j] == 1)
			{
				if (graph[best + i][from - 1 + j] == 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}

int main()
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> input[i][j];
		}
	}
	cin >> from;

	line_youxiao = 4;
	for (int i = 0; i < 4; ++i)
	{
		int number = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (input[3 - i][j] == 0)
				++number;
				
		}
		if (number == 4)
			--line_youxiao;
		else
			break;
	}

	int best = 0;
	while (true)
	{
		if (best + line_youxiao == 15)
			break;

		if (deal_block(best) == 1 && deal_block(best + 1) == 0)
			break;

		++best;
	}
	

	for (int i = 0; i < line_youxiao; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (input[i][j] == 1)
			{
				graph[best + i][from - 1 + j] = 1;

			}
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}