//Celaya Guerrero Jose Manuel
class hfactura extends factura
{
	double pagoexA;
	double pagoexM;
	double AIn;
	public hfactura(int clv,int dest,String n,String ape,double tfa,int ns)
	{
		super(clv,dest,n,ape,tfa,ns);
	}
	double Calcular_AIn(double pexA)
	{
		pagoexA=pexA;
		double tot=(pagoexA*cantidadA);
		pagoexM=pagoexA*.5;
		tot+=(pagoexM*cantidadM);
		mbruto+=tot;
		Calcular_impuesto_total();
		return tot;
	}
	void himprimir()
	{
		System.out.println("\nClave de reservacion: "+clave);
		System.out.println("Destino: "+destino);
		System.out.println("Nombre de cliente: "+nombre);
		System.out.println("Apellido Pat.: "+apellido);
		System.out.printf("Tarifa por dia: $%.2f\n",tarifa);
		System.out.println("Noches: "+noches);
		System.out.println("Adultos: "+cantidadA);
		System.out.println("Menores: "+cantidadM);
		System.out.printf("Pago extra por Adulto: $%.2f\n",pagoexA);
		System.out.printf("Pago extra por Menor: $%.2f\n",pagoexM);
		System.out.printf("Total por servicio All Inclusive: $%.2f\n",AIn);
		System.out.printf("Monto bruto: $%.2f\n",mbruto);
		System.out.printf("Impuesto: $%.2f\n",impuesto);
		System.out.printf("Total: $%.2f\n",total);
	}
}