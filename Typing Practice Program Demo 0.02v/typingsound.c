#include"typingsound.h"


#define TypingSound "Ÿ�����ڸ�.wav"
#define TitleSound "��ٸ�Ÿ��.wav"
#define PokeSound "���ϸ�.wav"
#define TetSound "��Ʈ����.wav"
void typingsound()
{
	PlaySound(TEXT(TypingSound), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//���� ���� ��ġ, SND_ASYNC, SND_LOOP �������� ���� �߿�
	//SND_ASYNC : ����ϸ鼭 �����ڵ� ����
	//SND_LOOP : �ݺ����



}
void stopsound()
{
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void titlesound()
{
	PlaySound(TEXT(TitleSound), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}
void pokemonsound()
{
	PlaySound(TEXT(PokeSound), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	

}
void tetsound()
{
	PlaySound(TEXT(TetSound), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}
