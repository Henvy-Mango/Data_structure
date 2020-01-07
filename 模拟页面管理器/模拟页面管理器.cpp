#include <cstdio>
#include <cstdlib>
#include <iostream>

#define bsize 4 //物理块大小
#define psize 16 //进程大小
typedef struct page {
	int num; //记录页面号
	int time; //记录调入内存时间
} Page;

Page b[bsize]; //内存单元数

//LRU
int queue[100]; //pro调入顺序
int K; //调入列表的个数
int c[bsize][psize]; //保存栈

int phb[bsize] = { 0 }; //物理块标号
int pro[psize] = { 0 }; //进程序列号
int flag[bsize] = { 0 }; //进程队列

int pro_no = 0, block = 0; //进程标号,物理块号
int free_block = -1, proNow = -1; //物理块空闲和进程是否相同判断标志
int max = -1, maxflag = 0; //标记替换物理块进程下标

int count = 0; //缺页次数

//随机产生序列号函数
//TODO trap
int *build() {
	printf("随机产生进程序列号：\n");
	int i = 0;
	for (i = 0; i < psize; i++) {
		pro[i] = 10 * rand() / (RAND_MAX + 1) + 1;
		printf("%d ", pro[i]);
	}
	printf("\n");
	return (pro);
}

//查找空闲物理块
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

//查找相同进程
int searchpro() {
	for (block = 0; block < bsize; block++) {
		if (phb[block] == pro[pro_no]) {
			proNow = block;
			return block;
		}
	}
	return -1;
}

//清空内存
void empty() {
	for (pro_no = 0; pro_no < bsize; pro_no++)
		phb[pro_no] = 0;
	count = 0;
}

//先进先出页面置换算法
void FIFO() {
	for (pro_no = 0; pro_no < psize; pro_no++) {
		free_block = searchpb();
		proNow = searchpro();
		//找flag值最大的
		for (block = 0; block < bsize; block++) {
			if (flag[block] > maxflag) {
				maxflag = flag[block];
				max = block;
			}
		}
		if (proNow == -1) //不存在相同进程
		{
			if (free_block != -1) //存在空闲物理块
			{
				phb[free_block] = pro[pro_no]; //进程填入空闲物理块
				count++;
				flag[free_block] = 0;
				for (block = 0; block <= free_block; block++) {
					flag[block]++;
				}
				free_block = -1;
			}
			else //不存在空闲物理块
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
		else //存在相同的进程
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
	printf("缺页次数为：%d\n", count);
	printf("缺页率为:%16.6f", (float)count / psize);
	printf("\n");
}

//初始化内存单元、缓冲区
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


//取得在内存中停留最久的页面,默认状态下为最早调入的页面
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

//查找页面
int Equation(int pro_t, Page *b) {
	int i;
	for (i = 0; i < bsize; i++) {
		if (pro_t == b[i].num)
			return i;
	}
	return -1;
}

//LRU核心部分
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
		queue[++K] = fold;//记录调入页面
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
		//记录当前的内存单元中的页面
		for (j = 0; j < bsize; j++)
			c[j][i] = b[j].num;
	}
	//结果输出
	printf("内存状态为：\n");
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
	printf("\n调入队列为:");
	for (i = 0; i < K + 1; i++)
		printf("%3d", queue[i]);
	printf("\n缺页次数为：%6d\n缺页率：%16.6f", K + 1, (float)(K + 1) / psize);
}

//主函数
int main() {
	int sel;
	do {

		printf(" \t1、产生随机序列 \n ");
		printf(" \t2、最久未使用(LRU) \n ");
		printf(" \t3、先进先出(FIFO) \n ");
		printf(" \t0、退出 \n ");
		printf("请选择所要执行的操作(0/1/2/3):");
		std::cin >> sel;
		switch (sel) {
		case 0:
			system("pause");
			break;
		case 1:
			build();
			break;
		case 2:
			printf("最久未使用\n");
			LRU();
			empty();
			printf("\n");
			break;
		case 3:
			printf("先进先出\n");
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