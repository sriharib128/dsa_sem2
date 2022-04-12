#include "complex.h"

complex input(int d)
{
    complex a = (complex)malloc(sizeof(struct _complex));
    a->t =d;
    a->head = (float *)malloc(sizeof(float)*d);
    for(int i=0;i<d;i++)
        scanf("%f",&((a->head)[i]) );
    return a;
}

void print(complex a)
{
    int dim = a->t;
    for(int i=0;i<dim;i++)
        printf("%.2f ", ((a->head)[i]) );

    printf("\n");
}

complex add(complex a , complex b)
{
    complex c = (complex)malloc(sizeof(struct _complex));
    int dim = a->t;
    c->t = dim;
    float * temp = (float*)malloc(sizeof(float)*dim);
    for(int i=0;i<dim;i++)
    {
        temp[i]=(a->head)[i] + (b->head)[i];
    }
    c->head = temp;
    return c;
}

complex sub(complex a , complex b)
{
    complex c = (complex)malloc(sizeof(struct _complex));
    int dim = a->t;
    c->t = dim;
    float * temp = (float*)malloc(sizeof(float)*dim);
    for(int i=0;i<dim;i++)
    {
        temp[i]=(a->head)[i] - (b->head)[i];
    }
    c->head = temp;
    return c;
}

float mod(complex a)
{
    int dim = a->t;
    float sum =0;
    for(int i=0;i<dim;i++)
        sum += ((a->head)[i]) *((a->head)[i]);
    sum = square_root(sum);
    return sum;
}

float dot(complex a , complex b)
{
    int dim = a->t;
    float sum =0;
    for(int i=0;i<dim;i++)
        sum += ((a->head)[i]) *((b->head)[i]);
    return sum;
}
float COS(complex a, complex b)
{
    float x = dot(a,b) / (mod(a)*mod(b));
    return x;
}

float square_root(float sum)
{	
	float lo=0,hi=sum,mid;
	float prec = 1e-4;
	while(hi-lo>prec)
	{
		mid=(hi+lo)/2.0;
		if(mid*mid>sum)
			hi=mid;
		else
			lo = mid;
	}
    return lo;
}
