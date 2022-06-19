#include "complex.h"

complex_P input(int d)
{
    complex_P a = (complex_P)malloc(sizeof(struct _complex));
    a->t =d;
    a->head = (float *)malloc(sizeof(float)*d);
    for(int i=0;i<d;i++)
        scanf("%f",&((a->head)[i]) );
    return a;
}

void print(complex_P a)
{
    int dim = a->t;
    for(int i=0;i<dim;i++)
        printf("%.2f ", ((a->head)[i]) );

    printf("\n");
}

complex_P add(complex_P a , complex_P b)
{
    complex_P c = (complex_P)malloc(sizeof(struct _complex));
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

complex_P sub(complex_P a , complex_P b)
{
    complex_P c = (complex_P)malloc(sizeof(struct _complex));
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

float mod(complex_P a)
{
    int dim = a->t;
    float sum =0;
    for(int i=0;i<dim;i++)
        sum += ((a->head)[i]) *((a->head)[i]);
    sum = square_root(sum);
    return sum;
}

float dot(complex_P a , complex_P b)
{
    int dim = a->t;
    float sum =0;
    for(int i=0;i<dim;i++)
        sum += ((a->head)[i]) *((b->head)[i]);
    return sum;
}
float COS(complex_P a, complex_P b)
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
