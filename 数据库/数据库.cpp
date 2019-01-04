#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
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
typedef Student *Std;
void Add(Std L)
{
	scanf("%d", &L->Num);
	scanf("%s", &L->name);
	scanf("%d", &L->grade);
	scanf("%s", &L->major);
	scanf("%d", &L->score_1);
	scanf("%d", &L->score_2);
	scanf("%d", &L->score_3);
}
int main()
{
	struct Student Student[50];
	Add(Student);
	return 0;
}
