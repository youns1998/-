#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define wordmax 100//단어의 개수
#define wordspeed 30000//단어가 뜨는 속도

void gotoxy(int x, int y);//커서 위치 조정
void Help();// 도움말
void GameMain();// 게임메인
void PrintWord();//단어뜨게 해주는 함수
void SearchWord();//단어를 입력 받고 비교
void GameDesign();//게임 디자인
void GameMenu();//게임 시작 초기 화면
void Best();//최고점수
void RemoveCursor();// printf에서 단어를 뜨게할때 커서 제거
void MainDesign();//메인 디자인

char word[200][200] = { "printf", "scanf", "int", "float", "double", "%d", "%f", "%lf", "return", ";", "&", "main", "#include",//단어
"void", "#define", "stdio.h", "stdlib.h", "unsigned", "malloc", "free", "char", "if", "switch", "else", "break", "default", "while", "for", "++",
"--", "&&", "||", "NULL", "class", "cin", "cout", "endl", "new", "delete", "[]", "*", "=", "()", "time", "string", "strcmp", "getline", "gets", 
"sizeof", "temp", "extern", "register", "struct", "static", "goto", "do", "enum", "auto", "case", "const", "continue", "signed", "short", "friend", 
"public", "using","bool", "private", "true", "false", "typename", "union", "template", "protected", "clear", "time.h", "windows.h", "conio.h", 
"%s", "%c", "!=", "==", ">=", "<=", ">", "<", "iostream", "swap", "inline", "namespace", "ignore", "-", "+", "/", "%", "//", "/**/", ".", "->", "char" };
time_t startTime = 0, endTime = 0;//게임의 시간제한을 위해서
int time_gap;//시작시간과 시간차이
int check_word[200];//한 번뜬 단어들은 안뜨게 해주기 위해서
char typing_word[50];//타이핑한 단어
char word_data[200][3] = { 0 };//단어 정보
int menu_num;//초기화면에서 입력 받을때 변수
int x, y;// gotoxy 의 x값과 y값
int color;// 색깔
int x2, y2;// x,y값을 다시 불러올 때 변수
int color2;// 색깔 값을 다시 불러올때 변수
int eveything_get; //아무키나 입력받을때 변수
int score = 0;//점수
int best_score = 0;//최고점
int word_num;//단어수
int sword = 0;

int main()
{
	srand((unsigned)time(NULL));
	system("mode con cols=120 lines=30"); //콘솔 크기를 지정 가로 120 세로 30
	MainDesign(); //디자인 화면을 띄운다
	gotoxy(60, 9); //커서 위치 조정 함수
	RemoveCursor(); //화면에 뜨는 프린트의 커서를 지워주는함수
	GameMenu();
	
	while (1) 
	{
		gotoxy(45, 18);
		printf("선택메뉴 : ");
		gotoxy(58, 18);
		scanf("%d", &menu_num);
		gotoxy(58, 18);
		switch (menu_num)
		{
		case 1: 
			score = 0; //점수 초기화
			startTime = clock();
			GameMain();
			time_gap = 0;//게임이 끝나면 시간차이를 다시 초기화
			break;

		case 2: 
			Help();
			break;
		
		case 3: 
			Best();
			break;
		
		case 4: 
			return 0; 
			break;
		
		default:
			gotoxy(45, 19);
			printf("올바른 키가 아닙니다!");
			break;
		}
	}
}

void gotoxy(int x, int y)//커서 위치 조정 함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GameDesign() //게임화면 디자인
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|-----------------------------8bibim8bibim8bibim---------------------------8bibim8bibim8bibim-------------------------|\n");
	printf("|                          8bibim            8bibim                    8bibim            8bibim                       |\n");
	printf("|                                     ○                                          ○                                  |\n");
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

void MainDesign() //메인화면 디자인
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

void Help()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls"); // 창 전체를 깨끗히 지운다
	MainDesign();
	gotoxy(30, 7);
	printf("8bibim몬스터 얼굴에 나오는 단어 여드름을 타이핑해 지워주세요!\n");
	gotoxy(30, 9);
	printf("색마다 점수 배점이 다릅니다!");
	gotoxy(30, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("파 랑 : 150점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("초 록 : 200점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("하 늘 : 250점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("빨 강 : 300점 ");
	gotoxy(30, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("30초 동안 게임이 진행됩니다!! 끝나면 자동으로 종료됩니다.");
	gotoxy(30, 15);
	printf("최고점수가 저장됩니다. 메인메뉴의 '3. 점수보기'에서 확인 가능합니다.\n");
	gotoxy(30, 17);
	printf("아무키나 누르면 메인 메뉴로 돌아갑니다.\n");
	
	eveything_get = getch();
	if (_kbhit)
	{
		GameMenu();
	}
}

void Best()
{
	system("cls");
	MainDesign();
	
	if (best_score < score)
	{
		best_score = score;
	}
	
	gotoxy(50, 7);
	printf("최고점수 : %d", best_score);
	gotoxy(40, 13);
	printf("아무키나 누르면 메인 메뉴로 돌아갑니다.\n");
	eveything_get = getch();

	if (_kbhit)
	{
		GameMenu();
	}
}

void GameMain()
{
	system("cls");
	MainDesign();
	gotoxy(50, 9);
	printf(" 준비 하셨나요??");
	Sleep(1000);

	system("cls");
	MainDesign();
	gotoxy(50, 9);
	printf(" 3초 후 시작합니다");
	Sleep(1000);
	
	system("cls");
	MainDesign();
	gotoxy(50, 9);
	printf(" 2초 후 시작합니다");
	Sleep(1000);
	
	system("cls");
	MainDesign();
	gotoxy(50, 9);
	printf(" 1초 후 시작합니다");
	Sleep(1000);
	
	system("cls");
	GameDesign();
	
	while (1) 
	{
		PrintWord();
		SearchWord();
	}
}

void PrintWord()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(3, 2);
	printf("현재점수 : %d", score);
	gotoxy(3, 3);
	printf("남은시간 : %d", 34 - time_gap);
	
	x = rand() % 105 + 5;//위치 x를 랜덤으로 생성
	y = rand() % 19 + 3;//위치 y를 랜덤으로 생성
	color = rand() % 4 + 1;//색깔을 랜덤으로 생성
	word_num = rand() % wordmax; //랜덤으로 단어를 생성하기 위한 단어번호 생성

	if (check_word[word_num] != 1) //단어가 반복해서 나오지 않도록 한다.
	{
		check_word[word_num] = 1;//나온 단어는 체크
		
		for (int i = 0; i < 3; i++)//데이터의 위치,색깔정보를 입력받는다
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
		gotoxy(x, y);//랜덤위치로 이동
		printf("%s ", word[word_num]);//word배열의 word_num번째 단어를 출력
	}
}

void SearchWord()
{
	int time_count = 0;
	int typing_char;//입력받을 알파벳을 저장
	
	while (time_count < wordspeed)//단어속도를 조절 SearchWord함수가 끝나는 시간을 조절
	{
		time_count++;
		endTime = clock();
		time_gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //프로그램 수행에 소요된 시간을 초단위로 반환

		if (time_gap > 30) // 게임시간이 30초가 지나면 종료
		{
			system("cls");
			MainDesign();
			gotoxy(50, 11);
			printf("게임이 끝났습니다!");
			Sleep(2000);
			main();
		}
		
		if (_kbhit()) //키보드가 눌러졌을때
		{
			typing_char = getch();//여기서 알파벳 하나를 입력받아 typing_char에 저장
			if (typing_char != 8 && typing_char != 13) //백스페이스나 엔터키가 아니면, 즉 알파벳을 입력하면
			{
				typing_word[sword++] = typing_char; //typing_word(단어)에 입력받은 알파벳 저장
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word); //입력하는 단어를 출력
			}

			else if (typing_char == 8)//백스페이스를 입력받으면
			{
				gotoxy(1, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("|                                                                                                                     |\n");//일단 입력줄을 다 지운다
				typing_word[--sword] = typing_char; //전에 입력했던 알파벳을 지운다
				if (sword == -1) //애초에 배열에 입력받은 알파벳이 없었을때
					sword = 0; //다시 0으로 고쳐준다
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", typing_word);//화면에도 백스페이스를 한 단어를 출력
			}
			
			else if (typing_char == 13) //엔터값을 입력 받았을때 단어 비교 실행
			{
				sword = 0;
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");//일단 입력줄을 다 지워준다
				for (int i = 0; i <= wordmax; i++)
				{
					if (strcmp(typing_word, word[i]) == 0)//단어가 일치하는게 있을때
					{
						x2 = word_data[i][0];//그 단어의 x위치를 받는다
						y2 = word_data[i][1];//그 단어의 y위치를 받는다
						color2 = word_data[i][2];//그 단어의 색깔 정보를 받는다
						gotoxy(x2, y2);
						printf("          ");//프린트된 위치의 단어를 지운다
				
						switch (color2)
						{
						case 1: //파랑
							score += 150; 
							break;

						case 2: //초록
							score += 200; 
							break;
						
						case 3: //하늘
							score += 250; 
							break;
						
						case 4: //빨강
							score += 300; 
							break;
						
						default: 
							break;
						}
						gotoxy(3, 2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("현재점수 : %d", score);
					}
				}
				
				for (int i = 0; i < 50; i++) 
				{
					typing_word[i] = NULL; //타이핑한 단어를 다시 초기화 해준다
				}
			}
		}
	}
}

void GameMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	MainDesign();
	
	gotoxy(50, 8);
	printf(" 1. 게임시작");
	gotoxy(50, 10);
	printf(" 2. 도움말");
	gotoxy(50, 12);
	printf(" 3. 점수 보기");
	gotoxy(50, 14);
	printf(" 4. 게임 종료");
	gotoxy(50, 16);
	printf("  키를 누르세요");
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //CONSOLE_CURSOR_INFO 타입 변수 curInfo ==> struct 타입
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //GetConsoleCursorInfo() ==> 인자로 핸들값을 넘겨준다. (핸들값 얻는 함수: GetStdHandle())
	curInfo.bVisible = 0; //curInfo는 struct 이므로 bVisible 값을 바꿔준다. (1은 보이고, 0은 안보인다.)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //SetConsoleCursorInfo() ==> 변경된 값을 Set 해준다.
}