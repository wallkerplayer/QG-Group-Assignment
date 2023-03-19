#include<stdio.h>
#include<stdlib.h> 
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


//通过设置快慢指针判断是否成环，如果快指针可与慢指针重合，则链表成环
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


