#include<stdio.h>
int main(void) {
int x=7893;
int c=1234;
int m=15239;
int a=430;
int i=1;
int n;
printf("Введите количество элементов последовательности:\n");
scanf("%d",&n);
	while (i<=n) {
	x=(a*x+c)%m;
	printf("%d,  ", x);
	i=i+1;
			}
return 0;
}
