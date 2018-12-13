//#pragma warning(disable : 4996)
//
//#include <stdio.h>
//#include <algorithm>
//
//int MAXI = 0xffffff;
//int n, m;
//int D[1005][1005] = { MAXI };
//int Dk[1005][1005] = { MAXI };
//int W[1005][1005];
//
//int out[1005] = { 0 };
//
//void FLOYD_WARSHALL()
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			D[i][j] = W[i][j];
//		}
//	}
//	for (int k = 1; k <= n; ++k)
//	{
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n; ++j)
//			{
//				if (D[i][j] == 0 || D[i][k] + D[k][j] == 0)
//					Dk[i][j] = 0;
//				//Dk[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
//			}
//		}
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n; ++j)
//			{
//				D[i][j] = Dk[i][j];
//			}
//		}
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		int flag[1005] = { 0 };
//		for (int j = 1; j <= n; ++j)
//		{
//			if (D[i][j] == 0)
//				flag[j] = 1;
//			if (D[j][i] == 0)
//				flag[j] = 1;
//		}
//		int t = 1;
//		for (int j=1;j <= n; ++j)
//		{
//			if (flag[j] == 0)
//			{
//				t = 0;
//				break;
//			}
//		}
//		if (t == 1)
//			out[i] = 1;
//	}
//	
//}
//
//int main()
//{
//	int temp1, temp2;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//			Dk[i][j]= W[i][j] = MAXI;
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		W[i][i] = 0;
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		scanf("%d %d", &temp1, &temp2);
//		W[temp1][temp2] = 0;
//	}
//	FLOYD_WARSHALL();
//	int number = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (out[i] == 1)
//			++number;
//	}
//	printf("%d", number);
//	return 0;
//}