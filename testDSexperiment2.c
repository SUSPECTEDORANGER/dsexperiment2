#include "stdio.h"
#include "stdlib.h"
#include "DSexperiment2.h"

int main(void){

	LinkList list1 = NULL;
	LinkList list2 = NULL;
	LinkList list3 = NULL;

	int i, n, flag = 1;

	printf("====================================LinkList=====================================\n");
	printf("1.Create List       2.Add List        3.Sub List          4.Mul List       0.quit\n");
	printf("=================================================================================\n");
	scanf("%d", &i);

	while (i){
		switch (i){
            case 1: //生成指定长度的链表
	            printf("Now create a list!\nEnter flag 1 for list1,flag 2 for list 2.\n");
	            scanf("%d", &flag);
				printf("Please enter the size of the polynomial!\n");
	            scanf("%d", &n);
	            if (flag == 1){	
					if(list1){//释放内存
						if(list1->next){//并非只有头节点
							LinkList p = list1->next;
							while(p){
								free(list1);
								list1 = p;
								p = p->next;
							}
						}
						free(list1);//只有头节点
						list1 = NULL;
					}
	                list1 = CreatList(n);
	                printf("The result is: ");
	                Print(list1);
	            }
	            else if (flag == 2){
					if(list2){//释放内存
						if(list2->next){//并非只有头节点
							LinkList p = list2->next;
							while(p){
								free(list2);
								list2 = p;
								p = p->next;
							}
						}
						free(list2);//只有头节点
						list2 = NULL;
					}
	                list2 = CreatList(n);
	                printf("The result is: ");
	                Print(list2);
	            }
	            else
	                printf("Flag wrong!\n");
	            break;

			case 2: //多项式相加
	            printf("Now merge the two polynomials!\n");
	            printf("The first list is: ");
	            Print(list1);
	            printf("The second list is: ");
	            Print(list2);
	            printf("The result is: ");
	            list3 = AddLists(list1, list2);
	            Print(list3);
	            break;

	        case 3: //多项式相减
	            printf("Now sub the two polynomials!\n");
	            printf("The first list is: ");
	            Print(list1);
	            printf("The second list is: ");
	            Print(list2);
	            printf("The result is: ");
	            list3 = SubLists(list1, list2);
	            Print(list3);
	            break;

	        case 4: //多项式相乘
	            printf("Now multiply the two polynomials!\n");
	            printf("The first list is: ");
	            Print(list1);
	            printf("The second list is: ");
	            Print(list2);
	            printf("The result is: ");
	            list3 = MulList(list1, list2);
	            Print(list3);
	            break;
				
	        default:
	            break;

	        }
		printf("====================================LinkList=====================================\n");
		printf("1.Create List       2.Add List        3.Sub List          4.Mul List       0.quit\n");
		printf("=================================================================================\n");
	    scanf("%d", &i);
	}

	printf("End.\n");
	system("pause");
	return 0;
}
