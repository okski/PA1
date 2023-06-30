#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int lo; 
	int hi;
	char s, l, z, znak;
	int pocetnul = 0;
	int pocetcifer = 0;
	int sekvence = 0;
	znak = ' ';
	s = 's';
	l = 'l';
	z = 'z';
	printf("Zadejte interval:\n");
	//"<%d;%d>"
	if (scanf(" < %d ; %d > %c", &lo, &hi, &znak ) != 3){
		printf("Nespravny vstup.\n");
		return 0;
	} 
	if ((lo >= 0 && hi >= 0) != 1)
	{
		printf("Nespravny vstup.\n");
		return 0;
	}
	if ((lo>hi) != 0)
	{
		printf("Nespravny vstup.\n");
		return 0;
	} 
	if (znak != s && znak != l && znak != z ){
		printf("Nespravny vstup.\n");
		return 0;
	}
		int remainder, sekvencecisla, n;
		while (lo<=hi){
			sekvencecisla = 0;
			n = lo;
			 if (n == 0){
    			pocetnul = 1;
    			pocetcifer = 1;
    			sekvence = 1;
    		}
			while (n != 0)
				{  	
					remainder = n%2;
					n = n / 2;
					pocetcifer = pocetcifer + 1;
					if (remainder == 0)
					    {
					        pocetnul = pocetnul + 1;
					        sekvencecisla = sekvencecisla + 1;
					        if (sekvencecisla > sekvence)
					    		sekvence = sekvencecisla;
					    }
					if (remainder != 0)
						sekvencecisla = 0;
				}
			lo++;
		}
	switch (znak){
			default: printf("Velke spatne\n");
			case 'l':
				printf("Cifer: %d\n", pocetcifer); return 0;
			case 's':
				printf("Sekvence: %d\n", sekvence); return 0;	
			case 'z':
				printf("Nul: %d\n", pocetnul); return 0;
		return 0;
		}
}