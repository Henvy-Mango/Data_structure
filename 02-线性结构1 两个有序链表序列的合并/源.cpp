#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode List;

struct Node {
	ElementType Data;
	PtrToNode   Next;
};

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(struct Node));
	List p1, p2, p3;

	p1 = L1->Next;		//ָ�������һ��Ԫ��
	p2 = L2->Next;
	p3 = L;				//ָ�������ͷ���

	while (p1&&p2)		//p1��p2��һ������β����ѭ������
	{
		if (p1->Data <= p2->Data)
		{
			p3->Next = p1;
			p3 = p1;
			p1 = p1->Next;
		}
		else
		{
			p3->Next = p2;
			p3 = p2;
			p2 = p2->Next;
		}
	}
	if (p1)
		p3->Next = p1;
	else
		p3->Next = p2;

	L1->Next = NULL;
	L2->Next = NULL;

	return L;
}

List Read()					//β�巨
{
	int N;
	scanf("%d", &N);

	List p, rear;
	List L = (List)malloc(sizeof(Node));
	rear = L;

	for (int i = 0; i < N; i++)
	{
		p = (List)malloc(sizeof(Node));
		scanf("%d", &p->Data);

		rear->Next = p;		//βָ�� ָ���½����
		rear = p;			//rearָ���ƶ�
	}
	rear->Next = NULL;

	return L;
}

void Print(List L)
{
	L = L->Next;
	if (L)
	{
		while (L)
		{
			printf("%d ", L->Data);
			L = L->Next;
		}
	}
	else
	{
		printf("NULL");
	}
	printf("\n");
}