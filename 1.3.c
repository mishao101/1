#include <stdio.h>
int main( ) {
int day;
int month;
int a;
day=19;
month=9;
a=day;
day=month;
month= a;
printf("month=%d,day=%d",month,day);
return(0);
}

