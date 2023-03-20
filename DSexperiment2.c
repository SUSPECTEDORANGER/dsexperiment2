#include "stdio.h"
#include "stdlib.h"
#include "DSexperiment2.h"

//创建可以输入N次的新表
LinkList CreatList(int m){
	LinkList list = IniList(); //初始化
	printf("Please enter the Coefficient and index!\n");
	for (int i = 0; i < m; i++)
	    Add(list); //调用插入函数
	return list;   //返回生成好的表头
}

//判断指数n是否已经存在于表中，若存在则返回该节点，不存在返回空
LinkList is_InList(LinkList list, int n){
	LinkList q;
	q = list;
	if (!list || !list->next)
	    return NULL;
	while (q) {//遍历判断
	    if (n == q->n)
	        return q; //找到了则返回对应节点
	    q = q->next;
	}
	return NULL;
}

//一个不需要scanf的顺序插入节点函数（用于乘法时插入），成功true，失败false
bool AddArg(LinkList list, int n, double a){
	int m;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	LinkList q, t;
	q = list;
	if (!list)
	    return false;       //空表失败
	if (list->next == NULL) {//只有表头，在表头后插入
	    p->next = q->next;
	    p->a = a;
	    p->n = n;
	    q->next = p;
	}
	else {//表内已有元素
	    t = is_InList(list, n); //判断指数n是否已经存在于表中，若存在则返回该节点，不存在返回空
	    if (t)
	        t->a += a; //合并同类项
	    else {//指数n不存在，则找到正确的位置插入
	        m = PlaceInList(list, n);   //找到n次幂的正确位置，返回整型位置
	        for (int i = 0; i < m; i++) //遍历正确位置前节点
	            q = q->next;
	        p->n = n; //插入
	        p->a = a;
	        p->next = q->next;
	        q->next = p;
	    }
	}
	return true;
}

//一个需要scanf的顺序插入节点函数，具体实现与上一函数类似，仅在同次数幂的处理上有所不同，成功true，失败false
bool Add(LinkList list){
	int n_temp, m;
	double a_temp;
	scanf("%lf %d", &a_temp, &n_temp);
	LinkList p = (LinkList)malloc(sizeof(LNode));
	LinkList q, t;
	q = list;
	if (!list)
	    return false;
	if (list->next == NULL){
	    p->next = q->next;
	    p->a = a_temp;
	    p->n = n_temp;
	    q->next = p;
	}
	else{
	    t = is_InList(list, n_temp);
	    if (t)
	    	t->a = a_temp; //替换
	    else{
	        m = PlaceInList(list, n_temp);
	        for (int i = 0; i < m; i++)
	        	q = q->next;
	        p->n = n_temp;
	        p->a = a_temp;
	        p->next = q->next;
	        q->next = p;
	    }
	}
	return true;
}

//找到n次幂的正确位置，返回整型位置
int PlaceInList(LinkList list, int n){
	if (!list)
	    return -1;
	LinkList p;
	p = list->next;
	int i = 0;
	while (p != NULL && n > p->n) {//当p不是尾节点且需插入的幂次大于p的幂次时，继续向后遍历
	    p = p->next;
	    i++;
	}
	return i; //返回位置
}

//初始化链表。将表头赋成（0，-1）
LinkList IniList(){
	LinkList list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	list->a = 0;
	list->n = -1;
	return list;
}

//打印多项式，成功true，失败false
bool Print(LinkList list){
	if (!list){	
		printf("NOT CREATED!\n");
		return false;
	}  
	LinkList p = list;
	DeleteNodeZero(list); //删除表中系数为零的项
	while (p){
	    if (p->n == -1) {//表头
            if (!p->next){
	            printf("0\n");
	            return false;
	        }
	    }
	    else if (p->n == 0) {//常数项，输出常数
	        if (p->next == NULL) //如果是最后一项，不输出符号
	            printf("%.0lf", p->a); //a
	        else{ //非最后一项，输出符号
	            if (p->next->a < 0)
	                printf("%.0lf ", p->a);
	            else
	                printf("%.0lf +", p->a); //a +
	        }
	    }
	    else if (p->n == 1) {//一次项，输出ax
	        if (p->next == NULL){ //若为最后一项，不输出符号
	            if (p->a == 1) //系数是1，输出x
	                printf("x");
	            else if (p->a == -1) //系数是-1，输出-x
	                printf("-x");
	            else
	                printf("%.0lfx", p->a); //一般项，输出ax
	        }
	        else if (p->next->a < 0) {//不是最后一项，后一项为负数
	            if (p->a == 1)
	                printf("x ");
	            else if (p->a == -1)
	                printf("-x ");
	            else
	                printf("%.0lfx ", p->a); //ax （符号由下一项自己提供）
	        }
	        else {//非最后一项，后一项为正数
	                if (p->a == 1)
	                    printf("x +");
	                else if (p->a == -1)
	                    printf("-x +");
	                else
	                    printf("%.0lfx +", p->a); //ax +（输出正号）
	        }
	    }
	    else{ //一般项，输出ax^n
	        if (p->next == NULL) {//最后一项
	            if (p->a == 1) //系数为1
	                printf("x^%d ", p->n);
	            else if (p->a == -1) //系数为-1
	                printf("-x^%d ", p->n);
	            else                                 //一般系数
	                printf("%.0lfx^%d", p->a, p->n); //ax^n
	        }
	        else if (p->next->a < 0) {//后一项系数小于0
	            if (p->a == 1)
	                printf("x^%d ", p->n);
	            else if (p->a == -1)
	                printf("-x^%d ", p->n);
	            else
	                printf("%.0lfx^%d ", p->a, p->n); //ax^n -
	        }
	        else {//后一项系数大于0
	            if (p->a == 1)
	                printf("x^%d +", p->n);
	            else if (p->a == -1)
	                printf("-x^%d +", p->n);
	            else
	                printf("%.0lfx^%d +", p->a, p->n); //ax^n +
	        }
	    }
	    p = p->next;
	}

	printf("\n");
	return true;
}

//合并顺序相加两表
LinkList AddLists(LinkList list1, LinkList list2){
	if (!list1&&!list2)
		return NULL;
	LinkList temp = NULL;
	LinkList list3 = NULL;
	LinkList end = NULL;
	while(list1 || list2){
		temp = (LinkList)malloc(sizeof(LNode));
		temp->next = NULL;
		if(!list1){
			temp->a = list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else if(!list2){
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if (list1->n < list2->n) {//若表一节点指数小于表二，将表一节点插入接在新表，将表一向后移动
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if(list1->n > list2->n){//若表一节点指数大于表二，将表二节点插入接在新表，将表二向后移动
			temp->a = list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else{//相等，则将两节点节点值相加，同时将两表向后移
			temp->a = list1->a + list2->a;
			temp->n = list1->n;
			list1 = list1->next;
			list2 = list2->next;
		}

		if(!list3)
			list3 = temp;
		else{
			end->next = temp;
		}
		end = temp;
	}
	return list3;
}

//合并顺序相减二表，具体细节同加法，仅在处理相等时不同
LinkList SubLists(LinkList list1, LinkList list2){
	if (!list1&&!list2)
		return NULL;
	LinkList temp = NULL;
	LinkList list3 = NULL;
	LinkList end = NULL;
	while(list1 || list2){
		temp = (LinkList)malloc(sizeof(LNode));
		temp->next = NULL;
		if(!list1){
			temp->a = -list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else if(!list2){
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if (list1->n < list2->n) {//若表一节点指数小于表二，将表一节点插入接在新表，将表一向后移动
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if(list1->n > list2->n){//若表一节点指数大于表二，将表二节点插入接在新表，将表二向后移动
			temp->a = list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else{//相等，则将两节点节点值相加，同时将两表向后移
			temp->a = list1->a - list2->a;
			temp->n = list1->n;
			list1 = list1->next;
			list2 = list2->next;
		}

		if(!list3)
			list3 = temp;
		else{
			end->next = temp;
		}
		end = temp;
	}
	return list3;
}

//将两表相乘
LinkList MulList(LinkList list1, LinkList list2){
    LinkList p, list3, q, t;
    //LinkList t = (LinkList)malloc(sizeof(LNode));
    list3 = IniList(list3);
    t = list3->next;	    
	for (p = list1->next; p; p = p->next){
	    for (q = list2->next; q; q = q->next)
	        AddArg(list3, p->n + q->n, q->a * p->a); //按顺序将新节点插入表3
	    }
	return list3;
}

//删除系数为0的节点，由于这些节点在输出时是无用的，故删除
bool DeleteNodeZero(LinkList list){
	int flag = 0;
    LinkList p = list;
    LinkList q;
    if (!list || !list->next)
        return false;
    while (p->next != NULL){
        if (p->next->a == 0){
	        q = p->next;
	        p->next = q->next;
            free(q);
		    flag++;
	    }
        else
            p = p->next;
	}
    if (flag)
        return true; //若删除了节点，返回真
		
    return false;
}