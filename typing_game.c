#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define wordmax 100//�ܾ��� ����
#define wordtime 30000//�ܾ �ߴ� �ӵ�

time_t startTime = 0, endTime = 0;// ���� �ð� ����
int time_gap;

void gotoxy(int x, int y);//Ŀ�� ��ġ ���� �Լ�
void help();// ����
void gamemain();// ���Ӹ���
void printword();//�ܾ�߰� ���ִ� �Լ�
void search_word();//�ܾ �Է� �޴� �Լ�
void game_design();//���� ������
void game_menu();//���� ���� �ʱ� ȭ��
void best();//�ְ�����
void removeCursor();// printf���� �ܾ �߰��Ҷ� Ŀ�� ����
void main_design();//���� ������

char word[200][200] = { "printf", "scanf", "int", "float", "double", "%d", "%f", "%lf", "return", ";", "&", "main", "#include",//�ܾ� DB
"void", "#define", "stdio.h", "stdlib.h", "unsigned", "malloc", "free", "char", "if", "switch", "else", "break", "default", "while", "for", "++",
"--", "&&", "||", "NULL", "class", "cin", "cout", "endl", "new", "delete", "[]", "*", "=", "()", "time", "string", "strcmp", "getline", "gets", 
"sizeof", "temp", "extern", "register", "struct", "static", "goto", "do", "enum", "auto", "case", "const", "continue", "signed", "short", "friend", 
"public", "using","bool", "private", "true", "false", "typename", "union", "template", "protected", "clear", "time.h", "windows.h", "conio.h", 
"%s", "%c", "!=", "==", ">=", "<=", ">", "<", "iostream", "swap", "inline", "namespace", "ignore", "-", "+", "/", "%", "//", "/**/", ".", "->", "char" };

int check_word[200];//�� ���� �ܾ���� �ȶ߰� ���ֱ� ���� ������
char typing_word[50];//Ÿ������ �ܾ�
char word_data[256][3] = { 0 };//�ܾ� ����
int menu_num;//�ʱ�ȭ�鿡�� �Է� ������ ����
int x, y;// gotoxy �� x���� y��
int x2, y2;// x,y���� �ٽ� �ҷ��� �� ����
int color;// ����
int color2;// ���� ���� �ٽ� �ҷ��ö� ����
int eveything_get;
int score;//����
int best_score = 0;
int word_num;//�ܾ��
int sword = 0;

int main() ////////////////////�Ϻ�
{
	srand((unsigned)time(NULL));
	system("mode con cols=120 lines=30"); //�ܼ� ũ�⸦ ���� ���� 120 ���� 30
	main_design(); //������ ȭ���� ����
	//Sleep(1500); //1.5�ʰ� ����
	gotoxy(60, 9); //Ŀ�� ��ġ ���� �Լ�
	removeCursor(); //ȭ�鿡 �ߴ� ����Ʈ�� Ŀ���� �����ִ��Լ�
	game_menu();
	
	while (1) 
	{
		gotoxy(45, 18);
		printf("���ø޴� : ");
		gotoxy(58, 18);
		scanf("%d", &menu_num);
		gotoxy(58, 18);
		switch (menu_num)
		{
		case 1: 
			score = 0; //���� �ʱ�ȭ
			startTime = clock();
			gamemain(); 
			time_gap = 0;//�ð����̸� �ٽ� �ʱ�ȭ
			break;

		case 2: 
			help(); 
			break;
		
		case 3: 
			best(); 
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


void gotoxy(int x, int y)//Ŀ�� ��ġ ���� �Լ�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_design() {
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

void main_design() {
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

void help() 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls"); // â ��ü�� ������ �����
	main_design();
	gotoxy(30, 7);
	printf("-8bibim���� �󱼿� ������ �ܾ� ���帧�� Ÿ�ڷ� �Է��� �����ּ���!\n");
	gotoxy(30, 9);
	printf("-������ ���� ������ �ٸ��ϴ�!");
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
	printf("-30�� ���� ������ ����˴ϴ�!! ������ �ڵ����� ����˴ϴ�.");
	gotoxy(30, 15);
	printf("-�ְ������� ����˴ϴ�. ���θ޴��� '3. ��������'���� Ȯ�� �����մϴ�.\n");
	gotoxy(30, 17);
	printf("-�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	eveything_get = getch();
	if (_kbhit)
	{
		//game_menu();
		main();
	}
}

void best() 
{
	system("cls");
	main_design();
	
	if (best_score < score)
	{
		best_score = score;
	}
	
	gotoxy(50, 7);
	printf("�ְ����� : %d", best_score);
	gotoxy(40, 13);
	printf("�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	eveything_get = getch();

	if (_kbhit)
	{
		game_menu();
	}
}

void gamemain() 
{
	system("cls");
	main_design();
	gotoxy(50, 9);
	printf("�غ� �ϼ̳���??");
	Sleep(1000);

	system("cls");
	main_design();
	gotoxy(50, 9);
	printf(" 3�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	main_design();
	gotoxy(50, 9);
	printf(" 2�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	main_design();
	gotoxy(50, 9);
	printf(" 1�� �� �����մϴ�");
	Sleep(1000);
	
	system("cls");
	game_design();
	
	while (1) 
	{
		printword();
		search_word();
	}
}

void printword() 
{
	gotoxy(3, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("�������� :%d", score);
	
	static int check = wordmax;/////////////////////////////////////�����뵵? �� ������ ��� �ݺ�����??

	x = rand() % 105 + 5;//��ġ x�� �������� ����
	y = rand() % 19 + 3;//��ġ y�� �������� ����
	color = rand() % 4 + 1;//������ �������� ����
	word_num = rand() % wordmax;

	if (check_word[word_num] != 1) //�ܾ �ݺ��ؼ� ������ �ʵ��� �Ѵ�.
	{
		check_word[word_num] = 1;
		check--;
		gotoxy(x, y);
		
		for (int i = 0; i < 3; i++)//�������� ��ġ,���������� �Է¹޴´� ////////////////////i
		{
			if (i == 0) 
			{
				word_data[word_num][i] = x;
			}
			else if (i == 1) 
			{
				word_data[word_num][i] = y;
			}
			else if (i == 2) 
			{
				word_data[word_num][i] = color;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		printf("%s ", word[word_num]);//word�迭�� word_num��° �ܾ ���
	}
}

void search_word()
{
	int time_count = 0;
	
	while (time_count < wordtime)
	{
		time_count++;
		word_num = 0;

		int typing_char;
		endTime = clock();
		time_gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //���α׷� ���࿡ �ҿ�� �ð��� �ʴ����� ��ȯ

		if (time_gap > 30) // ���ӽð��� 30�ʰ� ������ ����
		{
			system("cls");
			main_design();
			gotoxy(50, 11);
			printf("������ �������ϴ�!");
			Sleep(2000);
			main();
		}
		
		if (_kbhit()) //Ű���ٰ� ����������
		{
			typing_char = getch();//���⼭ ���ĺ� �ϳ��� �Է¹޾� typing_char�� ����
			if (typing_char != 8 && typing_char != 13) //�齺���̽��� ����Ű�� �ƴϸ�, �� ���ĺ��� �Է��ϸ�
			{
				gotoxy(5, 25);
				typing_word[sword++] = typing_char; //typing_word(�ܾ�)�� �Է¹��� ���ĺ� ����
				//printf("                 ");
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word); //�Է��ϴ� �ܾ ���
			}

			else if (typing_char == 8)//�齺���̽��� �Է¹�����
			{
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");
				gotoxy(5, 25);
				typing_word[--sword] = typing_char; //���� �Է��ߴ� ���ĺ��� �����
				if (sword == -1) //���ʿ� �迭�� �Է¹��� ���ĺ��� ��������
					sword = 0; //�ٽ� 0���� �����ش�
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word);//ȭ�鿡�� �齺���̽��� ����
			}
			else if (typing_char == 13) //���Ͱ��� �Է� �޾�����
			{//�ܾ� �� ����
				sword = 0;
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");//������ ������ �����ش�
				for (int i = 0; i <= wordmax; i++)
				{
					if (strcmp(typing_word, word[i]) == 0)//�ܾ ��ġ�Ѵٸ�
					{
						x2 = word_data[i][0];
						y2 = word_data[i][1];
						color2 = word_data[i][2];
						gotoxy(x2, y2);
						printf("          ");//����Ʈ�� ��ġ�� �ܾ �����
						gotoxy(1, 25);
						//printf("|                                                                                                                     |\n");
						switch (color2)
						{
						case 1: //�Ķ�
							score += 150; 
							break;

						case 2: //�ʷ�
							score += 200; 
							break;
						
						case 3: //�ϴ�
							score += 250; 
							break;
						
						case 4: //����
							score += 300; 
							break;
						
						default: 
							break;
						}
						gotoxy(3, 2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("�������� :%d", score);
					}
				}
				
				for (int i = 0; i < 50; i++) 
				{
					typing_word[i] = NULL; //�ٽ� �ʱ�ȭ ���ش�
				}
			}
		}
	}
}

void game_menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	
	main_design();
	
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

void removeCursor() ///////////////////////////////////////////////////////�Ϻ�
{
	CONSOLE_CURSOR_INFO curInfo; //CONSOLE_CURSOR_INFO Ÿ�� ���� curInfo ==> struct Ÿ��
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //GetConsoleCursorInfo() ==> ���ڷ� �ڵ鰪�� �Ѱ��ش�. (�ڵ鰪 ��� �Լ�: GetStdHandle())
	curInfo.bVisible = 0; //curInfo�� struct �̹Ƿ� bVisible ���� �ٲ��ش�. (1�� ���̰�, 0�� �Ⱥ��δ�.)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //SetConsoleCursorInfo() ==> ����� ���� Set ���ش�.
}