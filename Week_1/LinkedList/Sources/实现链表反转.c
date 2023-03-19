#include<stdio.h>
#include<stdlib.h> 
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


//非递归实现
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


//递归实现,节点发生改变
ListNode Reverse(ListNode *L) {
    //递归到最后一个节点
    if (L != NULL || L->next == NULL) {
        return *L;
    }
    else {  //递归回溯部分,先反转后边的节点，到最后节点
        ListNode head = Reverse(L->next);
        //将当前节点设置为后边节点的后继节点
        L->next->next = L;
        L->next = NULL;
        return head;
    }

}