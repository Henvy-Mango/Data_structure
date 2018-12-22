//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status;
///*������������ڵ�*/
//typedef struct HTNode {
//	int parent;/*��¼˫��*/
//	int Lchild;/*��������*/
//	int Rchild;
//	int Weight;/*��¼Ȩ��*/
//}HTNode;
//typedef struct HTNode * HuffmanTree;
//typedef char ** HuffmanCode;
//
///*��ǰk�������ҵ�Ȩ����С����*/
//int Min(HuffmanTree HT, int k) {
//	int i = 0, min_weight = 0, min = 0;
//	/*�ҳ���һ��˫�״��ڵĽڵ㣬����Ȩֵ��ֵ��min_weight*/
//	/*ע��˴�����ֱ�ӽ�HT[0].weight����min_weight��ԭ�������HT[0].weight��С����ô�ڵ�һ�ι��������ʱ�ͻᱻѡ�ߣ���������ÿһ��ѡ����СȨֵ����������ıȽ�
//	��������HT[0].weight��ֵ�������жϣ������ֻ��ٴν���ѡ�ߣ��Ӷ������߼��ϵĴ���*/
//	while (HT[i].parent != -1)
//		i++;
//	min_weight = HT[i].Weight;
//	min = i;
//	for (i; i < k; i++) {
//		if (HT[i].Weight < min_weight&&HT[i].parent == -1) {
//			min_weight = HT[i].Weight;
//			min = i;
//		}
//	}
//	/*�ҵ���СȨ�ص���������˫����Ϊ1*/
//	/*����������ע�����HT���±꣡��������һ���ϲ��ҳ����С���⣬��д��HT[i]!!!!!!*/
//	HT[min].parent = 1;
//	return min;
//}
//
///*��ǰk������ѡ��Ȩ����С��������,������Ÿ���min1��min2*/
//Status SelectMin(HuffmanTree HT, int k, int &min1, int &min2) {
//	min1 = Min(HT, k);
//	min2 = Min(HT, k);
//	return OK;
//}
//
//
///*����һ�λ���������-1��ʾ������*/
///*wetΪһ����¼Ȩ�ص����飬����Ϊint*/
//HuffmanTree CreateHuffmanTree(HuffmanTree HT, int *wet, int n) {
//	int i = 0;
//	int total = 2 * n - 1;/*��n��������Ҫ���룬����n��Ҷ�ӽڵ㣬Ҳ����n-1����Ϊ2�Ľڵ㣬�ܽڵ���Ϊn+n-1=2*n-1*/
//	/*��ʼ״̬�£�ǰn���ڵ��˫�ף���������Ӧ�þ�Ϊ-1��Ȩ��Ϊ��Ӧ��Ȩ��*/
//	/*��HT��ǰn�������洢n����(��n����������������)��ɭ��*/
//	/*����total��int��ɵĶ�̬����*/
//
//	if (!HT)
//		return ERROR;
//	for (i = 0; i < n; i++) {//ÿ�����ݽ���
//		HT[i].Lchild = -1;
//		HT[i].parent = -1;
//		HT[i].Rchild = -1;
//		HT[i].Weight = *wet;
//		wet++;
//	}
//
//	/*��n��total�ķ������г�ʼ��*/
//	for (i; i < total; i++) {
//		HT[i].Lchild = -1;
//		HT[i].Rchild = -1;
//		HT[i].parent = -1;
//		HT[i].Weight = 0;
//	}
//	/*��HT�ĺ�n-1�������洢��������*/
//	/*���ú���SelectMin�ҳ�ɭ��������Ȩ����С����*/
//	int min1 = 0, min2 = 0;
//	for (i = n; i < total; i++) {
//		SelectMin(HT, i, min1, min2);
//		HT[min1].parent = i;
//		HT[min2].parent = i;
//		HT[i].Lchild = min1;
//		HT[i].Rchild = min2;
//		HT[i].Weight = HT[min1].Weight + HT[min2].Weight;
//	}
//	return HT;
//}
//
///*��Ҷ�ӽڵ㿪ʼ������л���������*/
///*HC�����������������ֵ*/
//Status HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n) {
//	/*HC������һ��char���������ָ��,��ָ��n��char���͵ĵ�ַ�����Ը�HC�����ڴ�Ӧ��д����������*/
//	HC = (HuffmanCode)malloc(n * sizeof(char *));
//	if (!HC)
//		return ERROR;
//	/*����һ����̬����code��������ʱ�洢����������,���麬��n-1���������룬����һ��'\0'��ֹ��������n��Ԫ�أ����Է����ڴ�ʱ*/
//	char *code;
//	code = (char *)malloc(n * sizeof(char));
//	if (!code)
//		return ERROR;
//	code[n - 1] = '\0';/*�����һ��Ԫ��Ϊ��ֹ��*/
//
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		int current = i;
//		int father = HT[i].parent;
//		int start = n - 1;
//		while (father != -1) {
//			if (current == HT[father].Lchild)
//				code[--start] = '0';
//			else
//				code[--start] = '1';
//			current = father;
//			father = HT[father].parent;
//		}
//		/*HC[i]�������մ洢�������룬��char���͵����飬��n��char���͵�����*/
//		HC[i] = (char *)malloc((n - start) * sizeof(char));
//		if (!HC[i])
//			return ERROR;
//		/*����ʱ�ռ��и��Ƶ�HC[i]��*/
//		strcpy(HC[i], code + start);
//	}
//	/*�ͷ���ʱ�洢�ռ�*/
//	free(code);
//	code = NULL;
//	return OK;
//}
//
//int main(void) {
//	int amount = 0, i = 0;
//	int *wet = (int *)malloc(amount * sizeof(int));
//	printf("Please input n:\n");
//	scanf("%d", &amount);
//	for (i = 0; i < amount; i++)
//		scanf("%d", wet + i);
//	HuffmanTree HT;
//	int total = 2 * amount - 1;
//	HT = (HuffmanTree)malloc(total * sizeof(HTNode));
//	HT = CreateHuffmanTree(HT, wet, amount);
//
//	HuffmanCode HC;
//	HuffmanCoding(HT, HC, amount);
//	printf("Huffman codes are : ");
//	for (i = 0; i < amount; i++)
//		printf("%s ", HC[i]);
//	return OK;
//}