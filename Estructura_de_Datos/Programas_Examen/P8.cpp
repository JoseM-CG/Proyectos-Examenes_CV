#include<stdio.h>
#include<string.h>
main()
{
	char pila[15]={'\0'},expresion[25]={'\0'};
	int i,tope=0;
	gets(expresion);
	for(i=0;i<strlen(expresion);i++)
	{       
		if(expresion[i]=='('||expresion[i]==')'||expresion[i]=='['||expresion[i]==']'||expresion[i]=='{'||expresion[i]=='}')
		{
			pila[tope]=expresion[i];
		}
		if(expresion[i]==')'||expresion[i]==']'||expresion[i]=='}')
		{
			if(tope>0)
			{
				if((pila[tope]==')'&&pila[tope-1]=='(')||(pila[tope]==']'&&pila[tope-1]=='[')||(pila[tope]=='}'&&pila[tope-1]=='{'))
				{                                                                                                      
					pila[tope]='\0';
					pila[tope-1]='\0';
					if(tope==1)
						tope--;
					else
						tope-=2;
				}
			}
		}
		if(strlen(pila)!=0)
			tope++;
		else
			tope=0;
	}
	puts("Expresion:");
	puts(expresion);
	puts("Pila:");
	if(strlen(pila)==0)
		printf("Vacia\n\nExpresion Valida");
	else
		printf("%s\n\nExpresion Invalida",pila);
}