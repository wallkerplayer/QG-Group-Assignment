#pragma once
#define STACK_H_INCLUDED
#include <stdio.h>	
#include <stdlib.h> 
#include <malloc.h>	

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

//������ջ�ṹ��
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ
Status StackTraverse(LinkStack s);//����ջ
Status visit(ElemType c);//��ӡ
