
#include "menu.h"


void TP_menu()
{
	while (1)
	{

		int tp_menu;
		printf("1. �� �� ����\n");
		printf("2. ª�� �� ����\n");
		printf("3. Ÿ�� ���� ����\n");
		printf("4. ���� �޴���\n");
		tp_menu = _getch();

		switch (tp_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("�� �� ���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;
				}
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("ª�� �� ���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}
		case '3':
		{
			while (1)
			{
				system("cls");
				printf("���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}

		case'4':
			system("cls");
			return;
		default:
			system("cls");
			break;
			
		}


	}
}
void CP_menu()
{
	while (1)
	{

		int cp_menu;
		printf("1. C ����\n");
		printf("2. C++ ����\n");
		printf("3. Ÿ�� ���� ����\n");
		printf("4. ���� �޴���\n");
		cp_menu = _getch();

		switch (cp_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("C ���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("C++ ���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}
		case '3':
		{
			while (1)
			{
				system("cls");
				printf("���� ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}

		case'4':
			system("cls");
			return;
		default:
			system("cls");
			break;
		}


	}



}

void rank_menu()
{
	while (1)
	{

		int rank_menu;
		printf("1. �Ϲ� ��ŷ\n");
		printf("2. �ڵ� ��ŷ\n");
		printf("3. ���� �޴���\n");
		rank_menu = _getch();

		switch (rank_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("�Ϲ� ��ŷ ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("�ڵ� ��ŷ ����\n");
				printf("esc�� ������ ���� �޴��� ���ư��ϴ�\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					system("Cls");
					continue;

				}
			}
		}
		case '3':
			system("cls");
			return;
		default:
			system("cls");
			break;


		}


	}
}
