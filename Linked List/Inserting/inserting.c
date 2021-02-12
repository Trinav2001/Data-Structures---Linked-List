#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
	int i;
	struct Node *temp,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	for(i=1;i<n;i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void display(struct Node *p)
{
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void insert(struct Node *p, int pos, int element)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));         // creating a new node
	temp->data = element;                                      //storing element in the new node
	if(pos==0)                                                 // in the beginning
	{
		temp->next = first;
		first = temp;
	}
	else                                                        // anywhere else
	{
		int i;
		for(i=0;i<pos-1 && p;i++)                               // we need a pointer pointing to the previous node
		{
			p = p->next;
		}
		temp->next = p->next;                 
		p->next = temp;
	}
}

int main()
{
	int A[5] = {5,2,4,1,8};
	create(A,5);
	display(first);
	printf("\n\n");
	insert(first,1,10);          //we can also create a linked list using insertion technique
	display(first);
	return 0;
}
