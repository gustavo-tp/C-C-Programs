#include <stdio.h>
#include <math.h>

//K é o número de interações
//E é a precisão
//[a, b] é o intervalo da raiz

float funcaoX(float x) {
    return sqrt(x) - cos(x);
}

float bisseccao() {
    int i, itv = 2, N;
    float intv[itv], E, fx, Xn, fXn;
    intv[0] = 0;
    intv[1] = 1;
    E = 0.001;
    N = (int) ceil((log(intv[1]-intv[0]) - log(E)) / log(2));
    printf("N\t  an\t      bn\t Xn\t    f(a)\tf(Xn)\t      SINAL\t  E(b-a)\n");
    for (i=0; i<N+1; i++) {
        Xn = (intv[0] + intv[1]) / 2;
        fx = funcaoX(intv[0]);
        fXn = funcaoX(Xn);
        E = intv[1] - intv[0];
        printf("%d\t", i);
        printf("  %f    %f",intv[0], intv[1]);
        printf("   %f", Xn);
        printf("   %f   %f\t", fx, fXn);
        if(fx*fXn >= 0) {
            printf("+");
            intv[0] = Xn;
        } else {
            printf("-");
            intv[1] = Xn;
        }
        if (i == 0)
            printf("\t   ---");
        else {
            printf("\t  %.4f", E);
        }
        printf("\n");
    }
}

void drawChart() {

}

int main () {
    bisseccao();

    return 0;
}
