
#include <stdio.h>
int main(void)
{
char k;
printf("Введите строку:\n");
while ((k = getchar())!= '\n')
	{	
	if(k>='a'&& k<='z')
	putchar(k-32);
	else putchar(k);
	}
return 0;
}
