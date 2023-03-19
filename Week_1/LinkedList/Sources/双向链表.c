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

//ͷָ��
LNode* pHead = NULL;   

//βָ��
LNode* pEnd = NULL;    




//����˫������
void CreateLinkList()
{
	LNode* pNew = malloc(sizeof(LNode));
	pNew->data = NULL;    //ͷ��㲻��Ԫ��
	pNew->pNext = NULL;
	pNew->pPrior = NULL;

	pHead = pNew;//��ͷ��βָ�붼ָ��ͷ���
	pEnd = pNew;
	printf("��������ɹ�!\n");
}


//����˫������ڵ�
void CreateNode(LNode* pNode)
{
	if (NULL != pNode)
	{
		printf("�����������ݣ�");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
	pNode->pPrior = NULL;
}


//��ӽ�㣬���������ΰ�˳�����
void AddNode()
{
	LNode* pTemp = pEnd;
	LNode* pNew = malloc(sizeof(LNode));
	CreateNode(pNew);

	pEnd->pNext = pNew;       //nextָ��ָ��new�ڵ�
	pEnd = pNew;              //��βָ��ָ��new�ڵ�
	pEnd->pPrior = pTemp;     //��new�ڵ�����һ�ڵ�˫������
	printf("��ӽ��ɹ�\n");
}

//���˫������
void ShowLinkList()
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior) //�ж������Ƿ����
	{
		LNode* pTemp = pEnd;  //pTempָ��ָ��β��㣬���ڲ���˫���������ȷ�ԣ��Ƿ��ܹ��Ӻ���ǰ����
		printf("����ĵ�������Ϊ��");            
		while (pHead != pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->pPrior;
		}
	}
	else
	{
		printf("˫������Ϊ�ձ�!\n");
	}
}

//˫�������в���ĳ�����
LNode* FindNode(int val)   //valΪ��������
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pTemp = pEnd;
		while (pTemp != pHead)
		{
			if (val == pTemp->data)
			{
				printf("�ڵ����ڵ�ַΪ:%p\n", pTemp);
				return pTemp;
			}
			pTemp = pTemp->pPrior;
		}
	}
	return NULL;
}

//�޸�˫������ĳһ����ֵ
void ModifyNode(int val)
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pNode = FindNode(val);
		if (NULL != pNode)
		{
			printf("�������޸ĺ�Ľ�����ݣ�");
			scanf("%d", &pNode->data);
			printf("�޸Ľ�����ݳɹ�!\n");
		}
		else
		{
			printf("��Ҫ�޸ĵĽ��δ�ҵ�!\n");
		}
	}
}

//˫�������ض�λ�ò�����
void InsertNode(int e, int nType)   //eΪ������Ӧ��ֵ��nType��ʾ����ķ�ʽ��nType=0Ϊǰ�壬nType=1Ϊ���
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pPos = FindNode(e);
		LNode* pNew = malloc(sizeof(LNode));
		CreateNode(pNew);

		if (0 == nType)  //ǰ��
		{
			pNew->pNext = pPos;
			pNew->pPrior = pPos->pPrior;
			pNew->pPrior->pNext = pNew;
			pPos->pPrior = pNew;
		}
		else  //���
		{
			if (pPos == pEnd)   //�������λ�������һ�����
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
		printf("������ɹ�!\n");
	}
}


//ɾ��˫������ĳһ���
void DeleteNode(int e)
{
	if (NULL != pHead->pNext && NULL == pHead->pPrior)
	{
		LNode* pPos = FindNode(e);

		if (pEnd == pPos)   //ɾ�����һ�����
		{
			pPos->pPrior->pNext = NULL;
			pEnd = pPos->pPrior;
		}
		else                    //ɾ������λ�ý��
		{
			pPos->pPrior->pNext = pPos->pNext;
			pPos->pNext->pPrior = pPos->pPrior;
		}
		free(pPos);   //�ͷ��ڴ�ռ�
		printf("ɾ�����ɹ�!\n");
	}
}

//ɾ������˫������
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
		printf("�������ɹ�!\n");
	}
}


int main()
{
	printf("********************************************\n");
	printf("*                  ���ܲ˵�                *\n");
	printf("* 1 ����˫������           2 ˳������½��*\n");
	printf("* 3 �޸Ľ��               4 ���ҽ��      *\n");
	printf("* 5 ����λ�ò�����       6 ɾ��ĳ���    *\n");
	printf("* 7 �������˫������       8 ��ӡ��������  *\n");
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
			int e, type;
			printf("������Ҫ�����λ�úͲ��뷽ʽ(1Ϊǰ�壬0Ϊ���)(��������֮���ÿո�ֿ�)��");
			scanf("%d %d", &e, &type);
			InsertNode(e, type);
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
