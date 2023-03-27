#pragma once
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

void InitLQueue(LQueue* Q); //��ʼ������
void DestoryLQueue(LQueue* Q);  //���ٶ���
Status IsEmptyLQueue(const LQueue* Q);  //�������Ƿ�Ϊ��
Status GetHeadLQueue(LQueue* Q, void* e);   //�鿴��ͷԪ��
int LengthLQueue(LQueue* Q);    //ȷ�����г���
Status EnLQueue(LQueue* Q, void* data); //��Ӳ���
Status DeLQueue(LQueue* Q); //���Ӳ���
void ClearLQueue(LQueue* Q);    //��ն���
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q));   //������������
void LPrint(void* q);   //��������

//��ʼ������
void InitLQueue(LQueue* Q)
{
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));//�����µĽ����Ϊͷ�ڵ�����ͷβָ��ָ���� 
    Q->front->next = NULL;//ͷ�ڵ� 
    Q->length = 0;
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
    while (Q->front)//�ǿ�
    {
        //����
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
    if (Q->front == NULL && Q->rear == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void* e)
{
    if (Q->front == NULL)
    {
        printf("empty!\n");
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        printf("Quene:\n:");
        return TRUE;
    }
}

//ȷ�����г���
int LengthLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q))
    {
        return 0;
    }
    else
    {
        int* len = &Q->length;
        printf("length:%d\n", *len);
    }
}

//��Ӳ���
Status EnLQueue(LQueue* Q, void* data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) {  //���pΪ�տ��ٽ��ʧ��
        return FALSE;
    }
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;  //��rearָ��ָ���Ԫ�ص�nextָ���²���Ľ��p
    Q->rear = p;  //����rearָ��λ��
    Q->length++;
    return TRUE;
}

//���Ӳ���
Status DeLQueue(LQueue* Q)
{
    if (Q->rear == Q->front)
    {
        return FALSE;
    }
    Node* p = Q->front->next;   //��ָ��p����¼Ҫɾ���Ľ��
    Q->front->next = p->next;
    if (Q->rear == p)
    {		//���rearָ����ָ���Ԫ��Ϊ���һ��Ԫ�أ�����rearָ���λ��
        Q->rear = Q->front;
    }
    free(p);
    Q->length--;
    p = NULL;  //��Ȼfree������p������p��Ȼ���¼��ʱ�ĵ�ַ
    return TRUE;
}


//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
    Node* q = Q->front;
    printf("Quene��");
    while (q != NULL)
    {

        LPrint(q->data);
        q = q->next;
    }
    printf("\n");
}

//��������
void LPrint(void* q)
{
    printf("%d", *(int*)q);
}
#endif
