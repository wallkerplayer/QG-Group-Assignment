#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char val;//数据域
    struct node* next;//指针域
}pnode;

typedef struct seqstack
{
    int size;   //记录大小
    pnode* top; //指向栈顶元素
}phead;

//创建栈
phead* initstack()
{
    phead* itack = (phead*)malloc(sizeof(phead));    //创建头节点
    if (itack != NULL)
    {
        itack->top = NULL;
        itack->size = 0;
    }
    return itack;
}

//判断栈是否为空
int isempty(phead* istack)
{
    if (istack->top == NULL)
    {
        return 1;//栈为空
    }
    return 0;//栈不为空
}

// 获取栈顶元素的数据节点
pnode* seqstack_top(phead* istack)
{
    if (istack->size != 0)
    {
        return istack->top;//返回的是栈顶的数据节点而不是栈顶的元素
    }
    return NULL;
}

//找出栈顶元素
pnode* seqstack_pop(phead* istack)
{
    if (isempty(istack) == 0)
    {
        pnode* account = istack->top;
        istack->top = istack->top->next;//指向栈顶下一个元素
        istack->size--;
        return account;//返回弹出的数据节点
    }
    return NULL;
}


void seqstack_push(phead* istack, char x)//压栈(入栈)
{
    pnode* temp;//进行压栈的数据节点
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//填充数据域
    temp->next = istack->top;//连接栈顶的数据节点
    istack->top = temp;//充当栈顶
    istack->size++;//记录栈大小的变化
    return;
}


char buffer[256] = { 0 };//对数组中每个数据都初始化为'\0'

void char_put(char ch)//用来将字符放入
{
    static int index = 0;
    buffer[index++] = ch;
}

//用来比较优先级
int priority(char ch)
{
    int ret = 0;
    switch (ch)
    {
    case '+':    //上一个case没有break语句时会继续向下执行
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

//判断是不是数字
int is_number(char ch)
{
    return(ch >= '0' && ch <= '9');//数字返回1，否则返回0
}

//判断是不是运算符
int is_operator(char ch)
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//是不是左括号
int is_left(char ch)
{
    return(ch == '(');
}

//是不是右括号
int is_right(char ch)
{
    return(ch == ')');
}
int transform(char str[])
{
    phead* istack = initstack(); //创建一个栈
    int i = 0;
    while (str[i] != '\0') //遍历整个字符串
    {
        //判断是不是数字
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//后面1也是数字,则直接放
            {
                char_put(str[i]);//数字直接输出
            }
            else//后面不是数字,添加一个空格作为分隔符
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
                while ((isempty(istack) == 0) && (priority(str[i]) <= (priority(seqstack_top(istack)->val))))//栈不为空并且新运算符优先级不高于栈顶
                {
                    char_put(seqstack_pop(istack)->val);//满足条件的栈顶就弹出直到不满足条件
                    char_put(' ');
                }
            }
            seqstack_push(istack, str[i]); //再将该运算符入栈
        }
        else if (is_left(str[i])) //左括号直接入栈
        {
            seqstack_push(istack, str[i]);
        }
        else if (is_right(str[i])) //判断是不是右括号
        {
            while (is_left(seqstack_top(istack)->val) != 1)//若栈顶不是左括号
            {
                char_put(seqstack_pop(istack)->val);//弹出并存储到结果串
                if (isempty(istack) == 1)//栈为空仍未找到左括号
                {
                    printf("没有匹配到左括号\n");
                    return -1;
                }
            }
            //此时匹配到了左括号
            seqstack_pop(istack);
            //弹出左括号,这里并不用保存,即两个括号相抵消
        }
        else
        {
            printf("有不能识别的字符\n");
            return -1;
        }
        i++;
    }
  
    //遍历到字符串末尾
    if (str[i] == '\0')
    {
        while (isempty(istack) == 0)  //栈中元素全部出栈
        {
            if (seqstack_top(istack)->val == '(')//栈顶元素为左括号
            {
                printf("有没有匹配到的'(',缺少')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->val);//将栈中元素放入最终串
        }
    }
    else
    {
        printf("遍历没有完成！\n");
    }
    return 1;
}


int main()
{
    char str[1024] = { 0 };//将数组每个元素赋值为'\0'
    printf("***********************************\n");
    printf("请输入四则运算表达式（+，-，*，/）:\n");
    scanf("%s", str);
    int number = transform(str);
    if (number == -1)
    {
        printf("表达式转换错误:\n");
    }
    else if (number == 1)
    {
        printf("转化后的表达式为: %s\n", buffer);
    }
    else
    {
        return 0;
    }
}