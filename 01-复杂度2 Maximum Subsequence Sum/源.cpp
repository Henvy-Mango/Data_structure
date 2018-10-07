#include<stdio.h>

int main()
{
	int num[100005], N;
	int head = 0, rear = 0,head_index=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	//在线更新改造
	int Max = 0, Now = 0, tag = 0;
	for (int j = 0; j < N; j++)
	{
		if (num[j] >= 0)
			tag = 1;	//全为负数时标记

		Now += num[j];

		if (Now > Max|| (Now == Max && Max== 0))	//记录当前最大子列和
		{

			Max = Now;
			rear = j;
			head = head_index;

		}

		if (Now < 0)	//当前子列和小于0，则直接抛弃重新计算
		{
			Now = 0;
			head_index=j+1;
		}

	}
	if (tag)
		printf("%d %d %d", Max, num[head], num[rear]);
	else
		printf("%d %d %d", Max, num[0], num[N - 1]);

	return 0;
}