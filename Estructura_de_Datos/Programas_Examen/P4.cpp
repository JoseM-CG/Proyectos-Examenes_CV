#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
	int dato;
	lista *sig;
}nodo;
nodo *Nuevo();
main()
{
	nodo *p=NULL,*q=NULL,*r=NULL;
	int n;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Dato: ");
	while(scanf("%d",&n)!=EOF)
	{
		q=Nuevo();
		q->dato=n;
		if(p==NULL)
		{
			p=q;
			p->sig=q;
		}
		else
		{
			q->sig=p->sig;
			p->sig=q;
			p=q;
		}
		printf("Dato: ");
	}
	if(p!=NULL)
	{
		//Mostrar
		printf("\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
		q=p->sig;
		while(q!=p)
		{
			printf("%p\t%d\t%p\n",q,q->dato,q->sig);
			q=q->sig;
		}
		printf("%p\t%d\t%p\n",p,p->dato,p->sig);
		//Buscar nodo y borrar el siguiente
		printf("\nDato a buscar: ");
		scanf("%d",&n);
		q=p->sig;
		while(q!=p&&q->dato!=n)
			q=q->sig;
		if(q->dato!=n)
			printf("\nDato no encontrado\n");
		else
		{	
			printf("\nDato encontrado, Direccion: %p\nBorrando nodo siguiente...",q);
			if(q==p)
			{
				printf("\nSolo hay un nodo");
				p=NULL;
				free(q);
			}
			else
			{
				r=q;
				q=q->sig;
				r->sig=q->sig;
				q->sig=NULL;
				if(q!=p)
					free(q);
				else
				{
					free(q);
					p=r;
				}
				r=NULL;
			}
			//Mostrar
			if(p!=NULL)
			{
				printf("\n\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
				q=p->sig;
				while(q!=p)
				{
					printf("%p\t%d\t%p\n",q,q->dato,q->sig);
					q=q->sig;
				}
				printf("%p\t%d\t%p\n",p,p->dato,p->sig);
			}
		}
	}
	//Liberar Memoria
	printf("\n\nLiberando memoria...");
	if(p==NULL)
		printf("\nNo hay lista");
	else	
	{
		q=p->sig;
		if(p==q)
		{
			printf("\nSolo hay un nodo");
			q=NULL;
			free(p);
		}
		else
		{
			while(q!=p)
			{
				p->sig=q->sig;
				free(q);
				q=p->sig;
			}
			q=NULL;
			free(p);
		}
	}
}
nodo *Nuevo()
{
	nodo *nuevo=NULL;
	nuevo=(nodo*)malloc(sizeof(nodo));
	if(nuevo==NULL)
	{
		printf("\n...No hay espacio en la memoria\n");
		exit(1);
	}
	else
		return nuevo;
}