#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;
	int len;
	vector <int> input;
	int hao = 1;
	for (int i = 1; i <= n; ++i)
		input.push_back(i);
	while (1)
	{
		len = input.size();
		if (len == 1)
		{
			printf("%d", input[0]);
			return 0;
		}
		for (int i = 0; i < len; ++i)
		{
			if (hao % k == 0 || hao % 10 == k)
			{
				input.erase(input.begin() + i, input.begin() + i+1);
				--i;
				--len;
				if (len == 1)
				{
					printf("%d", input[0]);
					return 0;
				}
			}
			++hao;
		}
	}
	return 0;
}