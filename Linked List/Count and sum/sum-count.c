#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	struct Node *temp, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	int i;
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
	while(p!=0)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int count(struct Node *p)
{
	int count = 0;
	while(p!=0)
	{
		count++;
		p = p->next;
	}
	return count;
}

int Rcount(struct Node *p)
{
	if(p!=NULL)
	{
		return Rcount(p->next) + 1;
	}
}

int sum(struct Node *p)
{
	int sum=0;
	while(p)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

int Rsum(struct Node *p)
{
	if(!p)
	{
		return 0;
	}
	else
		return Rsum(p->next) + p->data;
}

int main()
{
	int A[8] = {4,2,6,8,1,10,5,2};
	create(A,8);
	display(first);
	printf("\n\n");
	printf("count is %d", Rcount(first));
	printf("\n\nsum is %d",Rsum(first));
	return 0;
}
