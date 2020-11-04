#include<stdio.h>

    typedef struct COMPLEX{
        float a;
        float b;
    }Complex;

Complex multiply(Complex, Complex);
Complex add(Complex, Complex);
Complex sub(Complex, Complex);

int main(){
    int i;
    Complex cx[4];

    Complex imd[10];
    Complex temp[2];

    Complex minus;
    minus.a=-1;
    minus.b=0;

    Complex cpx;
    cpx.a=0;
    cpx.b=-1;

    printf("4 point DIT FFT DFT Time: 0,2,1,3 --> Freq: 0,1,2,3\n");
    printf("format: A+Bi\n\n");
    printf("Enter 4 points x(n): ");

    for (i=0;i<4;i++){
        scanf("%f+%fj", &cx[i].a ,&cx[i].b);
    }

//1 butterfly
    imd[0] = add(cx[0], cx[2]);
    printf(" n1:  %f+%fi\n", imd[0].a ,imd[0].b);

    imd[1] = add(cx[0], multiply(minus,cx[2]));
    printf(" n2:  %f+%fi\n", imd[1].a ,imd[1].b);

//2 butterfly
    imd[2] = add(cx[1], cx[3]);
    printf(" n3:  %f+%fi\n", imd[2].a ,imd[2].b);

    imd[3] = add(cx[1], multiply(minus,cx[3]));
    printf(" n4:  %f+%fi\n", imd[3].a ,imd[3].b);

printf("\n\n");

//3 butterfly
    imd[4] = add(imd[0], imd[2]);
    printf(" nn1:  %f+%fi\n", imd[4].a ,imd[4].b);

    imd[5] = add(imd[1], multiply(cpx,imd[3]));
    printf(" nn2:  %f+%fi\n", imd[5].a ,imd[5].b);

//4 butterfly
    imd[6] = add(imd[0],  multiply(minus,imd[2]));
    printf(" nn3:  %f+%fi\n", imd[6].a ,imd[6].b);

    temp[0] = multiply(cpx,imd[3]);
    imd[7] = add(imd[1], multiply(minus,temp[0]));
    printf(" nn4:  %f+%fi\n", imd[7].a ,imd[7].b);

printf("\n\n");
     for (i=4;i<8;i++){
       printf("Final:  %f+%fi\n", imd[i].a ,imd[i].b);
    }

    return 0;
}


Complex multiply(Complex x, Complex y){
    Complex z;
    z.a = x.a * y.a - x.b * y.b;
    z.b = x.a * y.b + x.b * y.a;
    return z;
}

Complex add(Complex x, Complex y){
    Complex z;
    z.a = x.a + y.a ;
    z.b = x.b + y.b ;
    return z;
}

Complex sub(Complex x, Complex y){
    Complex z;
    z.a = x.a - y.a ;
    z.b = x.b - y.b ;
    return z;
}




