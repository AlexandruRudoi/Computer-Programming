#include <stdio.h>
#include <math.h>

float a, b, c;
float x1, x2, px;
float x, F;
int n;

void forFunc();
void whileFunc();
void doWhileFunc();
void gotoFunc();

int main(){
    printf("Enter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    do {
        printf("Enter x1, x2, px: ");
        scanf("%f%f%f", &x1, &x2, &px);
    } while(x1 > x2);

    printf("\nResults using for: \n");
    forFunc();

    printf("\nResults using while: \n");
    whileFunc();

    printf("\nResults using do-while: \n");
    doWhileFunc();

    printf("\nResults using goto: \n");
    forFunc();
        
    return 0;
}

void forFunc(){
    n = 0;
    for(x=x1; x<=x2; x+=px) {        n++;
        if(x - 2 > 0 && a == 0) {
            F = ((a + log(x)) / sin(c)) - pow(b, 2);
        } else if(x - 2 < 0 || a != 0) {
            F = (x - sin(x + 1)) / b;
        } else {
            F = (a*x + c) / cos(2*x);
        }
        printf("%d: x = %f\t F = %f\n", n, x, F);
    }
}

void whileFunc(){
    n = 0;
    x = x1;
    while(x <= x2) {
        n++;
        if(x - 2 > 0 && a == 0) {
            F = ((a + log(x)) / sin(c)) - pow(b, 2);
        } else if(x - 2 < 0 || a != 0) {
            F = (x - sin(x + 1)) / b;
        } else {
            F = (a*x + c) / cos(2*x);
        }
        printf("%d: x = %f\t F = %f\n", n, x, F);
        x += px;
    }
}

void doWhileFunc(){
    n = 0;
    x = x1;
     do{
        n++;
        if(x - 2 > 0 && a == 0) {
            F = ((a + log(x)) / sin(c)) - pow(b, 2);
        } else if(x - 2 < 0 || a != 0) {
            F = (x - sin(x + 1)) / b;
        } else {
            F = (a*x + c) / cos(2*x);
        }
        printf("%d: x = %f\t F = %f\n", n, x, F);
        x += px;
    } while(x <= x2);
}

void gotoFunc(){
    n = 0;
    x = x1;
    func: 
        n++;
        if(x - 2 > 0 && a == 0) {
            F = ((a + log(x)) / sin(c)) - pow(b, 2);
        } else if(x - 2 < 0 || a != 0) {
            F = (x - sin(x + 1)) / b;
        } else {
            F = (a*x + c) / cos(2*x);
        }
        printf("%d: x = %f\t F = %f\n", n, x, F);
        x += px;

   if(x <= x2) {
    goto func;
   } 
}