#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int from;
	int to;
};

struct pos
{
	int x;
	int y;
	long long int time;
};

node input_node[101][101];
bool visit[101][101][301] = { false };
int n, m, t;
long long int time;
queue <pos> qnode;
vector <pos> linjie;

void get_lin(pos now_pos)
{
	linjie.clear();
	++now_pos.time;
	time = now_pos.time;

	++now_pos.x;
	if (now_pos.x <= n && (input_node[now_pos.x][now_pos.y].from > time || input_node[now_pos.x][now_pos.y].to < time))
		linjie.push_back(now_pos);
	--now_pos.x;

	++now_pos.y;
	if (now_pos.y <= m && (input_node[now_pos.x][now_pos.y].from>time || input_node[now_pos.x][now_pos.y].to<time))
		linjie.push_back(now_pos);
	--now_pos.y;

	--now_pos.x;
	if (now_pos.x >= 1 && ( input_node[now_pos.x][now_pos.y].from>time || input_node[now_pos.x][now_pos.y].to<time))
	{
		linjie.push_back(now_pos);
	}
	now_pos.x++;

	--now_pos.y;
	if (now_pos.y >= 1 && (input_node[now_pos.x][now_pos.y].from > time || input_node[now_pos.x][now_pos.y].to < time))
		linjie.push_back(now_pos);
	++now_pos.y;

}

void bfs()
{
	int nowx, nowy;
	pos temp_pos;
	temp_pos.x = 1;
	temp_pos.y = 1;
	temp_pos.time = 0;
	qnode.push(temp_pos);

	pos now_pos;
	while (!qnode.empty())
	{
		now_pos = qnode.front();
		qnode.pop();
		//++time;
		get_lin(now_pos);

		int len = linjie.size();
		for (int i = 0; i < len; ++i)
		{
			if (visit[linjie[i].x][linjie[i].y][linjie[i].time])
				continue;

			if (linjie[i].x == n && linjie[i].y == m)
			{
				cout << linjie[i].time;
				return;
			}
			else
				qnode.push(linjie[i]);
			visit[linjie[i].x][linjie[i].y][linjie[i].time] = true;
		}

	}
	
}




int main()
{
	int r, c, a, b;
	cin >> n >> m >> t;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			input_node[i][j].from = -1;
			input_node[i][j].to = -1;
		}
	}
	for (int i = 1; i <= t; ++i)
	{
		cin >> r >> c >> a >> b;
		input_node[r][c].from = a;
		input_node[r][c].to = b;
	}

	time = 0;
	bfs();



	return 0;
}