#include <stdio.h>
#include <stdlib.h>
//�˹�Boolean
#define bool int
#define true 1
#define false 0

typedef struct LNode //������
{
    double a;
    int n;
    struct LNode *next;
} LNode, *LinkList;

bool Print(LinkList list);                         //��ӡ����
bool Add(LinkList list);                           //��˳�������ڵ�
int PlaceInList(LinkList list, int n);             //�ҳ��ض�ָ���ڱ��е�λ��
LinkList IniList();                                //��ʼ����
LinkList CreatList(int m);                         //�½�����Ϊn�ı�
LinkList is_InList(LinkList list, int n);          //�ж�ĳָ���Ƿ����ڱ���
LinkList AddLists(LinkList list1, LinkList list2); //����ʽ�ӷ�
LinkList SubLists(LinkList list1, LinkList list2); //����ʽ����
LinkList MulList(LinkList list1, LinkList list2);  //����ʽ�˷�
bool AddArg(LinkList list, int n, double a);       //����������
bool DeleteNodeZero(LinkList list);                //ɾ��ϵ��0�Ľڵ�

