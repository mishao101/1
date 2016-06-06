#include <stdio.h>
int main(void)
{
int days1;
int days2;
int months;
int years;
printf("Введите количество дней");
scanf("%d",&days1);
years=days1/365;
months=days1%365/30;
days2=days1%365%30;
printf("%d лет,%d месяцев, %d дней",years,months,days2);
}

