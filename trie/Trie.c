#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct trienode
{
  struct trienode* data[26];
  int counter;
  int isend;
};

void insert(struct trienode** root, char str[])//adds word to TRIE
{
  int length=strlen(str);
  int index;
  struct trienode* ptr=*root;
    for(int i=0;i<length;i++)
  {
    index=str[i]-97;
    if(ptr->data[index]==NULL)
    {
    struct trienode* temp=(struct trienode*)malloc(sizeof(struct trienode));
    temp->counter=0;
    ptr->counter+=1;
    ptr->data[index]=temp;
    }
    ptr=ptr->data[index];
  }
  ptr->isend=1;
}

int search(struct trienode** root, char str[])//Searches in TRIE
{
  int length=strlen(str);
  int index;
  struct trienode* ptr=*root;
    for(int i=0;i<length;i++)
  {
    index=str[i]-97;
   
    if(ptr->data[index]==NULL)
    return 0;
    else
    {
      ptr=ptr->data[index];
    }
  }
  if(ptr->isend==1)
  return 1;
  else
  return 0;
}

void delete(struct trienode** root, char str[])
{

}

int main()
{
  struct trienode* root=(struct trienode*)malloc(sizeof(struct trienode));
int ch=1;
  root->isend=0;
  root->counter=0;
  char str1[]="hello";
  char str2[]="hi";
char str3[]="aloha";
 char str[100];
  insert(&root,str1);
  insert (&root,str2);
  while(ch!=0)
{
  scanf("%s",str);
  int x=search(&root,str);
  if(x==1)printf("\n the string is present\n");
  else
  printf("\n the string is not present\n");
  printf("\n do you want to continue(1/0)?\n");
	scanf("%d",&ch);

}
  return 0;
}
