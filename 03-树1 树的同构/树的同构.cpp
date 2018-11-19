#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	char Name;
	int lchild;
	int rchild;
}T1[10], T2[10];

int BulidTree(struct TreeNode T[]);
int Isomorphic(int R1, int R2);

int main()
{
	int R1, R2;
	R1 = BulidTree(T1);
	R2 = BulidTree(T2);
	if (Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
}

int BulidTree(struct TreeNode T[])
{
	int N = 0;
	int Root = -1, check[10];
	char lc, rc;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		check[i] = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("\n%c %c %c", &T[i].Name, &lc, &rc);

		if (lc != '-')
		{
			T[i].lchild = lc - '0';
			//���ǰѶ�Ӧ���ַ�������s[i],ת�������ε�s[i],�ַ�����ǿ��ת�������ε�ʱ��,ֵ�����ַ��Ͷ�Ӧ��ascii��ֵ,
			//ͬʱ,0-9��ascii��ֵ��������,�����ַ�s[i]��Ӧ������ֵ,�����ַ�s[i]��Ӧ��ascii��ֵ��ȥ0��Ӧ��ascii��ֵ��
			check[T[i].lchild] = 1;
		}
		else
			T[i].lchild = -1;

		if (rc != '-')
		{
			T[i].rchild = rc - '0';
			check[T[i].rchild] = 1;
		}
		else
			T[i].rchild = -1;
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i] == 0)
		{
			Root = i;
			break;
		}
	}

	return Root;
}

int Isomorphic(int R1, int R2)
{
	if (R1 == -1 && R2 == -1)
		return 1;

	if ((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1))
		return 0;

	if (T1[R1].Name != T2[R2].Name)
		return 0;

	if ((T1[R1].lchild == -1) && (T2[R2].lchild == -1))
		return Isomorphic(T1[R1].rchild, T2[R2].rchild);

	if (((T1[R1].lchild != -1) && (T2[R2].lchild != -1)) && ((T1[T1[R1].lchild].Name) == (T2[T2[R2].lchild].Name)))
		return (Isomorphic(T1[R1].lchild, T2[R2].lchild) && Isomorphic(T1[R1].rchild, T2[R2].rchild));

	else
		return (Isomorphic(T1[R1].lchild, T2[R2].rchild) && Isomorphic(T1[R1].rchild, T2[R2].lchild));
}