#include <stdio.h>
#include <string.h>
int main(void) 
{
int n=0; 
int sum=0; 
int a;
float sr;
printf("Введите целое число \n");
scanf("%d",&a);
    while (a!=0) 
    {
	 sum+=a%10;
	 a/=10;
	 n=n+1;
	}
sr=(float)sum/(float)n;
printf("Количество = %d\n",n);
printf("Сумма = %d\n",sum);
printf("Среднее значение = %f\n",sr);
    return 0;
}



