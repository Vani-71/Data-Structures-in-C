#include<stdio.h>

int top=-1;

int size=5;

void push();

void pop();

void display();

void isempty();

void isfull();

void peak();

void palindrome();

int option;

int stack[5];

void main()

{



do

{

printf("\nThe options are...\n1.push\n2.pop\n3.display\n4.isempty\n5.isfull\n6.top of the stack\ n7.Palindrome\nEnter 0 to return\nEnter your choice");
scanf("%d",&option);


switch(option)

{

case 1:

push();

break;

case 2:

pop();

break;

case 3:

display();

break;

case 4:

isempty();

break;

case 5:

isfull();

break;

case 6:

peak();

break;

case 7:

palindrome();

break;

case 0:

return;

break;

}

}while(option!=0);

}

void push()

{

if(top==4)

{
printf("\nStack is full");


}

else

{

int element;

top++;

printf("\nEnter the element");

scanf("%d",&element);

stack[top]=element;

}

}

void pop()

{

if(top==-1)

printf("\nStack is empty");

else

{

printf("\nThe deleted element is %d",stack[top]);

top--;

}

}

void display()

{

int i;

for(i=top;i!=-1;i--)

{

printf("%d",stack[i]);

}

}

void isempty()

{

if(top==-1)

printf("\nThe stack is empty");

}
void isfull()


{

if(top==size-1)

printf("\nThe stack is full");

else

printf("Not full");

}

void peak()

{

printf("\nThe top of the stack is %d",stack[top]);

}

void palindrome()

{

printf("$%");

int i, j;

for(i=0,j=top;i<=(top/2);i++,j--)

{

printf("H");

if(stack[i]!=stack[j])

{

printf("not a Palindrome");

break;

}

}

if(i>top/2)

printf("Stack is a palindrome");

}

