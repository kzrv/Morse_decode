#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "morse.h"

int main(void) {
	int pocet;
	tMorse* t = nactiMorse("dataMorse.bin", &pocet);
	char* res = decode("dataEncode.txt", t, pocet);
	printf("%s", res);
	return 0;
}