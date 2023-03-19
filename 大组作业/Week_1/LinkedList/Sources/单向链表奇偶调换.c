#include<stdio.h>
#include<stdlib.h> 
#include <stdbool.h>

typedef struct ListNode 
{
    int val;
    struct ListNode* next;
} ListNode;


void Exchange(ListNode *L) 
{
    ListNode* p1;
    ListNode* p2;
    ListNode* p;    //p1为第一个节点，p和p2为第二个节点
    p1 = L->next;
    p = p2 = p1->next;

    while (p1->next != NULL && p1->next->next != NULL) 
    {
        p1->next = p1->next->next;
        p1 = p1->next;

        if (p2->next != NULL && p2->next->next != NULL) 
        {
            p2->next = p2->next->next;
            p2 = p2->next;
        }
    }
    p2->next = NULL;
    p1->next = p;

}