#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode {
	int data;
	struct LNode* pNext;
	struct LNode* pPrior;
}LNode;

//头指针
LNode* pHead = NULL;   

//尾指针
LNode* pEnd = NULL;    




//创建双向链表
void CreateLinkList()
{
	LNode* pNew = malloc(sizeof(LNode));
	pNew->data = NULL;    //头结点不放元素
	pNew->pNext = NULL;
	pNew->pPrior = NULL;

	pHead = pNew;//将头、尾指针都指向头结点
	pEnd = pNew;
	printf("创建链表成功!\n");
}


//创建双向链表节点
void CreateNode(LNode* pNode)
{
	if (NULL != pNode)
	{
		printf("请输入结点数据：");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
	pNode->pPrior = NULL;
}


//添加结点，结点后面依次按顺序添加
void AddNode()
{
	LNode* pTemp = pEnd;
	LNode* pNew = malloc(sizeof(LNode));
	CreateNode(pNew);

	pEnd->pNext = pNew;       //next指针指向new节点
	pEnd = pNew;              //将尾指针指向new节点
	pEnd->pPrior = pTemp;     //将new节点与上一节点双向连接
	printf("添加结点成功\n");
}

//输出双向链表
void ShowLinkList()
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior) //判断链表是否存在
	{
		LNode* pTemp = pEnd;  //pTemp指针指向尾结点，便于测试双向链表的正确性，是否能够从后往前遍历
		printf("输出的单向链表为：");            
		while (pHead != pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->pPrior;
		}
	}
	else
	{
		printf("双向链表为空表!\n");
	}
}

//双向链表中查找某个结点
LNode* FindNode(int val)   //val为查找条件
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pTemp = pEnd;
		while (pTemp != pHead)
		{
			if (val == pTemp->data)
			{
				printf("节点所在地址为:%p\n", pTemp);
				return pTemp;
			}
			pTemp = pTemp->pPrior;
		}
	}
	return NULL;
}

//修改双向链表某一结点的值
void ModifyNode(int val)
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pNode = FindNode(val);
		if (NULL != pNode)
		{
			printf("请输入修改后的结点数据：");
			scanf("%d", &pNode->data);
			printf("修改结点数据成功!\n");
		}
		else
		{
			printf("需要修改的结点未找到!\n");
		}
	}
}

//双向链表特定位置插入结点
void InsertNode(int e, int nType)   //e为插入点对应的值，nType表示插入的方式，nType=0为前插，nType=1为后插
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pPos = FindNode(e);
		LNode* pNew = malloc(sizeof(LNode));
		CreateNode(pNew);

		if (0 == nType)  //前插
		{
			pNew->pNext = pPos;
			pNew->pPrior = pPos->pPrior;
			pNew->pPrior->pNext = pNew;
			pPos->pPrior = pNew;
		}
		else  //后插
		{
			if (pPos == pEnd)   //如果插入位置是最后一个结点
			{
				pNew->pPrior = pPos;
				pPos->pNext = pNew;
				pEnd = pNew;
			}
			else
			{
				pNew->pNext = pPos->pNext;
				pNew->pPrior = pPos;
				pPos->pNext = pNew;
				pNew->pNext->pPrior = pNew;
			}
		}
		printf("插入结点成功!\n");
	}
}


//删除双向链表某一结点
void DeleteNode(int e)
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pPos = FindNode(e);

		if (pEnd == pPos)   //删除最后一个结点
		{
			pPos->pPrior->pNext = NULL;
			pEnd = pPos->pPrior;
		}
		else                    //删除其他位置结点
		{
			pPos->pPrior->pNext = pPos->pNext;
			pPos->pNext->pPrior = pPos->pPrior;
		}
		free(pPos);   //释放内存空间
		printf("删除结点成功!\n");
	}
}

//删除整个双向链表
void ClearLinkList()
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pClear = pHead->pNext;
		LNode* pTemp = NULL;

		while (NULL != pClear)
		{
			pTemp = pClear->pNext;
			free(pClear);
			pClear = pTemp;
		}
		pHead->pNext = NULL;
		pHead->pPrior = NULL;
		pEnd = pHead;
		printf("清空链表成功!\n");
	}
}


int main()
{
	printf("********************************************\n");
	printf("*                  功能菜单                *\n");
	printf("* 1 创建双向链表           2 顺序添加新结点*\n");
	printf("* 3 修改结点               4 查找结点      *\n");
	printf("* 5 任意位置插入结点       6 删除某结点    *\n");
	printf("* 7 清空整个双向链表       8 打印单向链表  *\n");
	printf("********************************************\n");
	while (1)
	{
		int choice;
		printf("\n请输入功能序号：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			CreateLinkList();
			break;
		}
		case 2:
		{
			AddNode();
			break;
		}
		case 3:
		{
			int e;
			printf("请输入要修改的结点：");
			scanf("%d", &e);
			ModifyNode(e);
			break;
		}
		case 4:
		{
			int e;
			printf("请输入要查找的结点：");
			scanf("%d", &e);
			FindNode(e);
			break;
		}
		case 5:
		{
			int e, type;
			printf("请输入要插入的位置和插入方式(1为前插，0为后插)(两个数据之间用空格分开)：");
			scanf("%d %d", &e, &type);
			InsertNode(e, type);
			break;
		}
		case 6:
		{
			int e;
			printf("请输入要删除的结点：");
			scanf("%d", &e);
			DeleteNode(e);
			break;
		}
		case 7:
		{
			ClearLinkList();
			break;
		}
		case 8:
		{
			ShowLinkList();
			break;
		}
		default:
			printf("error");
		}
	}

	return 0;
}
