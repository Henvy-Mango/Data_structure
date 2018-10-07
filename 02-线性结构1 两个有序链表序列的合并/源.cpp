#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;
int N;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	//L2 = Read();
	//L = Merge(L1, L2);
	//Print(L);
	Print(L1);
	//Print(L2);
	return 0;
}

//List Merge(List L1, List L2)
//{
//
//}

List Read()
{
	scanf("%d", &N);
	int i = 0; Node *p, *rear;
	List L = (Node*)malloc(sizeof(Node));
	rear = L;

	for (; i < N; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &p->Data);

		rear->Next = p; //尾指针 指向新建结点
		rear = p;//rear指针移动
	}
	rear->Next = NULL;

	return L;
}

void Print(List L)
{
	;	for (int i = 1; i <= N; i++)
	{
		L = L->Next;
		printf("%d ", L->Data);
	}
}