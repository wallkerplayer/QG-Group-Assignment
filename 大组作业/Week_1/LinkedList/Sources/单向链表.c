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

//ͷָ��
LNode* pHead = NULL;

//βָ��
LNode* pEnd = NULL;

//�����ڵ�
void CreateNode(LNode* pNode)
{
	if (NULL != pNode)
	{
		printf("�����������ݣ�");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
}

// ������������
void CreateLinkList()
{
	struct LNode* pNew = malloc(sizeof(struct LNode));
	pNew->data = NULL;
	pNew->pNext = NULL;

	pHead = pNew;//��ͷ��βָ�붼ָ��ͷ���
	pEnd = pNew;
	printf("��������ɹ�!\n");
}

//��ӽڵ�
void AddNode()
{

	//����β��ָ�룬���������½ڵ�
	struct LNode* pRear = pHead;

	//����һ���µĽڵ�newnode
	LNode* pTemp = pEnd;
	LNode* pNew = malloc(sizeof(struct LNode));
	CreateNode(pNew);

	pEnd->pNext = pNew;       //���½ڵ����������
	pEnd = pNew;              //����βָ��ָ��
	printf("��ӽ��ɹ�\n");
	return pHead;  //����ͷ�ڵ�
};


//�޸ĵ�������ĳһ����ֵ
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
		if (pCurrent->data == oldval)   //�ҵ���Ӧλ�ã�ֹͣѭ��
		{
			break;
		}
		//û�ҵ���Ӧλ������ָ�������
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //��ʱ˵��������û��ֵΪoldval�Ľڵ�
	{
		printf("��Ҫ�޸ĵĽ��δ�ҵ�!\n");;
	}
	printf("�������޸ĺ�Ľ�����ݣ�");
	scanf("%d", &pCurrent->data);
	printf("�޸Ľ�����ݳɹ�!\n");

}




//��ֵΪoldval�Ľڵ�ǰ�����µ�����newval
void InsertNode()
{
	if (NULL == pHead)
	{
		return;
	}
	int oldval;
	int newval;
	printf("Ҫ�����ݲ��뵽�ĸ��ڵ�ǰ��");
	scanf("%d", &oldval);
	printf("���������Ϊ��");
	scanf("%d", &newval);
	//������������ָ�����ҵ��滻ֵ��λ��
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == oldval)   //�ҵ���Ӧλ�ã�ֹͣѭ��
		{
			break;
		}
		//û�ҵ���Ӧλ������ָ�������
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //��ʱ˵��������û��ֵΪoldval�Ľڵ�
	{
		return;
	}


	struct LNode* newnode = malloc(sizeof(struct LNode));
	newnode->data = newval;
	newnode->pNext = NULL;

	//���½ڵ����
	newnode->pNext = pCurrent;
	pPrev->pNext = newnode;
};






//���������в���ĳ�����
LNode* FindNode(int val)   //valΪ��������
{
	if (NULL == pHead)
	{
		return;
	}
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == val)   //�ҵ���Ӧλ�ã�ֹͣѭ��
		{
			break;
		}
		//û�ҵ���Ӧλ������ָ�������
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == NULL)  //��ʱ˵��������û��ֵΪoldval�Ľڵ�
	{
		printf("���ҽ��δ�ҵ�!\n");;
	}
	printf("�ڵ����ڵ�ַΪ:%p\n", pCurrent);


}




//ɾ��ֵΪval�Ľڵ�
void DeleteNode(int delValue)
{

	if (NULL == pHead)
	{
		return;
	}

	//�Ͳ��뺯��һ����ԭ��
	struct LNode* pPrev = pHead;
	struct LNode* pCurrent = pPrev->pNext;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == delValue)   //�ҵ���Ӧλ�ã�ֹͣѭ��
		{
			break;
		}
		//û�ҵ���Ӧλ������ָ�������
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == NULL)
	{
		return;
	}
	//���½���������
	pPrev->pNext = pCurrent->pNext;
	//ɾ����Ӧ�ڵ�
	free(pCurrent);
	pCurrent = NULL;
};

//�������������
void ShowLinkList()
{
	if (NULL == pHead)
	{
		printf("��������");
	}

	else
	{ //����һ������ָ��
		struct LNode* pCurrent = pHead->pNext;

		while (pCurrent != NULL)
		{
			printf("%d   ", pCurrent->data);  //����������������ӡ
			pCurrent = pCurrent->pNext;
		}

	}
};

//���
void Destory_LinkList()
{
	if (NULL == pHead)
	{
		return;
	}
	//��������ָ��
	struct LNode* pCurrent = pHead->pNext;

	while (pCurrent != NULL)
	{
		//�ȱ�����һ�ڵ��ַ
		struct LNode* pNext = pCurrent->pNext;
		//��յ�ǰ�ڵ��ڴ�
		free(pCurrent);

		//ָ������ƶ�
		pCurrent = pNext;
		pHead->pNext = NULL;
		pEnd = pHead;
		printf("����ɹ�\n");
	}
};


int main()
{
	printf("********************************************\n");
	printf("*                  ���ܲ˵�                *\n");
	printf("* 1 ������������           2 ˳������½��*\n");
	printf("* 3 �޸Ľ��               4 ���ҽ��      *\n");
	printf("* 5 ����λ�ò�����       6 ɾ��ĳ���    *\n");
	printf("* 7 ���������������       8 ��ӡ��������  *\n");
	printf("********************************************\n");
	while (1)
	{
		int choice;
		printf("\n�����빦����ţ�");
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
			printf("������Ҫ�޸ĵĽ�㣺");
			scanf("%d", &e);
			ModifyNode(e);
			break;
		}
		case 4:
		{
			int e;
			printf("������Ҫ���ҵĽ�㣺");
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
			printf("������Ҫɾ���Ľ�㣺");
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