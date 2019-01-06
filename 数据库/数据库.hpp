#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student {
	int Num;//学号
	char name[10];//名字
	int grade;//年级
	char major[10];//专业
	int score_1;//成绩1
	int score_2;//成绩2
	int score_3;//成绩3
	int score_Avg;//平均成绩
	int score_Sum;//总成绩
};
typedef student *Std;

//全局变量
struct student Student[100];
int N = 0;//数据库内所有数据条数
int Avg_flag = 0;//平均成绩排序标志
int Sum_flag = 0;//总成绩排序标志

void Addition(Std Student, int i)
{
	printf("请输入学生的学号(数字):\n");
	scanf("%d", &Student->Num);
	printf("请输入学生的名字(字符):\n");
	scanf("%s", &Student->name);
	printf("请输入学生的年级(数字):\n");
	scanf("%d", &Student->grade);
	printf("请输入学生的专业(字符):\n");
	scanf("%s", &Student->major);
	printf("请输入学生的成绩 1(数字):\n");
	scanf("%d", &Student->score_1);
	printf("请输入学生的成绩 2(数字):\n");
	scanf("%d", &Student->score_2);
	printf("请输入学生的成绩 3(数字):\n");
	scanf("%d", &Student->score_3);

	//计算平均成绩和总成绩
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
	Avg_flag = 0;
	Sum_flag = 0;

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
	Avg_flag = 0;
	Sum_flag = 0;

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
	Avg_flag = 0;
	Sum_flag = 0;

	printf("\n");
	printf("修改结束\n");
	system("pause");
}

void Display(student L)
{
	printf("学号:  %d  名字:  %s  年级:  %d  专业:  %s\n", L.Num, L.name, L.grade, L.major);
	printf("成绩 1:  %d  成绩 2:  %d  成绩 3:  %d\n", L.score_1, L.score_2, L.score_3);
	printf("平均成绩:  %d  总成绩:  %d\n", L.score_Avg, L.score_Sum);
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

		//五个分一组，分页显示
		if ((i + 1) % 5 == 0)
			system("pause");
	}
	system("pause");
}

void Avg_Sort()
{
	//插入排序
	for (int j = N - 1; j >= 0; j--)
	{
		int temp = 0;
		struct student L;
		for (int k = 0; k < j; k++)
		{
			if (Student[k].score_Avg < Student[k + 1].score_Avg)
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
	Avg_flag = 1;
	Sum_flag = 0;

	printf("\n");
	printf("平均成绩排序成功!\n");
	system("pause");
}

void Sum_Sort()
{
	//插入排序
	for (int j = N - 1; j >= 0; j--)
	{
		int temp = 0;
		struct student L;
		for (int k = 0; k < j; k++)
		{
			if (Student[k].score_Sum < Student[k + 1].score_Sum)
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
	Avg_flag = 0;
	Sum_flag = 1;

	printf("\n");
	printf("总成绩排序成功!\n");
	system("pause");
}

void Save(char *data)
{
	FILE *fp = fopen(data, "w+");

	if (fp == NULL)
	{
		printf("无法打开文件!\n");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		//文件保存
		fprintf(fp, "学号:  %d  名字:  %s  年级:  %d  专业:  %s  成绩 1:  %d  成绩 2:  %d  成绩 3:  %d  平均成绩:  %d  总成绩:  %d\n", Student[i].Num, Student[i].name, Student[i].grade, Student[i].major, Student[i].score_1, Student[i].score_2, Student[i].score_3, Student[i].score_Avg, Student[i].score_Sum);
	}
	fclose(fp);
	return;
}

void Sort()
{
	int temp;
	while (1)
	{
		printf("---------降序排序菜单--------\n");
		printf("--排序成功后生成相应txt文件--\n");
		printf("1.平均成绩排序   2.总成绩排序\n");
		printf("0.退出\n");
		printf("-----------------------------\n");
		scanf("%d", &temp);
		if (temp == 1)
		{
			Avg_Sort();
			//保存到Avg_List.txt
			char data[15] = { "Avg_List.txt" };
			Save(data);
			return;
		}
		else if (temp == 2)
		{
			Sum_Sort();
			//保存到Sum_List.txt
			char data[15] = { "Sum_List.txt" };
			Save(data);
			return;
		}
		else if (temp == 0)
			return;
		else
		{
			printf("指令有误!请重新输入!\n");
			system("pause");
		}
	}
}

void Search()
{
	int select;

	while (1)
	{
		printf("-----------查找菜单----------\n");
		printf("---------查找前请排序--------\n");
		printf("1.查找平均成绩   2.查找总成绩\n");
		printf("0.退出\n");
		printf("-----------------------------\n");

		scanf("%d", &select);

		if (select == 1)
		{
			if (Avg_flag == 0)
			{
				printf("\n");
				printf("当前平均成绩数据尚未排序!\n");
				printf("请排序完成后再来!\n");
				system("pause");
				return;
			}

			printf("输入需要查找的平均成绩:\n");

			int temp;
			scanf("%d", &temp);

			printf("\n");

			int low, mid, high;
			low = 0;
			high = N - 1;
			//二分查找
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp < Student[mid].score_Avg)
					low = mid + 1;
				if (temp > Student[mid].score_Avg)
					high = mid - 1;
				else if (temp == Student[mid].score_Avg)
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
		else if (select == 2)
		{
			if (Sum_flag == 0)
			{
				printf("\n");
				printf("当前总成绩数据尚未排序!\n");
				printf("请排序完成后再来!\n");
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
			//二分查找
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp < Student[mid].score_Sum)
					low = mid + 1;
				if (temp > Student[mid].score_Sum)
					high = mid - 1;
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
		else
		{
			printf("指令有误!请重新输入!\n");
			system("pause");
		}
	}
}

void Load()
{
	int temp;

	while (1)
	{
		printf("-----------排序菜单----------\n");
		printf("1.读取平均成绩   2.读取总成绩\n");
		printf("0.退出\n");
		printf("-----------------------------\n");

		scanf("%d", &temp);

		if (temp == 1)
		{
			FILE *fp = fopen("Avg_List.txt", "r+");

			if (fp == NULL)
			{
				printf("无法打开文件!\n");
				return;
			}

			while (!feof(fp))
			{
				//读取文件
				temp = fscanf(fp, "学号:  %d  名字:  %s  年级:  %d  专业:  %s  成绩 1:  %d  成绩 2:  %d  成绩 3:  %d  平均成绩:  %d  总成绩:  %d\n", &Student[N].Num, &Student[N].name, &Student[N].grade, &Student[N].major, &Student[N].score_1, &Student[N].score_2, &Student[N].score_3, &Student[N].score_Avg, &Student[N].score_Sum);
				//检查读取的变量个数
				if (temp != 9)
				{
					printf("文件格式错误!\n");
					system("pause");
					return;
				}
				//计算平均成绩和总成绩
				Student[N].score_Sum = Student[N].score_1 + Student[N].score_2 + Student[N].score_3;
				Student[N].score_Avg = Student[N].score_Sum / 3;
				N++;
			}
			fclose(fp);
			printf("平均成绩读取成功!\n");
			system("pause");
			return;
		}
		else if (temp == 2)
		{
			FILE *fp = fopen("Sum_List.txt", "r+");

			if (fp == NULL)
			{
				printf("无法打开文件!\n");
				return;
			}

			while (!feof(fp))
			{
				fscanf(fp, "学号:  %d  名字:  %s  年级:  %d  专业:  %s  成绩 1:  %d  成绩 2:  %d  成绩 3:  %d  平均成绩:  %d  总成绩:  %d\n", &Student[N].Num, &Student[N].name, &Student[N].grade, &Student[N].major, &Student[N].score_1, &Student[N].score_2, &Student[N].score_3, &Student[N].score_Avg, &Student[N].score_Sum);
				N++;
			}
			fclose(fp);
			printf("总成绩读取成功!\n");
			system("pause");
			return;
		}
		else
		{
			printf("指令有误!请重新输入!\n");
			system("pause");
		}
	}
}

void Menu()
{
	//菜单界面
	while (1)
	{
		printf("-------学生成绩管理系统------\n");
		printf("----当前系统有  %d  条记录---\n", N);
		printf("1.添加     2.删除     3.修改 \n");
		printf("4.显示     5.排序     6.查找 \n");
		printf("7.读取     0.退出\n");
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
		else if (select == 7)
			Load();
		else if (select == 0)
			return;
		else
		{
			printf("指令有误!请重新输入!\n");
			system("pause");
		}
	}
}