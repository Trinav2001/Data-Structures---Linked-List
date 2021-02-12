#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *temp, *last;
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
		printf("%d ",p->data);
		p = p->next;
	}
}

int IsSorted(struct Node *p)
{
	int x = -1;
	while(p!=NULL)
	{
		if(x > p->data)
		{
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}

int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	display(first);
	printf("\n\n");
	if(IsSorted(first))
	{
		printf("Sorted");
	}
	else
		printf("Not sorted");
	return 0;
}
