#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct tf *tp;
	struct tf
	{
		int am;
		tp next;
	};
tp h, t;

void insert(tp *h, tp *t, int da);
void print1(tp h);
void print2(tp h);
void delete(tp *h, tp *t, int da);
bool exist(tp h, int da);

int main(void)
{
	h = NULL;
	t = NULL;
	int da;
	int choice = 1;
	while (choice)
	{
		char xar;
		printf("\nEnter D to delete, I to insert, P to print list and E to exit\n");
		scanf("%c", &xar);
		switch (xar)
		{
		case 'D':
			{
				printf("\nEnter am you want to delete: ");
				scanf("%d", &da);
				if(exist(h, da) == 1)
					delete(&h, &t, da);
				else
					printf("\nThere is no am = %d to delete!", da);
			}
			break;
		case 'I':
			{
				printf("\nGive me the AM integer: ");
				scanf("%d", &da);
				if(exist(h, da) == 0)
					insert(&h, &t, da);
				else
					printf("\nThis am = %d is already in the list!", da);	
			}
			break;
		case 'P':
			{
				if(h==NULL)
					printf("\nList is empty!");
				else
					print1(h);	
				break;
			}
		case 'p':
			{
				if(h==NULL)
					printf("\nList is empty!");
				else
					print2(h);	
				break;
			}	
		case 'E':
				choice = 0;
				break;
		default:
			printf("Wrong input!");
		}
		getchar();
	}
	return 0;
}
void insert(tp *h, tp *t, int da)
{
	tp temp, aux;
		
	temp = (tp)malloc(sizeof(struct tf));
	temp->am = da;
	temp->next = NULL;
	printf("\nThe AM of temp is %d\n", temp->am);
	if(*h == NULL)
	{
		printf("I1\n");
		*h = temp;
		*t = temp;
		printf("\nh = %d\nt = %d", *h, *t);
	}
	else
	{
		if(temp->am < (*h)->am)
		{
			printf("I2\n");
			temp->next = *h;
			*h = temp;
			printf("\nh = %d\nt = %d", *h, *t);
		}
		else if(temp->am > (*t)->am)
		{
			printf("I3\n");
			(*t)->next = temp;
			*t = temp;
			printf("\nh = %d\nt = %d", *h, *t);
		}
		else if((temp->am > (*h)->am) && (temp->am < (*t)->am))
		{
			printf("I4\n");
			aux = *h;
			while((aux->next != NULL) && (aux->next->am < temp->am))
				aux = aux->next;
			temp->next = aux->next;
			aux->next = temp;
			printf("\nh = %d\nt = %d", *h, *t);
		}
	}
}
void print1(tp h)
{
	tp aux;
	aux = h;
	while(aux != NULL)
	{
		printf("\n%d", aux->am);
		aux = aux->next;
	}
}
void print2(tp h)
{
	if(h != NULL)
	{
		printf("\n%d", h->am);
		print2(h->next);
	}
	else return;
}
void delete(tp *h, tp *t, int da)
{
	tp temp, aux;
	printf("\nh kai t before delete\nh = %d\nt = %d\n", *h, *t);
	if(*h == NULL)
		printf("\nList is empty!");
	else
	{
		if ((*h)->am == da)
		{
			printf("D1\n");
			aux = *h;
			*h = (*h)->next;
			free(aux);
			aux = NULL;
			if(*h == NULL)
			{
				*t = NULL;
				printf("\nList is empty!");
			}
			printf("\nh = %d\nt = %d\n", *h, *t);
		}
		/*else if((*h)->am != da && (*h)->next == NULL)
		{
			printf("D2\n");
			printf("\nThere is no am = %d to delete", da);
		}*/
			
   		else if((*h)->am != da && (*h)->next != NULL)
		{
			tp aux = *h;
			while ((aux->next != NULL) && (aux->next->am != da))
				aux = aux->next;
			/*if(aux->next == NULL)
			{
				printf("3");
				printf("\nThere is no am = %d to delete", da);
				printf("\nh = %d\nt = %d\n", *h, *t);
			}*/
		    if(aux->next != NULL)
			{
				temp = aux->next;
				aux->next = temp->next;
				
				
				if(temp != *t)
      			{	
      				printf("D2a\n");
       				free(temp);
       				temp=NULL;
      			}
				if(temp == *t)
      			{
      				printf("D2b\n");
       				*t = aux;
       				free(temp);
       				temp=NULL;	
				}	
			}
			printf("\nh = %d\nt = %d\n", *h, *t);	
		}
	} 
}
bool exist(tp h, int da)
{
	
	tp aux;
	aux = h;
		while(aux != NULL)
		{
			if(aux->am == da)
				return 1;
			else 
				aux = aux->next;
		}
		return 0;	
}
