#include<stdio.h>
#include<stdlib.h>

struct ListNode* middleNode(struct ListNode* head);//��������

typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

int main() {
	//�����ڵ� 
	struct ListNode* lnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* lnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* lnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* lnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* lnode5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	lnode1->val = 1;
	lnode2->val = 2;
	lnode3->val = 3;
	lnode4->val = 4;
	lnode5->val = 5;
	lnode1->next = lnode2;
	lnode2->next = lnode3;
	lnode3->next = lnode4;
	lnode4->next = lnode5;
	lnode5->next = NULL;

	struct ListNode* temp = middleNode(lnode1);  //���ú����ҳ���ֵ

	//��ӡ��ֵ
	printf("%d", temp->val);
	
	return 0;
}
struct ListNode* middleNode(struct ListNode* head) 
{
	// ��ָ��
	struct ListNode* p = head;
	// ��ָ��
	struct ListNode* q = head;
	while (p != NULL && p->next != NULL) {
		q = q->next;
		p = p->next->next;
	}
	return q;
}
