#pragma once


typedef struct LNode {
	int data;
	struct LNode* pNext;
	struct LNode* pPrior;
}LNode;

//创建双向链表（带头节点）,可以理解为创建一个空表，创建的链表中只包含一个头结点
void CreateLinkList();
//创建双向链表节点
void CreateNode(LNode* pNode);
//添加结点，结点后面依次按顺序添加
void AddNode();
//输出双向链表
void ShowLinkList();
//双向链表中查找某个结点
LNode* FindNode(int val);
//修改双向链表某一结点的值
void ModifyNode(int val);
// 双向链表特定位置插入结点
void InsertNode(int e, int nType);
//删除双向链表某一结点
void DeleteNode(int e);
//删除整个双向链表
void ClearLinkList();