#include<stdio.h>
int main() {
int a;
int b=1;
printf("Введите число  ");
scanf("%d",&a);
while (a>1) {
b=b*a;
a=a-1;
}
printf("%d",b);
return 0;
}


