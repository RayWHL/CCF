#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string INPUT[105];
int n = 0;
vector <string> answer;

void DealHeading()
{
	for (int i = 0; i < answer.size(); ++i)
	{
		int hn = 0;
		for (int j = 0; j < answer[i].size(); ++j)
		{
			if (answer[i][j] == '#')
				++hn;
			else break;
		}
		for (int j = 0; j < hn; ++j)
		{
			answer[i].erase(answer[i].begin(), answer[i].begin() + 1);
		}
		//answer[i].erase(answer[i].begin(), answer[i].begin() + 1);

		if (hn>0)
		{
			answer[i].erase(answer[i].begin(), answer[i].begin() + 1);

			string stemp = "h";
			stemp += hn + '0';
			string stemp1 = '<' + stemp + '>';
			string stemp2 = "<";
			stemp2 += "/";
			stemp2 += stemp;
			stemp2 += ">";

			answer[i].insert(0, stemp1);
			answer[i] += stemp2;
		}
	}

}

void DealBody()
{
	vector<string>::iterator pos = answer.begin();
	while ((pos = find(pos, answer.end(), ""))!=answer.end())
	{
		if (pos != answer.end() - 1)
		{
			if (answer[pos - answer.begin() + 1][0] != '#' &&
				answer[pos - answer.begin() + 1][0] != '*')
				answer[pos - answer.begin() + 1].insert(0, "<p>");
		}
		else
			break;
		pos = pos + 1;
		if ((pos = find(pos, answer.end(), "")) != answer.end())
		{
			if (answer[pos - answer.begin() - 1][0] != '#' &&
				answer[pos - answer.begin() - 1][0] != '*')
			answer[pos - answer.begin() - 1] += "</p>";
		}
		else
		{
			if (answer[pos - answer.begin() - 1][0] != '#' &&
				answer[pos - answer.begin() - 1][0] != '*')
				answer[pos - answer.begin() - 1] += "</p>";
		}
	}
}


void DealList()
{
	for (int i = 0; i < answer.size(); ++i)
	{
		int hn = 0;
		if (answer[i][0] == '*')
		{
			hn = 1;
			answer[i].erase(answer[i].begin(), answer[i].begin() + 1);
			answer[i].erase(answer[i].begin(), answer[i].begin() + 1);

			if (i - 1 >= 0)
			{
				if (answer[i - 1] == "")
				{
					answer.insert(answer.begin()+i, "<ul>");
					++i;
				}
			}
			if (i + 1 == answer.size())
			{
				answer.push_back("</ul>");
			}
			else if(answer[i+1]=="")
				answer.insert(answer.begin()+i+1, "</ul>");

		}
		if (hn>0)
		{
			string stemp1 = "<li>";
			string stemp2 = "</li>";
		
			answer[i].insert(0, stemp1);
			answer[i] += stemp2;
		
		}
	}
}

void DeleteNull()
{
	for (int i = 0; i < answer.size(); ++i)
	{
		if (answer[i] == "")
		{
			answer.erase(answer.begin() + i);
			--i;
		}
	}
}

void DealLine()
{
	string stemp1 = "<em>";
	string stemp2 = "</em>";
	for (int i = 0; i < answer.size();++i)
	{
		int pos = 0;
		while (true)
		{
			pos = answer[i].find("_", pos);
			if (pos != string::npos)
			{
				answer[i].erase(pos,1);
				answer[i].insert(pos, stemp1);
				pos += 1;
				pos = answer[i].find("_", pos);
				if (pos != string::npos)
				{
					answer[i].erase(pos, 1);
					answer[i].insert(pos, stemp2);
					pos += 1;

				}
				else
					break;
			}
			else
				break;
		}
		
	}
}

void DealLink()
{
	string text, link;
	string stemp1, stemp2;
	for (int i = 0; i < answer.size(); ++i)
	{

		int pos1 = 0;
		int pos2 = 0;
		pos1 = answer[i].find("[", pos1);
		if (pos1 != string::npos)
		{
			pos2 = pos1;
			pos2 = answer[i].find("]", pos2);
			text = answer[i].substr(pos1 + 1, pos2 - pos1 - 1);
		}
		int pos3 = 0;
		int pos4 = 0;
		pos3 = answer[i].find("(", pos3);
		if (pos3 != string::npos)
		{
			pos4 = pos3;
			pos4 = answer[i].find(")", pos4);
			link = answer[i].substr(pos3 + 1, pos4 - pos3 - 1);
		}
		if (pos2 != 0 && pos4 != 0)
		{
			answer[i].erase(pos1, pos4 - pos1 + 1);
			string temp;
			temp = "<a href=\"";
			temp += link;
			temp += "\">";
			temp += text;
			temp += "</a>";
			answer[i].insert(pos1,temp);
		}

	}
}

int main()
{
	
	fstream file;
	file.open("D:/ray/ccf/20170303/input.txt", ifstream::in);

	streambuf *backup;
	backup = cin.rdbuf();   // back up cin's streambuf  
	cin.rdbuf(file.rdbuf()); // assign file's streambuf to cin  

	answer.push_back("");
	string stemp;
	while (getline(cin,stemp))
	{
		INPUT[n] == stemp;
		answer.push_back(stemp);
		++n;
	}
	DealBody();
	DealHeading();
	DealList();
	DealLine();
	DealLink();
	DeleteNull();

	int i = 0;
	for (i = 0; i < answer.size()-1; ++i)
	{
		cout << answer[i] << endl;
	}
	if (i == answer.size() - 1)
		cout << answer[i];

	cin.rdbuf(backup);

	return 0;
}