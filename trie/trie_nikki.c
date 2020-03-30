#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct trienode
{
	struct trienode* data[26];
	int isend;
	struct trienode* parent;
	int children_no;
}trienode;

void insert(trienode** root,char str[])
{
	trienode* temp=*root;
	for(int i=0;i<strlen(str);i++)
	{
		if(temp->data[str[i]-'a'] !=NULL)
			temp=temp->data[str[i]-'a'];
		else
		{
			trienode* node=(trienode*)malloc(sizeof(trienode));
			temp->data[str[i]-'a']=node;
			node->parent=temp;
			temp->children_no++;
			temp=temp->data[str[i]-'a'];}
	}
	temp->isend=1;
}	

int search(trienode** root, char str[])
{
	trienode* temp=*root;
	for(int i=0;i<strlen(str);i++)
	{
		if(temp->data[str[i]-'a'] == NULL)
			return 0;
		else
		{
			temp=temp->data[str[i]-'a'];
		}
	}
	if(temp->isend==1)
		return 1;
	else
		return 0;
	return 0;
}

void delete(trienode** root,char str[])
{
	trienode* temp=*root;
        for(int i=0;i<strlen(str);i++)
        {
                if(temp->data[str[i]-'a'] == NULL)
                        return;
                else
                {
                        temp=temp->data[str[i]-'a'];
                }
        }
	for(int i=strlen(str)-1;i>-1;i--)
	{
	while(temp->parent!=NULL)
	{
	if( temp->children_no==0)
	{
		trienode* useless=temp;
		free(useless);
		temp=temp->parent;
		temp->data[str[i]-'a']=NULL;
		temp->children_no--;
	}
	else if(temp->isend==1 || temp->children_no >1)
		return;
	else
	{
		 trienode* useless=temp;
                free(useless);
                temp=temp->parent;
                temp->data[str[i]-'a']=NULL;
                temp->children_no--;

	}
	}}
}


int main()
{
	trienode* root=(trienode*)malloc(sizeof(trienode));
	insert(&root,"hello");
	insert(&root,"hi");
	int k=search(&root,"hi");
	printf("%d",k);
	printf("%d",search(&root,"helloamnikki"));
	delete(&root,"hi");
	printf("%d",search(&root,"hi"));
	return 0;
}	
