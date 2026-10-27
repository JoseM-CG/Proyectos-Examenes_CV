import java.util.*;
//Jose Manuel Celaya Guerrero
class deops_cajas
{
	public static void main (String[] args)
	{
		int cantc,td,nvl_ent;
		double pcja;
		Scanner s=new Scanner(System.in);
		System.out.printf("\nNumero de servico: ");
		int num_s=s.nextInt();
		System.out.printf("\nNombre cliente: ");
		String n=s.next();
		do
		{
			System.out.printf("\nCajas: ");
			cantc=s.nextInt();
		}
		while(cantc<=0);
		do
		{
			System.out.printf("\nPeso de la caja: ");
			pcja=s.nextDouble();
		}while(pcja<=0||pcja>50);
		do
		{
			System.out.printf("\nTipo de destino(1/2): ");
			td=s.nextInt();
		}
		while(td<1||td>2);
		do
		{
			System.out.printf("\nNivel de entrega: ");
			nvl_ent=s.nextInt();
		}
		while(nvl_ent<=0||nvl_ent>5);
		ops_cajas obj=new ops_cajas(num_s,n);
		obj.costo_flete=obj.calcular_costoin(cantc,pcja);
		obj.extras=obj.calcular_cargoesex(nvl_ent,td);
		obj.impuesto=obj.calcular_imp();
		obj.total=obj.calcular_total();
		obj.mostrar();
	}
}