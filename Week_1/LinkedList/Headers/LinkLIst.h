#pragma once

//定义节点数据类型
	struct LNode
	{
		int data;
		struct LNode* pNext;
	};

	//创建节点
	void CreateNode(LNode* pNode);
	// 创建单向链表
	void CreateLinkList();
	//添加节点
	void AddNode();
	//修改双向链表某一结点的值
	void ModifyNode(int oldval);
	//在值为oldval的节点前插入新的数据newval
	void InsertNode();
	//双向链表中查找某个结点
	LNode* FindNode(int val);
	//删除值为val的节点
	void DeleteNode(int delValue);
	//遍历并输出链表
	void ShowLinkList();
	//清空
	void Destory_LinkList();



