#include<stdio.h>
int main() {
float v;
float t;
float sina;
float a;
printf("Введите начальную скорость тела в м/с   \n");
scanf("%f",&v);
printf("Введите угол   \n");
scanf("%f",&a);
a=(a*3.14)/180;
sina=a-(a*a*a)/6;
t=2*v*sina/9.81;
printf("Время падения тела составит %.3f секунд   \n",t);
return 0;
}

