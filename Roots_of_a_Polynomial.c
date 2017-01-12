#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void linear(double a0,double a1)
{
    double e=-a0/a1;
    printf("\n\nThe real roots for the given polynomial equation is :\n\n %.3lf \n\n",e);
}

void quadratic(double t,double r,double s)
{
    double det,x1,x2,x1r,x1i;
    det=(r*r)-(4*s*t);
    if(det>=0)
    {
        x1= (-r+sqrt(det))/2*t;
        x2= (-r-sqrt(det))/2*t;
        printf("\n\nThe real roots for the given polynomial equation are :\n\n %.3lf , %.3lf \n\n",x2,x1);
    }
    else
    {
        x1r=-r/2;
        x1i=sqrt(fabs(det))/2;
        printf("\n\nThe complex roots for the given polynomial equation are :\n\n %.3lf + %.3lf j and %.3lf -%.3lf j \n\n",x1r,x1i,x1r,x1i);
    }
}

int main()
{
    int w,j,i,n;
    double t,det,p,q,x1=0.00,x2=0.00,x1r,x1i,r=0.1,s=0.1,ds,dr,a[100],b[100],c[100],d[100];
    b[4]=0,b[3]=0;
    printf("\n**************************************************************************\n");
    printf("\n\nThis program calculates all roots of a polynomial with real coefficients : \n");
    printf("\n**************************************************************************\n\n");
    printf("\nEnter the highest degree of the polynomial : ");
    scanf("%d",&n);
    printf("\n\nEnter the coefficients of the polynomial function which will be represented in the following manner :\n\n");
    printf("\n\n 'a[n]x^n+a[n-1]x^(n-1)+a[n-2]x^(n-2)+..................+a[1]x+a[0]' \n\n");

    for(i=n;i>=0;i--)
    {
        printf("\n\n a[%d] : ",i);
        scanf("%lf",&a[i]);
    }

    printf("\nThe entered polynomial is : \n\n");
    for(i=0;i<=n;i++)
    if(a[n-i]>=0)
        printf(" +%.2lfx^%d",a[n-i],n-i);
    else
        printf(" %.2lfx^%d",a[n-i],n-i);
        //printf("\n\nEnter two initial approximation value : \n\n");
        //scanf("%lf %lf",&r,&s);
    w=n;
    if(w==1)
    {
        linear(a[0],a[1]);
        w--;
    }
    if(w==2)
    {
        quadratic(a[2],a[1],a[0]);
        w=w-2;
    }
    while(w>=3)
    {
        for(j=1;j<=50;j++) {
            b[n]=a[n];
            b[n-1]=a[n-1]-r*b[n];
            for(i=n-2;i>=1;i--)
            {
                b[i]=a[i]-r*b[i+1]-s*b[i+2];
            }
            b[0]=a[0]-s*b[2];
            c[n]=b[n];
            c[n-1]=b[n-1]-r*c[n];
            for(i=n-2;i>=2;i--)
            {
                c[i]=b[i]-r*c[i+1]-s*c[i+2];
            }
            c[1]=-s*c[3];
            d[n]=b[n];
            d[n-1]=b[n-1]-r*d[n];
            for(i=n-2;i>=3;i--)
            {
                d[i]=b[i]-r*d[i+1]-s*d[i+2];
            }
            d[2]=b[2]-s*d[4];
            dr=(b[0]*d[3]-b[1]*d[2])/((d[2]-r*d[3])*d[2]+s*d[3]*d[3]);
            ds=(-b[1]*s*d[3]-b[0]*(d[2]-r*d[3]))/((d[2]-r*d[3])*d[2]+s*d[3]*d[3]);
            p=r-dr;
            q=s-ds;
            r=p;
            s=q;
        }
        t=1;
        quadratic(t,r,s);
        w=w-2;
        for(i=n;i>=0;i--){
            a[n-i]=b[n-i];
        }
        for(i=n;i>=0;i--) {
            a[n-i]=a[n-i+2];
        }
    }
    if(w==2)
    {
        quadratic(b[4],b[3],b[2]);
        w=w-2;
    }
    if(w==1)
    {
        linear(b[2],b[3]);
        w--;
    }
    getch();
}
