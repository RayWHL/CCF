#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct IPS
{
	long long int ip;
	int len;
	int ipn[4];
	bool operator < (const IPS temp) const
	{
		if (ip != temp.ip)
			return ip < temp.ip;
		else
			return len < temp.len;
	}
};

vector<IPS> input;
int n;

int my_stoi(string s)
{
	int out = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		out = out * 10 + s[i] - '0';
	}
	return out;
}


void deal_input(string s)
{
	int pos;
	IPS temp;
	//含有/
	if ((pos = s.find("/", 0)) != string::npos)
	{
		string s1, s2;
		s1 = s.substr(0, pos);
		s2 = s.substr(pos + 1, s.size() - pos - 1);
		int ppos = 0;
		string s_temp;
		int i = 0;
		//找四个ip段
		while ((pos=s1.find(".",ppos))!=string::npos)
		{
			s_temp = s1.substr(ppos, pos - ppos);
			temp.ipn[i] = my_stoi(s_temp);
			ppos = pos + 1;
			++i;
		}
		s_temp = s1.substr(ppos, s1.size() - ppos);
		temp.ipn[i] = my_stoi(s_temp);
		++i;
		for (; i < 4; ++i)
			temp.ipn[i] = 0;

		//长度段
		temp.len = my_stoi(s2);
		temp.ip = 0;
		for (i = 0; i < 4; ++i)
			temp.ip = temp.ip * 256 + temp.ipn[i];
	}
	else
	{
		int ppos = 0;
		string s_temp;
		int i = 0;
		//找四个ip段
		while ((pos = s.find(".", ppos)) != string::npos)
		{
			s_temp = s.substr(ppos, pos - ppos);
			temp.ipn[i] = my_stoi(s_temp);
			ppos = pos + 1;
			++i;
		}
		s_temp = s.substr(ppos, s.size() - ppos);
		temp.ipn[i] = my_stoi(s_temp);
		++i;
		temp.len = i * 8;

		for (; i < 4; ++i)
			temp.ipn[i] = 0;

		temp.ip = 0;
		for (i = 0; i < 4; ++i)
			temp.ip = temp.ip * 256 + temp.ipn[i];
	}
	input.push_back(temp);
}

void print_ip()
{
	int len = input.size();
	for (int i = 0; i < len; ++i)
	{
		cout << input[i].ipn[0] << "." << input[i].ipn[1] << "." << input[i].ipn[2] << "." << input[i].ipn[3] << "/" << input[i].len << endl;
	}
}

string getip_string(IPS a, int len)
{
	string s;
	for (int i = 0; i < 4; ++i)
	{
		int ip_temp = a.ipn[i];
		char temp[9] = { 0 };
		for (int j = 7; j >=0; --j)
		{
			if (ip_temp % 2 == 1) temp[j] = '1';
			else temp[j] = '0';
			ip_temp = ip_temp / 2;
		}
		s += temp;
	}
	string out= s.substr(0, len);
	return out;
}

int match_ip(IPS a, IPS b)
{
	if (a.len <= b.len)
	{
		if (getip_string(a, a.len) == getip_string(b, a.len))
			return 1;
	}
	return 0;
}

void deal_second()
{
	int len = input.size();
	for (int i = 0; i < len - 1; )
	{
		if (match_ip(input[i], input[i + 1]))
		{
			input.erase(input.begin() + i + 1, input.begin() + i + 2);
			--len;
			if (i == len - 1)
				break;
		}
		else
			++i;
	}
}

//符合就处理并且返回1
int third_match(IPS a, IPS b,int pos)
{
	if (a.len == b.len)
	{
		IPS newip;
		string s1 = getip_string(a, a.len);
		string s2 = getip_string(b, b.len);
		if (s1.substr(0, a.len - 1) == s2.substr(0, b.len - 1) &&
			s1[a.len - 1] == '0' && s2[b.len - 1] == '1')
		{
			newip = a;
			--newip.len;
			input[pos] = newip;
			input.erase(input.begin() + pos + 1, input.begin() + pos + 2);
			return 1;
		}
	}
	return 0;
}

void deal_third()
{
	int len = input.size();
	for (int i = 0; i < len - 1; )
	{
		if (third_match(input[i], input[i + 1],i))
		{
			if (i == 0)
				--len;
			else
			{
				--i;
				--len;
			}
			if (i == len - 1)
				break;
		}
		else
			++i;
	}
}

int main()
{
	string ip_temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> ip_temp;
		deal_input(ip_temp);
	}
	sort(input.begin(), input.end());
	deal_second();
	deal_third();
	print_ip();
	return 0;
}