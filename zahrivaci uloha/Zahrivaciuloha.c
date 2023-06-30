#include <stdio.h>

int main()
    {double x = 0;
    printf("ml' nob:\n");
    scanf("%lf",&x);
	if ( x != (int)x ||  !(x >=1 && x <= 5) ){
		printf("luj\n");
		return 0;
	   	}
	else{	    
	    	if ( x == 1){
				printf("Qapla'\nnoH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
				return 0;
			}
			if ( x == 2){
				printf("Qapla'\nQu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
				return 0;
			}	
			if ( x == 3){
				printf("Qapla'\nqaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
				return 0;
			}
			if ( x == 4){
				printf("Qapla'\nHa'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
				return 0;
			}	
			if ( x == 5){
				printf("Qapla'\nleghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
		        return 0;
			}
	}  
}
