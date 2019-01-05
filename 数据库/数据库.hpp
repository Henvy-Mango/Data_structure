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
	printf("添加结束\n");
}

void Del()
{
	if (N == 0)
	{
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

	printf("删除结束\n");
}

void Modify()
{
	if (N == 0)
	{
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

	printf("修改结束\n");
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
		printf("当前数据库为空!\n");
		return;
	}
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
}

void Search()
{
	printf("输入需要查找的总成绩:\n");

	int temp;
	scanf("%d", &temp);

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
			printf("正在显示第 %d 条记录\n", mid + 1);
			Display(Student[mid]);
			return;
		}
	}
	printf("未找到记录!\n");
	system("pause");
	return;
}

void Menu()
{
	while (1)
	{
		printf("学生成绩管理系统菜单界面\n");
		printf("当前系统有  %d  条记录\n", N);
		printf("输入下列指令来操作:\n");
		printf("添加记录请输入      1\n");
		printf("删除记录请输入      2\n");
		printf("修改记录请输入      3\n");
		printf("显示记录请输入      4\n");
		printf("输出排序记录请输入  5\n");
		printf("查找成绩记录请输入  6\n");
		printf("退出菜单请输入      0\n");

		int select;
		scanf("%d", &select);

		if (select == 1)
			Add();
		if (select == 2)
			Del();
		if (select == 3)
			Modify();
		if (select == 4)
			Dis();
		if (select == 5)
			Sort();
		if (select == 6)
			Search();
		if (select == 0)
			return;
	}
}