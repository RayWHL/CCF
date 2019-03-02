#include <iostream>
#include <string>
#include <vector>

using namespace std;

//权限可以重复出现  查询不一定出现
struct category
{
	string s;
	int level;		//无等级使用-1表示
};

//角色
struct role
{
	string s;
	int number_cate;
	vector <category> role_cate;
};

//用户
struct user
{
	string s;
	int number_role;
	vector <string> user_role;
};

vector <category> input_cate;
vector <role> input_role;
vector <user> input_user;
int p, r, u, q;
string query_user, query_cate;


int my_stoi(string s)
{
	int output = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		output = output * 10 + s[i] - '0';
	}
	return output;
}

category get_cate(string s)
{
	category temp;
	int pos = s.find(":", 0);
	if ( pos!= string::npos)
	{
		temp.s = s.substr(0, pos);
		temp.level = my_stoi(s.substr(pos + 1, s.size() - pos-1));
	}
	else
	{
		temp.s = s;
		temp.level = -1;
	}
	return temp;
}

void query_input()
{
	int flag=-2;	//标志 -1 trye -2 false 
	//带查询权限
	category query_temp = get_cate(query_cate);
	for (int i = 0; i < u; ++i)
	{
		//与该用户名相同
		if (input_user[i].s == query_user)
		{
			//该用户的角色
			for (int j = 0; j < input_user[i].number_role; ++j)
			{
				for (int k = 0; k < r; ++k)
				{
					//角色与输入一致
					if (input_user[i].user_role[j] == input_role[k].s)
					{
						for (int t = 0; t < input_role[k].number_cate; ++t)
						{
							//权限名同
							if (input_role[k].role_cate[t].s == query_temp.s)
							{
								//无等级查询
								if (query_temp.level == -1 && input_role[k].role_cate[t].level==-1)
								{
									flag = -1;
									//return;
								}
								if ( input_role[k].role_cate[t].level != -1)
								{
									if (query_temp.level == -1)
									{
										if (input_role[k].role_cate[t].level > flag)
											flag = input_role[k].role_cate[t].level;
									}
									else
									{
										if (query_temp.level <= input_role[k].role_cate[t].level)
											flag = -1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (flag == -2) cout << "false" << endl;
	else if (flag == -1) cout << "true" << endl;
	else cout << flag << endl;
}

int main()
{
	string temp;
	int role_n;
	string role_s;
	cin >> p;
	for (int i = 0; i < p; ++i)
	{
		cin >> temp;
		input_cate.push_back(get_cate(temp));
	}
	cin >> r;
	for (int i = 0; i < r; ++i)
	{
		role role_temp;
		cin >> role_temp.s >> role_temp.number_cate;
		for (int j = 0; j < role_temp.number_cate; ++j)
		{
			cin >> temp;
			role_temp.role_cate.push_back(get_cate(temp));
		}
		input_role.push_back(role_temp);
	}
	cin >> u;
	for (int i = 0; i < u; ++i)
	{
		user user_temp;
		cin >> user_temp.s >> user_temp.number_role;
		for (int j = 0; j < user_temp.number_role; ++j)
		{
			cin >> temp;
			user_temp.user_role.push_back(temp);
		}
		input_user.push_back(user_temp);
	}
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> query_user >> query_cate;
		query_input();
	}
	return 0;
}