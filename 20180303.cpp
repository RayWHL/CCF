#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

string	BQstring1[105], BQueryM;
string Qstring1[105], Qstring2[105], Astring[105];
string QueryM;
int m, n;
vector <string> answer;

void getString()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < Qstring1[i].size(); ++j)
		{
			if (Qstring1[i][j] == '/')
			{
				Qstring1[i][j] = ' ';
			}
		}
		Qstring1[i].erase(Qstring1[i].begin());
		if (Qstring1[i][Qstring1[i].size() - 1] == ' ')
			Qstring1[i].pop_back();
	}
}

void MatchString()
{
	
	stringstream sstring, qstring;

	string ss, qs;
	int temp;

	for (int i = 0; i < n; ++i)
	{
		int successflag = 0;

		qstring.clear();
		qstring.str("");
		qstring.str(QueryM);

		answer.clear();
		sstring.clear();
		sstring.str("");
		sstring.str(Qstring1[i]);

		while (true)
		{
			sstring >> ss;
			if (sstring.fail())
			{
				if (BQueryM[BQueryM.size() - 1] == '/'&&BQstring1[i][BQstring1[i].size() - 1] != '/')
				{
					if (successflag)
						answer[answer.size() - 1] += "/";
					else
						break;
				}
				if (BQueryM[BQueryM.size() - 1] != '/'&&BQstring1[i][BQstring1[i].size() - 1] == '/')
				{
					
						break;
				}
				qstring >> qs;
				if (qstring.fail())
				{
					cout << Qstring2[i];
					for (int k = 0; k < answer.size(); ++k)
					{
						cout <<" "<< answer[k];
					}
					cout << endl;
					return;
				}
				else break;
			}
			if (ss == "<int>")
			{
				qstring >> temp;
				if (qstring.fail())
					break;
				else
				{
					stringstream inttemp;
					inttemp << temp;
					string stringtemp;
					inttemp >> stringtemp;
					answer.push_back(stringtemp);
				}
					
			}
			else if (ss == "<str>")
			{
				qstring >> qs;
				if (qstring.fail())
					break;
				else
				{
					answer.push_back(qs);

				}

			}
			else if (ss == "<path>")
			{
				string temp;
				qstring >> qs;
				if (!qstring.fail())
				{
					successflag = 1;
					temp = qs;
					for(qstring >> qs;!qstring.fail();qstring>>qs)
					{
						temp = temp + "/";
						temp = temp + qs;
				
					}
					answer.push_back(temp);
				}
				else break;
			}
			else
			{
				qstring >> qs;
				if (ss != qs)
				{
					break;
				}
			}
		}

	}
	cout << "404" << endl;
}

int main()
{
	fstream file;
	file.open("D:/ray/ccf/String_CCF/input.txt", ifstream::in);

	streambuf *backup;
	backup = cin.rdbuf();   // back up cin's streambuf  
	cin.rdbuf(file.rdbuf()); // assign file's streambuf to cin  

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> Qstring1[i] >> Qstring2[i];
		BQstring1[i] = Qstring1[i];
	}
	getString();
	for (int i = 0; i < m; ++i)
	{
		cin >> QueryM;
		BQueryM = QueryM;
		for (int j = 0; j < QueryM.size(); ++j)
		{
			if (QueryM[j] == '/')
			{
				QueryM[j] = ' ';
			}
		}
		QueryM.erase(QueryM.begin());
		if (QueryM[QueryM.size() - 1] == ' ')
			QueryM.pop_back();
		MatchString();
	}
	cin.rdbuf(backup);
}