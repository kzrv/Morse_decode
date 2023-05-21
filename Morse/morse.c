#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "morse.h"



tMorse* nactiMorse(char* jmSoub, int* dim) {
	FILE* f = fopen(jmSoub, "rb");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return 1;
	}
	tMorse* t = NULL;
	int n = 0;
	tMorse buf;
	while (fread(&buf, sizeof(tMorse), 1, f) == 1) {
		n++;
		t = realloc(t, sizeof(tMorse) * (n + 1));
		if (t == NULL) {
			printf("CHYBA ALLOKOVANI");
			return 1;
		}
		t[n - 1] = buf;
	}
	*dim = n;
	fclose(f);
	return t;
}
char getCharByMorseSymbol(char* morseSymbol, tMorse* poleMorse, int dim) {
	if (strcmp(morseSymbol, "/")==0) return " ";
	for (int i = 0;i < dim; i++) {
		if (strcmp(morseSymbol, poleMorse[i].morseSymbol) == 0) {
			return poleMorse[i].znak;
		}
	}
	printf("CHYBA DEKODVANI\n");
	return NULL;
}
char* decode(char* jmSoub, tMorse* poleMorse, int dim) {
	FILE* f = fopen(jmSoub, "r");
	if (f == NULL) {
		printf("CHYBA CTENI\n");
		return 1;
	}
	char fin[1000]="";
	char buf;
	char str[20] = "";
	int i = 0;
	while (fscanf(f,"%c",&buf)==1) {
		if (buf != ' ') {
			strncat(str, &buf,1);
		}
		else {
			char s = getCharByMorseSymbol(str, poleMorse, dim);
			strncat(fin, &s,1);
			memset(str, 0, sizeof(str));
		}
	}
	return fin;
}
