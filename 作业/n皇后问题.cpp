//#include <stdio.h>
//
//// C������ʾ�У�ֵ��ʾ��
//// tot��ʾ��ĸ���
//int C[50], tot = 0, n = 8;
//
//void search(int cur) {
//	int i, j;
//	if (cur == n) {
//		for (i = 0; i < n; i++)
//			for (j = i + 1; j < n; j++)
//				if (C[i] == C[j] || i - C[i] == j - C[j] || i + C[i] == j + C[j]) return;
//		tot++;
//		// �����ȷ���
//		for (int m = 0; m < n; m++) {
//			printf("%d-", C[m]+1);
//		}
//		printf("\n");
//	}
//	else for (i = 0; i < n; i++) {
//		C[cur] = i;
//		search(cur + 1);
//	}
//}
//
//int main() {
//	scanf("%d", &n);
//	search(0);
//	printf("Total: %d solutions.", tot);
//	return 0;
//}