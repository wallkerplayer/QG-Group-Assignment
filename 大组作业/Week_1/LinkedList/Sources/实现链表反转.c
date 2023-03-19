#include<stdio.h>
#include<stdlib.h> 
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


//�ǵݹ�ʵ��
ListNode Reverse(ListNode *L) {
  ListNode *head, *temp;
    if (!L) 
    {
        return;
    }
    head = L;

    L = L->next;
    head->next = NULL;
    while (L) {
        temp = L;
        L = L->next;
        temp->next = head;

        head = temp;
    }

    return *head;

}


//�ݹ�ʵ��,�ڵ㷢���ı�
ListNode Reverse(ListNode *L) {
    //�ݹ鵽���һ���ڵ�
    if (L != NULL || L->next == NULL) {
        return *L;
    }
    else {  //�ݹ���ݲ���,�ȷ�ת��ߵĽڵ㣬�����ڵ�
        ListNode head = Reverse(L->next);
        //����ǰ�ڵ�����Ϊ��߽ڵ�ĺ�̽ڵ�
        L->next->next = L;
        L->next = NULL;
        return head;
    }

}