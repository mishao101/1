#include <stdio.h>
#include <string.h>
int main(void)
{
char s[1000];
int i;
printf("Введите строку  ");
scanf("%s",s);
i=strlen(s)+1;
printf("Размер строки равен %d байт  ",i);
}
