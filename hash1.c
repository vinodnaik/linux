#include<stdio.h>
#include<stdlib.h>
#include "hash.h"



void hash_initialize(hash_t *hash_table[],int limit)
{
	int i=0;
	for(i=0;i<limit;i++)
		hash_table[i]=NULL;
}

int hash(int value)
{
	return value%10;
}

void hash_insert(hash_t *table[],int key,int value)
{
	hash_t *hashnode,*p,*q;
	
	if(table[key]==NULL)
	{
		hashnode=calloc(1,sizeof(hash_t));
		hashnode->next=NULL;
		hashnode->value=value;
		table[key]=hashnode;
		return ;
	}

	p=table[key];
	while(p!=NULL)
	{
		q=p;
		p=p->next;
	}

	p=calloc(1,sizeof(hash_t));
	p->next=NULL;
	p->value=value;
	q->next=p;
	return ;
}

void hash_print(hash_t *table[],int limit)
{
	int i=0;
	hash_t *p;
	for(i=0;i<limit;i++)
	{
		p=table[i];
		printf("%d\t",i);
		while(p!=NULL)
		{
			printf("%d\t",p->value);
			p=p->next;
		}
		printf("\n");
	}
}

hash_t *hash_get(hash_t *table[],int val)
{
	int key;
	hash_t *p,*q;

	key=hash(val);

	p=q=table[key];
	while(p!=NULL && p->value != val)
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("%d not found\n",val);
		return ;
	}
	else
		return p;
}

void hash_delete(hash_t *table[],int val)
{
	int key;
	hash_t *p,*q;
	key=hash(val);
	p=table[key];
	if(p->value=val)
	{
		//q=p;
		table[key]=q;
		printf("%d removed\n",p->value);
		free(p);
	}
	while(p!=NULL && p->value!=val)
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("%d not found\n",val);
		return ;
	}
	else
	{
		q->next=p->next;
		printf("%d removed\n",p->value);
		free(p);
	}
}


int main()
{
	int value,key,i;
	hash_t *hash_table[10],*p;

	hash_initialize(hash_table,10);


	for(i=7;i<100;i=i+7)
	{
		key=hash(i);
		hash_insert(hash_table,key,i);
	}

	hash_print(hash_table,10);
	p=hash_get(hash_table,84);
	printf("%d\n",p->value);
	p=hash_get(hash_table,28);
	printf("%d\n",p->value);
	hash_delete(hash_table,63);
	hash_delete(hash_table,91);
	hash_print(hash_table,10);

}


