#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int ou(int n, ...){
	va_list valores;
	int i, r = 0;
	va_start (valores,n);
	for(i=0;i<n;i++) if(va_arg(valores, int)) r = 1;
	va_end(valores);
	return r;
}

int main(){
	int x=3,y=2;
	printf("%i\n%i\n%i\n%i\n", ou(1 , x>y), ou(2, 3>2 , 7>5), ou(3, 1 !=1 , 2!=2 , 3!=3), ou(3 , 1!=1 , 2!=2 , 3 == 3));
}
