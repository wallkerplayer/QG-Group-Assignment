#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
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



void get_type()    //让用户选择输入的数据类型
{
	while (1)
	{
		type = '\0';
		printf("输入您想输入的数据类型\n");
		printf("***********************************\n");
		printf("*  'i'整数    'f'浮点数    'c'字符*\n");
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

//输入整型数据
void get_int(void** data)
{
	printf("请输入一个整数:\n");
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
		printf("请正确输入一个大于-10000且小于10000的数;\n");
	}
}

//输入浮点型整型数据
void get_float(void** data)
{
	printf("请输入一个浮点数:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//输入字符型整型数据
void get_char(void** data)
{
	printf("请输入一个字符:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}

//演示函数
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
			printf("*                 功能菜单                 *\n");
			printf("* 1 判断队列是否为空         2 查看队首元素*\n");
			printf("* 3 入队                     4 出队        *\n");
			printf("* 5 查看队列                 6 查看队列长度*\n");
			printf("* 7 销毁队列并退出                         *\n");			
			printf("********************************************\n");
	
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>7)  //确保数字输入正常
			{
				system("cls");
				printf("请输入正确的数字\n");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://判断队列是否为空
			if (IsEmptyLQueue(Q) == TRUE)
				printf("队列为空\n");
			else
				printf("队列不为空\n");
			break;
		case(2)://查看队首元素
			if (GetHeadLQueue(Q, data) == TRUE)
				LPrint(data);
			else
				printf("队列为空\n");
			break;
		case(3)://入队
			if (type == 'i')
				get_int(&add_data);
			else if (type == 'f')
				get_float(&add_data);
			else
				get_char(&add_data);
			if (EnLQueue(Q, add_data) == TRUE)
				printf("输入入队的值\n");
			else
			{
				printf("储存空间已满\n");
				exit(-1);
			}
			break;
		case(4)://出队 
			if (DeLQueue(Q) == TRUE)
				printf("已经完成出队\n");
			else
				printf("队列为空\n");
		case(5)://查看队列 
			TraverseLQueue(Q, LPrint);
			break;
		case(6)://查看队列长度
			if (LengthLQueue(Q) != TRUE)
				printf("出现错误\n");
			else
			{
				LengthLQueue(Q);
			}
			break;
		case(7)://销毁队列并退出
			DestoryLQueue(Q);
			free(Q);
			printf("complete");
			return;
		}
	}

}
