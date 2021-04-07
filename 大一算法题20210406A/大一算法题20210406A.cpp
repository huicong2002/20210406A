#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Count(int M, int N)
{
	if (M == 0 || N == 1)
	{
		return 1;//1.若只剩一个盘子，那只有一种分法。2.若苹果数为0，即可当作每个盘子均有一个苹果，只有一种分法
	}

	if (M < N)
	{
		return Count(M, M);//若盘子的数量大于苹果数，即必有盘子多余，可当作盘子和苹果一样多处理
	}
	else
	{
		return Count(M, N - 1) + Count(M - N, N);//可分别为两种情况的结合：1.一个空盘子，其余再排。2.所有盘子都有至少一个苹果，然后再排。
	}

}
int main()
{
	int t, N, M;

	scanf("%d", &t);

	while (t--)
	{
		int K = 0;

		scanf("%d%d", &M, &N);
		
		if (M < N)
		{
			K = Count(M, M);
		}
		else
		{
			K = Count(M, N);
		}

		printf("%d\n",K);
	}

	return 0;
}