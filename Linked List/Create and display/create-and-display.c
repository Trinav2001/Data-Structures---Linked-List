#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *temp,*last;
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

void Rdisplay(struct Node *p)
{
	if(p!=NULL)
	{
		Rdisplay(p->next);
		printf("%d ",p->data);
	}
}
int main()
{

    int A[] = {4,2,9,6,1};
    create(A,5);
    display(first);
    printf("\n\n\n");
    Rdisplay(first);
    return 0;
}
