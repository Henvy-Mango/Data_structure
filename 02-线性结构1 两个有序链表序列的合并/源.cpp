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

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

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

		rear->Next = p; //βָ�� ָ���½����
		rear = p;//rearָ���ƶ�
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