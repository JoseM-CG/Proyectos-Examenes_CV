//Jose Manuel Celaya Guerrero
class ops_cajas
{
	int n_servicio;
	String nombre;
	double peso_caja;
	double costo_caja;
	int cantidad_cjs;
	double peso_flete;
	int tipo_destino;
	int nvl_entrega;
	double costo_flete;
	double extras;
	double impuesto;
	double total;
	public ops_cajas(int num_s,String n)
	{
		n_servicio=num_s;
		nombre=n;
	}
	double calcular_costoin(int cantc,double pcja)
	{
		cantidad_cjs=cantc;
		peso_caja=pcja;
		if(peso_caja<5)
			costo_caja=15;	
		if(peso_caja>=6&&peso_caja<=25)
			costo_caja=30;	
		if(peso_caja>25&&peso_caja<=50)
			costo_caja=100;
		return (cantidad_cjs*costo_caja);
	}
	double calcular_cargoesex(int nvl_ent,int td)
	{
		nvl_entrega=nvl_ent;
		tipo_destino=td;
		double cext=0;
		peso_flete=(peso_caja*cantidad_cjs);
		if(tipo_destino==1)
			cext=5*peso_flete;
		if(nvl_entrega>2)
		{
			for(int i=2;i<=nvl_entrega;i++)
				cext+=(.01*peso_flete)*i;
		}
		return cext;
	}
	double calcular_imp()
	{
		return ((costo_flete+extras)*.15);
	}
	double calcular_total()
	{
		return (costo_flete+extras-impuesto);
	}
	void mostrar()
	{
		System.out.println("---------------------------------------");
		System.out.println("Numero de servicio: "+n_servicio);
		System.out.println("Nombre cliente: "+nombre);
		System.out.println("Cajas: "+cantidad_cjs);
		System.out.printf("Peso por caja: %.2f kg\n",peso_caja);
		System.out.printf("Peso del flete: %.2f kg\n",peso_flete);
		System.out.println("Tipo destino: "+tipo_destino);
		System.out.println("Nivel de entrega: "+nvl_entrega);
		System.out.printf("Costo del flete: $%.2f\n",costo_flete);
		System.out.printf("Cargos extras: $%.2f\n",extras);
		System.out.printf("Impuesto: $%.2f\n",impuesto);
		System.out.printf("Total: $%.2f",total);
	}
}