#include<stdio.h>
#include<cstdlib>
typedef struct lista
{
	int dato;
	lista *sig;
}nodo;
nodo *Nuevo();
main()
{
	nodo *p=NULL,*q=NULL,*r=NULL,*ant=NULL;
	int n;
	bool bandera=true;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Dato: ");
	while(scanf("%d",&n)!=EOF)
	{
		q=Nuevo();
		q->dato=n;
		q->sig=NULL;
		if(bandera)
		{
			r=p=q;
			q->sig=NULL;
			bandera=false;
		}
		else
		{
			r->sig=q;
			r=q;
		}
		printf("Dato: ");
	}
	if(p!=NULL)
	{
		//Mostrar
		printf("\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
		q=p;
		while(q!=NULL)
		{
			printf("%p\t%d\t",q,q->dato);
			q=q->sig;
			printf("%p\n",q);
		}
		//Buscar nodo y borrarlo
		printf("\nDato a buscar: ");
		scanf("%d",&n);
		q=p;
		while(q!=NULL&&q->dato!=n)
		{
			ant=q;
			q=q->sig;
		}
		if(q==NULL)
			printf("\nDato no encontrado\n");
		else
		{	
			printf("\nDato encontrado, Direccion: %p\nBorrando nodo...",q);
			if(p==r)
			{
				printf("\nSolo hay un nodo\n");
				p=ant=r=NULL;
				free(q);
			}
			else
			{
				if(q==r)
					r=ant;
				if(q==p)
				{
					p=p->sig;
					free(q);
				}
				else
				{
					ant->sig=q->sig;
					free(q);
				}
				printf("\n\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
				q=p;
				while(q!=NULL)
				{
					printf("%p\t%d\t",q,q->dato);
					q=q->sig;
					printf("%p\n",q);
				}
			}
		}
		ant=NULL;
		if(p!=NULL)
		{
			//Buscar nodo y borrar el siguiente
			printf("\nDato a buscar: ");
			scanf("%d",&n);
			q=p;
			while(q!=NULL&&q->dato!=n)
			{
				q=q->sig;
			}
			if(q==NULL)
				printf("\nDato no encontrado\n");
			else
			{	
				printf("\nDato encontrado, Direccion: %p\nBorrando nodo siguiente...",q);
				if(q->sig==NULL)
					printf("\nNo tiene otro nodo a la derecha\n");
				else
				{
					if(q->sig==r)
						r=q;
					q->sig=q->sig->sig;
					q=q->sig;
					free(q);
					printf("\n\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
					q=p;
					while(q!=NULL)
					{
						printf("%p\t%d\t",q,q->dato);
						q=q->sig;
						printf("%p\n",q);
					}
				}
			}
		}
	}
	//Liberar Memoria
	if(p==NULL)
	{
		printf("\nNo hay lista");
	}
	else	
	{
		printf("\nLiberando memoria...");
		if(p==r)
		{
			printf("\nSolo hay un nodo");
			r=q=NULL;
			free(p);
		}
		else
		{
			q=p;
			while(p!=NULL)
			{
				p=p->sig;
				free(q);
				q=p;
			}
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