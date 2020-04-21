
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct island
{
	char a[50];
	struct island * next;
} island;




island * fisland()
{
	island *head;
	char str[50] = {0};
	head = malloc(sizeof(island));
	if (head == NULL)
	{
		return NULL;
	}
	printf("Input string island \n");
	scanf("%s", str);
	
	memcpy(head->a, str, 50);
	head->next = NULL;
	return head;
}


int addisland(island *head)
{
	char str[50] = {0};
	printf("Input new island (string): \n");
	scanf("%s", str);
	
	
	island *tmp = (island*)malloc(sizeof(island));

	memcpy(tmp->a, str, 50);

	tmp->next = NULL;

	island *p = head;

	while (p->next != NULL)
		p = p->next;

	p->next = tmp;

	return 0;
}




void show(island *head)
{

	island *tmp = head;
	while (tmp != NULL)
	{
		
		printf("\n %s \n", tmp->a);
		tmp = tmp->next;
	}
}




void remall(island **head)
{
	
	island* tmp;
	tmp = *head;
	while (tmp != NULL)
	{
		void * next = tmp->next;

		free(tmp);

		tmp = next;
	}

	*head = NULL;

}
		
		

void remone(island **head) {
	
	if (*head == NULL)
	{
		return;
	}
	island *p = *head;
	if (p->next == NULL)
	{
		free(p);
		*head = NULL;
		return;

	}
	
	island * next = p->next;

	while (next->next != NULL)
	{
		p = next;
		next = p->next;
	}
	free(next);
	p -> next = NULL;
}


int find(island *head, char * str, int size)
{

	int n=1;
	island *tmp = head;
	while (tmp!= NULL)
	{

		if (memcmp(tmp->a, str, size)==0)
		{
			return n;
		}
		n++;
		tmp = tmp->next;
	}
	return 0;
}





int main()
{

	
	island * head;
	head = NULL;
	int  m = 0, n;
	{
		while (m==0)
		{

			system("cls");


			printf("Click 1 to create list.\n");
			printf("Click 2 to add a new island.\n");
			printf("Click 3 to look islands\n");
			printf("Click 4 to remove the last island\n");
			printf("Click 5 to delete all islands\n");
			printf("Click 6 to search island\n");
			printf("Click 7 to exit. \n \n");


			int b = scanf("%d", &n);

			if (b != 1)
			{
				fflush(stdin);
				n = 0;
			}
			
			switch (n)
			{
			case 1:
				head = fisland(); 
				if (head == NULL)
				{
					printf("error: your string is invalid. \n");
					break;
				}

				printf("\n List is created \n"); system("pause");
				
				break;
				
			case 2:
				if (head == NULL)
				{
					printf("error: List not created.  \n");
					system("pause");
					break;
				}
				int l = addisland(head);
				if (l == 1)
				{
					printf("error: your string is invalid.  \n");
					system("pause");
					break;
				}
				system("pause");  break;
			
			case 3:
				if (head == NULL)
				{
					printf("error: List not created.  \n");
					system("pause");
					break;
				}
				show(head); system("pause"); break;
		
			case 4:
				if (head == NULL)
				{
					printf("error: List not created.  \n");
					system("pause");
					break;
				}
				remone(&head); printf("island is deleted \n"); system("pause"); break;
			
			case 5:
				if (head == NULL)
				{
					printf("error: List not created. \n");
					system("pause");
					break;
				}
				remall(&head);
				printf("List is deleted \n"); 
				system("pause");
				break;

			case 6:
				if (head == NULL)
				{
					printf("error: List not created. \n");
					system("pause");
					break;
				}
				char str[50] = {0};
				scanf("%s", str);
				int num = find(head, str, 50);
				if (num > 0)
					printf("\n Number:%d \n", num);
				else
					printf("Can`t find \n");
				system("pause");
				break;
			
			case 7:
				exit(0); break;

			default:
				printf("error: entered invalid value \n");
				system("pause");
				break;
			}
		}
	}

	system("pause");
	return 0;
}
