#include<stdio.h>

int main()
{
	int num[100005], N;
	int head = 0, rear = 0, index = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	//���߸��¸���
	int Max = 0, Now = 0,flag=0;
	for (int j = 0; j < N; j++)
	{
		if (num[j] >= 0)
			flag = 1;
		Now += num[j];
		if (Now > Max)	//��¼��ǰ������к�
		{
			index++;
			Max = Now;
			rear = num[j];
			if (index == 1)
				head = num[j];
		}
		if (Now == Max&&num[j]==0)	//��¼��ǰ������к�
		{
			index++;
			Max = Now;
			rear = num[j];
			if (index == 1)
				head = num[j];
		}
		if (Now < 0)	//��ǰ���к�С��0����ֱ���������¼���
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