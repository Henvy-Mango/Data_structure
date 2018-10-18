#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode List;

struct Node {
	ElementType Data;
	PtrToNode   Next;
};

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

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

	p1 = L1->Next;		//指向链表第一个元素
	p2 = L2->Next;
	p3 = L;				//指向链表的头结点

	while (p1&&p2)		//p1和p2有一个到达尾部，循环结束
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

List Read()					//尾插法
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

		rear->Next = p;		//尾指针 指向新建结点
		rear = p;			//rear指针移动
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