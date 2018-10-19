#include<stdio.h>
#include<stdlib.h>

typedef struct Node *List;
typedef int ElementType;
struct Node
{
	ElementType adr;
	ElementType Data;
	ElementType next_adr;
	List Next;
};

void Print(List L);
void Attach(ElementType adr, ElementType Data, ElementType next_adr, List *rear);
List Sort(ElementType st_adr, List L);
List Reverse(ElementType K, List L);

//����ע������Ҫ����ÿ��K��Ԫ�ط�ת

int num = 0;

int main()
{
	ElementType st_adr, N, K;
	ElementType adr, Data, next_adr;
	List p;
	List L = (List)malloc(sizeof(struct Node));
	p = L;
	scanf("%d %d %d", &st_adr, &N, &K);

	while (N--)
	{
		scanf("%d %d %d", &adr, &Data, &next_adr);
		Attach(adr, Data, next_adr, &L);
	}
	L = p;
	L = L->Next;	//ָ���һ��Ԫ��
	L = Sort(st_adr, L);
	Print(L);
	L = Reverse(K, L);
	Print(L);

	return 0;
}

void Attach(ElementType adr, ElementType Data, ElementType next_adr, List *rear)
{
	List p = (List)malloc(sizeof(struct Node));

	p->adr = adr;
	p->Data = Data;
	p->next_adr = next_adr;

	p->Next = NULL;
	(*rear)->Next = p;
	*rear = p;
}

List Sort(ElementType st_adr, List L)
{
	List P = (List)malloc(sizeof(struct Node));

	List t1 = L, t2 = P;
	ElementType find_adr = st_adr;

	while (find_adr != -1)
	{
		L = t1;
		while (L)
		{
			if (L->adr == find_adr)		//����ַ��������
			{
				Attach(L->adr, L->Data, L->next_adr, &P);
				find_adr = L->next_adr;
				num++;
			}
			else
			{
				L = L->Next;
			}
		}
	}
	P = t2;
	P = P->Next;

	return P;
}

List Reverse(ElementType K, List L)		//����
{
	int cnt = 1;        //���ڼ�������ת�Ľ���� 
	List p1 = L;
	List p2 = p1->Next;
	List tmp, head;

	while (cnt < K) {
		tmp = p2->Next;    //����old�����ת�� ��¼δ��ת�����ͷ��� 
		p2->Next = p1;
		p1->Next = tmp;
		p1 = p2;            //�����λ 
		p2 = tmp;            //�����λ 
		cnt++;                //��ת�ڵ�+1 
	}
	L->Next = p1;

	return p1;        //�µ�ͷ��� 
}
void Print(List L)
{
	printf("\n");	//����ר��

	while (L)
	{
		if (L->next_adr != -1)
		{
			printf("%.5d %d %.5d\n", L->adr, L->Data, L->next_adr);
			L = L->Next;
		}
		else
		{
			printf("%.5d %d %d\n", L->adr, L->Data, L->next_adr);
			L = L->Next;
		}
	}
}