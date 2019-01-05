#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student {
	int Num;
	char name[10];
	int grade;
	char major[10];
	int score_1;
	int score_2;
	int score_3;
	int score_Avg;
	int score_Sum;
};
typedef student *Std;

//ȫ�ֱ���
struct student Student[50];
int N = 0;
int flag = 0;

void Addition(student Student[], int i)
{
	printf("������ѧ����ѧ��:\n");
	scanf("%d", &Student->Num);
	printf("������ѧ��������:\n");
	scanf("%s", &Student->name);
	printf("������ѧ�����꼶:\n");
	scanf("%d", &Student->grade);
	printf("������ѧ����רҵ:\n");
	scanf("%s", &Student->major);
	printf("������ѧ���ĳɼ� 1:\n");
	scanf("%d", &Student->score_1);
	printf("������ѧ���ĳɼ� 2:\n");
	scanf("%d", &Student->score_2);
	printf("������ѧ���ĳɼ� 3:\n");
	scanf("%d", &Student->score_3);

	Student->score_Sum = Student->score_1 + Student->score_2 + Student->score_3;
	Student->score_Avg = Student->score_Sum / 3;
}

void Add()
{
	printf("��Ҫ��Ӷ�������¼:\n");

	int temp;
	scanf("%d", &temp);

	N += temp;
	for (int i = N - temp; i < N; i++)
	{
		printf("������ӵ� %d ����¼\n", i + 1);
		Addition(&Student[i], i);
	}
	flag = 0;

	printf("\n");
	printf("��ӽ���\n");
	system("pause");
}

void Del()
{
	if (N == 0)
	{
		printf("\n");
		printf("�Ƿ�����!\n");
		return;
	}
	printf("��Ҫɾ����������¼:\n");

	int temp;
	scanf("%d", &temp);

	if (temp > N)
	{
		printf("�Ƿ�����!\n");
		return;
	}

	N -= temp;
	flag = 0;

	printf("\n");
	printf("ɾ������\n");
	system("pause");
}

void Modify()
{
	if (N == 0)
	{
		printf("\n");
		printf("�Ƿ�����!\n");
		return;
	}

	printf("��Ҫ�޸ĵڼ�����¼:\n");

	int temp;
	scanf("%d", &temp);

	if (temp > N || temp == 0)
	{
		printf("�Ƿ�����!\n");
		return;
	}

	Addition(&Student[temp - 1], temp);
	flag = 0;

	printf("\n");
	printf("�޸Ľ���\n");
	system("pause");
}

void Display(student L)
{
	printf("ѧ��:  %d  ����:  %s  �꼶:  %d  רҵ:  %s\n", L.Num,L.name,L.grade,L.major);
	printf("�ɼ� 1:  %d  �ɼ� 2:  %d  �ɼ� 3:  %d\n", L.score_1, L.score_2, L.score_3);
	printf("ƽ���ɼ�:  %d  �ܳɼ�:  %d\n", L.score_Avg,L.score_Sum);
	printf("\n");
}
void Dis()
{
	if (N == 0)
	{
		printf("\n");
		printf("��ǰ���ݿ�Ϊ��!\n");
		return;
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("������ʾ�� %d ����¼\n", i + 1);
		Display(Student[i]);

		//������һ�飬��ҳ��ʾ
		if ((i+1) % 3 == 0)
			system("pause");
	}
}

void Sort()
{
	for (int j = N - 1; j >= 0; j--)
	{
		int temp = 0;
		struct student L;
		for (int k = 0; k < j; k++)
		{
			if (Student[k].score_Sum > Student[k + 1].score_Sum)
			{
				L = Student[k];
				Student[k] = Student[k + 1];
				Student[k + 1] = L;
				temp = 1;
			}
		}
		if (temp == 0)
			break;
	}
	flag = 1;
	printf("\n");
	printf("����ɹ�!\n");
	system("pause");
}

void Search()
{
	if (flag == 0)
	{
		printf("\n");
		printf("��ǰ������δ����!\n");
		system("pause");
		return;
	}

	printf("������Ҫ���ҵ��ܳɼ�:\n");

	int temp;
	scanf("%d", &temp);

	printf("\n");

	int low, mid, high;
	low = 0;
	high = N - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (temp < Student[mid].score_Sum)
			high = mid - 1;
		if (temp > Student[mid].score_Sum)
			low = mid + 1;
		else if (temp == Student[mid].score_Sum)
		{
			printf("���ҳɹ�,������ʾ�� %d ����¼\n", mid + 1);
			Display(Student[mid]);
			system("pause");
			return;
		}
	}

	printf("����ʧ��,δ�ҵ���¼!\n");

	system("pause");
	return;
}

void Menu()
{
	while (1)
	{
		printf("-------ѧ���ɼ�����ϵͳ------\n");
		printf("----��ǰϵͳ��  %d  ����¼---\n", N);
		printf("1.���     2.ɾ��     3.�޸� \n");
		printf("4.��ʾ     5.����     6.���� \n");
		printf("7.����     0.�˳�\n");
		printf("-----------------------------\n");
		int select;
		printf("������:");
		scanf("%d", &select);

		if (select == 1)
			Add();
		else if (select == 2)
			Del();
		else if (select == 3)
			Modify();
		else if (select == 4)
			Dis();
		else if (select == 5)
			Sort();
		else if (select == 6)
			Search();
		//else if (select == 7)
		//	Save();
		else if (select == 0)
			return;
		else
		{
			printf("ָ������!����������!\n");
			system("pause");
		}
	}
}