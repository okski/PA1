#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compareInt (const void * a, const void * b){
	if (*(int*)a == *(int*)b){
		return 0;
	}
	if ( *(int*)a <= 0 ) {
		return 1;
	}
	if ( *(int*)b <= 0 ) {
		return -1;
	}
	return *(int*)a < *(int*)b ? -1 : 1;
}
int main()
{
	int len, dist;
	const int a = 1000001;
	char y;
	int vzd[a];
	printf("Mozna umisteni:\n");
	// %d : { %d ,  }
	if ((scanf(" %d : { %d", &len, &vzd[0]) == 2) && len % 1 == 0 && len > 0 && vzd[0] % 1 == 0 && vzd[0] >= 1 && vzd[0] <= (len-1)) {
		int i = 1;
		for (; i < a; i++)
		{
			int x = scanf(" , %d", &vzd[i]);
			if (x == 0) {
				printf("Nespravny vstup.\n");
				return 0 ;
			}
			if ((x == 1) && i < (a - 1) && vzd[i] % 1 == 0 && vzd[i] >= 1 && vzd[i] <= (len-1)) {
				
			} else {
				printf("Nespravny vstup.\n");
				return 0 ;
			}
		}
		if (scanf(" %[}]", &y) != 1) {
			printf("Nespravny vstup.\n");
			return 0;
		}
		qsort(vzd, i, sizeof(int), compareInt);

		printf("Vzdalenosti:\n");
		while (scanf(" %d", &dist) == 1) {
			if (dist % 1 == 0 && dist > 0) {	
				if (dist >= len) {
					printf("Billboardu: 0\n");
					continue;
				}
				int min, max, las, poc;
				min = 1;
				max = dist;
				las = 0;
				poc = 0;
				for (int x = 0 ; x<=i ; x++) {
					int act = vzd[x];
							//printf("%d %d %d %d\n", min,max,las,act);
					if (act == 0) {
						if ((len - las) <= dist) {
							poc++;
							printf("Billboardu: %d\n", poc);
						} else {
							printf("N/A\n");
						}
						break;
					}
					if (act >= min && act <= max) {
						las = act;//printf("2\n");
					} else {
						min = las;
						max = las + dist;
						poc++;//printf("3\n");
						if (max >= len){
							printf("Billboardu: %d\n", poc);
							break;
						}
						if (act >= min && act <= max) {
							las = act;//printf("4\n");
						} else {
							printf("N/A\n");
							break;
						}
					}
				}//printf("5\n");	
			} else {
				printf("Nespravny vstup.\n");
				continue;
			}
		} 
	} else {
		printf("Nespravny vstup.\n");
		return 0;
	}
}
/* (len - dist - 1) < vzd || (dist >= vzd && */
//(len - dist - 1) < vzd || (dist >= vzd && 
// x = (len - 1) / dist;