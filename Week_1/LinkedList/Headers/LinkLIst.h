#pragma once

//����ڵ���������
	struct LNode
	{
		int data;
		struct LNode* pNext;
	};

	//�����ڵ�
	void CreateNode(LNode* pNode);
	// ������������
	void CreateLinkList();
	//��ӽڵ�
	void AddNode();
	//�޸�˫������ĳһ����ֵ
	void ModifyNode(int oldval);
	//��ֵΪoldval�Ľڵ�ǰ�����µ�����newval
	void InsertNode();
	//˫�������в���ĳ�����
	LNode* FindNode(int val);
	//ɾ��ֵΪval�Ľڵ�
	void DeleteNode(int delValue);
	//�������������
	void ShowLinkList();
	//���
	void Destory_LinkList();



