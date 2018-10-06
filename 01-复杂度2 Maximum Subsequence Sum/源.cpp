#include<stdio.h>

int main()
{
	int num[100005], N;
	int head = 0, rear = 0, index = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	//在线更新改造
	int Max = 0, Now = 0,flag=0;
	for (int j = 0; j < N; j++)
	{
		if (num[j] >= 0)
			flag = 1;
		Now += num[j];
		if (Now > Max)	//记录当前最大子列和
		{
			index++;
			Max = Now;
			rear = num[j];
			if (index == 1)
				head = num[j];
		}
		if (Now == Max&&num[j]==0)	//记录当前最大子列和
		{
			index++;
			Max = Now;
			rear = num[j];
			if (index == 1)
				head = num[j];
		}
		if (Now < 0)	//当前子列和小于0，则直接抛弃重新计算
		{
			Now = 0;
			index = 0;
		}
	}
	if (flag==0)
		printf("%d %d %d", Max, num[0], num[N - 1]);
	else
		printf("%d %d %d", Max, head, rear);

	return 0;
}