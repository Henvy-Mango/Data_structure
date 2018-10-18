#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;

typedef struct LNode * List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */

List ReadInput() {//List is a point;
	int N;
	scanf("%d", &N);
	List L = (List)malloc(sizeof(struct LNode)); 
	L->Last = N;
	for (ElementType i = 1; i <= N; i++) 
	{
		scanf("%d", &L->Data[i]);
	}
	return L;
}

Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

Position BinarySearch(List L, ElementType X)
{
	Position right, mid, left;
	left = 0;
	right = L->Last;
	while (left <= right)
	{
		mid = (left + right) / 2;    /*�۰�*/
		if (X < L->Data[mid])
			right = mid - 1;
		if (X > L->Data[mid])
			left = mid + 1;
		else if (X == L->Data[mid])
			return mid;
	}
			return NotFound;
}