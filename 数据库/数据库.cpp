#include "���ݿ�.hpp"

int main()
{

	//����ϵͳ
	int Password = 666;
	printf("������ȷ��������������\n");
	printf("��ȷ����Ϊ666\n");
	for (int i = 0; i < 3; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp != Password)
		{
			printf("����!\n");
				//���������
				if (i == 2)
				{
					printf("��������ﵽ���Σ������Զ��˳�\n");
					system("pause");
					//�˳�����
					return -1;
				}
		}
		else
			break;
	}
	printf("������ȷ!\n");

	//�˵�
	Menu();
	system("pause");
	return 0;
}
