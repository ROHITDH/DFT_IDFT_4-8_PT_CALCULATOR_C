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
    Complex cx[8];

    Complex imd[30];
    Complex temp[10];


//////////////////////////////////
    Complex minus; //-1
    minus.a=-1;
    minus.b=0;

    Complex cpx;  // i
    cpx.a=0;
    cpx.b=1;

    Complex w8m1;
    w8m1.a = 0.707;
    w8m1.b = 0.707;

    Complex w8m3;
    w8m3.a = -0.707;
    w8m3.b = 0.707;
/////////////////////////////////


    printf("8 point DIT FFT IDFT Freq: 0,1,2,3,4,5,6,7 --> Time: 0,4,2,6,1,5,3,7\n");
    printf("format: A+Bi\n\n");
    printf("Enter 8 points X(k): ");

    for (i=0;i<8;i++){
        scanf("%f+%fj", &cx[i].a ,&cx[i].b);
    }

//1 butterfly
    imd[0] = add(cx[4], cx[0]);
    printf(" n1:  %f+%fi\n", imd[0].a ,imd[0].b);

    imd[1] = add(cx[5], cx[1]);
    printf(" n2:  %f+%fi\n", imd[1].a ,imd[1].b);

    imd[2] = add(cx[6], cx[2]);
    printf(" n3:  %f+%fi\n", imd[2].a ,imd[2].b);

    imd[3] = add(cx[7], cx[3]);
    printf(" n4:  %f+%fi\n", imd[3].a ,imd[3].b);


    imd[4] = add(cx[0], multiply(minus,cx[4]));
    printf(" n5:  %f+%fi\n", imd[4].a ,imd[4].b);

    imd[5] = add(cx[1], multiply(minus,cx[5]));
    imd[5] = multiply(w8m1,imd[5]);
    printf(" n6:  %f+%fi\n", imd[5].a ,imd[5].b);

    imd[6] = add(cx[2], multiply(minus,cx[6]));
    imd[6] = multiply(cpx,imd[6]);
    printf(" n7:  %f+%fi\n", imd[6].a ,imd[6].b);

    imd[7] = add(cx[3], multiply(minus,cx[7]));
    imd[7] = multiply(w8m3,imd[7]);
    printf(" n8:  %f+%fi\n", imd[7].a ,imd[7].b);

     printf("\n\n");

//2 butterfly
    imd[8] = add(imd[2], imd[0]);
    printf(" n11:  %f+%fi\n", imd[8].a ,imd[8].b);

    imd[9] = add(imd[3], imd[1]);
    printf(" n22:  %f+%fi\n", imd[9].a ,imd[9].b);

    imd[10] = add(imd[0], multiply(minus,imd[2]));
    printf(" n33:  %f+%fi\n", imd[10].a ,imd[10].b);

    imd[11] = add(imd[1],  multiply(minus,imd[3]));
    imd[11] = multiply(cpx,imd[11]);
    printf(" n44:  %f+%fi\n", imd[11].a ,imd[11].b);

    imd[12] = add(imd[6], imd[4]);
    printf(" n55:  %f+%fi\n", imd[12].a ,imd[12].b);

    imd[13] = add(imd[7], imd[5]);
    printf(" n66:  %f+%fi\n", imd[13].a ,imd[13].b);

    imd[14] = add(imd[4], multiply(minus,imd[6]));
    printf(" n77:  %f+%fi\n", imd[14].a ,imd[14].b);

    imd[15] = add(imd[5],  multiply(minus,imd[7]));
    imd[15] = multiply(cpx,imd[15]);
    printf(" n88:  %f+%fi\n", imd[15].a ,imd[15].b);

    printf("\n\n");

//3 butterfly
    imd[16] = add(imd[8], imd[9]);
    printf(" n11:  %f+%fi\n", imd[16].a ,imd[16].b);

    imd[17] = add(imd[8], multiply(minus,imd[9]));
    printf(" n11:  %f+%fi\n", imd[17].a ,imd[17].b);


    imd[18] = add(imd[10], imd[11]);
    printf(" n11:  %f+%fi\n", imd[18].a ,imd[18].b);

    imd[19] = add(imd[10], multiply(minus,imd[11]));
    printf(" n11:  %f+%fi\n", imd[19].a ,imd[19].b);


    imd[20] = add(imd[12], imd[13]);
    printf(" n11:  %f+%fi\n", imd[20].a ,imd[20].b);

    imd[21] = add(imd[12], multiply(minus,imd[13]));
    printf(" n11:  %f+%fi\n", imd[21].a ,imd[21].b);


    imd[22] = add(imd[14], imd[15]);
    printf(" n11:  %f+%fi\n", imd[22].a ,imd[22].b);

    imd[23] = add(imd[14], multiply(minus,imd[15]));
    printf(" n11:  %f+%fi\n", imd[23].a ,imd[23].b);



printf("\n\n");
     for (i=16;i<24;i++){
       printf("Final:  %f+%fi\n", imd[i].a/8 ,imd[i].b/8);
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




