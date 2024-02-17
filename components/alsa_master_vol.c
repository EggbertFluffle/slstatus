/* Created by William Rabbermann */
#include <stdio.h>
#include <stdbool.h>
#include "../util.h"

#define TMP_BUF_SIZE 6
const char* alsa_master_vol(void) {
	char tmp_buf[TMP_BUF_SIZE];
	unsigned short i = 0;

	FILE *fp = popen("amixer get Master | tail -n 1 | grep -o '[0-9]*%'", "r");
	char ch;
	while ((ch = fgetc(fp)) != EOF && i < TMP_BUF_SIZE) {
		tmp_buf[i++] = ch;
	}
	tmp_buf[i] = '\0';

	pclose(fp);

	printf("%s", tmp_buf);

	return bprintf("%s", tmp_buf);
}
