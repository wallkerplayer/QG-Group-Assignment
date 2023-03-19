#pragma once


typedef struct LNode {
	int data;
	struct LNode* pNext;
	struct LNode* pPrior;
}LNode;

//����˫��������ͷ�ڵ㣩,�������Ϊ����һ���ձ�������������ֻ����һ��ͷ���
void CreateLinkList();
//����˫������ڵ�
void CreateNode(LNode* pNode);
//��ӽ�㣬���������ΰ�˳�����
void AddNode();
//���˫������
void ShowLinkList();
//˫�������в���ĳ�����
LNode* FindNode(int val);
//�޸�˫������ĳһ����ֵ
void ModifyNode(int val);
// ˫�������ض�λ�ò�����
void InsertNode(int e, int nType);
//ɾ��˫������ĳһ���
void DeleteNode(int e);
//ɾ������˫������
void ClearLinkList();