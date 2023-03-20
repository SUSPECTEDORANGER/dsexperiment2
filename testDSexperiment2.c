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
            case 1: //����ָ�����ȵ�����
	            printf("Now create a list!\nEnter flag 1 for list1,flag 2 for list 2.\n");
	            scanf("%d", &flag);
				printf("Please enter the size of the polynomial!\n");
	            scanf("%d", &n);
	            if (flag == 1){	
					if(list1){//�ͷ��ڴ�
						if(list1->next){//����ֻ��ͷ�ڵ�
							LinkList p = list1->next;
							while(p){
								free(list1);
								list1 = p;
								p = p->next;
							}
						}
						free(list1);//ֻ��ͷ�ڵ�
						list1 = NULL;
					}
	                list1 = CreatList(n);
	                printf("The result is: ");
	                Print(list1);
	            }
	            else if (flag == 2){
					if(list2){//�ͷ��ڴ�
						if(list2->next){//����ֻ��ͷ�ڵ�
							LinkList p = list2->next;
							while(p){
								free(list2);
								list2 = p;
								p = p->next;
							}
						}
						free(list2);//ֻ��ͷ�ڵ�
						list2 = NULL;
					}
	                list2 = CreatList(n);
	                printf("The result is: ");
	                Print(list2);
	            }
	            else
	                printf("Flag wrong!\n");
	            break;

			case 2: //����ʽ���
	            printf("Now merge the two polynomials!\n");
	            printf("The first list is: ");
	            Print(list1);
	            printf("The second list is: ");
	            Print(list2);
	            printf("The result is: ");
	            list3 = AddLists(list1, list2);
	            Print(list3);
	            break;

	        case 3: //����ʽ���
	            printf("Now sub the two polynomials!\n");
	            printf("The first list is: ");
	            Print(list1);
	            printf("The second list is: ");
	            Print(list2);
	            printf("The result is: ");
	            list3 = SubLists(list1, list2);
	            Print(list3);
	            break;

	        case 4: //����ʽ���
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
