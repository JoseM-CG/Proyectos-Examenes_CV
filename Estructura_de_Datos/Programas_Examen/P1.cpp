#include<stdio.h>
#include<cstdlib>
typedef struct lista
{
	float dato;
	lista *sig;
}nodo;
nodo *Nuevo();
main()
{
	nodo *p=NULL,*q=NULL,*r=NULL;
	float n,sum=0;
	int nodos=0;
	//Nodos
	printf("Captura de calificaciones (CTRL+Z para finalizar):\n");
	printf("<---Nodo\nCalificacion: ");
	while(scanf("%f",&n)!=EOF)
	{
		q=Nuevo();
		nodos++;
		q->dato=n;
		q->sig=p;
		if(nodos==1)
			r=q;
		p=q;
		printf("Calificacion: ");
	}
	//Mostrar
	if(p!=NULL)
	{
		printf("\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
		while(q!=NULL)
		{
			printf("%p\t%.1f\t",q,q->dato);
			q=q->sig;
			printf("%p\n",q);
		}
	}
	//Nodos
	printf("\nNodo--->\nCalificacion: ");
	q=r;
	while(scanf("%f",&n)!=EOF)
	{
		q=Nuevo();
		nodos++;
		q->dato=n;
		q->sig=NULL;
		if(nodos==1)
		{
			r=p=q;
			q->sig=NULL;
		}
		else
		{
			r->sig=q;
			r=q;
		}
		printf("Calificacion: ");
	}
	//Mostrar y Sumar
	if(p!=NULL)
	{
		printf("\nLista:\n\nDireccion\t\tDato\tDireccion sig.\n\n");
		q=p;
		while(q!=NULL)
		{
			printf("%p\t%.1f\t",q,q->dato);
			sum+=q->dato;
			q=q->sig;
			printf("%p\n",q);
		}
		printf("\nPromedio = %.1f\n",sum/nodos);
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