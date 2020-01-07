//#include <stdio.h>
//
//void Swap(int *lhs, int *rhs)
//{
//	int t = *lhs;
//
//	*lhs = *rhs;
//	*rhs = t;
//}
//
//void FullPermutation(int source[], int begin, int end)
//{
//	int i;
//
//	if (begin >= end) // 找到一个排列
//	{
//		for (i = 0; i < end; i++)
//		{
//			printf("%d-", source[i]);
//		}
//		printf("\n");
//	}
//	else// 没有找完一个排列，则继续往下找下一个元素
//	{
//		for (i = begin; i < end; i++)
//		{
//			if (begin != i)
//			{
//				Swap(&source[begin], &source[i]); // 交换
//			}
//
//			// 递归排列剩余的从begin+1到end的元素
//			FullPermutation(source, begin + 1, end);
//
//			if (begin != i)
//			{
//				Swap(&source[begin], &source[i]); // 回溯时还原
//			}
//		}
//	}
//}
//
//int main()
//{
//	int source[10000];
//	int i, count;
//
//	scanf("%d", &count);
//
//	// 初始化数组
//	for (i = 0; i < count; i++)
//	{
//		scanf("%d", &source[i]);
//	}
//
//	FullPermutation(source, 0, count);
//
//	return 0;
//}
