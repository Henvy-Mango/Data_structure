#include<stdio.h>

int main()
{
	int num[100005],N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	scanf("%d", &num[i]);

	//在线更新
	int Max=0, Now=0;
	for (int j = 0; j < N; j++)
	{
		Now += num[j];

		if (Now > Max)	//记录当前最大子列和
			Max = Now;

		if (Now < 0)	//当前子列和小于0，则直接抛弃重新计算
			Now = 0;
	}
	
	printf("%d", Max);
	
	return 0;
}