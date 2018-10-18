#include<stdio.h>
#include <stdlib.h>

typedef struct PolyNode * Polynomial;
typedef int ElementType;
struct PolyNode
{
	ElementType coef;	//系数
	ElementType expn;	//指数
	Polynomial Next;
};

Polynomial Read();
void Print(Polynomial L);
Polynomial Plus(Polynomial A, Polynomial B);
Polynomial Muti(Polynomial A, Polynomial B);

int main()
{
	Polynomial A, B, PM, PP;
	A = Read();
	B = Read();
	PP = Plus(A, B);
	PM = Muti(A, B);
	Print(PM);
	Print(PP);
	return 0;
}

Polynomial Read()
{
	int N;
	scanf("%d", &N);

	Polynomial p, L, rear;
	L = (Polynomial)malloc(sizeof(struct PolyNode));

	rear = L;

	for (int i = 0; i < N; i++)
	{
		p = (Polynomial)malloc(sizeof(struct PolyNode));
		scanf("%d %d", &p->coef, &p->expn);
		rear->Next = p;
		rear = p;
	}

	rear->Next = NULL;
	L = L->Next;

	return L;
}

int Compare(ElementType e1, ElementType e2)
{
	if (e1 > e2)
		return 1;
	else if (e1 == e2)
		return 0;
	else
		return -1;
}

void Attach(ElementType c, ElementType e, Polynomial *rear)
{
	Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));

	p->expn = e;
	p->coef = c;

	p->Next = NULL;
	(*rear)->Next = p;
	*rear = p;
}

Polynomial Plus(Polynomial A, Polynomial B)
{
	Polynomial rear = (Polynomial)malloc(sizeof(struct PolyNode));
	Polynomial front,temp;
	int sum;

	front = rear;
	while (A&&B)
	{
		switch (Compare(A->expn, B->expn))
		{
		case 1:
			Attach(A->coef, A->expn, &rear);
			A = A->Next;
			break;
		case -1:
			Attach(B->coef, B->expn, &rear);
			B = B->Next;
			break;
		case 0:
			sum = A->coef + B->coef;
			if (sum)
				Attach(sum, A->expn, &rear);
			A = A->Next;
			B = B->Next;
			break;
		}
	}
	for (; A; A = A->Next)
		Attach(A->coef, A->expn, &rear);
	for (; B; B = B->Next)
		Attach(B->coef, B->expn, &rear);

	rear->Next = NULL;
	
	temp = front;
	front = front->Next;
	free(temp);

	return front;
}

Polynomial Muti(Polynomial A, Polynomial B)
{
	Polynomial P, rear, t1, t2, tmp;
	ElementType e, c;
	if (!A || !B)
		return NULL;
	t1 = A;
	t2 = B;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	rear = P;
	while (t2)
	{
		Attach(t1->coef*t2->coef, t1->expn + t2->expn, &rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1)
	{
		t2 = B;
		rear = P;
		while (t2)
		{
			e = t1->expn + t2->expn;
			c = t1->coef*t2->coef;
			while (rear->Next&&rear->Next->expn > e)
				rear = rear->Next;
			if (rear->Next&&rear->Next->expn == e)
			{
				if (rear->Next->coef + c)
				{
					rear->Next->coef += c;
				}
				else
				{
					tmp = rear->Next;
					rear->Next = tmp->Next;
					free(tmp);
				}
			}
			else
			{
				tmp = (Polynomial)malloc(sizeof(struct PolyNode));
				tmp->coef = c;
				tmp->expn = e;
				tmp->Next = rear->Next;
				rear->Next = tmp;
				rear = rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	t2 = P;
	P = P->Next;
	free(t2);
	return P;
}

void Print(Polynomial L)
{
	if (L)
	{
		while (L)
		{
			printf("%d %d", L->coef, L->expn);
			L = L->Next;
			if (L)
				printf(" ");
		}
		printf("\n");
	}
	else
		printf("0 0\n");
}