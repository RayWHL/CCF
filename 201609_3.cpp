#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct  slaver
{
	int life;
	int attack;
};

//int first_hero;
//int second_hero;

int n;
int fir_or_sec;	//0 1 先 后

vector<slaver> first_slaver;
vector <slaver> second_slaver;

//仆从位置1-7


void deal_action(string action)
{
	if (action == "summon")
	{
		int position;
		slaver new_temp;
		cin >> position >> new_temp.attack >> new_temp.life;
		if (fir_or_sec == 0)
		{
			first_slaver.insert(first_slaver.begin() + position, new_temp);
		}
		else if (fir_or_sec == 1)
			second_slaver.insert(second_slaver.begin() + position, new_temp);
	}
	else if (action == "attack")
	{
		int attacker, defender;
		cin >> attacker >> defender;
		if (fir_or_sec == 0)
		{
			first_slaver[attacker].life -= second_slaver[defender].attack;
			second_slaver[defender].life -= first_slaver[attacker].attack;
			if (first_slaver[attacker].life <= 0)
				first_slaver.erase(first_slaver.begin() + attacker, first_slaver.begin() + attacker + 1);
			if (second_slaver[defender].life == 0 && defender != 0)
				second_slaver.erase(second_slaver.begin() + defender, second_slaver.begin() + defender + 1);
		}
		else if (fir_or_sec == 1)
		{
			second_slaver[attacker].life -= first_slaver[defender].attack;
			first_slaver[defender].life -= second_slaver[attacker].attack;
			if (second_slaver[attacker].life <= 0)
				second_slaver.erase(second_slaver.begin() + attacker, second_slaver.begin() + attacker + 1);
			if (first_slaver[defender].life == 0 && defender != 0)
				first_slaver.erase(first_slaver.begin() + defender, first_slaver.begin() + defender + 1);
		
		}
	}
	else //end
	{
		fir_or_sec = (fir_or_sec + 1) % 2;
	}
}


int main()
{
	string action;
	cin >> n;
	fir_or_sec = 0;
	slaver temp;
	temp.life = 30;
	temp.attack = 0;
	first_slaver.push_back(temp);
	second_slaver.push_back(temp);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> action;
		deal_action(action);
	}

	if (first_slaver[0].life <= 0)
		cout << -1 << endl;
	else if (second_slaver[0].life <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	cout << first_slaver[0].life << endl;
	cout << first_slaver.size() - 1;
	for (int i =1 ; i < first_slaver.size(); ++i)
	{
		cout << " " << first_slaver[i].life;
	}
	cout << endl;

	cout << second_slaver[0].life << endl;
	cout << second_slaver.size() - 1;
	for (int i = 1; i < second_slaver.size(); ++i)
	{
		cout << " " << second_slaver[i].life;
	}
	cout << endl;

	return 0;
}

