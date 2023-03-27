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



//定义链栈结构体
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



// 创建栈
int CreateStack(LinkStack *s)
{
	ElemType e;
	scanf("%d", &e);    // 读入数据   
	while (e != -99999) // 输入-99999停止 
	{     
		pushLStack(s, e);      // 调用入栈函数进行入栈
		scanf("%d", &e);     
	}
	return 1;
}


// 初始化链栈
Status initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode)); // 动态分配一片内存空间 
	
	s->top= NULL;//初始化链栈头结点指针域
	return SUCCESS;
}

//判断链栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->top == NULL) // 如果栈的当前长度为0，则栈为空
	{ 
		return SUCCESS ;
	}
	else
	{
		return ERROR;
	}
}

//查找栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s)) 
		return ERROR;
	*e = s->top->data; // 将栈顶结点的数据域赋给e
	printf("栈顶元素为:%d\n",*e);
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		printf("栈为空，无需清空\n");
		return ERROR;
	}
	else
	{
		LinkStackPtr p = s->top; // 定义一个指向栈顶结点的指针p
		while (p->next) // 只要p指向的结点的的指针域为空，则证明p已经指向最后一个不存放数据的节点，则p->next存在即为执行该循环的条件
		{
			s->top = s->top->next; // 先将栈顶指针下移至栈顶的下一个结点
			free(p); // 将当前栈顶结点释放
			p = s->top; // 将指针p指向下一结点
		}
		s->count = 0; // 将栈当前长度置为0
	}
}

//销毁链栈
Status destroyLStack(LinkStack* s)
{
	LinkStackPtr p = s->top; // 定义一个指向栈顶结点的指针p
	while (p) // 只要p存在，证明仍有未释放的结点，则进入循环释放
	{
		s->top = s->top->next; // 先将栈顶指针下移至栈顶的下一个结点


		free(p); // 将当前栈顶结点释放
		p = s->top; // 将指针p指向下一结点
	}
	s->count = 0; // 将栈当前长度置为0

}

//检测栈长度
Status LStackLength(LinkStack* s)
{
	int length;
	length = 0;
	while (s->top->next != NULL) //只要还存在着下一个节点就不会停止循环
	{
		s->top = s->top->next;
		length++;                  //得出链栈的长度
	}
	printf("链栈长度%d\n", length);
}


// 入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode)); //创建新结点
	if (!S)
	{
		return ERROR;
	}
	S->data = data;   //将data的值赋给新结点的数据域
	S->next = s->top;
	s->top = S;        //将新的结点s赋值给栈顶指针
	s->count++;       //长度加1

	return SUCCESS;
}

// 出栈
Status popLStack(LinkStack* s, ElemType* data)
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		return ERROR;
	}

	p = s->top;        
	s->top = s->top->next;// 使得栈顶指针下移一位，指向后一结点
	free(p);              
	s->count--;         //长度减1

	return SUCCESS;
}

//遍历栈
Status StackTraverse(LinkStack s)
{
	LinkStackPtr p;
	p = s.top;     // 定义一个指向栈顶结点的指针p
	while (p->next)      
	{
		visit(p->data);   //调用函数打印出数据
		p = p->next;	//p下移一位
	}
	printf("\n");
	return SUCCESS;
}

//打印
Status visit(ElemType c)
{
	printf("%d ", c);
	return SUCCESS;
}



int main()
{



	printf("********************************************\n");
	printf("*                 功能菜单                 *\n");
	printf("* 1 初始化链栈           2 判断链栈是否为空*\n");
	printf("* 3 查看栈顶元素         4 检查栈的大小    *\n");
	printf("* 5 清空栈               6 销毁栈          *\n");
	printf("* 7 入栈                 8 出栈            *\n");
	printf("* 9 查看链栈             0 退出            *\n");
	printf("********************************************\n");
	LinkStack s;      
	initLStack(&s);
	int status=-1;     
	ElemType e;     // 元素
	while (1)
	{

		
		printf("\n请输入功能序号：");
		int a= scanf("%d", &status);    //判断输入的是否为数字
		if (a == 0)
		{
			printf("输入错误,请重新启动程序\n");
			system("pause");

		}
		switch (status)
		{
		case 1://初始化链栈
		{
			initLStack(&s);
			printf("已成功初始化\n");
			printf("请按顺序输入元素（输入-99999停止）：\n");
			CreateStack(&s);
			break;
		}
		case 2://判断链栈是否为空
		{
			if (isEmptyLStack(&s)) // 如果栈的当前长度为0，则栈为空
			{
				printf("栈为空\n");
			}
			else
			{
				printf("栈不为空\n");
			}	
			break;
		}
		case 3://查看栈顶元素
		{
			 getTopLStack(&s, &e);
			break;
		}
		case 4://检查栈的大小 
		{
			 LStackLength(&s);
			break;
		}
		case 5://清空栈 
		{
			 clearLStack(&s);
			 printf("清空成功\n");
			break;
		}
		case 6://销毁栈 
		{
			 destroyLStack(&s);
			 printf("销毁成功\n");
			break;
		}
		case 7://入栈
		{
			printf("请输入要入栈的数:\n");
			scanf("%d", &e);
			 pushLStack(&s, e);
			 printf("入栈成功\n");
			break;
		}
		case 8://出栈
		{
			 popLStack(&s, &e);
			 printf("出栈成功\n");
			break;
		}
		case 9://查看链栈
		{
			printf("链栈为：\n");
			 StackTraverse(s);
			 break;
		}
		case 0://退出
		{
			system("cls");
			printf("感谢您的使用！\n"); 
			return 0;
		}
		default:
			printf(" error ");
		}
	}
	return 0;
}

