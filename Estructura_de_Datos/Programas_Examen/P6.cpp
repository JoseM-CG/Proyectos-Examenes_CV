#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
	int dato;
	lista *sig;
	lista *ant;
}nodo;
nodo *Nuevo();
main()
{
	nodo *in=NULL,*p=NULL,*q=NULL;
	int x;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Dato: ");
	while(scanf("%d",&x)!=EOF)
	{
		q=Nuevo();
		q->dato=x;
		if(in==NULL)
		{
			q->sig=NULL;
			q->ant=NULL;
			in=p=q;
		}
		else
		{
			q->sig=p->sig;
			p->sig=q;
			q->ant=p;
			p=q;
		}
		printf("Dato: ");
	}
	if(in!=NULL)
	{
		//Mostrar
		printf("\nLista:\n\nDireccion ant.\t\tDireccion\t\tDato\tDireccion sig.\n\n");
		p=in;
		while(p!=NULL)
		{
			printf("%p\t%p\t%d\t%p\n",p->ant,p,p->dato,p->sig);
			p=p->sig;
		}
		//Insertar nodo al inicio
		printf("\nDato a insertar al inicio: ");
		if(scanf("%d",&x)!=EOF)
		{
			p=Nuevo();
			p->dato=x;
			p->sig=in;
			p->ant=in->ant;
			in->ant=p;
			in=p;
		}
		//Mostrar
		printf("\nLista:\n\nDireccion ant.\t\tDireccion\t\tDato\tDireccion sig.\n\n");
		p=in;
		while(p!=NULL)
		{
			printf("%p\t%p\t%d\t%p\n",p->ant,p,p->dato,p->sig);
			q=p;
			p=p->sig;
		}
		//Insertar nodo al final
		printf("\nDato a insertar al final: ");
		if(scanf("%d",&x)!=EOF)
		{
			p=Nuevo();
			p->dato=x;
			q->sig=p;
			p->sig=NULL;
			p->ant=q;
		}
		//Mostrar
		printf("\nLista:\n\nDireccion ant.\t\tDireccion\t\tDato\tDireccion sig.\n\n");
		p=in;
		while(p!=NULL)
		{
			printf("%p\t%p\t%d\t%p\n",p->ant,p,p->dato,p->sig);
			p=p->sig;
		}
	}
	//Liberar Memoria
	printf("\n\nLiberando memoria...");
	if(in==NULL)
		printf("\nNo hay lista");
	else	
	{
		q=NULL;
		if(in->sig==NULL)
		{
			printf("\nSolo hay un nodo");
			p=NULL;
			free(in);
		}
		else
		{
			p=in;
			while(p->sig!=NULL)
			{
				p=p->sig;
				p->ant=in->ant;
				free(in);
				in=p;
			}
			p=NULL;
			free(in);
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