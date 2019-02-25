#include <iostream>
#include <string>

using namespace std;

int k, n;
string input;
string input_xiao;
string input_com;
string input_com_xiao;

void switch_xiao(string &in, string &out)
{
	out = in;
	int len = in.size();
	for (int i = 0; i < len; ++i)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			out[i] = in[i] - 'A' + 'a';
		}
	}
}

int main()
{
	cin >> input;
	switch_xiao(input, input_xiao);
	cin >> k >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input_com;
		if (k == 0)
		{
			switch_xiao(input_com, input_com_xiao);
			if (input_com_xiao.find(input_xiao,0) != string::npos)
			{
				cout << input_com << endl;
			}
		}
		else
		{
			if (input_com.find(input, 0) != string::npos)
			{
				cout << input_com << endl;
			}
		}
	}

}