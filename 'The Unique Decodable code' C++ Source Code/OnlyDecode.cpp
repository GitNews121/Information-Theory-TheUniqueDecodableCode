#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct strings
{
	char *string;
	struct strings *next;
};
struct strings  Fstr, *Fh, *FP;
//�����ǰ����
void outputstr(strings *str)
{
	do
	{
		cout << str->string << endl;
		str = str->next;
	} while (str);
	cout << endl;
}
inline int MIN(int a, int b)
{
	return a>b ? b : a;
}
inline int MAX(int a, int b)
{
	return a>b ? a : b;
}
#define length_a (strlen(CP))
#define length_b (strlen(tempPtr))
//�ж�һ�����Ƿ���һ���뼯���У����򷵻�0�����ڷ���1
int comparing(strings *st_string, char *code)
{
	while (st_string->next)
	{
		st_string = st_string->next;
		if (!strcmp(st_string->string, code))
			return 0;
	}
	return 1;
}
//�ж����������Ƿ�һ������һ����ǰ׺������������ɺ�׺��
void houzhui(char *CP, char *tempPtr)
{
	if (!strcmp(CP, tempPtr))
	{
		cout << "!-----����C�ͼ���F������ͬ����:---!" << endl;
		cout << CP << endl << endl;
		cout << "!-----����Ψһ����������-------!" << endl << endl;
		getchar();
		getchar();
		exit(1);
	}
	if (!strncmp(CP, tempPtr, MIN(length_a, length_b)))
	{
		struct strings *cp_temp;
		cp_temp = new (struct strings);
		cp_temp->next = NULL;
		cp_temp->string = new char[abs(long(length_a - length_b)) + 1];
		char *longstr;
		longstr = (length_a>length_b ? CP : tempPtr);//�����ȳ����븳��longstr
													 //ȡ����׺
		for (int k = MIN(length_a, length_b); k<MAX(length_a, length_b); k++)
			cp_temp->string[k - MIN(length_a, length_b)] = longstr[k];
		cp_temp->string[abs(long(length_a - length_b))] = NULL;
		//�ж������ɵĺ�׺���Ƿ����ڼ���F����������F����
		if (comparing(Fh, cp_temp->string))
		{
			FP->next = cp_temp;
			FP = FP->next;
		}
	}
}
void main()
{
	//������ʾ�ͳ����ʼ��׼��
	cout << "!------Ψһ��������о�ʵ��-------!" << endl << endl;
	cout << "!-------�����������--------!" << endl << endl;
	cout << "!-------ѧ�ţ�14070110007---!" << endl << endl;
	struct strings  Cstr, *Ch, *CP, *tempPtr;
	Ch = &Cstr;
	CP = Ch;
	Fh = &Fstr;
	FP = Fh;
	char c[] = "����C :";
	Ch->string = new char[strlen(c)];
	strcpy(Ch->string, c);
	Ch->next = NULL;
	char f[] = "����F :";
	Fh->string = new char[strlen(f)];
	strcpy(Fh->string, f);
	Fh->next = NULL;
	//����������ĸ���
	int Cnum;
	cout << "!----����������ĸ���:------!"<< endl;
	cin >> Cnum;
	cout << "!-----����������-----!" << endl;
	for (int i = 0; i<Cnum; i++)
	{
		cout << i + 1 << "��";
		char tempstr[10];
		cin >> tempstr;
		CP->next = new (struct strings);
		CP = CP->next;
		CP->string = new char[strlen(tempstr)];
		strcpy(CP->string, tempstr);
		CP->next = NULL;
	}
	outputstr(Ch);
	CP = Ch;
	while (CP->next->next)
	{
		CP = CP->next;
		tempPtr = CP;
		do
		{
			tempPtr = tempPtr->next;
			houzhui(CP->string, tempPtr->string);
		} while (tempPtr->next);
	}
	outputstr(Fh);
	struct strings *Fbegin, *Fend;
	Fend = Fh;
	while (1)
	{
		if (Fend == FP)
		{
			cout << "!-----��Ψһ����������------!" << endl;
			getchar();
			getchar();
			exit(1);
		}
		Fbegin = Fend;
		Fend = FP;
		CP = Ch;
		while (CP->next)
		{
			CP = CP->next;
			tempPtr = Fbegin;
			for (;;)
			{
				tempPtr = tempPtr->next;
				houzhui(CP->string, tempPtr->string);
				if (tempPtr == Fend)
					break;
			}
		}
		outputstr(Fh);//���F������ȫ��Ԫ��
	}
}
