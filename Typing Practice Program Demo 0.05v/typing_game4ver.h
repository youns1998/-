#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "Header.h"
#define wordmax 100//�ܾ��� ����
#define wordspeed 25//25000//�ܾ �ߴ� �ӵ�
void _Help();// ����
void _GameMain();// ���Ӹ���
void _PrintWord();//�ܾ�߰� ���ִ� �Լ�
void _SearchWord();//�ܾ �Է� �ް� ��
void _GameDesign();//���� ������
void _GameMenu();//���� ���� �ʱ� ȭ��
void _Best();//�ְ�����
void _RemoveCursor();// printf���� �ܾ �߰��Ҷ� Ŀ�� ����
void _MainDesign();//���� ������

char _word[200][200] = { "printf", "scanf", "int", "float", "double", "%d", "%f", "%lf", "return", ";", "&", "main", "#include",//�ܾ�
"void", "#define", "stdio.h", "stdlib.h", "unsigned", "malloc", "free", "char", "if", "switch", "else", "break", "default", "while", "for", "++",
"--", "&&", "||", "NULL", "class", "cin", "cout", "endl", "new", "delete", "[]", "*", "=", "()", "time", "string", "strcmp", "getline", "gets",
"sizeof", "temp", "extern", "register", "struct", "static", "goto", "do", "enum", "auto", "case", "const", "continue", "signed", "short", "friend",
"public", "using","bool", "private", "true", "false", "typename", "union", "template", "protected", "clear", "time.h", "windows.h", "conio.h",
"%s", "%c", "!=", "==", ">=", "<=", ">", "<", "iostream", "swap", "inline", "namespace", "ignore", "-", "+", "/", "%", "//", "/**/", ".", "->", "char" };
time_t _startTime = 0, _endTime = 0;//������ �ð������� ���ؼ�
int time_gap;//���۽ð��� �ð�����
int check_word[200];//�ѹ��� �ܾ���� �ȶ߰� ���ֱ� ���ؼ�
char typing_word[50];//Ÿ������ �ܾ�
char word_data[200][3] = { 0 };//�ܾ� ����
char check_position[120][30] = { 0 };//�ѹ��� ��ġ���� �ȶ߰� ���ֱ� ���ؼ�
int menu_num;//�ʱ�ȭ�鿡�� �Է� ������ ����
int _x, _y;// gotoxy �� _x���� _y��
int _color;// ����
int x2, y2;// _x,_y���� �ٽ� �ҷ��� �� ����
int color2;// ���� ���� �ٽ� �ҷ��ö� ����
int eveything_get; //�ƹ�Ű�� �Է¹����� ����
int _score = 0;//����
int word_num;//�ܾ��
int sword = 0;
int check_x, check_y;//�ѹ��� ��ġ�� �ٽ� ���� �ʱ� ���� ����
int game_set = 0;
int best_score = 0;//�ְ���
int score_2nd = 0;
int score_3rd = 0;
char best_player[10] = { 0 };
char player2[10] = { 0 };
char player3[10] = { 0 };