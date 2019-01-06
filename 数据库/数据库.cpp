#include "数据库.hpp"

int main()
{

	//口令系统
	int Password = 666;
	printf("输入正确口令来继续操作\n");
	printf("正确口令为666\n");
	for (int i = 0; i < 3; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp != Password)
		{
			printf("错误!\n");
				//检查错误次数
				if (i == 2)
				{
					printf("错误次数达到三次，程序自动退出\n");
					system("pause");
					//退出程序
					return -1;
				}
		}
		else
			break;
	}
	printf("口令正确!\n");

	//菜单
	Menu();
	system("pause");
	return 0;
}
