//Celaya Guerrero Jose Manuel
class factura
{
	int clave;
	int destino;
	String nombre;
	String apellido;
	double tarifa;
	int noches;
	int cantidadA;
	int cantidadM;
	double mbruto;
	double impuesto;
	double total;
	public factura(int clv,int dest,String n,String ape,double tfa,int ns)
	{
		clave=clv;
		destino=dest;
		nombre=n;
		apellido=ape;
		tarifa=tfa;
		noches=ns;
	}
	void asignar(int clv,int dest,String n,String ape,double tfa,int ns)
	{
		clave=clv;
		destino=dest;
		nombre=n;
		apellido=ape;
		tarifa=tfa;
		noches=ns;
	}
	double Calcular_mbruto(int cA,int cM)
	{
		cantidadA=cA;
		cantidadM=cM;
		double a=0,m=0;
		if(destino==1)
		{
			a=tarifa*cantidadA;
			m=(tarifa*.7)*cantidadM;
		}
		if(destino==2)
		{
			a=(tarifa*cantidadA)+((tarifa*cantidadA)*.1);
			m=(tarifa*.5)*cantidadM;
		}
		if(destino==3)
		{
			a=(tarifa*cantidadA)+((tarifa*cantidadA)*.2);
			m=0;
		}
		return ((a+m)*noches);
	}
	void Calcular_impuesto_total()
	{
		impuesto=mbruto*.15;
		total=mbruto+impuesto;
	}
	void imprimir()
	{
		System.out.println("\nClave de reservacion: "+clave);
		System.out.println("Destino: "+destino);
		System.out.println("Nombre de cliente: "+nombre);
		System.out.println("Apellido Pat.: "+apellido);
		System.out.printf("Tarifa por dia: $%.2f\n",tarifa);
		System.out.println("Noches: "+noches);
		System.out.println("Adultos: "+cantidadA);
		System.out.println("Menores: "+cantidadM);
		System.out.printf("Monto bruto: $%.2f\n",mbruto);
		System.out.printf("Impuesto: $%.2f\n",impuesto);
		System.out.printf("Total: $%.2f\n",total);
	}
}