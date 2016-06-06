#include <stdio.h>
int main(void){
printf(" int-  %zd байт \n", sizeof(int));
printf(" char- %zd байт \n", sizeof(char));
printf(" double-  %zd байт \n", sizeof(double));
printf(" float-  %zd байт\n", sizeof(float));
printf(" void- %zd байт\n", sizeof(void));
return 0;
}
