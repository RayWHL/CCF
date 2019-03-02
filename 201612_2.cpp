#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t1 = 0;
	int t2 = 3500;
	int t3 = 3500 + 1500 * 0.97;
	int t4 = t3 + 3000 * 0.9;
	int t5 = t4 + 4500 * 0.8;
	int t6 = t5 + 26000 * 0.75;
	int t7 = t6 + 20000 * 0.7;
	int t8 = t7 + 25000 * 0.65;
	int t;
	cin >> t;
	if (t <= t2)
	{

	}
	else if (t <= t3)
	{
		t = (t - t2) / 0.97 + t2;
	}
	else if (t <= t4)
	{
		t = (t - t3) / 0.9 + 5000;
	}
	else if (t <= t5)
	{
		t = (t - t4) / 0.8 + 8000;
	}
	else if (t <= t6)
	{
		t = (t - t5) / 0.75 + 12500;
	}
	else if (t <= t7)
	{
		t = (t - t6) / 0.7 + 38500;
	}
	else if (t <= t8)
	{
		t = (t - t7) / 0.65 + 58500;
	}
	else
	{
		t = (t - t8) / 0.55 + 83500;
	}

	cout << t;

	return 0;
}
