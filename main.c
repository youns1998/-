﻿#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
/*타자 연습 메인 함수*/
void TP_menu()
{
	while (1)
	{

		int tp_menu;
		printf("1. 긴 글 연습\n");
		printf("2. 짧은 글 연습\n");
		printf("3. 타자 연습 게임\n");
		printf("4. 이전 메뉴로\n");
		tp_menu = _getch();

		switch (tp_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("긴 글 연습 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
					printf("잘못 입력하셨습니다.\n");
				system("pause");//잠시만 임시로 넣어둘게요^,^
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("짧은 글 연습 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}
		case '3':
		{
			while (1)
			{
				system("cls");
				printf("게임 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}

		case'4':
			return;
		}


	}
}
void CP_menu()
{
	while (1)
	{

		int cp_menu;
		printf("1. C 연습\n");
		printf("2. C++ 연습\n");
		printf("3. 타자 연습 게임\n");
		printf("4. 이전 메뉴로\n");
		cp_menu = _getch();

		switch (cp_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("C 연습 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("C++ 연습 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}
		case '3':
		{
			while (1)
			{
				system("cls");
				printf("게임 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}

		case'4':
			return;
		}


	}



}

void rank_menu()
{
	while (1)
	{

		int rank_menu;
		printf("1. 일반 랭킹\n");
		printf("2. 코딩 랭킹\n");
		printf("3. 이전 메뉴로\n");
		rank_menu = _getch();

		switch (rank_menu) {
		case '1':
		{
			while (1)
			{
				system("cls");
				printf("일반 랭킹 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		}

		case '2':
		{
			while (1)
			{
				system("cls");
				printf("코딩 랭킹 실행\n");
				printf("esc를 누르면 이전 메뉴로 돌아갑니다\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
		}
		case '3':
			return;



		}


	}
}
void main()
{


	while (1) {
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("............................................................................................,............................................\n");
			printf(".......................................................................................,+7$?:.,..........................................\n");
			printf("..................................................................................,., 7DNNNNN8,..........................................\n");
			printf(".....................................................................................+NNDZZONNNO:........................................\n");
			printf(".....................................................................................OMN7777IDMND=,......................................\n");
			printf("..............................................................,..:=?+=:.,,..,.....,..7MNZ77777ZMNN=..,...................................\n");
			printf("..............................................................,ONNNNDDND7.............ONNMMDZIIZND8......................................\n");
			printf("...........................................................,.=8NN87=+IONN8:...........~8DNNNNN87$NN=.....................................\n");
			printf(".............,,.......,.................,,................,..8ND~......=NNO,..........~DNZ.,?NNNODNO....,,............,..................\n");
			printf("..............................,.........,....,...............DNO.......,NND,..........:8NO,..:7NNNNN:...,................................\n");
			printf("................:+7O8NNNNDDOI=...........:IZDNNNNNNND8$+:....8NO.......,NN8,..,=7ODNND8NNO.....~8NNM~....~?O8DNNNNNN8O$=,................\n");
			printf(".............,=8NNNNNNMNNNNNNND$: ....,INNMNNNNMMNNMNNDNNZ: .8NO.......,NND,.IDNDNNNNNNNNZ......~NNM+..$DDNNNNNNNNNMNNNNNZ~.,............\n");
			printf("............:8NNN8$+~,...,~?ZNNNN$...+DNNNZ?:,. .. .:=$DDNNZ,DNO.......,DNO=DNDNZ+:,.,~IDZ.......INM+?NDNNO?~,......~?7NNNN$.............\n");
			printf("........,..7NNN=.. ...........:INND?ZMN8:... ............$NNNNNO.......,DNDND8:........... ......:DNNNN7,...............:$MNO~,..........\n");
			printf("..........~ND8~................ +NNNNNO,...  ... ....... ,INNNNO.......,NNNND:....... ............DNNN$..........,.... ..,+NN$...........\n");
			printf(".........,$NN=.......~8NNO, .....:8DDDNZ$ODNNNMMNND~,.  .  INNNO.......,NNNN=.......7NNNZ.........DNN8,.... .,$NMNI....... 7ND=..,.......\n");
			printf("........,:8ND,.... .,NNNNN$.......?NNNNNNNNNNNNNNNNM=......~NNNO.......,DNN8. .....=NDNDNI .......DNN=.......7NNNNN+.. ....~NN$..........\n");
			printf(".........=DNO.......,NNNNND,... ..~DNNDNDZ+:,.........     ,8NNO...... ,NNDZ..... .?NNNNNO........NND,..    .ZDDNNN7...   .,NNO,.........\n");
			printf(".........=NNZ.......,NNNNND,..... ,DDNDI........ .....    ..8NNO...... ,NNN$ .... .?NNNNNO........NND,...   .ZDDNNN7...   .,NND,.........\n");
			printf(".........=NNZ..... .,NNNNND,......,DNN+... ...?8DN8I,......,8NNO...... ,NNDO.. ....?NNNNNO........NND,.......ZNNNNN7.......,NN8.,........\n");
			printf(".........=NNZ........MNNDNZ.......~NND,..... ,NNDNNM? .....~NNNO...... ,NNDN:.... .~NNNDMI.......:DNN?.......7MDNDM?.......=NN$..........\n");
			printf(".........~DNO.........    .......+NNNN$,......... .. .....+MDNNO.......,NNDNN$..................+MNDNN$..................,?MNO...........\n");
			printf(".........~DN8,... ..............INND8NN8:...............,$NNDDNO.......,NN8OMN8~...............$NDD:8NN7:...............:ZMNO~,..........\n");
			printf(".........:8ND~..... :NZ=,..,~?DMNMO,.?NNNN8$=~,,,.,~+IONNDM$.ZNND?:..:I8NMI.~8NNDD7=,....,~?ONNNMZ,..=DNNN87+~,.,.,~?78NNDMI,............\n");
			printf(".........,ONNZ,... .,NNNNNMNNNND8+.,,,.IDNNDNNNNMNNNNNDNN$:.,,$NNNNMMNDND$.,,.IDNNNNNMNNNNNNDNNZ:....,,$DNNNNNNNNMNNNNDMD$:.,............\n");
			printf(".........,$NDNZ.....,NNN8NNNDZ?:.,,......,=7ODDNNDD8O$+~.......:IZDNDDOI,.......:+Z8DNDNNDDZI~...........:+$O8DNNDD8O7+:.................\n");
			printf("..........INNNN8~...,NNZ......,,..,...................,,...,..........,...........................,...................,,.................\n");
			printf("..........=NN8DNNZ=.:NNZ..,....................................,....,,.,,,...................,,.........,................................\n");
			printf("..........,DNDZODDNNDNM$.,...............,.,......,....,,...,,.............................,.,.,...,.,...................................\n");
			printf("...........IMNDZ$Z8DDNDN?.............................................,,,........,...............,.......................................\n");
			printf("........,.,,7NN8ZZZZZODDN:..........,. _______          _               _____                _   _          ,............................\n");
			printf(".............IMNDZZZZZ8NN+...........,|__   __|        (_)             |  __ Y              | | (_)         .............................\n");
			printf("........,,,.,.=MNDDOO8NDM:...........    | |_   _ _ __  _ _ __   __ _  | |__) | __ __ _  ___| |_ _  ___ ___ .............................\n");
			printf("............,,.,$NNDNDND~............    | | | | | '_ Y| | '_ Y / _` | |  ___/ '__/ _` |/ __| __| |/ __/ _ Y,,...........................\n");
			printf("............,,.,...DNDND~..............  | | |_| | |_) | | | | | (_| | | |   | | | (_| | (__| |_| | (_|  __/,,...........................\n");
			printf(".......................................  |_|Y__, | .__/|_|_| |_|Y__, | |_|   |_|  Y__,_|Y___|Y__|_|Y___Y___|.............................\n");
			printf(".....................................        __/ | |             __/ |                                      .............................\n");
			printf(".....................................       |___/|_|            |___/                                       .............................\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("                                      ====================================================================\n");
			printf("                                                                1 . 한글 타자 연습\n");
			printf("                                                                2 . 코딩 타자 연습\n");
			printf("                                                                3 . 랭킹 확인\n");
			printf("                                                                4 . 도움말\n");
			printf("                                                                5 . 프로그램 종료\n");
			printf("                                      ====================================================================\n");
		}
		int main_menu;

		main_menu = _getch();

		switch (main_menu) {
		case '1':
			system("cls");
			TP_menu();
			break;
		case '2':
			system("cls");
			CP_menu();
			break;
		case '3':
			system("cls");
			rank_menu();
			break;
		case '4':
			system("cls");
			while (1)
			{
				system("cls");
				printf("도움말 출력\n");
				printf("esc를 누르면 이전메뉴로 돌아갑니다.\n");
				if (_getch() == 27)
				{
					system("cls");
					break;
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
					system("pause");

				}
			}
			break;
		case '5':
			system("cls");
			printf("시스템 종료\n");
			system("pause");
			return;
		}

	}
}