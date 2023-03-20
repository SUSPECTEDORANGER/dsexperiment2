#include "stdio.h"
#include "stdlib.h"
#include "DSexperiment2.h"

//������������N�ε��±�
LinkList CreatList(int m){
	LinkList list = IniList(); //��ʼ��
	printf("Please enter the Coefficient and index!\n");
	for (int i = 0; i < m; i++)
	    Add(list); //���ò��뺯��
	return list;   //�������ɺõı�ͷ
}

//�ж�ָ��n�Ƿ��Ѿ������ڱ��У��������򷵻ظýڵ㣬�����ڷ��ؿ�
LinkList is_InList(LinkList list, int n){
	LinkList q;
	q = list;
	if (!list || !list->next)
	    return NULL;
	while (q) {//�����ж�
	    if (n == q->n)
	        return q; //�ҵ����򷵻ض�Ӧ�ڵ�
	    q = q->next;
	}
	return NULL;
}

//һ������Ҫscanf��˳�����ڵ㺯�������ڳ˷�ʱ���룩���ɹ�true��ʧ��false
bool AddArg(LinkList list, int n, double a){
	int m;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	LinkList q, t;
	q = list;
	if (!list)
	    return false;       //�ձ�ʧ��
	if (list->next == NULL) {//ֻ�б�ͷ���ڱ�ͷ�����
	    p->next = q->next;
	    p->a = a;
	    p->n = n;
	    q->next = p;
	}
	else {//��������Ԫ��
	    t = is_InList(list, n); //�ж�ָ��n�Ƿ��Ѿ������ڱ��У��������򷵻ظýڵ㣬�����ڷ��ؿ�
	    if (t)
	        t->a += a; //�ϲ�ͬ����
	    else {//ָ��n�����ڣ����ҵ���ȷ��λ�ò���
	        m = PlaceInList(list, n);   //�ҵ�n���ݵ���ȷλ�ã���������λ��
	        for (int i = 0; i < m; i++) //������ȷλ��ǰ�ڵ�
	            q = q->next;
	        p->n = n; //����
	        p->a = a;
	        p->next = q->next;
	        q->next = p;
	    }
	}
	return true;
}

//һ����Ҫscanf��˳�����ڵ㺯��������ʵ������һ�������ƣ�����ͬ�����ݵĴ�����������ͬ���ɹ�true��ʧ��false
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
	    	t->a = a_temp; //�滻
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

//�ҵ�n���ݵ���ȷλ�ã���������λ��
int PlaceInList(LinkList list, int n){
	if (!list)
	    return -1;
	LinkList p;
	p = list->next;
	int i = 0;
	while (p != NULL && n > p->n) {//��p����β�ڵ����������ݴδ���p���ݴ�ʱ������������
	    p = p->next;
	    i++;
	}
	return i; //����λ��
}

//��ʼ����������ͷ���ɣ�0��-1��
LinkList IniList(){
	LinkList list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	list->a = 0;
	list->n = -1;
	return list;
}

//��ӡ����ʽ���ɹ�true��ʧ��false
bool Print(LinkList list){
	if (!list){	
		printf("NOT CREATED!\n");
		return false;
	}  
	LinkList p = list;
	DeleteNodeZero(list); //ɾ������ϵ��Ϊ�����
	while (p){
	    if (p->n == -1) {//��ͷ
            if (!p->next){
	            printf("0\n");
	            return false;
	        }
	    }
	    else if (p->n == 0) {//������������
	        if (p->next == NULL) //��������һ����������
	            printf("%.0lf", p->a); //a
	        else{ //�����һ��������
	            if (p->next->a < 0)
	                printf("%.0lf ", p->a);
	            else
	                printf("%.0lf +", p->a); //a +
	        }
	    }
	    else if (p->n == 1) {//һ������ax
	        if (p->next == NULL){ //��Ϊ���һ����������
	            if (p->a == 1) //ϵ����1�����x
	                printf("x");
	            else if (p->a == -1) //ϵ����-1�����-x
	                printf("-x");
	            else
	                printf("%.0lfx", p->a); //һ������ax
	        }
	        else if (p->next->a < 0) {//�������һ���һ��Ϊ����
	            if (p->a == 1)
	                printf("x ");
	            else if (p->a == -1)
	                printf("-x ");
	            else
	                printf("%.0lfx ", p->a); //ax ����������һ���Լ��ṩ��
	        }
	        else {//�����һ���һ��Ϊ����
	                if (p->a == 1)
	                    printf("x +");
	                else if (p->a == -1)
	                    printf("-x +");
	                else
	                    printf("%.0lfx +", p->a); //ax +��������ţ�
	        }
	    }
	    else{ //һ������ax^n
	        if (p->next == NULL) {//���һ��
	            if (p->a == 1) //ϵ��Ϊ1
	                printf("x^%d ", p->n);
	            else if (p->a == -1) //ϵ��Ϊ-1
	                printf("-x^%d ", p->n);
	            else                                 //һ��ϵ��
	                printf("%.0lfx^%d", p->a, p->n); //ax^n
	        }
	        else if (p->next->a < 0) {//��һ��ϵ��С��0
	            if (p->a == 1)
	                printf("x^%d ", p->n);
	            else if (p->a == -1)
	                printf("-x^%d ", p->n);
	            else
	                printf("%.0lfx^%d ", p->a, p->n); //ax^n -
	        }
	        else {//��һ��ϵ������0
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

//�ϲ�˳���������
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
		else if (list1->n < list2->n) {//����һ�ڵ�ָ��С�ڱ��������һ�ڵ��������±�����һ����ƶ�
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if(list1->n > list2->n){//����һ�ڵ�ָ�����ڱ����������ڵ��������±����������ƶ�
			temp->a = list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else{//��ȣ������ڵ�ڵ�ֵ��ӣ�ͬʱ�����������
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

//�ϲ�˳�������������ϸ��ͬ�ӷ������ڴ������ʱ��ͬ
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
		else if (list1->n < list2->n) {//����һ�ڵ�ָ��С�ڱ��������һ�ڵ��������±�����һ����ƶ�
			temp->a = list1->a;
			temp->n = list1->n;
			list1 = list1->next;
		}
		else if(list1->n > list2->n){//����һ�ڵ�ָ�����ڱ����������ڵ��������±����������ƶ�
			temp->a = list2->a;
			temp->n = list2->n;
			list2 = list2->next;
		}
		else{//��ȣ������ڵ�ڵ�ֵ��ӣ�ͬʱ�����������
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

//���������
LinkList MulList(LinkList list1, LinkList list2){
    LinkList p, list3, q, t;
    //LinkList t = (LinkList)malloc(sizeof(LNode));
    list3 = IniList(list3);
    t = list3->next;	    
	for (p = list1->next; p; p = p->next){
	    for (q = list2->next; q; q = q->next)
	        AddArg(list3, p->n + q->n, q->a * p->a); //��˳���½ڵ�����3
	    }
	return list3;
}

//ɾ��ϵ��Ϊ0�Ľڵ㣬������Щ�ڵ������ʱ�����õģ���ɾ��
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
        return true; //��ɾ���˽ڵ㣬������
		
    return false;
}