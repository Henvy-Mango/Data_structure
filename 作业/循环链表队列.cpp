#include<stdio.h>
#include<stdlib.h>

typedef struct LNode *List;
struct LNode
{
	int Data;
	List Next;
};

List InitQueue();
void Add(List * L);
void Del(List * L);

int n = 0;

int main()
{
	List L, tmp;
	L = InitQueue();
	tmp = L;

	int m;
	scanf("%d", &m);
	if (m <= n)
	{
		for (int i = 0; i < m; i++)
			Add(&L);
	}
	else
		printf("Error\n");

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		Del(&tmp);
	}
	if (m - k)
	{
		for (int i = 0; i < m - k; i++)
		{
			printf("%d ", tmp->Data);
			tmp = tmp->Next;
		}
	}
	else
		printf("NULL\n");

	return 0;
}
List InitQueue()
{
	scanf("%d", &n);
	List L = (List)malloc(sizeof(struct LNode));
	List p, t;
	t = L;
	for (int i = 0; i < n - 1; i++)
	{
		p = (List)malloc(sizeof(struct LNode));
		t->Next = p;
		t = p;
	}
	t->Next = L;

	return L;
}

void Add(List * L)
{
	scanf("%d", &(*L)->Data);
	*L = (*L)->Next;
}

void Del(List *L)
{
	List t, p;
	p = *L;
	*L = (*L)->Next;
	free(p);
}
