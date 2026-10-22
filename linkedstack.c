#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*sp=NULL;
void push(int item)
{
struct node*t=malloc(sizeof(struct node));
t->data=item;
t->next=sp;
sp=t;
}
int pop(int*status)
{
struct node*t;
int item;
if(sp==NULL)
{
*status=0;
printf("empty stack\n");
return 0;
}
t=sp;
item=t->data;
sp=sp->next;
free(t);
*status=1;
return item;
}
int search(int item)
{
struct node*t=sp;
int count=0;
while(t!=NULL)
{
count++;
if(t->data==item)
return count;
t=t->next;
}
return 0;
}
int main()
{
int opt,item,ans,status;
while(1)
{
printf("\n1.push\n2.pop\n3.search\n4.exit\n");
printf("option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("data:");
scanf("%d",&item);
push(item);
printf("\n inserted%d\n",item);
break;
case 2:
item=pop(&status);
if(status)
printf("deleted item is %d\n",item);
break;
case 3:
printf("searching");
scanf("%d",&item);
ans=search(item);
if(ans==0)
printf("item not found\n");
else
printf("found at %dnode\n",ans);
break;
case 4:
return 0;
}
}
}
