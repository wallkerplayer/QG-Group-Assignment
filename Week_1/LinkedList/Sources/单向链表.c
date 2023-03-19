#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct LNode
{
	int data;
	struct LNode* pNext;
}LNode;

//头指针
LNode* pHead = NULL;

//尾指针
LNode* pEnd = NULL;

//创建节点
void CreateNode(LNode* pNode)
{
	if (NULL != pNode)
	{
		printf("请输入结点数据：");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
}

// 创建单向链表
void CreateLinkList()
{
	struct LNode* pNew = malloc(sizeof(struct LNode));
	pNew->data = NULL;
	pNew->pNext = NULL;

	pHead = pNew;//将头、尾指针都指向头结点
	pEnd = pNew;
	printf("创建链表成功!\n");
}

//添加节点
void AddNode()
{

	//创建尾部指针，帮助插入新节点
	struct LNode* pRear = pHead;

	//创建一个新的节点newnode
	LNode* pTemp = pEnd;
	LNode* pNew = malloc(sizeof(struct LNode));
	CreateNode(pNew);

	pEnd->pNext = pNew;       //将新节点插入链表中
	pEnd = pNew;              //更新尾指针指向
	printf("添加结点成功\n");
	return pHead;  //返回头节点
};


//修改单向链表某一结点的值
void ModifyNode(int oldval)
{
	if (NULL == pHead)
	{
		return;
	}
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == oldval)   //找到对应位置，停止循环
		{
			break;
		}
		//没找到对应位置则两指针向后移
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //此时说明链表中没有值为oldval的节点
	{
		printf("需要修改的结点未找到!\n");;
	}
	printf("请输入修改后的结点数据：");
	scanf("%d", &pCurrent->data);
	printf("修改结点数据成功!\n");

}




//在值为oldval的节点前插入新的数据newval
void InsertNode()
{
	if (NULL == pHead)
	{
		return;
	}
	int oldval;
	int newval;
	printf("要将数据插入到哪个节点前：");
	scanf("%d", &oldval);
	printf("输入的数据为：");
	scanf("%d", &newval);
	//创建两个辅助指针来找到替换值的位置
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == oldval)   //找到对应位置，停止循环
		{
			break;
		}
		//没找到对应位置则两指针向后移
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //此时说明链表中没有值为oldval的节点
	{
		return;
	}


	struct LNode* newnode = malloc(sizeof(struct LNode));
	newnode->data = newval;
	newnode->pNext = NULL;

	//将新节点插入
	newnode->pNext = pCurrent;
	pPrev->pNext = newnode;
};






//单向链表中查找某个结点
LNode* FindNode(int val)   //val为查找条件
{
	if (NULL == pHead)
	{
		return;
	}
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == val)   //找到对应位置，停止循环
		{
			break;
		}
		//没找到对应位置则两指针向后移
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //此时说明链表中没有值为oldval的节点
	{
		printf("查找结点未找到!\n");;
	}
	printf("节点所在地址为:%p\n", pCurrent);


}




//删除值为val的节点
void DeleteNode(int delValue)
{

	if (NULL == pHead)
	{
		return;
	}

	//和插入函数一样的原理
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == delValue)   //找到对应位置，停止循环
		{
			break;
		}
		//没找到对应位置则两指针向后移
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == NULL)
	{
		return;
	}
	//重新将链表连结
	pPrev->pNext = pCurrent->pNext;
	//删除对应节点
	free(pCurrent);
	pCurrent = NULL;
};

//遍历并输出链表
void ShowLinkList()
{
	if (NULL == pHead)
	{
		printf("链表不存在");
	}

	else
	{ //建立一个遍历指针
		struct LNode* pCurrent = pHead->pNext;

		while (pCurrent != NULL)
		{
			printf("%d   ", pCurrent->data);  //将链表中所有数打印
			pCurrent = pCurrent->pNext;
		}

	}
};

//清空
void Destory_LinkList()
{
	if (NULL == pHead)
	{
		return;
	}
	//创建辅助指针
	struct LNode* pCurrent = pHead->pNext;

	while (pCurrent != NULL)
	{
		//先保存下一节点地址
		struct LNode* pNext = pCurrent->pNext;
		//清空当前节点内存
		free(pCurrent);

		//指针向后移动
		pCurrent = pNext;
		pHead->pNext = NULL;
		pEnd = pHead;
		printf("清理成功\n");
	}
};


int main()
{
	printf("********************************************\n");
	printf("*                  功能菜单                *\n");
	printf("* 1 创建单向链表           2 顺序添加新结点*\n");
	printf("* 3 修改结点               4 查找结点      *\n");
	printf("* 5 任意位置插入结点       6 删除某结点    *\n");
	printf("* 7 清空整个单向链表       8 打印单向链表  *\n");
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

			InsertNode();
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
			Destory_LinkList();
			break;
		}
		case 8:
		{
			ShowLinkList(pHead);
			break;
		}
		default:
			printf("error");
		}
	}

	return 0;
}