#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"


//Initialize the contents of our array to NULL
void hash_init(hash_t *hash_table[],int limit)
{
	int i=0;
	for(i=0;i<limit;i++)
		hash_table[i]=NULL;
}


int hash(char *value)
{
	int len,i,sum=0;
	len=strlen(value);

//Calculate the sum of ascii values of the characters in the string and return the remainder when devided by 1000, which is our key value
	for(i=0;i<len;i++)
		sum+=value[i];
	return sum%1000;
}




//Our insert function which accepts the hash table, hash key and the record to be inserted
void hash_insert(hash_t *table[],int key,char *value)
{
	hash_t *hashnode,*p,*q,*s;
	
//Allocate storage for a new node
	hashnode=calloc(1,sizeof(hash_t));
	hashnode->next=NULL;
	hashnode->value=value;

//If the element to be inserted is the first one in the list
	if(table[key]==NULL)
	{
		table[key]=hashnode;
		return ;
	}
//Traverse to the end of the list and insert node
	p=table[key];
	while(p!=NULL )
	{
		q=p;
		p=p->next;
	}

	if(p==NULL)
		q->next=hashnode;
	return ;
}




//Function to get hash dump
void hash_print(hash_t *table[],int limit)
{
	int i=0;
	hash_t *p;
	for(i=0;i<limit;i++)
	{
		p=table[i];
		if(p!=NULL)
			printf("%d\t",i);
		while(p!=NULL)
		{
			printf("%s\n",p->value);
			p=p->next;
		}
	}
}





//Our retreival function which accepts the hash table, value to be retreived and returns a pointer to the structure which contains the value
hash_t *hash_get(hash_t *table[],char *val)
{
	int key;
	hash_t *p,*q;

	key=hash(val);

	p=q=table[key];

//table[key] gives us the head node of the list which contains all the strings whose ascii sum maps to key.We traverse it till the end to search our key value
	while(p!=NULL && abs(strcmp(p->value,val)))
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("%s not found\n",val);
		return NULL;
	}
	else
		return p;
}





//Our delete function which accepts a hash_table and the value to be deleted
void hash_delete(hash_t *table[],char *val)
{
	int key;
	hash_t *p,*q;
	key=hash(val);
	p=table[key];

//This code is for the case where the first node itself contains the value to be removed
	if(!(strcmp(p->value,val)))
	{
		table[key]=p->next;
		printf("%s removed\n",p->value);
		free(p);
		table[key]=NULL;
		return ;
	}

//We traverse till the end of the list to find the node containing our value
	while(p!=NULL && abs(strcmp(p->value,val)))
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("%s not found\n",val);
		return ;
	}
	else
	{
		q->next=p->next;
		printf("%s removed\n",p->value);
		free(p);
	}
}



int main()
{
	int value,key,i;

//hash_table is our hash table which contains pointers to the nodes contining value. If 2 strings map on to the same key, we create a single linked list at that node 
	hash_t *hash_table[1000],*p;
	char *s[10]={"vinod naik","anil","shreyas","gowda","lohit","rash","naik","kian","nika","lina"};
	hash_init(hash_table,1000);


	for(i=0;i<10;i++)
	{
		key=hash(s[i]);
		hash_insert(hash_table,key,s[i]);
	}


	hash_print(hash_table,1000);
	p=hash_get(hash_table,"gowda");
	printf("Retreived %s\n",p->value);
	p=hash_get(hash_table,"anil");
	printf("Retreived %s\n",p->value);
	hash_delete(hash_table,"kian");
	hash_delete(hash_table,"rash");
	hash_print(hash_table,1000);
	hash_insert(hash_table,hash("aink"),"aink");
	hash_print(hash_table,1000);
	

}


