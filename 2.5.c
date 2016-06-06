#include<stdio.h>
int main() {
int sum;
int raz;
int pro;
float chast;
float a;
float b;
printf("Введите первое число \n");
scanf("%f",&a);
printf("Введите второе число \n");
scanf("%f",&b);
sum= a+b;
raz= a-b;
pro= a*b;
chast= a/b;
printf(" сумма: %d, разность: %d, произведение: %d, частное: %.3f ",sum,raz,pro,chast);
return 0;
}


