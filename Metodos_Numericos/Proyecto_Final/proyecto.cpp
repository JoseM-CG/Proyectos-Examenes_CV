#include<stdio.h>
int i,n=5;
double prom(double a[]);
double sum_n(double x[],double y[],double Y);
double sum_d(double x[],double Y);
main()
{
    double x[]={2013,2014,2015,2016,2017},y[]={2.52,2.04,2.78,1.38,2.02},X=0,Y=0,m=0,b=0,z=2018;
    //Calcular promedio de x_i y y_i
    X=prom(x);
    Y=prom(y);
    printf("Promedio x = %lf\nPromedio y = %lf",X,Y);
    //Calcular m
    m=sum_n(x,y,Y)/sum_d(x,X);
    printf("\nm = %lf",m);
    //Calcular b
    b=Y-m*X;
    printf("\nb = %lf",b);
    //Calcular P(x)
    printf("\nP(x) = %lf(x) + (%lf) => P(%lf) = %lf",m,b,z,(m*z)+b);
}
double prom(double a[]){
    double s=0;
    for(i=0;i<n;i++){
        s+=a[i];
    }
    return s/n;
}
//Suma correspondiente al numerador de m
double sum_n(double x[],double y[],double Y){
    double s=0;
    for(i=0;i<n;i++){
        s+=x[i]*(y[i]-Y);
    }
    return s;
}
//Suma correspondiente al denominador de m
double sum_d(double x[],double X){
    double s=0;
    for(i=0;i<n;i++){
        s+=x[i]*(x[i]-X);
    }
    return s;
}