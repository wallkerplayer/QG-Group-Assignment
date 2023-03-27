#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
#include <malloc.h>


void get_type();
void get_int(void** data);
void get_float(void** data);
void get_char(void** data);
void show();

int main()
{
	get_type();
	show();
	return 0;
}



void get_type()    //���û�ѡ���������������
{
	while (1)
	{
		type = '\0';
		printf("���������������������\n");
		printf("***********************************\n");
		printf("*  'i'����    'f'������    'c'�ַ�*\n");
		printf("***********************************\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}

//������������
void get_int(void** data)
{
	printf("������һ������:\n");
	int* p = (int*)malloc(sizeof(int));
	char s[50];
	int flag = 1;
	while (1)
	{
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 6)
			{
				int i;
				for (i = 1; i < 6 && s[i] != '\0'; i++)
					if (s[i] < '0' || s[i]>'9');
				{
					flag = 0;
					break;
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 6 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 5)
		{
			int i;
			for (i = 0; i < 5 && s[i] != '\0'; i++)
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 5 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("����ȷ����һ������-10000��С��10000����;\n");
	}
}

//���븡������������
void get_float(void** data)
{
	printf("������һ��������:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//�����ַ�����������
void get_char(void** data)
{
	printf("������һ���ַ�:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}

//��ʾ����
void show()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	void* data = NULL;
	if (type == 'i')
		data = (void*)malloc(sizeof(int));
	else if (type == 'f')
		data = (void*)malloc(sizeof(float));
	else if (type == 'c')
		data = (void*)malloc(sizeof(char));
	void* add_data;
	int flag;
	InitLQueue(Q);
	while (1)
	{
		while (1)
		{
			flag = 0;
			printf("********************************************\n");
			printf("*                 ���ܲ˵�                 *\n");
			printf("* 1 �ж϶����Ƿ�Ϊ��         2 �鿴����Ԫ��*\n");
			printf("* 3 ���                     4 ����        *\n");
			printf("* 5 �鿴����                 6 �鿴���г���*\n");
			printf("* 7 ���ٶ��в��˳�                         *\n");			
			printf("********************************************\n");
	
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>7)  //ȷ��������������
			{
				system("cls");
				printf("��������ȷ������\n");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://�ж϶����Ƿ�Ϊ��
			if (IsEmptyLQueue(Q) == TRUE)
				printf("����Ϊ��\n");
			else
				printf("���в�Ϊ��\n");
			break;
		case(2)://�鿴����Ԫ��
			if (GetHeadLQueue(Q, data) == TRUE)
				LPrint(data);
			else
				printf("����Ϊ��\n");
			break;
		case(3)://���
			if (type == 'i')
				get_int(&add_data);
			else if (type == 'f')
				get_float(&add_data);
			else
				get_char(&add_data);
			if (EnLQueue(Q, add_data) == TRUE)
				printf("������ӵ�ֵ\n");
			else
			{
				printf("����ռ�����\n");
				exit(-1);
			}
			break;
		case(4)://���� 
			if (DeLQueue(Q) == TRUE)
				printf("�Ѿ���ɳ���\n");
			else
				printf("����Ϊ��\n");
		case(5)://�鿴���� 
			TraverseLQueue(Q, LPrint);
			break;
		case(6)://�鿴���г���
			if (LengthLQueue(Q) != TRUE)
				printf("���ִ���\n");
			else
			{
				LengthLQueue(Q);
			}
			break;
		case(7)://���ٶ��в��˳�
			DestoryLQueue(Q);
			free(Q);
			printf("complete");
			return;
		}
	}

}
