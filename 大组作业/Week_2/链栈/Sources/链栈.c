#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef int ElemType;
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;



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



// ����ջ
int CreateStack(LinkStack *s)
{
	ElemType e;
	scanf("%d", &e);    // ��������   
	while (e != -99999) // ����-99999ֹͣ 
	{     
		pushLStack(s, e);      // ������ջ����������ջ
		scanf("%d", &e);     
	}
	return 1;
}


// ��ʼ����ջ
Status initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode)); // ��̬����һƬ�ڴ�ռ� 
	
	s->top= NULL;//��ʼ����ջͷ���ָ����
	return SUCCESS;
}

//�ж���ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s)
{
	if (s->top == NULL) // ���ջ�ĵ�ǰ����Ϊ0����ջΪ��
	{ 
		return SUCCESS ;
	}
	else
	{
		return ERROR;
	}
}

//����ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s)) 
		return ERROR;
	*e = s->top->data; // ��ջ�����������򸳸�e
	printf("ջ��Ԫ��Ϊ:%d\n",*e);
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		printf("ջΪ�գ��������\n");
		return ERROR;
	}
	else
	{
		LinkStackPtr p = s->top; // ����һ��ָ��ջ������ָ��p
		while (p->next) // ֻҪpָ��Ľ��ĵ�ָ����Ϊ�գ���֤��p�Ѿ�ָ�����һ����������ݵĽڵ㣬��p->next���ڼ�Ϊִ�и�ѭ��������
		{
			s->top = s->top->next; // �Ƚ�ջ��ָ��������ջ������һ�����
			free(p); // ����ǰջ������ͷ�
			p = s->top; // ��ָ��pָ����һ���
		}
		s->count = 0; // ��ջ��ǰ������Ϊ0
	}
}

//������ջ
Status destroyLStack(LinkStack* s)
{
	LinkStackPtr p = s->top; // ����һ��ָ��ջ������ָ��p
	while (p) // ֻҪp���ڣ�֤������δ�ͷŵĽ�㣬�����ѭ���ͷ�
	{
		s->top = s->top->next; // �Ƚ�ջ��ָ��������ջ������һ�����


		free(p); // ����ǰջ������ͷ�
		p = s->top; // ��ָ��pָ����һ���
	}
	s->count = 0; // ��ջ��ǰ������Ϊ0

}

//���ջ����
Status LStackLength(LinkStack* s)
{
	int length;
	length = 0;
	while (s->top->next != NULL) //ֻҪ����������һ���ڵ�Ͳ���ֹͣѭ��
	{
		s->top = s->top->next;
		length++;                  //�ó���ջ�ĳ���
	}
	printf("��ջ����%d\n", length);
}


// ��ջ
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode)); //�����½��
	if (!S)
	{
		return ERROR;
	}
	S->data = data;   //��data��ֵ�����½���������
	S->next = s->top;
	s->top = S;        //���µĽ��s��ֵ��ջ��ָ��
	s->count++;       //���ȼ�1

	return SUCCESS;
}

// ��ջ
Status popLStack(LinkStack* s, ElemType* data)
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		return ERROR;
	}

	p = s->top;        
	s->top = s->top->next;// ʹ��ջ��ָ������һλ��ָ���һ���
	free(p);              
	s->count--;         //���ȼ�1

	return SUCCESS;
}

//����ջ
Status StackTraverse(LinkStack s)
{
	LinkStackPtr p;
	p = s.top;     // ����һ��ָ��ջ������ָ��p
	while (p->next)      
	{
		visit(p->data);   //���ú�����ӡ������
		p = p->next;	//p����һλ
	}
	printf("\n");
	return SUCCESS;
}

//��ӡ
Status visit(ElemType c)
{
	printf("%d ", c);
	return SUCCESS;
}



int main()
{



	printf("********************************************\n");
	printf("*                 ���ܲ˵�                 *\n");
	printf("* 1 ��ʼ����ջ           2 �ж���ջ�Ƿ�Ϊ��*\n");
	printf("* 3 �鿴ջ��Ԫ��         4 ���ջ�Ĵ�С    *\n");
	printf("* 5 ���ջ               6 ����ջ          *\n");
	printf("* 7 ��ջ                 8 ��ջ            *\n");
	printf("* 9 �鿴��ջ             0 �˳�            *\n");
	printf("********************************************\n");
	LinkStack s;      
	initLStack(&s);
	int status=-1;     
	ElemType e;     // Ԫ��
	while (1)
	{

		
		printf("\n�����빦����ţ�");
		int a= scanf("%d", &status);    //�ж�������Ƿ�Ϊ����
		if (a == 0)
		{
			printf("�������,��������������\n");
			system("pause");

		}
		switch (status)
		{
		case 1://��ʼ����ջ
		{
			initLStack(&s);
			printf("�ѳɹ���ʼ��\n");
			printf("�밴˳������Ԫ�أ�����-99999ֹͣ����\n");
			CreateStack(&s);
			break;
		}
		case 2://�ж���ջ�Ƿ�Ϊ��
		{
			if (isEmptyLStack(&s)) // ���ջ�ĵ�ǰ����Ϊ0����ջΪ��
			{
				printf("ջΪ��\n");
			}
			else
			{
				printf("ջ��Ϊ��\n");
			}	
			break;
		}
		case 3://�鿴ջ��Ԫ��
		{
			 getTopLStack(&s, &e);
			break;
		}
		case 4://���ջ�Ĵ�С 
		{
			 LStackLength(&s);
			break;
		}
		case 5://���ջ 
		{
			 clearLStack(&s);
			 printf("��ճɹ�\n");
			break;
		}
		case 6://����ջ 
		{
			 destroyLStack(&s);
			 printf("���ٳɹ�\n");
			break;
		}
		case 7://��ջ
		{
			printf("������Ҫ��ջ����:\n");
			scanf("%d", &e);
			 pushLStack(&s, e);
			 printf("��ջ�ɹ�\n");
			break;
		}
		case 8://��ջ
		{
			 popLStack(&s, &e);
			 printf("��ջ�ɹ�\n");
			break;
		}
		case 9://�鿴��ջ
		{
			printf("��ջΪ��\n");
			 StackTraverse(s);
			 break;
		}
		case 0://�˳�
		{
			system("cls");
			printf("��л����ʹ�ã�\n"); 
			return 0;
		}
		default:
			printf(" error ");
		}
	}
	return 0;
}

