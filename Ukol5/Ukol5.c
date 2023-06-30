#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define ZNAKY 26
#define INIT_SIZE 4



typedef struct usek_t {int length; float poplatek [ZNAKY]; int typmyta [ZNAKY];} cteniuseku;

int readTUsek(cteniuseku* readUsek) {
	int length;
	char nactenyznak;
	float poplatek;
	int a = scanf(" [ %d", &length);
	if (a == 0) {
		printf("Nespravny vstup.\n");
		exit (1);
	}
	if (a == 1) {
		if (length > 0) {
			char dvojtecka = ':';
			int b = scanf(" %c", &dvojtecka);
			if (b == 0) {
				printf("Nespravny vstup.\n");
				exit (1);
			}
			if (dvojtecka == ':') {
				char carka = ',';
				while (carka == ',') {
					int c = scanf(" %c", &nactenyznak);
					if (c == 0) {
						printf("Nespravny vstup.\n");
						exit (1);
					}				
					if (nactenyznak >= 'A' && nactenyznak <= 'Z') {
						readUsek->typmyta[nactenyznak - 'A'] = nactenyznak;
						int f = scanf(" = %f", &poplatek);
						if ( f == 1 && poplatek >= 0) {
							readUsek->poplatek[nactenyznak - 'A'] = poplatek;
							int y = scanf(" %c", &carka);
							if (y == 0) {
								printf("Nespravny vstup.\n");
								exit (1);
							}
							if (y == 1) {
								if (carka == ',') {
									continue;
								}
								if (carka == ']') {
									break;
								}
							}
						} 
						
					} else {
						printf("Nespravny vstup.\n");
						exit (1);
					}
				}
			}
		} else {
			printf("Nespravny vstup.\n");
			//free(readUsek);
			exit (1);
		}
	}
	readUsek->length = length;
	return length;
}

typedef struct useky_t {cteniuseku* data; int size; int count;} cteniradky;

void add (cteniradky* array, cteniuseku* d) {
	if (array->count == array->size) {
		if (array->size == 0){
			array->size = INIT_SIZE;
		}
		else {
			array->size += 1;	
		}
		array->data = (cteniuseku*) realloc(array->data, array->size * sizeof(cteniuseku));
	}
	array->data[array->count] = *d;
	array->count++;
}

int readTUseky (cteniradky* read) {
	char slozenazavorka = '{';
	int a = scanf(" %c", &slozenazavorka);
	if (a == 0){
			printf("Nespravny vstup.\n");
			exit (1);
		}
	if (a == 1) {		
		if (slozenazavorka == '{') {
			char carka = ',';
			cteniuseku readUsek = {0, {0}, {0}};
			while (carka == ',') {
				if (readTUsek(&readUsek)) {
					add(read, &readUsek);
				}
				int y = scanf(" %c", &carka);
				if (y != 1) {
					printf("Nespravny vstup.\n");
					exit (1);
				}
				if (y == 1) {
					if (carka == ',') {
						continue;
					}
					if (carka == '}') {
						break;
					}
					if (carka != ',' && carka != '}') {
						printf("Nespravny vstup.\n");
						exit (1);
					}
				}
			}
		} else {
			printf("Nespravny vstup.\n");
			exit (1);;
		}
	}
	return 0;
}

void printvysledek (float vyseldnaCastka[], cteniradky* read) {
	int vytisk = 0;
		for(int j = 0; j < ZNAKY; j++) {
			if (vyseldnaCastka[j] < 1e-20){
				continue;
			}
			if (vytisk == 1) {
				printf(",");
			}
			printf(" %c=%f", read->data[read->count - 1].typmyta[j], vyseldnaCastka[j]);
			vytisk = 1;
		}
	printf("\n");
}

float vypocet (cteniradky* read, int Hledani[2]) {
	float vyseldnaCastka[ZNAKY];
	int max, min;
	if (Hledani[0] < Hledani[1] ) {
		min = Hledani[0];
		max = Hledani[1];
	} else {
		min = Hledani[1];
		max = Hledani[0];
	}
	int usek;
	for (int j = 0; j<ZNAKY; j++) {
		vyseldnaCastka[j] = 0;
	}
	int soucetcasti = 0;
	int puvodnimax = max;
	for (int i = 0; i < read->count; i++) {
		soucetcasti = soucetcasti + read->data[i].length;
		if (min > soucetcasti) {
			continue;
		}
		if (puvodnimax > soucetcasti) {
			max = soucetcasti;
		} else {
			max = puvodnimax;
		}
		for (int j = 0; j < ZNAKY; j++) {
			usek = max - min;
			vyseldnaCastka[j] = vyseldnaCastka[j] + usek * read->data[i].poplatek[j];
		}
		if (max < soucetcasti) {
			break;
		}
		min = soucetcasti;
	}
	printvysledek(vyseldnaCastka, read);
	return 1;
}

int main() {
	cteniradky readUseky = {NULL, 0, 0};
	printf("Myto:\n");
	for (int i = 0; i < readUseky.count ; i++) {
		for (int j = 0; j < ZNAKY; j++) {
			readUseky.data[i].poplatek[j] = 0;
			readUseky.data[i].typmyta[j]= 0;
		}
	}
	readTUseky(&readUseky);
	printf("Hledani:\n");
	int soucet = 0;
	for (int i = 0; i < readUseky.count; ++i){
		soucet = soucet + readUseky.data[i].length;
	}
	int y = 2;
	int Hledani[2];
	while (y  == 2){
		y = scanf(" %d %d", &Hledani[0], &Hledani[1]);
		if (y == EOF) {
			free(readUseky.data);
			return 0;
		}
		if (y != 2) {
			printf("Nespravny vstup.\n");
			exit (1);
		}
		if (Hledani[0] > soucet || Hledani[1] > soucet) {
			printf("Nespravny vstup.\n");
			exit (1);	
		}
		if (Hledani[0] == Hledani[1]) {
			printf("Nespravny vstup.\n");
			exit (1);
		}
		if (Hledani[0] > soucet || Hledani[1] > soucet) {
			printf("Nespravny vstup.\n");
			exit (1);
		}
		printf("%d - %d:", Hledani[0], Hledani[1]);
		vypocet(&readUseky, Hledani);
	}
	free(readUseky.data);
	return 0;
}