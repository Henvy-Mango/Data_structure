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

//全局变量
struct student Student[50];
int N = 0;
int flag = 0;

void Addition(student Student[], int i)
{
	printf("请输入学生的学号:\n");
	scanf("%d", &Student->Num);
	printf("请输入学生的名字:\n");
	scanf("%s", &Student->name);
	printf("请输入学生的年级:\n");
	scanf("%d", &Student->grade);
	printf("请输入学生的专业:\n");
	scanf("%s", &Student->major);
	printf("请输入学生的成绩 1:\n");
	scanf("%d", &Student->score_1);
	printf("请输入学生的成绩 2:\n");
	scanf("%d", &Student->score_2);
	printf("请输入学生的成绩 3:\n");
	scanf("%d", &Student->score_3);

	Student->score_Sum = Student->score_1 + Student->score_2 + Student->score_3;
	Student->score_Avg = Student->score_Sum / 3;
}

void Add()
{
	printf("您要添加多少条记录:\n");

	int temp;
	scanf("%d", &temp);

	N += temp;
	for (int i = N - temp; i < N; i++)
	{
		printf("正在添加第 %d 条记录\n", i + 1);
		Addition(&Student[i], i);
	}
	flag = 0;

	printf("\n");
	printf("添加结束\n");
	system("pause");
}

void Del()
{
	if (N == 0)
	{
		printf("\n");
		printf("非法操作!\n");
		return;
	}
	printf("您要删除多少条记录:\n");

	int temp;
	scanf("%d", &temp);

	if (temp > N)
	{
		printf("非法操作!\n");
		return;
	}

	N -= temp;
	flag = 0;

	printf("\n");
	printf("删除结束\n");
	system("pause");
}

void Modify()
{
	if (N == 0)
	{
		printf("\n");
		printf("非法操作!\n");
		return;
	}

	printf("您要修改第几条记录:\n");

	int temp;
	scanf("%d", &temp);

	if (temp > N || temp == 0)
	{
		printf("非法操作!\n");
		return;
	}

	Addition(&Student[temp - 1], temp);
	flag = 0;

	printf("\n");
	printf("修改结束\n");
	system("pause");
}

void Display(student L)
{
	printf("学号:  %d  名字:  %s  年级:  %d  专业:  %s\n", L.Num,L.name,L.grade,L.major);
	printf("成绩 1:  %d  成绩 2:  %d  成绩 3:  %d\n", L.score_1, L.score_2, L.score_3);
	printf("平均成绩:  %d  总成绩:  %d\n", L.score_Avg,L.score_Sum);
	printf("\n");
}
void Dis()
{
	if (N == 0)
	{
		printf("\n");
		printf("当前数据库为空!\n");
		return;
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("正在显示第 %d 条记录\n", i + 1);
		Display(Student[i]);

		//三个分一组，分页显示
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
	printf("排序成功!\n");
	system("pause");
}

void Search()
{
	if (flag == 0)
	{
		printf("\n");
		printf("当前数据尚未排序!\n");
		system("pause");
		return;
	}

	printf("输入需要查找的总成绩:\n");

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
			printf("查找成功,正在显示第 %d 条记录\n", mid + 1);
			Display(Student[mid]);
			system("pause");
			return;
		}
	}

	printf("查找失败,未找到记录!\n");

	system("pause");
	return;
}

void Menu()
{
	while (1)
	{
		printf("-------学生成绩管理系统------\n");
		printf("----当前系统有  %d  条记录---\n", N);
		printf("1.添加     2.删除     3.修改 \n");
		printf("4.显示     5.排序     6.查找 \n");
		printf("7.保存     0.退出\n");
		printf("-----------------------------\n");
		int select;
		printf("请输入:");
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
			printf("指令有误!请重新输入!\n");
			system("pause");
		}
	}
}