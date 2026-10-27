#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
	float dato;
	lista *sig;
}nodo;
nodo *Nuevo();
main()
{
	nodo *p=NULL,*q=NULL;
	float x,sum=0;
	int nodos=0;
	//Nodos
	printf("Captura de datos (CTRL+Z para finalizar):\n");
	printf("Calif.: ");
	while(scanf("%f",&x)!=EOF)
	{
		q=Nuevo();
		q->dato=x;
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
		printf("Calif.: ");
	}
	if(p!=NULL)
	{
		//Mostrar
		printf("\nLista:\n\nDireccion\t\tCalif.\tDireccion sig.\n\n");
		q=p->sig;
		while(q!=p)
		{
			printf("%p\t%.1f\t%p\n",q,q->dato,q->sig);
			q=q->sig;
		}
		printf("%p\t%.1f\t%p\n",p,p->dato,p->sig);
		//Contar y promediar
		q=p->sig;
		while(q!=p)
		{
			nodos++;
			sum+=q->dato;
			q=q->sig;
		}
		nodos++;
		sum+=p->dato;
		printf("\nNodos = %d\nPromedio = %.1f\n",nodos,sum/nodos);
		//Promedios mayores a media
		printf("\nPromedios mayores a media:\n\nDireccion\t\tCalif.\tDireccion sig.\n\n");
		q=p->sig;
		while(q!=p)
		{
			if(q->dato>(sum/nodos))
				printf("%p\t%.1f\t%p\n",q,q->dato,q->sig);
			q=q->sig;
		}
		if(p->dato>(sum/nodos))
			printf("%p\t%.1f\t%p\n",p,p->dato,p->sig);
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