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
	nodo *p=NULL,*q=NULL,*r=NULL,*nvo=NULL;
	int n;
	bool bandera=true;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Dato: ");
	while(scanf("%d",&n)!=EOF)
	{
		if(bandera)
		{
			q=Nuevo();
			q->dato=n;
			q->sig=NULL;
			r=p=q;
			bandera=false;
		}
		else
		{
			nvo=Nuevo();
			if(n<=p->dato)
			{
				nvo->dato=n;
				nvo->sig=p;
				p=nvo;
			}
			else
			{
				q=p;
				while(q!=r&&n>q->dato)
					q=q->sig;
				if(q!=r)
				{
					*nvo=*q;
					q->dato=n;
					q->sig=nvo;
				}
				else
				{
					if(n>=r->dato)
					{
						nvo->dato=n;
						nvo->sig=q->sig;	
					}
					else
					{
						*nvo=*q;
						q->dato=n;
					}
					q->sig=nvo;
					r=nvo;
				}
			}
			nvo=NULL;
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