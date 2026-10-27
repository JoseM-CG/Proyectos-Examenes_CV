//Celaya Guerrero Jose Manuel
import java.util.*;
class dehfactura
{
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int clv,dest,ns,cA,cM,t;
		String n,ape;
		double tfa,pexA;
		boolean AI;
		do
		{
			System.out.println("\nCuantas reservaciones desea realizar:");
			t=s.nextInt();
		}while(t<1);
		hfactura ob[]=new hfactura[t];
		for(int i=0;i<t;i++)
		{
			ob[i]=new hfactura(0,0,"","",0.0,0);
			System.out.println("\nClave de reservacion:");
			clv=s.nextInt();
			do
			{
				System.out.println("Destino:");
				dest=s.nextInt();
			}while(dest<1||dest>3);
			System.out.println("Nombre de cliente:");
			n=s.next();
			System.out.println("Apellido Paterno:");
			ape=s.next();
			System.out.println("Tarifa por dia:");
			tfa=s.nextDouble();
			System.out.println("Noches:");
			ns=s.nextInt();
			do
			{
				System.out.println("Adultos:");
				cA=s.nextInt();
				System.out.println("Menores:");
				cM=s.nextInt();
			}while((cA+cM)<1||(cA+cM)>5);
			ob[i].asignar(clv,dest,n,ape,tfa,ns);
			ob[i].mbruto=ob[i].Calcular_mbruto(cA,cM);
			ob[i].Calcular_impuesto_total();
			System.out.println("Desea dar un pago extra?(t/f):");
			AI=s.nextBoolean();
			if(AI)
			{
				do
				{
					System.out.println("Pago extra por Adulto:");
					pexA=s.nextDouble();
				}while(pexA<500);
				ob[i].AIn=ob[i].Calcular_AIn(pexA);
				ob[i].himprimir();
			}
			else
				ob[i].imprimir();
		}
	}
}