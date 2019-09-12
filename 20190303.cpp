#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, l, m;
string input[1000];
vector<long long> inputnum;

int pernum;

//得到块号对应的冗余条所在盘号
int getrongyu(int num)
{
	//int pernum = s*(n - 1);		//条带一行的块数
	int t = (n - 1 - num / pernum);	 //所在盘号
	while (t<0)
	{
		t += n;
	}
	return t%n;
}

string dealinput(int num)
{
	//int hang = num / (s*(n - 1));
	int hang = num / (pernum);
	int t1 = getrongyu(num);
	int disk = (t1 + num % (pernum) / s + 1) % n;
	int begin = s * 8 * hang + num%s * 8;
	if (input[disk].size() != 0)
		return input[disk].substr(begin, 8);
	else
	{
		if (l == n - 1)
		{
			string temp;
			for (int i = 0; i<8; ++i)
			{
				int a = 0;
				for (int j = 0; j<n; ++j)
				{
					if (j == disk) continue;
					if (input[j][i + begin] >= '0' && input[j][i + begin] <= '9')
						a = a ^ (input[j][i + begin] - '0');
					else if (input[j][i + begin] >= 'A' && input[j][i + begin] <= 'F')
						a = a ^ (input[j][i + begin] - 'A' + 10);
				}
				if (a <= 9)
					temp += a + '0';
				else
					temp += a - 10 + 'A';
			}
			return temp;
		}
		else
			return "";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	string temp = "";
	int num;
	long long getnum;
	cin >> n >> s >> l;
	pernum = s*(n - 1);		//条带一行的块数

	for (int i = 0; i < l; ++i)
	{
		cin >> num;
		cin >> input[num];
		//scanf("%s", input[num]);
	}
	//recovery();
	cin >> m;
	/*for (int i = 0; i < m; ++i)
	{
	long long temp;
	cin >> temp;
	inputnum.push_back(temp);
	}*/
	for (int i = 0; i < m; ++i)
	{
		///getnum = inputnum[i];
		cin >> getnum;
		if (getnum >= max(input[0].size(), input[1].size()) / 8 * (n - 1))
			cout << "-" << endl;
		else
		{
			string out = dealinput(getnum);
			if (out == "")
				cout << "-" << endl;
			else
				cout << out << endl;
		}
	}
	return 0;
}

//2 1 2
//0 000102030405060710111213141516172021222324252627
//1 000102030405060710111213141516172021222324252627

//0 000102030405060710111213141516172021222324252627
//1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
