#include <cstdio>
#include <cstdlib>
#include <iostream>

#define bsize 4 //������С
#define psize 16 //���̴�С
typedef struct page {
	int num; //��¼ҳ���
	int time; //��¼�����ڴ�ʱ��
} Page;

Page b[bsize]; //�ڴ浥Ԫ��

//LRU
int queue[100]; //pro����˳��
int K; //�����б�ĸ���
int c[bsize][psize]; //����ջ

int phb[bsize] = { 0 }; //�������
int pro[psize] = { 0 }; //�������к�
int flag[bsize] = { 0 }; //���̶���

int pro_no = 0, block = 0; //���̱��,������
int free_block = -1, proNow = -1; //�������кͽ����Ƿ���ͬ�жϱ�־
int max = -1, maxflag = 0; //����滻���������±�

int count = 0; //ȱҳ����

//����������кź���
//TODO trap
int *build() {
	printf("��������������кţ�\n");
	int i = 0;
	for (i = 0; i < psize; i++) {
		pro[i] = 10 * rand() / (RAND_MAX + 1) + 1;
		printf("%d ", pro[i]);
	}
	printf("\n");
	return (pro);
}

//���ҿ��������
int searchpb() {
	for (block = 0; block < bsize; block++) {
		if (phb[block] == 0) {
			free_block = block;
			return free_block;
			//            break;
		}
	}
	return -1;
}

//������ͬ����
int searchpro() {
	for (block = 0; block < bsize; block++) {
		if (phb[block] == pro[pro_no]) {
			proNow = block;
			return block;
		}
	}
	return -1;
}

//����ڴ�
void empty() {
	for (pro_no = 0; pro_no < bsize; pro_no++)
		phb[pro_no] = 0;
	count = 0;
}

//�Ƚ��ȳ�ҳ���û��㷨
void FIFO() {
	for (pro_no = 0; pro_no < psize; pro_no++) {
		free_block = searchpb();
		proNow = searchpro();
		//��flagֵ����
		for (block = 0; block < bsize; block++) {
			if (flag[block] > maxflag) {
				maxflag = flag[block];
				max = block;
			}
		}
		if (proNow == -1) //��������ͬ����
		{
			if (free_block != -1) //���ڿ��������
			{
				phb[free_block] = pro[pro_no]; //����������������
				count++;
				flag[free_block] = 0;
				for (block = 0; block <= free_block; block++) {
					flag[block]++;
				}
				free_block = -1;
			}
			else //�����ڿ��������
			{
				phb[max] = pro[pro_no];
				flag[max] = 0;
				for (block = 0; block < bsize; block++) {
					flag[block]++;
				}
				max = -1;
				maxflag = 0;
				count++;
			}
		}
		else //������ͬ�Ľ���
		{
			phb[proNow] = pro[pro_no];
			for (block = 0; block < bsize; block++) {
				flag[block]++;
			}
			proNow = -1;
		}
		for (block = 0; block < bsize; block++) {
			printf("%d ", phb[block]);
		}
		printf("\n");
	}
	printf("ȱҳ����Ϊ��%d\n", count);
	printf("ȱҳ��Ϊ:%16.6f", (float)count / psize);
	printf("\n");
}

//��ʼ���ڴ浥Ԫ��������
void Init(Page *b, int c[bsize][psize]) {
	int i, j;
	for (i = 0; i < psize; i++) {
		b[i].num = -1;
		b[i].time = psize - i - 1;
	}
	for (i = 0; i < bsize; i++)
		for (j = 0; j < psize; j++)
			c[i][j] = -1;
}


//ȡ�����ڴ���ͣ����õ�ҳ��,Ĭ��״̬��Ϊ��������ҳ��
int GetMax(Page *b) {
	int i;
	int max = -1;
	int tag = 0;
	for (i = 0; i < bsize; i++) {
		if (b[i].time > max) {
			max = b[i].time;
			tag = i;
		}
	}
	return tag;
}

//����ҳ��
int Equation(int pro_t, Page *b) {
	int i;
	for (i = 0; i < bsize; i++) {
		if (pro_t == b[i].num)
			return i;
	}
	return -1;
}

//LRU���Ĳ���
void Lruu(int fold, Page *b) {
	int i;
	int val;
	val = Equation(fold, b);
	if (val >= 0) {
		b[val].time = 0;
		for (i = 0; i < bsize; i++)
			if (i != val)
				b[i].time++;
	}
	else {
		queue[++K] = fold;//��¼����ҳ��
		val = GetMax(b);
		b[val].num = fold;
		b[val].time = 0;
		for (i = 0; i < bsize; i++)
			if (i != val)
				b[i].time++;
	}
}

void LRU() {
	int i, j;
	K = -1;
	Init(b, c);
	for (i = 0; i < psize; i++) {
		Lruu(pro[i], b);
		c[0][i] = pro[i];
		//��¼��ǰ���ڴ浥Ԫ�е�ҳ��
		for (j = 0; j < bsize; j++)
			c[j][i] = b[j].num;
	}
	//������
	printf("�ڴ�״̬Ϊ��\n");
	for (j = 0; j < psize; j++)
		printf("|%2d ", pro[j]);
	printf("|\n\n");
	for (i = 0; i < bsize; i++) {
		for (j = 0; j < psize; j++) {
			if (c[i][j] == -1)
				printf("|%2c ", 32);
			else
				printf("|%2d ", c[i][j]);
		}
		printf("|\n");
	}
	printf("\n�������Ϊ:");
	for (i = 0; i < K + 1; i++)
		printf("%3d", queue[i]);
	printf("\nȱҳ����Ϊ��%6d\nȱҳ�ʣ�%16.6f", K + 1, (float)(K + 1) / psize);
}

//������
int main() {
	int sel;
	do {

		printf(" \t1������������� \n ");
		printf(" \t2�����δʹ��(LRU) \n ");
		printf(" \t3���Ƚ��ȳ�(FIFO) \n ");
		printf(" \t0���˳� \n ");
		printf("��ѡ����Ҫִ�еĲ���(0/1/2/3):");
		std::cin >> sel;
		switch (sel) {
		case 0:
			system("pause");
			break;
		case 1:
			build();
			break;
		case 2:
			printf("���δʹ��\n");
			LRU();
			empty();
			printf("\n");
			break;
		case 3:
			printf("�Ƚ��ȳ�\n");
			FIFO();
			empty();
			printf("\n");
			break;
		default:
			printf("Check your input!!!");
			printf("\n\n");
			break;
		}
	} while (sel != 0);
	return 0;
}