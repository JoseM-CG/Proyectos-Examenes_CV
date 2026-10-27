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
	nodo *in=NULL,*p=NULL,*q=NULL,*nvo=NULL;
	int x;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Dato: ");
	while(scanf("%d",&x)!=EOF)
	{	
		if(in==NULL)
		{
			q=Nuevo();
			q->dato=x;
			q->sig=NULL;
			q->ant=NULL;
			in=p=q;
		}
		else
		{
			nvo=Nuevo();
			if(x<=in->dato)
			{
				nvo->dato=x;
				nvo->sig=in;
				nvo->ant=in->ant;
				in->ant=nvo;
				in=nvo;
			}
			else
			{
				q=in;
				while(q!=p&&x>q->dato)
					q=q->sig;
				if(q!=p)
				{
					*nvo=*q;
					q->sig->ant=nvo;
					q->sig=nvo;
					nvo->ant=q;
					q->dato=x;
				}
				else
				{
					
					if(x>=p->dato)
					{
						nvo->dato=x;
						nvo->sig=p->sig;
						p->sig=nvo;
						nvo->ant=p;
					}
					else
					{
						*nvo=*p;
						p->sig=nvo;
						nvo->ant=p;
						p->dato=x;
					}
					p=nvo;
				}
			}
			nvo=NULL;
		}
		printf("Dato: ");
	}
	if(in!=NULL)
	{
		//Imprimir
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