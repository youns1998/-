#include"typingsound.h"


#define TypingSound "D:\\�������Ƽ\\bibim.github\\Ÿ�����ڸ�\\Ÿ�����ڸ�.wav"

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

