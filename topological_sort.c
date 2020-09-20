#include<stdio.h>

#include<stdlib.h>

struct descriptor{


int data;

};


struct successor_node{


int suc;


struct succeccor_node *nextsuc;


};


int n=0;


int predcount[20];


int tag[20];


struct descriptor *desptr[20];


struct successor_node *suclist[20];


struct successor_node *f,*r;


int store(int dat,int m)


{


int d,k;


d = k= dat%10;


struct descriptor *p;


while(k!=d || k==dat%10){


if(desptr[k]==NULL)
{


p = (struct descriptor*)malloc(sizeof(struct descriptor));


p->data = dat;


desptr[k] = p;


n = n+1;


return(k);


}


if(desptr[k]->data == dat)


return(k);


k = k+1;

if(k>m)k=1;

if(k==d){printf("Overflow\n");return(0);}}


}


void construct(int m)


{


int k=1,data=1;


while(k<=m)


{


desptr[k]=suclist[k]=NULL;


predcount[k]=0;


k++;


}


while(data==1){
int pred,suc;


printf("the predeccessor value: ");


scanf("%d",&pred);


printf("the successor value: ");


scanf("%d",&suc);


int i,j;


i = store(pred,m);


j = store(suc,m);


predcount[j] = predcount[j]+1;


struct successor_node *q;


q = (struct successor_node*)malloc(sizeof(struct successor_node));


q->suc = j;


q->nextsuc = suclist[i];


suclist[i]=q;


printf("Press 1 to enter data or Press 0: ");


scanf("%d",&data);


}


}


void lqinsert(int k)


{


struct successor_node *p,*q;


p = (struct successor_node*)malloc(sizeof(struct successor_node)); p->suc = k;
p->nextsuc = NULL;


if(r == NULL)


f = r = p;


else{


r->nextsuc = p;


r = p;


}


}


void topology_sort(int m)


{


int k=1;


while(k<=m){


if(desptr[k]!=NULL && predcount[k]==0)


lqinsert(k);


k++;


}


while(f!=NULL){


k = f->suc;


n = n-1;


f = f->nextsuc;


printf("%d ",desptr[k]->data);


desptr[k] = NULL;


if(f == NULL)
r = NULL;


struct successor_node *q;


q = suclist[k];


suclist[k]=NULL;


while(q!=NULL)


{


predcount[q->suc] = predcount[q->suc]-1;


if(predcount[q->suc]==0)


lqinsert(q->suc);


q = q->nextsuc;


}}


return;


}


void main()


{


int m,i;


//struct successor_node *p;


printf("Enter total number of vertices: ");


scanf("%d",&m);


construct(m);


/*for(i=1;i<=m;i++)printf("\n%d",predcount[i]);


for(i=1;i<=m;i++)


{
if(desptr[i]!=NULL)


{


printf("\n%d - %d",i,desptr[i]->data);


}


}


for(i=1;i<=m;i++)


{


if(suclist[i]!=NULL)


{


printf("\n%d - %d",i,suclist[i]->suc);


p = suclist[i];


while(p->nextsuc!=NULL)


{


p = suclist[i]->nextsuc;


printf("->%d",p->suc);


}


}


}*/


topology_sort(m);


}

