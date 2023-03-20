#include <stdio.h>
#include <stdlib.h>
//人工Boolean
#define bool int
#define true 1
#define false 0

typedef struct LNode //链表定义
{
    double a;
    int n;
    struct LNode *next;
} LNode, *LinkList;

bool Print(LinkList list);                         //打印链表
bool Add(LinkList list);                           //按顺序新增节点
int PlaceInList(LinkList list, int n);             //找出特定指数在表中的位置
LinkList IniList();                                //初始化表
LinkList CreatList(int m);                         //新建长度为n的表
LinkList is_InList(LinkList list, int n);          //判断某指数是否已在表内
LinkList AddLists(LinkList list1, LinkList list2); //多项式加法
LinkList SubLists(LinkList list1, LinkList list2); //多项式减法
LinkList MulList(LinkList list1, LinkList list2);  //多项式乘法
bool AddArg(LinkList list, int n, double a);       //带参数插入
bool DeleteNodeZero(LinkList list);                //删除系数0的节点

