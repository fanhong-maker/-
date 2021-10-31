#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
        float real;
        float image;
}Complex;
void assign(Complex* z, float real, float image)
{
        z->real = real;
        z->image = image;
}
void add(Complex* z, Complex z1, Complex z2)
{
        z->real = z1.real + z2.real;
        z->image = z1.image + z2.image;
}
void subtract(Complex* z, Complex z1, Complex z2)
{
        z->real = z1.real - z2.real;
        z->image = z1.image - z2.image;
}
void multiply(Complex* z, Complex z1, Complex z2)
{
        z->real = z1.real * z2.real - z1.image * z2.image;
        z->image = z1.real * z2.image + z2.real * z1.image;
}
void divide(Complex* z, Complex z1, Complex z2)
{
        Complex* temp1;
        Complex* temp2;
        multiply(temp1, z2, z2);
        multiply(temp2, z1, z2);
        z->real = temp1->real/(temp2->image + temp2->real);
        z->image = temp1->image/(temp2->image + temp2->real);
}
float getreal(Complex z)
{
        return z.real;
}
float getimage(Complex z)
{
        return z.image;
}
void printfplural(Complex z)
{       
        printf("z = %d + %di",z.real, z.image);
}
int main(void)
{

        return 0;
}