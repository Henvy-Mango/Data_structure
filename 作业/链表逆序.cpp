//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct LNode *List;
//struct LNode
//{
//	int Data;
//	List Next;
//};
//
//List Reverse(List L);
//
//int main()
//{
//	int N;
//	printf("Please input N = \n");
//	scanf("%d", &N);
//
//	List L = (List)malloc(sizeof(struct LNode));
//	List tmp;
//
//	tmp = L;
//
//	for (int i = 0; i < N; i++)
//	{
//		List p = (List)malloc(sizeof(struct LNode));
//		scanf("%d", &p->Data);
//		tmp->Next = p;
//		tmp = p;
//	}
//	tmp->Next = NULL;
//	L = L->Next;
//
//	L = Reverse(L);
//
//	while (L)
//	{
//		printf("%d ", L->Data);
//		L = L->Next;
//	}
//	
//	printf("\n");
//	return 0;
//}
//
//List Reverse(List L)
//{
//	List p1, p2;
//
//	p1 = L;
//	p2 = L->Next;
//
//	while (p2)
//	{
//		p1->Next = p2->Next;
//		p2->Next = L;
//		L = p2;
//		p2 = p1->Next;
//	}
//
//	return L;
//}