#include <iostream>
#include <vector>
using namespace std;

struct mystruct
{
	int type;
	int time;
	int anothertime;
};

int r, y, g;
int n;
vector <mystruct> input;
int sum;
long long int output;

void first_deal()
{
	for (int i = 0; i < n; ++i)
	{
		if (input[i].type == 1)
		{
			input[i].anothertime = g + input[i].time;
		}
		if (input[i].type == 2)
		{
			input[i].anothertime = g + r+ input[i].time;
		}
		if (input[i].type == 3)
		{
			input[i].anothertime = input[i].time;
		}
	}
}

int main()
{
	cin >> r >> y >> g;
	cin >> n;
	sum = r + y + g;
	mystruct temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp.type >> temp.time;
		input.push_back(temp);
	}

	first_deal();

	output = 0;

	for (int i = 0; i < n; ++i)
	{
		if (input[i].type == 0)
			output += input[i].time;
		else
		{
			input[i].anothertime = (input[i].anothertime - (output%sum) + sum) % sum;
			if (input[i].anothertime == 0)
				input[i].anothertime = sum;
			if (input[i].anothertime>=g)
				output += input[i].anothertime - g;
		}

	}
	cout << output;

	return 0;
}