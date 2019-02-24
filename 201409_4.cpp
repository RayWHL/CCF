#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

struct node
{
	int x, y;
	int color;	//01 2 
	int d;
	int type;	// 0路线 1不能走 2分店 3客户 4完成
	int account;
	/*bool operator = (node temp)
	{
		x = temp.x;
		y = temp.y;
		color = temp.color;
		d = temp.d;
		type = temp.type;
		account = temp.account;
		return true;
	}*/
};

node input[1001][1001];
int n, m, k, d;
long long price;
int k_temp;

queue <node> qnode;
vector <node> get_route;

void get_router_1(node temp)
{
	node output = temp;
	if (temp.x - 1 > 0)
	{
		output = input[temp.x - 1][temp.y];
		if (output.type == 3 || output.type == 0)
		{
			if (output.color == 0)
			{
				
				get_route.push_back(output);
			}
		}
	}
	if (temp.y - 1 > 0)
	{
		output = input[temp.x][temp.y-1];
		if (output.type == 3 || output.type == 0)
		{
			if (output.color == 0)
				get_route.push_back(output);
		}
	}
	if (temp.x + 1 <=n)
	{
		output = input[temp.x + 1][temp.y];
		if (output.type == 3 || output.type == 0)
		{
			if (output.color == 0)
				get_route.push_back(output);
		}
	}
	if (temp.y + 1 <=n)
	{
		output = input[temp.x][temp.y + 1];
		if (output.type == 3 || output.type == 0)
		{
			if (output.color == 0)
				get_route.push_back(output);
		}
	}
}

void bfs()
{
	int tiao = 0;
	k_temp = k;
	node temp, temp_lin;
	int len;
	while (!qnode.empty() && k_temp!=0)
	{
		++tiao;
		//printf("%d ", tiao);
		temp = qnode.front();
		qnode.pop();
		get_route.clear();
		get_router_1(temp);
		len = get_route.size();
		for (int i = 0; i <len; ++i)
		{
			temp_lin = get_route[i];
			if (input[temp_lin.x][temp_lin.y].color == 0)
			{
				input[temp_lin.x][temp_lin.y].color = 1;
				input[temp_lin.x][temp_lin.y].d = temp.d + 1;
				if (temp_lin.type == 3)
				{
					--k_temp;
					price = input[temp_lin.x][temp_lin.y].d * input[temp_lin.x][temp_lin.y].account + price;
				}
				qnode.push(input[temp_lin.x][temp_lin.y]);
			}
			
		}
		input[temp.x][temp.y].color = 2;
	}
	printf("%lld", price);
}

int main()
{
	int tempx, tempy, tempz;
	cin >> n >> m >> k >> d;
	for (int i = 0; i < m; ++i)
	{
		cin >> tempx >> tempy;
		input[tempx][tempy].color = 1;
		input[tempx][tempy].x = tempx;
		input[tempx][tempy].y = tempy;
		input[tempx][tempy].d = 0;
		input[tempx][tempy].type = 2;
		qnode.push(input[tempx][tempy]);
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> tempx >> tempy >> tempz;
		input[tempx][tempy].color = 0;
		input[tempx][tempy].x = tempx;
		input[tempx][tempy].y = tempy;
		input[tempx][tempy].d = 0;
		if (input[tempx][tempy].type == 3)
		{
			input[tempx][tempy].account += tempz;
		}
		else if (input[tempx][tempy].type != 2)
		{
			input[tempx][tempy].account = tempz;
			input[tempx][tempy].type = 3;
		}
		
	}
	for (int i = 0; i < d; ++i)
	{
		cin >> tempx >> tempy;
		input[tempx][tempy].color = 0;
		input[tempx][tempy].x = tempx;
		input[tempx][tempy].y = tempy;
		input[tempx][tempy].d = 0;
		input[tempx][tempy].type = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			input[i][j].x = i;
			input[i][j].y = j;
		}
	}
	bfs();
	return 0;
}