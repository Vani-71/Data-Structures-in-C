#include<stdio.h>

int current=-1;
int list[5];


int isempty();

int isfull();

void insert_front();

void insert_middle();

void insert_end();

void display();

void delete();

int size=5;

void main()

{ int a; printf("\n");

do{

printf("\n1.Isempty\n2.Isfull\n3.Insert at front\n4.Insert at middle\n5.Insert at end\n6.Delete\n7.Display\ n0.Exit\n\n");

scanf("%d",&a);

switch(a)

{

case 1:

isempty();

break;

case 2:

isfull();

break;

case 3:

insert_front();

break;

case 4:

insert_middle();

break;

case 5:

insert_end();

break;

case 6:
delete();


break;

case 7:

display();

break;

case 0:

printf("\nExiting");

break;

}

}while(a!=0);

}

int isempty()

{

if(current==-1)

{

printf("\nList is empty\n");

return 1;

}

else

{

printf("\nList is not empty\n");

return 0;

}

}

int isfull()

{

if(current==(size-1))

{

printf("List is full\n");

return 1;

}

else

{

printf("List is not full\n");
return 0;


}

}

void insert_front()

{

int i;

if(!isfull())

{

if(isempty())

scanf("%d",&list[++current]);

else

{

for(i=current;i>=0;i--)

list[i+1]=list[i];

printf("\nEnter element\n");

scanf("%d",&list[0]);

current++;

}

}

}

void insert_end()

{

if(!isfull())

scanf("%d",&list[++current]);

}

void insert_middle()

{

int pos;

int i;

if(!isfull())

{

printf("Enter position\n");

scanf("%d",&pos);

if(((pos-1)>current)&&((pos-1)<size))
{


printf("\nEnter element to insert at last\n");

scanf("%d",&list[++current]);

}

else if((pos-1)>=size)

printf("Enter position within size\n");

else

{

for(i=current;i>=(pos-1);i--)

{

list[i+1]=list[i];

}

printf("Insert Element\n");

scanf("%d",&list[pos-1]);

current++;

}

}

}

void delete()

{

int pos;

int i;

if(!isempty())

{

printf("Enter position to delete\n");

scanf("%d",&pos);

if((pos-1)>=size)

printf("Enter valid position within size\n");

else if((pos-1)<=current)

{

for(i=(pos-1);i<current;i++)

{

list[i]=list[i+1];

}
current--;


}

else printf("Content is already deleted\n");

}

}

void display()

{

int i;

if(!isempty())

{

for(i=0;i<=current;i++)

{

printf("%d\n",list[i]);

}

}

}


