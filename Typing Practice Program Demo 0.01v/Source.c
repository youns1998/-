#include"Header.h"

void gotoxy(int x,int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
extern int language_Type = 1;	
int BreakHan(wchar_t *str, wchar_t *buffer, UINT nSize)	//�ѱ� �ѱ��ڿ� ���� �ʼ�,�߼�, ������ �ϳ��ϳ� �и����ִ� �Լ� 
{ 
	int head_Index,mid_Index,tail_Index;
	//�ʼ��� ���� ����
	static const wchar_t wcHead[] = {L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��'};

	//�߼��� ���� ����
	static const wchar_t wcMid[] = {L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', L'��'};

	//������ ���� ����
	static const wchar_t wcTail[] = {L' ', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��', 
		L'��', L'��', L'��', L'��'};

	UINT    pos = 0;
	while(*str != '\0') 
	{
		head_Index = (*str - 0xAC00) / (21*28);			//�ѱ� �ѱ����� �ʼ�
		mid_Index = (*str - 0xAC00) % (21 * 28) / 28;	//�߼�
		tail_Index = (*str - 0xAC00) % 28;				//����

		if(*str < 256)					//str�� �ѱ��� �ƴ϶��
		{ 
			if(pos+2 >= nSize-1)	
				break;

			buffer[pos] = *str;		//str�� �ѱ��ڸ� buffer�� ����
			++pos;		//�и��� ���� ����
			++str;		//str������ ���� ����
		} 
		else 
		{ 
			if(pos+4 >= nSize-1) 
				break;
			//�ʼ� 1�� �߼� 1�� 
			if(mid_Index < 9 || mid_Index == 12 || mid_Index == 13 ||mid_Index ==17||mid_Index == 18||mid_Index == 20)
			{
				//���� 0��
				if(tail_Index == 0)
				{
					buffer[pos] = wcHead[head_Index]; 
					buffer[pos+1] = wcMid[mid_Index];
					pos+= 2;
				}
				//���� 1��
				else if(tail_Index == 1 ||tail_Index ==2||tail_Index == 4||tail_Index == 6||tail_Index == 7||tail_Index == 8||tail_Index == 16||tail_Index == 17||tail_Index >= 19 )  
				{
					buffer[pos] = wcHead[head_Index]; 
					buffer[pos+1] = wcMid[mid_Index]; 
					buffer[pos+2] = wcTail[tail_Index];
					pos+=3;
				}
				//���� 2��
				else
				{
					buffer[pos] = wcHead[head_Index]; 
					buffer[pos+1] = wcMid[mid_Index]; 
					switch(tail_Index)
					{
					case 3:
						buffer[pos+2] = wcTail[1];
						buffer[pos+3] = wcTail[19];
						pos+= 4;
						break;
					case 5:
						buffer[pos+2] = wcTail[4];
						buffer[pos+3] = wcTail[22];
						pos+= 4;
						break;
					case 6:
						buffer[pos+2] = wcTail[4];
						buffer[pos+3] = wcTail[27];
						pos+= 4;
						break;
					case 9:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[1];
						pos+= 4;
						break;
					case 10:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[16];
						pos+= 4;
						break;
					case 11:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[17];
						pos+= 4;
						break;
					case 12:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[19];
						pos+= 4;
						break;
					case 13:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[25];
						pos+= 4;
						break;
					case 14:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[26];
						pos+= 4;
						break;
					case 15:
						buffer[pos+2] = wcTail[8];
						buffer[pos+3] = wcTail[27];
						pos+= 4;
						break;
					case 18:
						buffer[pos+2] = wcTail[17];
						buffer[pos+3] = wcTail[19];
						pos+= 4;
						break;
					}
				}

			}
			//�ʼ� 1�� �߼� 2�� ���� 2��
			else
			{
				buffer[pos] = wcHead[head_Index];
				switch(mid_Index)
				{
				case 9:
					buffer[pos+1] = wcMid[8];
					buffer[pos+2] = wcMid[0];
					break;
				case 10:
					buffer[pos+1] = wcMid[8];
					buffer[pos+2] = wcMid[1];
					break;
				case 11:
					buffer[pos+1] = wcMid[8];
					buffer[pos+2] = wcMid[20];
					break;
				case 14:
					buffer[pos+1] = wcMid[13];
					buffer[pos+2] = wcMid[4];
					break;
				case 15:
					buffer[pos+1] = wcMid[13];
					buffer[pos+2] = wcMid[4];
					break;
				case 16:
					buffer[pos+1] = wcMid[13];
					buffer[pos+2] = wcMid[20];
					break;
				case 19:
					buffer[pos+1] = wcMid[18];
					buffer[pos+2] = wcMid[20];
					break;
				}
				//���� 0��
				if(tail_Index == 0)
				{
					pos+= 3;
				}
				//���� 1��
				else if(tail_Index == 1 ||tail_Index ==2||tail_Index == 4||tail_Index == 6||tail_Index == 8||tail_Index == 7||tail_Index == 16||tail_Index == 17||tail_Index >= 19 )  
				{
					buffer[pos+3] = wcTail[tail_Index];
					pos+=4;
				}
				//���� 2��
				else
				{
					switch(tail_Index)
					{
					case 3:
						buffer[pos+3] = wcTail[1];
						buffer[pos+4] = wcTail[19];
						pos+= 5;
						break;
					case 5:
						buffer[pos+3] = wcTail[4];
						buffer[pos+4] = wcTail[22];
						pos+= 5;
						break;
					case 6:
						buffer[pos+3] = wcTail[4];
						buffer[pos+4] = wcTail[27];
						pos+= 5;
						break;
					case 9:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[1];
						pos+= 5;
						break;
					case 10:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[16];
						pos+= 5;
						break;
					case 11:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[17];
						pos+= 5;
						break;
					case 12:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[19];
						pos+= 5;
						break;
					case 13:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[25];
						pos+= 5;
						break;
					case 14:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[26];
						pos+= 5;
						break;
					case 15:
						buffer[pos+3] = wcTail[8];
						buffer[pos+4] = wcTail[27];
						pos+= 5;
						break;
					case 18:
						buffer[pos+3] = wcTail[17];
						buffer[pos+4] = wcTail[19];
						pos+= 5;
						break;
					}
				}
			}

			++str; 
		}

	}
	buffer[pos] = '\0'; 
	return pos;// ���ڿ��� ���ԵǾ� �ִ� ���ڼ��� ��ȯ�ϰ� ����

}
wchar_t** include_short_sentence(int* sentence_Count,FILE* Short_practice)	//�ؽ�Ʈ ���Ͽ� �ִ� ª�� �۵��� ������ ũ���� 2���� �迭�� ����.
{
	
	int i;
	char New_line;						
	wchar_t** Short_sentence;			//�ؽ�Ʈ���� ���� ª�� ������ �����ϴ� ������
	setlocale(LC_ALL, "Korean");		//�����ڵ� �ѱ۷� ����
	*sentence_Count = 0;				//�ؽ�Ʈ������ �� ��(ª�� ������ ����)
	
	while(!feof(Short_practice))		//�ؽ�Ʈ ������ ���μ��� �д´�.
	{
		New_line = fgetc(Short_practice);
		if(New_line == '\n')
			(*sentence_Count)++;		
	}
	rewind(Short_practice);				
	Short_sentence = (wchar_t**)malloc(sizeof(wchar_t*)*(*sentence_Count));	//�ؽ�Ʈ������ ���μ� == ª�� ���� ������� �����Ҵ�.
	for(i = 0 ; i < *sentence_Count ; i++)
	{
		Short_sentence[i] = (wchar_t*)malloc(sizeof(wchar_t)*50);	//ª���� �ϳ��� 50���� ���� ����
		fgetws(Short_sentence[i],50,Short_practice);				//�ؽ�Ʈ���Ͽ� �ִ� ª�� ������ �д´�.
	}
	return Short_sentence;	//ª������ �����ϰ� �ִ� ������ /��ȯ
}
wchar_t*** include_long_sentence(FILE* long_practice,int* Long_Num,int sentence_Count[])	//�ؽ�Ʈ������ ��۵��� ������ ũ���� 3���� �迭�� ����
{
	int i,j;
	char New_line;
	wchar_t buffer;
	wchar_t*** Long_sentence;
	
	setlocale(LC_ALL, "Korean");
	while(!feof(long_practice))
	{
		New_line = fgetc(long_practice);
		if(New_line == '[')					//�ؽ�Ʈ ���Ͽ��� '['�� ������
		{
			while((New_line = fgetc(long_practice)) != ']')	//']'�� ������ ����
			{
				if(New_line == '\n')
					sentence_Count[*Long_Num]++;			//sentence_Count�� �ϳ��� ��ۿ� ���� ���� ���� ����
			}												//Long_Num�� �� �� ����
			sentence_Count[*Long_Num]--;
			(*Long_Num)++;
		}
	}
	rewind(long_practice);
	Long_sentence = (wchar_t***)malloc(sizeof(wchar_t**)*(*Long_Num));	//��� ������ ���� 3���� �����Ҵ�
	for(i = 0 ; i < *Long_Num ; i++)
		Long_sentence[i] = (wchar_t**)malloc(sizeof(wchar_t*)*sentence_Count[i]);	//�ϳ��� ��ۿ����� ���� ������ ���� �����Ҵ�
	for(i = -1 ; !feof(long_practice) ;)
	{
		buffer = fgetc(long_practice);
		if(buffer == '[')		//�ؽ�Ʈ���Ͽ��� '['�� ������
		{ 
			i++;
			buffer = fgetc(long_practice);
			for(j = 0 ; j < sentence_Count[i] ; j++)	
			{
				Long_sentence[i][j] = (wchar_t*)malloc(sizeof(wchar_t)*50);		//�ϳ��� ��� ������ �޸𸮸� �Ҵ��ϰ�
				fgetws(Long_sentence[i][j],50,long_practice);					//�ؽ�Ʈ ���Ͽ��� ������ �д´�.
			}
		}
	}
	return Long_sentence;		//�� ���� �����ϰ� �ִ� ������ ��ȯ
}
wchar_t*** include_long_sentence_SOU(FILE* long_practice, int* Long_Num, int sentence_Count[])	//�ؽ�Ʈ������ ��۵��� ������ ũ���� 3���� �迭�� ����
{
	int i, j;
	char New_line;
	wchar_t buffer;
	wchar_t*** Long_sentence;

	setlocale(LC_ALL, "Korean");
	while (!feof(long_practice))
	{
		New_line = fgetc(long_practice);
		if (New_line == '@')					//�ؽ�Ʈ ���Ͽ��� '['�� ������
		{
			while ((New_line = fgetc(long_practice)) != '`')	//']'�� ������ ����
			{
				if (New_line == '\n')
					sentence_Count[*Long_Num]++;			//sentence_Count�� �ϳ��� ��ۿ� ���� ���� ���� ����
			}												//Long_Num�� �� �� ����
			sentence_Count[*Long_Num]--;
			(*Long_Num)++;
		}
	}

	rewind(long_practice);
	Long_sentence = (wchar_t***)malloc(sizeof(wchar_t**)*(*Long_Num));	//��� ������ ���� 3���� �����Ҵ�
	for (i = 0; i < *Long_Num; i++)
		Long_sentence[i] = (wchar_t**)malloc(sizeof(wchar_t*)*sentence_Count[i]);	//�ϳ��� ��ۿ����� ���� ������ ���� �����Ҵ�
	for (i = -1; !feof(long_practice);)
	{
		buffer = fgetc(long_practice);
		if (buffer == '@')		//�ؽ�Ʈ���Ͽ��� '['�� ������
		{
			i++;
			buffer = fgetc(long_practice);
			for (j = 0; j < sentence_Count[i]; j++)
			{
				Long_sentence[i][j] = (wchar_t*)malloc(sizeof(wchar_t) * 50);		//�ϳ��� ��� ������ �޸𸮸� �Ҵ��ϰ�
				fgetws(Long_sentence[i][j], 50, long_practice);					//�ؽ�Ʈ ���Ͽ��� ������ �д´�.
			}
		}
	}
	return Long_sentence;		//�� ���� �����ϰ� �ִ� ������ ��ȯ
}
void Record_set(int* start_Typing,int* X_Cursor,int* present,int* Check_accuracy,wchar_t* typing_One_word,wchar_t* Example_sentence)
{
	*start_Typing = 1;			//���۽��� �ʱ�ȭ
	*X_Cursor = 0;				//Ŀ���� �ʱ�ȭ
	*present = 0;				//���� �Է��ϰ� �ִ� ���� �ʱ�ȭ
	memset(Check_accuracy,-1,4*100);		//���ù��� �´��� üũ�ϴ� ���� �ʱ�ȭ
	memset(typing_One_word,0,sizeof(wchar_t)*50);		//����� �Էº��� �ʱ�ȭ
	memset(Example_sentence,0,sizeof(wchar_t)*50);		//���ù� �ʱ�ȭ

}
int Long_sentence_practice(wchar_t*** Long_sentence,int Long_Num,int sentence_Count[],FILE* Info_practice)
{
	wchar_t Example_sentence[50];	//���پ� ý
	wchar_t typing_One_word[7][50] = {L"",L"",L"",L"",L"",L"",L""}; //����� �ִ� 7�������� ����. �� ����� 50���� ���� ����
	wchar_t temp[500] = L"";
	wchar_t tmp[1000];
	double typing_start_Time,typing_finish_Time;
	double typing_duration_Time;
	int start_Typing=1,present = 0,correct_word_Count =0;	//start_typing�� 0�̸� �Է½���
	int len_Example_sentence ;
	int X_Cursor = 5;		//X Ŀ����ġ
	int Y_Cursor = 17;		//Y Ŀ����ġ
	int i,j = 0;
	int Highest_Typist = 0;		//�ִ� Ÿ�ڼ�
	int User_input_typist;		//����ڰ� �Է��� ���ڰ���
	long long Typist = 0;		//Ÿ�ڼ�
	int typing_Accuracy = 0;	//��Ȯ��
	int sentence_word_Count;	//��� ���忡���� ���ڰ���
	int Check_accuracy[100] = {-1,};	//-1�̸� ���Է� ����, -2�̸� �´� �Է�, �ٸ�������
	int Random;
	int k;
	
	setlocale(LC_ALL, "Korean");
	k = Long_prac_Main(Long_sentence,Long_Num);	//�޴����� ���° ������� ����
	if(k == -1)
		return 0;
	else if(k == -2)
		return -1;
	else
	{
	
		UI_Long_prac(Long_sentence[k],sentence_Count[k]);	//����ڰ� ������ ��� ���.
		while(j != sentence_Count[k])		//����� ����������
		{
			start_Typing = 1;			//���� �ʱ�ȭ
			X_Cursor = 2;
			present = 0;
			memset(Check_accuracy,-1,4*100);
			memset(Example_sentence,0,sizeof(wchar_t)*50);
			
			wcscpy(Example_sentence,Long_sentence[k][j]);		//����� �� ������ �д´�.
			len_Example_sentence = wcslen(Example_sentence);	//������ ���� ������ ����
			while(1)
			{

				gotoxy(5,16+(j*2));
				for(i = 0 ; i < len_Example_sentence ; i++)		//����� �Է°� ���ù����� ��ġ �ǽð� Ȯ��
				{
					if(Check_accuracy[i] == i)		//Ʋ�����
					{
						RED;
					}
					else if(Check_accuracy[i] == -2)	//�´°��
					{
						COROL;
					}
					else			//���Է»���
					{
						WHITE;
					}
					printf("%C",Example_sentence[i]);
				}
				if(present>=len_Example_sentence-1)	//���� ���̺��� ���� �Է¹����� ����
				{
					break;
				}	
				gotoxy(3+X_Cursor,Y_Cursor+(j*2));
				typing_One_word[j][present] = _getwche();	//���� �ϳ��� �Է¹���
				if(typing_One_word[j][present] == 27)	// ESCŰ�� ������ ��������
				{
					break;
				}
				if(typing_One_word[j][present] == 8 && present == 0)	//Ŀ���� ó���̰�, �齺���̽��� ������ 
					gotoxy(X_Cursor+3,Y_Cursor+(j*2));		//���۾��°�ó�� ���̰�.
				else if(typing_One_word[j][present] == 8)	//�齺���̽��� ������
				{
					if(present>=1)
					{
						if(Example_sentence[present-1] < 256)	//�� ���ڰ� 1byte�̸�
						{
							present--;
							X_Cursor-=1;						//Ŀ�� �ϳ��� �ڷ� �̵�
							gotoxy(X_Cursor+3,Y_Cursor+(j*2));
							printf(" ");		//��������ó�� ���̰� ���
						}
						else				//�� ���ڰ� 2byte��
						{	
							present--;		
							X_Cursor-=2;		//Ŀ�� �ΰ� �̵�
							gotoxy(X_Cursor+3,Y_Cursor+(j*2));
							printf("  ");
						}
					}
					Check_accuracy[present] = -1;	//������ ���ñ� �ٽ� �Ͼ������ ��µǰ� �� ����
				}
				else if(typing_One_word[j][present] != Example_sentence[present])  //���ù��̶� �޸����
				{
					if(present== 0 && start_Typing == 1 &&j == 0)		//�����Է½ÿ�
					{
						start_Typing = 0 ;				//�����Էº��� 0���� ����
						typing_start_Time = (double)(clock())/CLOCKS_PER_SEC;	//�Է� �ð� ����
					}
					if(typing_One_word[j][present] <256 && Example_sentence[present] <256)	//���� ũ�⿡ ���� Ŀ�� �̵�
					{
						X_Cursor+=1;
						Check_accuracy[present] = present;
					}
					else if(typing_One_word[j][present] > 256 && Example_sentence[present] <256)
					{
						if(Example_sentence[present+1] < 256)
						{
							Check_accuracy[present] = present;
							Check_accuracy[present+1] = present+1;
							X_Cursor+= 2;
							present++;
						}
						else
						{
							X_Cursor+= 3;
							Check_accuracy[present] = present;
							Check_accuracy[present+1] = present+1;
							present++;
						}
					}
					else if(typing_One_word[j][present] < 256 && Example_sentence[present] > 256)
					{
						X_Cursor+= 2;
						Check_accuracy[present] = present;
					}
					else if(typing_One_word[j][present] >256 && Example_sentence[present] > 256)
					{
						X_Cursor+= 2;
						Check_accuracy[present] = present;
					}
					present++;
				}
				else  //���ù��̶� ���� �Է�
				{
					if(present== 0 && start_Typing == 1 &&j == 0)
					{
						start_Typing = 0 ;
						typing_start_Time = (double)(clock())/CLOCKS_PER_SEC;
					}
					if(typing_One_word[j][present] < 256)
					{
						Check_accuracy[present] = -2;
						X_Cursor+= 1;
					}
					else
					{
						Check_accuracy[present] = -2;
						X_Cursor+=2;
					}
					present++;
				}
			}
			if(typing_One_word[j][present] == 27)
			{
				break;
			}
			j++;
		}
		if(typing_One_word[j][present] == 27)		//�Էµ��� ESCŰ �Է��ϸ� ����
			return 0;
		typing_finish_Time = (double)(clock())/CLOCKS_PER_SEC;	//��������ð�
		correct_word_Count = 0;
		for(j = 0 ; j < sentence_Count[k] ; j++)
		{
			memset(Example_sentence,0,sizeof(wchar_t)*50);
			wcscpy(Example_sentence,Long_sentence[k][j]);
			len_Example_sentence = wcslen(Example_sentence);
			for(i = 0 ; i <= len_Example_sentence ; i++)
			{
				if((typing_One_word[j][i] == Example_sentence[i]) && (typing_One_word[j][i] != 0))
				{
					temp[correct_word_Count] = Example_sentence[i];
					correct_word_Count++;
				}
			}
		}
		memset(tmp,0,sizeof(wchar_t)*1000);
		wcscpy(tmp,Example_sentence);
		typing_duration_Time = (typing_finish_Time-typing_start_Time)+0.5;//CLOCKS_PER_SEC;
		User_input_typist = BreakHan(temp,tmp,sizeof temp);	//����ڰ� �Է��� Ÿ��

		memset(tmp,0,sizeof(wchar_t)*1000);
		wcscpy(tmp,Example_sentence);
		memset(temp,0,sizeof(wchar_t)*500);
		//wcscpy(temp,Example_sentence);
		for(i = 0 ; i < sentence_Count[k] ; i++)
			wcscat(temp,Long_sentence[k][i]);
		sentence_word_Count = BreakHan(temp,tmp,sizeof temp);	//��ۿ� �Է��ؾ� �ϴ� Ÿ��

		typing_Accuracy = (float)(User_input_typist)/(sentence_word_Count-sentence_Count[k])*100;	//��Ȯ�����
		Typist = (User_input_typist*60)/(typing_duration_Time);		//Ÿ�ڼ� ���
		/*for( i = 0 ; i < Long_Num ; i++)
		{
			for(j = 0 ; j < sentence_Count[i] ; j++)
				free(Long_sentence[i][j]);
		}
		free(Long_sentence);*/

		Result_Long_prac(typing_Accuracy,Typist);		//���ȭ�� ���
		fprintf(Info_practice,"%d %d\n",typing_Accuracy,Typist);	//�ؽ�Ʈ���Ͽ� ����
	}
}
int Short_sentence_practice(wchar_t** Short_sentence,int sentence_Count)
{
	wchar_t Example_sentence[50];		//ª���� ���ù� ���̴� �ִ� 50����
	wchar_t typing_One_word[50] = L"";	//����� ���� �Է� ����
	wchar_t temp[50] = L"";
	wchar_t tmp[500];
	double typing_start_Time,typing_finish_Time;
	double typing_duration_Time;
	int start_Typing=1,present = 0,correct_word_Count =0;	//start_typing�� 0�̸� �Է½���
	int len_Example_sentence ;
	int X_Cursor = 0;
	int Y_Cursor = 20;
	int i;
	int Highest_Typist = 0;
	int User_input_typist;
	long long Typist = 0;
	int typing_Accuracy = 0;
	int sentence_word_Count;
	int Check_accuracy[100] = {-1,};	//-1�̸� ���Է� ����, -2�̸� �´� �Է�, �ٸ�������
//	int sentence_Count;
	int Random;
//	wchar_t** Short_sentence = NULL;
	setlocale(LC_ALL, "Korean");
	
//	Short_sentence = include_short_sentence(&sentence_Count,Short_practice);
	
	while(1)
	{
		typingsound();
		Record_set(&start_Typing,&X_Cursor,&present,Check_accuracy,typing_One_word,Example_sentence);	//�����Ͱ� �ʱ�ȭ
		UI_Short_prac(&Highest_Typist,&Typist,&typing_Accuracy);				//UI�Ѹ���
		
		srand((unsigned)time(0));			
		Random = rand()%sentence_Count;		//ª���� �������� ����
		wcscpy(Example_sentence,Short_sentence[Random]);	
		len_Example_sentence = wcslen(Example_sentence);
		
		while(1)	//��� �˻��ϴ°Ͱ� ����
		{
			
			if(present>=len_Example_sentence-1)
			{
				typing_finish_Time = (double)(clock())/CLOCKS_PER_SEC;
				break;
			}
			gotoxy(5,Y_Cursor-3);
			for(i = 0 ; i < len_Example_sentence ; i++)
			{
				if(Check_accuracy[i] == i)
				{
					RED;
				}
				else if(Check_accuracy[i] == -2)
				{
					COROL;
				}
				else
				{
					WHITE;
				}
				printf("%C",Example_sentence[i]);
			}
	
			gotoxy(X_Cursor+5,Y_Cursor);
			typing_One_word[present] = _getwche();
			if(typing_One_word[present] == 27)
			{
				break;
			}
			if(typing_One_word[present] == 8 && present == 0)
				gotoxy(X_Cursor+5,Y_Cursor);
			else if(typing_One_word[present] == 8)
			{
				if(present>=1)
				{
					if(Example_sentence[present-1] < 256)
					{
						present--;
						X_Cursor-=1;
						gotoxy(X_Cursor+5,Y_Cursor);
						printf(" ");
					}
					else
					{
						present--;
						X_Cursor-=2;
						gotoxy(X_Cursor+5,Y_Cursor);
						printf("  ");
					}
				}
				Check_accuracy[present] = -1;
			}
			else if(typing_One_word[present] != Example_sentence[present])  //���ù��̶� �ٸ����
			{
				if(present== 0 && start_Typing == 1)
				{
					start_Typing = 0 ;
					typing_start_Time = (double)(clock())/CLOCKS_PER_SEC;
				}
				if(typing_One_word[present] <256 && Example_sentence[present] <256)
				{
					X_Cursor+=1;
					Check_accuracy[present] = present;
				}
				else if(typing_One_word[present] > 256 && Example_sentence[present] <256)
				{
					if(Example_sentence[present+1] < 256)
					{
						Check_accuracy[present] = present;
						Check_accuracy[present+1] = present+1;
						X_Cursor+= 2;
						present++;
					}
					else
					{
						X_Cursor+= 3;
						Check_accuracy[present] = present;
						Check_accuracy[present+1] = present+1;
						present++;
					}
				}
				else if(typing_One_word[present] < 256 && Example_sentence[present] > 256)
				{
					X_Cursor+= 2;
					Check_accuracy[present] = present;
				}
				else if(typing_One_word[present] >256 && Example_sentence[present] > 256)
				{
					X_Cursor+= 2;
					Check_accuracy[present] = present;
				}
				present++;
			}
			else  //���ù��̶� ���� �Է�
			{
				if(present== 0 && start_Typing == 1)
				{
					start_Typing = 0 ;
					typing_start_Time = (double)(clock())/CLOCKS_PER_SEC;
				}
				if(typing_One_word[present] < 256)
				{
					Check_accuracy[present] = -2;
					X_Cursor+= 1;
				}
				else
				{
					Check_accuracy[present] = -2;
					X_Cursor+=2;
				}
				present++;
			}
		}
		correct_word_Count = 0;
		if(typing_One_word[present] == 27)
			break;
		for(i = 0 ; i <= len_Example_sentence ; i++)
		{
			if(typing_One_word[i] == Example_sentence[i])		//����ڰ� �Է��� ���ڿ� ���ù��� ���ڿ� �´� ���ڷθ� ���ο� ���ڿ� ����
			{
				temp[correct_word_Count] = Example_sentence[i];
				correct_word_Count++;
			}
		}
		memset(tmp,0,sizeof(wchar_t)*500);
		wcscpy(tmp,Example_sentence);
		typing_duration_Time = (typing_finish_Time-typing_start_Time)+0.5;//CLOCKS_PER_SEC;
		User_input_typist = BreakHan(temp,tmp,sizeof Example_sentence);	//����ڰ� ��Ȯ�ϰ� �Է��� Ÿ�� ����
		memset(tmp,0,sizeof(wchar_t)*500);
		wcscpy(tmp,Example_sentence);
		memset(temp,0,sizeof(wchar_t)*50);
		wcscpy(temp,Example_sentence);
		sentence_word_Count = BreakHan(temp,tmp,sizeof Example_sentence);	//����ڰ� �Է��ؾ��ϴ� ���ù��� Ÿ�� ����
		typing_Accuracy = (float)(User_input_typist)/(sentence_word_Count-1)*100;	//��Ȯ�� ���
		Typist = (User_input_typist*60)/(typing_duration_Time);		//Ÿ�ڼ� ���
	}
	stopsound();
	return 0;
}
int main(int argc,char* argv[])
{


	int i,j,k;
	wchar_t*** Long_sentence_KOR = NULL;
	int Long_Num_KOR = 0;
	int sentence_Count_KOR[5] = {0,};
	
	wchar_t*** Long_sentence_ENG = NULL;
	int Long_Num_ENG = 0;
	int sentence_Count_ENG[5] = {0,};

	wchar_t*** Long_sentence_SOU = NULL;
	int Long_Num_SOU = 0;
	int sentence_Count_SOU[5] = { 0, };

	
	wchar_t** Short_sentence_KOR = NULL;
	int Short_sentence_Count_KOR = 0;

	wchar_t** Short_sentence_ENG = NULL;
	int Short_sentence_Count_ENG = 0;
	wchar_t** Short_sentence_SOU = NULL;
	int Short_sentence_Count_SOU = 0;


	FILE* Short_practice_KOR;
	FILE* Short_practice_ENG;
	FILE* Long_practice_KOR;
	FILE* Long_practice_ENG;
	FILE* Long_practice_SOU;
	FILE* Short_practice_SOU;
	FILE* Info_practice;

			
	
	//���� ����
	Short_practice_KOR = fopen(argv[1],"r");
	Short_practice_ENG = fopen(argv[2],"r");
	Long_practice_KOR = fopen(argv[3],"r");
	Long_practice_ENG = fopen(argv[4],"r");
	Info_practice = fopen(argv[5],"r+");
	Long_practice_SOU = fopen("Long_practice_SOU.txt", "r");
	Short_practice_SOU = fopen("Short_practice_SOU.txt", "r");

	if(Short_practice_KOR == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	if(Short_practice_ENG == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	if(Long_practice_KOR == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	
	if(Long_practice_ENG == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	if(Info_practice == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	if (Long_practice_SOU == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	if (Short_practice_SOU == NULL)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	//�޸� �Ҵ�
	Long_sentence_KOR = include_long_sentence(Long_practice_KOR,&Long_Num_KOR,sentence_Count_KOR);
	Long_sentence_ENG = include_long_sentence(Long_practice_ENG,&Long_Num_ENG,sentence_Count_ENG);
	Short_sentence_KOR = include_short_sentence(&Short_sentence_Count_KOR,Short_practice_KOR);
	Short_sentence_ENG = include_short_sentence(&Short_sentence_Count_ENG,Short_practice_ENG);
	Long_sentence_SOU = include_long_sentence_SOU(Long_practice_SOU, &Long_Num_SOU, sentence_Count_SOU);
	Short_sentence_SOU = include_short_sentence(&Short_sentence_Count_SOU, Short_practice_SOU);

	
	//���α׷� ����
	First_Page();
	Beep(MI, 70);
	Beep(DO, 100);
	while(1)
	{
		
		i = Short_prac_Main();
			if (i == -1)
				break;
			switch (i)
			{
			case 0:
				break;
			case 1:

				if (language_Type == 1)
					i = Short_sentence_practice(Short_sentence_KOR, Short_sentence_Count_KOR);
				else if (language_Type == 2)
					i = Short_sentence_practice(Short_sentence_ENG, Short_sentence_Count_ENG);
				else if (language_Type == 3)
					i = Short_sentence_practice(Short_sentence_SOU, Short_sentence_Count_SOU);
				break;
			}
			fflush(stdin);


		if(language_Type == 1)
			i = Long_sentence_practice(Long_sentence_KOR,Long_Num_KOR,sentence_Count_KOR,Info_practice);
		else if(language_Type == 2)
			i = Long_sentence_practice(Long_sentence_ENG,Long_Num_ENG,sentence_Count_ENG,Info_practice);
		else if (language_Type == 3)
			i = Long_sentence_practice(Long_sentence_SOU, Long_Num_SOU, sentence_Count_SOU, Info_practice);

		if (i == -1)
		{
		
			
			break;
		}
		fflush(stdin);
		
		
		i = Game_Main();

		if (i == -1)
			break;
		switch (i)
		{
		case 0:

			break;
		default:
			startgame();
			break;
		}
		fflush(stdin);

		i = Environment_Main();
		if (i == -1)
			break;
		switch(i)
		{
		case 0:
		
			break;
		case 1:
			
			
			language_Type = Environment(Info_practice);
			break;
		}
	}
	
	//�޸� ��ȯ
	for( k = 0 ; k < Long_Num_KOR ; k++)
	{
		for(j = 0 ; j < sentence_Count_KOR[i] ; j++)
			free(Long_sentence_KOR[k][j]);
	}
	free(Long_sentence_KOR);
	for( k = 0 ; k < Long_Num_ENG ; k++)
	{
		for(j = 0 ; j < sentence_Count_ENG[i] ; j++)
			free(Long_sentence_ENG[k][j]);
	}
	free(Long_sentence_ENG);
	 
	for( i = 0 ; i < Short_sentence_Count_KOR ; i++)
	{
		free(Short_sentence_KOR[i]);
	}
	free(Short_sentence_KOR);
	for( i = 0 ; i < Short_sentence_Count_ENG ; i++)
	{
		free(Short_sentence_ENG[i]);
	}
	for (k = 0; k < Long_Num_SOU; k++)
	{
		for (j = 0; j < sentence_Count_SOU[i]; j++)
			free(Long_sentence_SOU[k][j]);
	}
	free(Long_sentence_SOU);
	for (i = 0; i < Short_sentence_Count_SOU; i++)
	{
		free(Short_sentence_SOU[i]);
	}
	

	
	//���� �ݱ�
	free(Short_sentence_SOU);
	free(Short_sentence_ENG);
	fclose(Short_practice_ENG);
	fclose(Short_practice_KOR);
	fclose(Long_practice_ENG);
	fclose(Long_practice_KOR);
	fclose(Info_practice);
	fclose(Long_practice_SOU);
	fclose(Short_practice_SOU);
	return 0;
}


