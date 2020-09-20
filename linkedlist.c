#include<stdio.h>

#include<stdlib.h>

struct list

{

int data;
struct list *next;


};

typedef struct list node;

node *first;

node *last;

int isempty();

void insert_front();

void insert_last();

void delete_front();

void delete_last();

void delete_middle();

void insert_middle_position();

void delete_middle_position();

void delete_middle_element();

void insert_middle_element();

//void search();

void display();

int count();

node* prevl();

int position(int);

node* previ(int);

void sort();

void main()

{

int x;

do

{

printf("\n");

printf("1.Isempty\n2.Insert_at_front\n3.Insert_at_last\n4.Delete_at_first\n5.Delete_at_last\n6.Display\

n7.Sort\n9.Insert_at_middle_position\n10.Delete_at_middle_position\npress 0 to exit\n\n"); scanf("%d",&x);

switch(x)

{

case 1:
isempty();


break;

case 2:

insert_front();

break;

case 3:

insert_last();

break;

case 4:

delete_front();

break;

case 5:

delete_last();

break;

case 6:

display();

break;

case 7:

sort();

break;

case 9:

insert_middle_position();

break;

case 10:

delete_middle_position();

break;

case 0:

printf("Exiting...");

break;

}

}while(x!=0);

}

int isempty()

{
if(first==NULL && last==NULL)


{

printf("List is empty\n");

return 1;

}

else

{

printf("Not empty\n");

return 0;

}

}

void insert_front()

{

node *newnode;

newnode=(node*)malloc(sizeof(node));

printf("Enter a element\n");

scanf("%d",&newnode->data);

if(isempty())

{

first=newnode;

last=newnode;

first->next=NULL;

}

else

{

newnode->next=first;

first=newnode;

}

}

void insert_last()

{

node *newnode;

newnode=(node*)malloc(sizeof(node));

printf("Enter a element\n");
scanf("%d",&newnode->data);


if(isempty())

{

first=newnode;

last=newnode;

first->next=NULL;

}

else

{

last->next=newnode;

last=newnode;

last->next=NULL;

}

}

void delete_front()

{

if(!isempty())

{

node *temp;

temp=first;

if(first->next==NULL)

{

first=NULL;

last=NULL;

}

else

{

first=first->next;

}

free(temp);

}

}

void delete_last()

{
if(!isempty())


{

node *prev;

prev = prevl();

if(prev==NULL)

{

prev=first;

first=last=NULL;

free(prev);

}

else

{

node *temp;

temp=prev->next;

last=prev;

last->next=NULL;

free(temp);

}

}

}

void display()

{

if(!isempty())

{

node *temp;

temp=first;

if(temp->next==NULL)

printf("%d\n",temp->data);

else

{

while(temp->next!=NULL)

{

printf("%d",temp->data);

temp=temp->next;
}


printf("%d\n",last->data);

}

}

}

node* previ(int x)

{

int a=0;

node *temp;

node *prev;

temp=first;

prev=NULL;

//printf("abfhgakfhjkahf");

while(temp->next!=NULL)

{

prev=temp;

temp=temp->next;

a++;

if(a==(x-1))

break;

}

if(a!=(x-1))

return NULL;

else

return prev;

}

node* prevl()

{

node *temp;

temp=first;

node *prev;

prev=NULL;

while(temp->next!=NULL)

{
prev=temp;


temp=temp->next;

}

return prev;

}

void insert_middle_position()

{

if(!isempty())

{

node *prev;

int pos;

printf("Enter the position..\n");

scanf("%d",&pos);

if(pos==1)

{

insert_front();

}

else

{

node *newnode;

newnode=(node*)malloc(sizeof(node));

printf("Enter element..\n");

scanf("%d",&newnode->data);

prev=previ(pos);

//printf("fgadfgafhajk");

if(prev==NULL)

printf("Enter a valid position\n");

else

{

newnode->next=prev->next;

prev->next=newnode;

}

}

}
}

void delete_middle_position()

{

if(!isempty())

{

int pos;

printf("Enter position..\n");

scanf("%d",&pos);

if(pos==1)

{

delete_front();

}

else if(pos==count())

{

delete_last();

}

else

{

node *prev;

prev = previ(pos);

if(prev==NULL)

printf("Enter a valid position");

else

{

node *temp;

temp=prev->next;

prev->next=temp->next;

free(temp);

}

}

}

}

int count()
{


if(!isempty())

{

int a=0;

node *temp;

temp=first;

while(temp->next!=NULL)

{

temp=temp->next;

a++;

}

printf("No. of element in list is %d\n",a+1);

return a+1;

}

}

int position(int x)

{

int a=0;

node *temp;

if(first->data==x)

{

//printf("faflakf");

return 1;

}

else

{

while(temp->next!=NULL)

{ temp=temp->next; a++; if(temp->data==x)

return a+1;



}

return 0;
}


}

void sort()

{

node *temp,*temp1;

int x,tem;

do

{

x=temp1->data;

while(temp->next!=NULL)

{

temp=temp->next;

if(x>temp->data)

{

tem=temp->data;

temp->data=x;

x=tem;

}

}

temp1->data=x;

temp1=temp1->next;

temp=temp1;

}while(temp1!=NULL);


