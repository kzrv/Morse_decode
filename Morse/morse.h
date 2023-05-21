#pragma once

typedef struct {
	char znak;
	char morseSymbol[6];
}tMorse;

tMorse* nactiMorse(char* jmSoub, int* dim);
char getCharByMorseSymbol(char* morseSymbol, tMorse* poleMorse, int dim);
char* decode(char* jmSoub, tMorse* poleMorse, int dim);
