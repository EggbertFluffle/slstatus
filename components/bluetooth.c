/* Created by Eggbert Fluffle */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../util.h"

#define TMP_BUF_SIZE 16
const char* bluetooth(void) {
	char tmp_buf[TMP_BUF_SIZE];
	unsigned short i = 0;

	FILE *fp = popen("bluetooth | grep -o ' o[nf]*'", "r");
	char ch;
	fgetc(fp);
	while ((ch = fgetc(fp)) != EOF && i < TMP_BUF_SIZE) {
		tmp_buf[i++] = ch;
	}
	tmp_buf[i - 1] = '\0';

	pclose(fp);

	if(strcmp("on", tmp_buf) == 0) {
		bprintf("ON");
	} else {
		bprintf("OFF");
	}
}
