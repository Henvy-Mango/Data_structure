#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int address;
	int data;
	int nextAddress;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

int main()
{
	//����ǰ 
	LinkList L1, p1, q1;
	L1 = (LinkList)malloc(sizeof(Node));    //����ͷָ�� 
	L1->next = NULL;
	int firstAddress;
	int N, K;//NΪ�ܽ���� KΪ�跭ת���� 
	scanf("%d %d %d", &firstAddress, &N, &K);
	p1 = L1;
	for (int i = 0; i < N; i++) {
		q1 = (LinkList)malloc(sizeof(Node));
		scanf("%d %d %d", &q1->address, &q1->data, &q1->nextAddress);
		p1->next = q1;
		p1 = q1;
	}
	p1->next = NULL;

	//    //����û���� 
	//    printf("����1 ��\n");
	//    p1 = L1->next;
	//    while(p1){
	//        printf("%05d %d %d\n", p1->address, p1->data, p1->nextAddress);
	//        p1 = p1->next;
	//    }

		//����� 
	LinkList L2, p2;
	L2 = (LinkList)malloc(sizeof(Node));    //����ͷָ�� 
	L2->next = NULL;
	int count = 0;
	int findAddress = firstAddress;
	p2 = L2;
	while (findAddress != -1) {            //while(count < N) {�ж����㲻��������ûͨ�� 

		q1 = L1;
		while (q1->next) {
			if (q1->next->address == findAddress) {
				p2->next = q1->next;
				q1->next = q1->next->next;
				p2 = p2->next;
				count++;
				//                printf("count = %d\n",count);
				findAddress = p2->nextAddress;
				//                printf("findAddress = %d\n",findAddress);
			}
			else {
				q1 = q1->next;
			}
		}
	}
	p2->next = NULL;

	//    //����û���� 
	//    printf("����2 ��\n");
	//    p2 = L2->next;
	//    while(p2){
	//        printf("%05d %d %05d\n", p2->address, p2->data, p2->nextAddress);
	//        p2 = p2->next;
	//    }
		//Reversing
	LinkList L3, p3, q3, tail;
	L3 = (LinkList)malloc(sizeof(Node));    //����ͷָ�� 
	L3->next = NULL;
	//��L2��ͷ�巨����L3
	int n = count;                //��ֹ�ж�����Ӱ�� n=N ��Ӱ��
	int k = K;
	p3 = L3;
	p2 = L2;
	while (n >= k) {
		n -= k;
		for (int i = 0; i < k; i++) {
			p3->next = p2->next;
			p2->next = p2->next->next;
			if (i == 0)
				tail = p3->next;
			else
				p3->next->next = q3;
			q3 = p3->next;
		}
		p3 = tail;
	}
	p3->next = L2->next;

	p3 = L3->next;
	while (p3->next) {
		printf("%05d %d %05d\n", p3->address, p3->data, p3->next->address);//������λ����0��ȫ 
		p3 = p3->next;
	}
	printf("%05d %d -1\n", p3->address, p3->data);
	return 0;
}