//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct Btree *Tree;
//struct Btree
//{
//	char Data;
//	Tree Lchild;
//	Tree Rchild;
//};
//
//Tree BuildTree(char T1[], char T2[], int n);
//void PrintTree(Tree P);
//
//int main()
//{
//	char T1[50];
//	char T2[50];
//	T2[0] = '\0';
//	printf("Please input the pre-order of binary tree : \n");
//	scanf("%s", T1);
//	printf("Please input the in-order of binary tree : \n");
//	scanf("%s", T2);
//
//	Tree root = BuildTree(T1, T2, strlen(T2));
//
//	//输出结果
//	PrintTree(root);
//}
//
//int FindFather(char T1[], char T2[], int n)
//{
//	//找父节点
//	for (int i = 0; i < n; i++)
//	{
//		if (*T1 == T2[i])
//			return i;
//	}
//	return -1;
//}
//
//Tree BuildTree(char T1[], char T2[], int n)
//{
//	if (n <= 0)
//		return NULL;
//	Tree P = (Tree)malloc(sizeof(struct Btree));
//	if (P == NULL)
//		return NULL;
//	P->Data = *T1;
//	int Mid = FindFather(T1, T2, n);
//	P->Lchild = BuildTree(T1 + 1, T2, Mid);
//	P->Rchild = BuildTree(T1 + Mid + 1, T2 + Mid + 1, n - Mid - 1);
//
//	return P;
//}
//
//void PrintTree(Tree P)
//{
//	if (P)
//	{
//		PrintTree(P->Lchild);
//		PrintTree(P->Rchild);
//		printf("%c", P->Data);
//	}
//	return;
//}