#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student {
	int Num;//ѧ��
	char name[10];//����
	int grade;//�꼶
	char major[10];//רҵ
	int score_1;//�ɼ�1
	int score_2;//�ɼ�2
	int score_3;//�ɼ�3
	int score_Avg;//ƽ���ɼ�
	int score_Sum;//�ܳɼ�
};
typedef student *Std;

//ȫ�ֱ���
struct student Student[100];
int N = 0;//���ݿ���������������
int Avg_flag = 0;//ƽ���ɼ������־
int Sum_flag = 0;//�ܳɼ������־

void Addition(Std Student, int i)
{
	printf("������ѧ����ѧ��(����):\n");
	scanf("%d", &Student->Num);
	printf("������ѧ��������(�ַ�):\n");
	scanf("%s", &Student->name);
	printf("������ѧ�����꼶(����):\n");
	scanf("%d", &Student->grade);
	printf("������ѧ����רҵ(�ַ�):\n");
	scanf("%s", &Student->major);
	printf("������ѧ���ĳɼ� 1(����):\n");
	scanf("%d", &Student->score_1);
	printf("������ѧ���ĳɼ� 2(����):\n");
	scanf("%d", &Student->score_2);
	printf("������ѧ���ĳɼ� 3(����):\n");
	scanf("%d", &Student->score_3);

	//����ƽ���ɼ����ܳɼ�
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
	Avg_flag = 0;
	Sum_flag = 0;

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
	Avg_flag = 0;
	Sum_flag = 0;

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
	Avg_flag = 0;
	Sum_flag = 0;

	printf("\n");
	printf("�޸Ľ���\n");
	system("pause");
}

void Display(student L)
{
	printf("ѧ��:  %d  ����:  %s  �꼶:  %d  רҵ:  %s\n", L.Num, L.name, L.grade, L.major);
	printf("�ɼ� 1:  %d  �ɼ� 2:  %d  �ɼ� 3:  %d\n", L.score_1, L.score_2, L.score_3);
	printf("ƽ���ɼ�:  %d  �ܳɼ�:  %d\n", L.score_Avg, L.score_Sum);
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

		//�����һ�飬��ҳ��ʾ
		if ((i + 1) % 5 == 0)
			system("pause");
	}
	system("pause");
}

void Avg_Sort()
{
	//��������
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
	printf("ƽ���ɼ�����ɹ�!\n");
	system("pause");
}

void Sum_Sort()
{
	//��������
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
	printf("�ܳɼ�����ɹ�!\n");
	system("pause");
}

void Save(char *data)
{
	FILE *fp = fopen(data, "w+");

	if (fp == NULL)
	{
		printf("�޷����ļ�!\n");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		//�ļ�����
		fprintf(fp, "ѧ��:  %d  ����:  %s  �꼶:  %d  רҵ:  %s  �ɼ� 1:  %d  �ɼ� 2:  %d  �ɼ� 3:  %d  ƽ���ɼ�:  %d  �ܳɼ�:  %d\n", Student[i].Num, Student[i].name, Student[i].grade, Student[i].major, Student[i].score_1, Student[i].score_2, Student[i].score_3, Student[i].score_Avg, Student[i].score_Sum);
	}
	fclose(fp);
	return;
}

void Sort()
{
	int temp;
	while (1)
	{
		printf("---------��������˵�--------\n");
		printf("--����ɹ���������Ӧtxt�ļ�--\n");
		printf("1.ƽ���ɼ�����   2.�ܳɼ�����\n");
		printf("0.�˳�\n");
		printf("-----------------------------\n");
		scanf("%d", &temp);
		if (temp == 1)
		{
			Avg_Sort();
			//���浽Avg_List.txt
			char data[15] = { "Avg_List.txt" };
			Save(data);
			return;
		}
		else if (temp == 2)
		{
			Sum_Sort();
			//���浽Sum_List.txt
			char data[15] = { "Sum_List.txt" };
			Save(data);
			return;
		}
		else if (temp == 0)
			return;
		else
		{
			printf("ָ������!����������!\n");
			system("pause");
		}
	}
}

void Search()
{
	int select;

	while (1)
	{
		printf("-----------���Ҳ˵�----------\n");
		printf("---------����ǰ������--------\n");
		printf("1.����ƽ���ɼ�   2.�����ܳɼ�\n");
		printf("0.�˳�\n");
		printf("-----------------------------\n");

		scanf("%d", &select);

		if (select == 1)
		{
			if (Avg_flag == 0)
			{
				printf("\n");
				printf("��ǰƽ���ɼ�������δ����!\n");
				printf("��������ɺ�����!\n");
				system("pause");
				return;
			}

			printf("������Ҫ���ҵ�ƽ���ɼ�:\n");

			int temp;
			scanf("%d", &temp);

			printf("\n");

			int low, mid, high;
			low = 0;
			high = N - 1;
			//���ֲ���
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp < Student[mid].score_Avg)
					low = mid + 1;
				if (temp > Student[mid].score_Avg)
					high = mid - 1;
				else if (temp == Student[mid].score_Avg)
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
		else if (select == 2)
		{
			if (Sum_flag == 0)
			{
				printf("\n");
				printf("��ǰ�ܳɼ�������δ����!\n");
				printf("��������ɺ�����!\n");
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
			//���ֲ���
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp < Student[mid].score_Sum)
					low = mid + 1;
				if (temp > Student[mid].score_Sum)
					high = mid - 1;
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
		else
		{
			printf("ָ������!����������!\n");
			system("pause");
		}
	}
}

void Load()
{
	int temp;

	while (1)
	{
		printf("-----------����˵�----------\n");
		printf("1.��ȡƽ���ɼ�   2.��ȡ�ܳɼ�\n");
		printf("0.�˳�\n");
		printf("-----------------------------\n");

		scanf("%d", &temp);

		if (temp == 1)
		{
			FILE *fp = fopen("Avg_List.txt", "r+");

			if (fp == NULL)
			{
				printf("�޷����ļ�!\n");
				return;
			}

			while (!feof(fp))
			{
				//��ȡ�ļ�
				temp = fscanf(fp, "ѧ��:  %d  ����:  %s  �꼶:  %d  רҵ:  %s  �ɼ� 1:  %d  �ɼ� 2:  %d  �ɼ� 3:  %d  ƽ���ɼ�:  %d  �ܳɼ�:  %d\n", &Student[N].Num, &Student[N].name, &Student[N].grade, &Student[N].major, &Student[N].score_1, &Student[N].score_2, &Student[N].score_3, &Student[N].score_Avg, &Student[N].score_Sum);
				//����ȡ�ı�������
				if (temp != 9)
				{
					printf("�ļ���ʽ����!\n");
					system("pause");
					return;
				}
				//����ƽ���ɼ����ܳɼ�
				Student[N].score_Sum = Student[N].score_1 + Student[N].score_2 + Student[N].score_3;
				Student[N].score_Avg = Student[N].score_Sum / 3;
				N++;
			}
			fclose(fp);
			printf("ƽ���ɼ���ȡ�ɹ�!\n");
			system("pause");
			return;
		}
		else if (temp == 2)
		{
			FILE *fp = fopen("Sum_List.txt", "r+");

			if (fp == NULL)
			{
				printf("�޷����ļ�!\n");
				return;
			}

			while (!feof(fp))
			{
				fscanf(fp, "ѧ��:  %d  ����:  %s  �꼶:  %d  רҵ:  %s  �ɼ� 1:  %d  �ɼ� 2:  %d  �ɼ� 3:  %d  ƽ���ɼ�:  %d  �ܳɼ�:  %d\n", &Student[N].Num, &Student[N].name, &Student[N].grade, &Student[N].major, &Student[N].score_1, &Student[N].score_2, &Student[N].score_3, &Student[N].score_Avg, &Student[N].score_Sum);
				N++;
			}
			fclose(fp);
			printf("�ܳɼ���ȡ�ɹ�!\n");
			system("pause");
			return;
		}
		else
		{
			printf("ָ������!����������!\n");
			system("pause");
		}
	}
}

void Menu()
{
	//�˵�����
	while (1)
	{
		printf("-------ѧ���ɼ�����ϵͳ------\n");
		printf("----��ǰϵͳ��  %d  ����¼---\n", N);
		printf("1.���     2.ɾ��     3.�޸� \n");
		printf("4.��ʾ     5.����     6.���� \n");
		printf("7.��ȡ     0.�˳�\n");
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
		else if (select == 7)
			Load();
		else if (select == 0)
			return;
		else
		{
			printf("ָ������!����������!\n");
			system("pause");
		}
	}
}