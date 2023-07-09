//____UNDO AND REDO OPERATION______

#include<stdio.h>
#include<ctype.h>
#define size 100

int undostack[size];
int redostack[size];
int top1=-1;
int top2=-1;

void rpush(int element);

void upush(int ele)
{
	if(top1+1==size)
	{
		printf("Cant undo");
	}
	else
	{
		top1++;
		undostack[top1]=ele;
	}
	printf("%d ",undostack[top1]);
	printf("\n");
}

void upop()
{
	int k;
	if(top1==-1)
	{
		printf("Cant undo");
	}
	else
	{
		k=undostack[top1];
		top1--;
		rpush(k);
	}
}

void rpush(int element)
{
	top2++;
	redostack[top2]=element;
	int i;
	printf("Stack: ");
	printf("%d ",redostack[top2]);
	printf("\n");
}

void disp()
{
	int i;
	for(i=0; i<=top1; i++)
		printf("%d\t", undostack[i]);
	printf("\n");
}

void rpop()
{
	int k;
	k=redostack[top2];
	top2--;
	upush(k);
}

int menu()
{
	int choice;
	printf("1. add\n2. undo\n3. redo\n4. History\n5. Exit");
	printf("\nEnter the choice: ");
	scanf("%d",&choice);
	return choice;
}

int main()
{
	int ch,ele;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1:
				
				printf("Enter element: ");
        		scanf("%d", &ele);
        		upush(ele);
        		break;
			case 2:
				upop();
				printf("Undo done successfully\n");
				break;
			case 3:
				rpop();
				break;
			case 4:
				disp();
				break;
			default:
				printf("Wrong choice\n");
				break;
				
		}
	}
}
