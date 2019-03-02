#include <iostream>
using namespace std;
long long int dp[1001][1001] = { 0 };
int n;
long long int input[1001][1001];
long long int max_int =0x3f3f3f3f3f3f3f3f;

int main()
{
	int i, j, l, k;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> input[i][i];
	}

	for (i = 1; i < n; ++i)
	{
		input[i][i + 1] = input[i][i] + input[i + 1][i + 1];
		dp[i][i + 1] = input[i][i] + input[i + 1][i + 1];
	}
	
	for (l = 2; l <= n-1; ++l)
	{
		for (i = 1; i <= n - l; ++i)
		{
			j = l + i;
			long long int temp = max_int;
			for (k = i; k < j; ++k)
			{
				input[i][j] = input[i][k] + input[k + 1][j];
				if (dp[i][k] + dp[k+1][j] + input[i][j] < temp)
					temp = dp[i][k] + dp[k+1][j] + input[i][j];
			}
			dp[i][j] = temp;
		}
	}
	cout << dp[1][n];
	return 0;
}