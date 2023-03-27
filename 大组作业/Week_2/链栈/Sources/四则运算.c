#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char val;//������
    struct node* next;//ָ����
}pnode;

typedef struct seqstack
{
    int size;   //��¼��С
    pnode* top; //ָ��ջ��Ԫ��
}phead;

//����ջ
phead* initstack()
{
    phead* itack = (phead*)malloc(sizeof(phead));    //����ͷ�ڵ�
    if (itack != NULL)
    {
        itack->top = NULL;
        itack->size = 0;
    }
    return itack;
}

//�ж�ջ�Ƿ�Ϊ��
int isempty(phead* istack)
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}

// ��ȡջ��Ԫ�ص����ݽڵ�
pnode* seqstack_top(phead* istack)
{
    if (istack->size != 0)
    {
        return istack->top;//���ص���ջ�������ݽڵ������ջ����Ԫ��
    }
    return NULL;
}

//�ҳ�ջ��Ԫ��
pnode* seqstack_pop(phead* istack)
{
    if (isempty(istack) == 0)
    {
        pnode* account = istack->top;
        istack->top = istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;
        return account;//���ص��������ݽڵ�
    }
    return NULL;
}


void seqstack_push(phead* istack, char x)//ѹջ(��ջ)
{
    pnode* temp;//����ѹջ�����ݽڵ�
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//���������
    temp->next = istack->top;//����ջ�������ݽڵ�
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}


char buffer[256] = { 0 };//��������ÿ�����ݶ���ʼ��Ϊ'\0'

void char_put(char ch)//�������ַ�����
{
    static int index = 0;
    buffer[index++] = ch;
}

//�����Ƚ����ȼ�
int priority(char ch)
{
    int ret = 0;
    switch (ch)
    {
    case '+':    //��һ��caseû��break���ʱ���������ִ��
    case '-':
        ret = 1;
        break;
    case '*':
    case '/':
        ret = 2;
        break;
    default:
        break;
    }
    return ret;
}

//�ж��ǲ�������
int is_number(char ch)
{
    return(ch >= '0' && ch <= '9');//���ַ���1�����򷵻�0
}

//�ж��ǲ��������
int is_operator(char ch)
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//�ǲ���������
int is_left(char ch)
{
    return(ch == '(');
}

//�ǲ���������
int is_right(char ch)
{
    return(ch == ')');
}
int transform(char str[])
{
    phead* istack = initstack(); //����һ��ջ
    int i = 0;
    while (str[i] != '\0') //���������ַ���
    {
        //�ж��ǲ�������
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//����1Ҳ������,��ֱ�ӷ�
            {
                char_put(str[i]);//����ֱ�����
            }
            else//���治������,���һ���ո���Ϊ�ָ���
            {
                char_put(str[i]);
                char_put(' ');
            }
        }
        else if (is_operator((str[i])) == 1)
        {
            if (str[i + 1] == '0' && str[i] == '/')
            {
                printf("ILLEGAL");
                return 0;
            }
            if (isempty(istack) == 0)
            {
                while ((isempty(istack) == 0) && (priority(str[i]) <= (priority(seqstack_top(istack)->val))))//ջ��Ϊ�ղ�������������ȼ�������ջ��
                {
                    char_put(seqstack_pop(istack)->val);//����������ջ���͵���ֱ������������
                    char_put(' ');
                }
            }
            seqstack_push(istack, str[i]); //�ٽ����������ջ
        }
        else if (is_left(str[i])) //������ֱ����ջ
        {
            seqstack_push(istack, str[i]);
        }
        else if (is_right(str[i])) //�ж��ǲ���������
        {
            while (is_left(seqstack_top(istack)->val) != 1)//��ջ������������
            {
                char_put(seqstack_pop(istack)->val);//�������洢�������
                if (isempty(istack) == 1)//ջΪ����δ�ҵ�������
                {
                    printf("û��ƥ�䵽������\n");
                    return -1;
                }
            }
            //��ʱƥ�䵽��������
            seqstack_pop(istack);
            //����������,���ﲢ���ñ���,���������������
        }
        else
        {
            printf("�в���ʶ����ַ�\n");
            return -1;
        }
        i++;
    }
  
    //�������ַ���ĩβ
    if (str[i] == '\0')
    {
        while (isempty(istack) == 0)  //ջ��Ԫ��ȫ����ջ
        {
            if (seqstack_top(istack)->val == '(')//ջ��Ԫ��Ϊ������
            {
                printf("��û��ƥ�䵽��'(',ȱ��')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->val);//��ջ��Ԫ�ط������մ�
        }
    }
    else
    {
        printf("����û����ɣ�\n");
    }
    return 1;
}


int main()
{
    char str[1024] = { 0 };//������ÿ��Ԫ�ظ�ֵΪ'\0'
    printf("***********************************\n");
    printf("����������������ʽ��+��-��*��/��:\n");
    scanf("%s", str);
    int number = transform(str);
    if (number == -1)
    {
        printf("���ʽת������:\n");
    }
    else if (number == 1)
    {
        printf("ת����ı��ʽΪ: %s\n", buffer);
    }
    else
    {
        return 0;
    }
}