#include<stdio.h>

int main()
{
	int num[100005],N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	scanf("%d", &num[i]);

	//���߸���
	int Max=0, Now=0;
	for (int j = 0; j < N; j++)
	{
		Now += num[j];

		if (Now > Max)	//��¼��ǰ������к�
			Max = Now;

		if (Now < 0)	//��ǰ���к�С��0����ֱ���������¼���
			Now = 0;
	}
	
	printf("%d", Max);
	
	return 0;
}