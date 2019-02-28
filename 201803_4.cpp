#include <iostream>
#include <algorithm>

using namespace std;

int input[3][3];
int output;
int T;
int flag;
int max_int = 0x3f3f3f3f;

//检测k是否赢，并输出分数
int get_state(int k)
{
	int out = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (input[i][j] == 0) ++out;

	if (out == 0)
	{
		flag = 1;
		return 0;
	}

	//行
	for (int i = 0; i < 3; ++i)
	{
		if (input[i][1] == input[i][2] && input[i][1] == input[i][0] && input[i][1] == k)
		{
			flag = 1;
			if (k == 1)	return out + 1;
			else	return -out - 1;
		}
	}
	//列
	for (int i = 0; i < 3; ++i)
	{
		if (input[1][i] == input[2][i] && input[1][i] == input[0][i] && input[1][i] == k)
		{
			flag = 1;
			if (k == 1)	return out + 1;
			else	return -out - 1;
		}
	}

	if ((input[0][0] == input[1][1] && input[1][1] == input[2][2] && input[2][2] == k)|| 
		(input[0][2] == input[1][1] && input[1][1] == input[2][0] && input[2][0] == k))
	{
		flag = 1;
		if (k == 1)	return out + 1;
		else	return -out - 1;
	}
	return out;
}

int dfs(int k)
{
	int out;
	int out1 = -max_int;
	int out2 = max_int;

	if (k == 1) out=get_state(2);
	else  out=get_state(1);

	if (flag == 1)
	{
		return out;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (input[i][j] == 0)
			{
				flag = 0;
				input[i][j] = k;
				if (k == 1)out1 = max(out1, dfs(2));//这个就是为了要满足最优下棋策略的语句，就是alice会选择下一步最优的解； 
				if (k == 2)out2 = min(out2, dfs(1));//同理 
				input[i][j] = 0;//回溯前面的状态；
			}
		}
	}

	if (k == 1) return out1;
	else return out2;
}

int main()
{
	cin >> T;
	for (; T > 0; --T)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				cin >> input[i][j];
		}
		flag = 0;
		cout << dfs(1) << endl;
	}
	return 0;
}


