#include<stdio.h>
#include<stdlib.h> 
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


//ͨ�����ÿ���ָ���ж��Ƿ�ɻ��������ָ�������ָ���غϣ�������ɻ�
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode* pre = head->next;
    struct ListNode* lag = head;
    while (pre) {
        if (lag == pre) {
            return true;
        }
        lag = lag->next;
        pre = pre->next;
        if (pre) {
            pre = pre->next;
        }
    }
    return false;
}


