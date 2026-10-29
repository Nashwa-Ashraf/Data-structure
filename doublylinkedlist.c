#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left,*right;
};
struct node*insert(struct node*start,int data)
{
struct node*t=malloc(sizeof(struct node));
t->data=data;
t->left=NULL;
t->right=start;
if(start!=NULL)
start->left=t;
return t;
}
struct node*search(struct node*start,int item)
{
while(start!=NULL)
{
if(start->data==item)
return start;
start=start->right;
}
return NULL;
}
struct node*delete(struct node*start,struct node*t)
{
if(t->left!=NULL)
t->left->right=t->right;
else
start=t->right;
if(t->right!=NULL)
t->right->left=t->left;
free(t);
return start;
}
int main()
{
struct node*L1=NULL,*t;
int opt,data;
do
{
printf("\n1.Insert\n2.Search\n3.Delete\n4.Exit\n");
printf("Enter option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter data:");
scanf("%d",&data);
L1=insert(L1,data);
break;
case 2:
printf("Enter item to search:");
printf("%d",data);
t=search(L1,data);
if(t==NULL)
printf("Not Found\n");
else
printf("found\n");
break;
case 3:
printf("Enter item to delete:");
scanf("%d",&data);
t=search(L1,data);
if(t!=NULL)
{
L1=delete(L1,t);
printf("Item deleted\n");
}
else
{
printf("Item does not exist\n");
}
break;
case 4:
printf("Exit\n");
break;
dafault:
printf("Invalid option\n");
}
}while(opt!=4);
return 0;
}


