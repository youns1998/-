
#include "typing_game4ver.h"


int startgame()
{
	
	srand((unsigned)time(NULL));
	system("mode con cols=120 lines=30"); //�ܼ� ũ�⸦ ���� ���� 120 ���� 30
	_MainDesign(); //������ ȭ���� ����
	gotoxy(60, 9); //Ŀ�� ��ġ ���� �Լ�
	_RemoveCursor(); //ȭ�鿡 �ߴ� ����Ʈ�� Ŀ���� �����ִ��Լ�
	_GameMenu();
	
	while (1) 
	{
		system("cls");
		_GameMenu();
		gotoxy(45, 18);
		printf("���ø޴� : ");
		gotoxy(58, 18);
		scanf("%d", &menu_num);
		gotoxy(58, 18);
		switch (menu_num)
		{
		case 1: 
			_score = 0; //���� �ʱ�ȭ
			_startTime = clock();
			_GameMain();
			time_gap = 0;//������ ������ �ð����̸� �ٽ� �ʱ�ȭ
			break;

		case 2: 
			_Help();
			break;
		
		case 3: 
			_Best();
			break;
		
		case 4: 
			return 0; 
			break;
		
		default:
			gotoxy(45, 19);
			printf("�ùٸ� Ű�� �ƴմϴ�!");
			break;
		}
	}
}



void _GameDesign() //����ȭ�� ������
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|-----------------------------8bibim8bibim8bibim---------------------------8bibim8bibim8bibim-------------------------|\n");
	printf("|                          8bibim            8bibim                    8bibim            8bibim                       |\n");
	printf("|                                     ��                                          ��                                  |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                  8bibim       8bibim                                                |\n");
	printf("|                                             8bibim      8bibim      8bibim                                          |\n");
	printf("|                                                   8bibim      8bibim                                                |\n");
	printf("|---------------------------------------------------------8bibim------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|");
}

void _MainDesign() //����ȭ�� ������
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|--------------------------------------------------typing game--------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|");
}

void _Help()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls"); // â ��ü�� ������ �����
	_MainDesign();
	gotoxy(30, 7);
	printf("8bibim���� �󱼿� ������ �ܾ� ���帧�� Ÿ������ �����ּ���!\n");
	gotoxy(30, 9);
	printf("������ ���� ������ �ٸ��ϴ�!");
	gotoxy(30, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("�� �� : 150�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("�� �� : 200�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("�� �� : 250�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("�� �� : 300�� ");
	gotoxy(30, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("30�� ���� ������ ����˴ϴ�!! ������ �ڵ����� ����˴ϴ�.");
	gotoxy(30, 15);
	printf("�ְ������� ����˴ϴ�. ���θ޴��� '3. ��������'���� Ȯ�� �����մϴ�.\n");
	gotoxy(30, 17);
	printf("�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	
	eveything_get = getch();
	if (_kbhit)
	{
		_GameMenu();
	}
}

void _Best()
{
	system("cls");
	_MainDesign();
	
	if (best_score < _score)
	{
		best_score = _score;
	}
	
	gotoxy(50, 7);
	printf("�ְ����� : %d", best_score);
	gotoxy(40, 13);
	printf("�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	eveything_get = getch();

	if (_kbhit)
	{
		_GameMenu();
	}
}

void _GameMain()
{
	system("cls");
	_MainDesign();
	gotoxy(50, 9);
	printf(" �غ� �ϼ̳���??");
	Sleep(1000);

	system("cls");
	_MainDesign();
	gotoxy(50, 9);
	printf(" 3�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	_MainDesign();
	gotoxy(50, 9);
	printf(" 2�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	_MainDesign();
	gotoxy(50, 9);
	printf(" 1�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	_GameDesign();

	for (int i = 0; i < 120; i++)
		for (int j = 0; j < 30; j++)
			check_position[i][j] = 0;

	for (int i = 0; i < 200; i++)
		check_word[i] = 0;

	game_set = 0;
	while (1) 
	{
		_PrintWord();
		_SearchWord();

		if (game_set == 1)
			break;
	}
}

void _PrintWord()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(3, 2);
	printf("�������� : %d", _score);
	gotoxy(3, 3);
	printf("�����ð� : %d", 34 - time_gap);
	
	_x = rand() % 80 + 18;//��ġ _x�� �������� ����
	_y = rand() % 15 + 5;//��ġ _y�� �������� ����
	_color = rand() % 4 + 1;//������ �������� ����
	word_num = rand() % wordmax; //�������� �ܾ �����ϱ� ���� �ܾ��ȣ ����

	if (check_position[_x][_y] != 1)//�ܾ ��ġ�� �ʱ����� ���� �ܾ� ��ġ �ֺ����� �ٽ� ������ �ʰ� �Ѵ�
	{
		for (check_x = _x ; check_x < _x + 5; check_x++)
		{
			for (check_y = _y ; check_y < _y + 5; check_y++)
			{
				check_position[check_x][check_y] = 1;
			}
		}

		for (check_x = _x; check_x > _x - 5; check_x--)
		{
			for (check_y = _y ; check_y > _y - 5; check_y--)
			{
				check_position[check_x][check_y] = 1;
			}
		}
		if (check_word[word_num] != 1) //�ܾ �ݺ��ؼ� ������ �ʵ��� �Ѵ�.
		{
			check_word[word_num] = 1;//���� �ܾ�� üũ

			for (int i = 0; i < 3; i++)//�������� ��ġ,���������� �Է¹޴´�
			{
				if (i == 0)
				{
					word_data[word_num][i] = _x;
				}
				else if (i == 1)
				{
					word_data[word_num][i] = _y;
				}
				else if (i == 2)
				{
					word_data[word_num][i] = _color;
				}
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
			gotoxy(_x, _y);//������ġ�� �̵�
			printf("%s ", _word[word_num]);//_word�迭�� word_num��° �ܾ ���
		}
	}
}

void _SearchWord()
{
	int time_count = 0;
	int typing_char;//�Է¹��� ���ĺ��� ����
	
	while (time_count < wordspeed)//�ܾ�ӵ��� ���� _SearchWord�Լ��� ������ �ð��� ����
	{
		time_count++;
		_endTime = clock();
		time_gap = (float)(_endTime - _startTime) / (CLOCKS_PER_SEC); //���α׷� ���࿡ �ҿ�� �ð��� �ʴ����� ��ȯ

		if (time_gap > 34) // ���ӽð��� 30�ʰ� ������ ����
		{
			system("cls");
			_MainDesign();
			gotoxy(50, 11);
			printf("������ �������ϴ�!");
			Sleep(2000);
			game_set = 1;
			break;
		}
		
		if (_kbhit()) //Ű���尡 ����������
		{
			typing_char = getch();//���⼭ ���ĺ� �ϳ��� �Է¹޾� typing_char�� ����
			if (typing_char != 8 && typing_char != 13) //�齺���̽��� ����Ű�� �ƴϸ�, �� ���ĺ��� �Է��ϸ�
			{
				typing_word[sword++] = typing_char; //typing_word(�ܾ�)�� �Է¹��� ���ĺ� ����
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word); //�Է��ϴ� �ܾ ���
			}

			else if (typing_char == 8)//�齺���̽��� �Է¹�����
			{
				gotoxy(1, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("|                                                                                                                     |\n");//�ϴ� �Է����� �� �����
				typing_word[--sword] = typing_char; //���� �Է��ߴ� ���ĺ��� �����
				if (sword == -1) //���ʿ� �迭�� �Է¹��� ���ĺ��� ��������
					sword = 0; //�ٽ� 0���� �����ش�
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word);//ȭ�鿡�� �齺���̽��� �� �ܾ ���
			}
			
			else if (typing_char == 13) //���Ͱ��� �Է� �޾����� �ܾ� �� ����
			{
				sword = 0;
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");//�ϴ� �Է����� �� �����ش�
				for (int i = 0; i <= wordmax; i++)
				{
					if (strcmp(typing_word, _word[i]) == 0)//�ܾ ��ġ�ϴ°� ������
					{
						x2 = word_data[i][0];//�� �ܾ��� _x��ġ�� �޴´�
						y2 = word_data[i][1];//�� �ܾ��� _y��ġ�� �޴´�
						color2 = word_data[i][2];//�� �ܾ��� ���� ������ �޴´�
						gotoxy(x2, y2);
						printf("          ");//����Ʈ�� ��ġ�� �ܾ �����
				
						switch (color2)
						{
						case 1: //�Ķ�
							_score += 150; 
							break;

						case 2: //�ʷ�
							_score += 200; 
							break;
						
						case 3: //�ϴ�
							_score += 250; 
							break;
						
						case 4: //����
							_score += 300; 
							break;
						
						default: 
							break;
						}
						gotoxy(3, 2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("�������� : %d", _score);
					}
				}
				
				for (int i = 0; i < 50; i++) 
				{
					typing_word[i] = NULL; //Ÿ������ �ܾ �ٽ� �ʱ�ȭ ���ش�
				}
			}
		}
	}
}

void _GameMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	_MainDesign();
	
	gotoxy(50, 8);
	printf(" 1. ���ӽ���");
	gotoxy(50, 10);
	printf(" 2. ����");
	gotoxy(50, 12);
	printf(" 3. ���� ����");
	gotoxy(50, 14);
	printf(" 4. ���� ����");
	gotoxy(50, 16);
	printf("  Ű�� ��������");
}

void _RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //CONSOLE_CURSOR_INFO Ÿ�� ���� curInfo ==> struct Ÿ��
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //GetConsoleCursorInfo() ==> ���ڷ� �ڵ鰪�� �Ѱ��ش�. (�ڵ鰪 ��� �Լ�: GetStdHandle())
	curInfo.bVisible = 0; //curInfo�� struct �̹Ƿ� bVisible ���� �ٲ��ش�. (1�� ���̰�, 0�� �Ⱥ��δ�.)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //SetConsoleCursorInfo() ==> ����� ���� Set ���ش�.
}