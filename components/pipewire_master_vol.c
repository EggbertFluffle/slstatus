/* Created by William Rabbermann */
#include <stdio.h>
#include <stdbool.h>
#include "../util.h"

#define TMP_BUF_SIZE 6
const char* pipewire_master_vol(void) {
	char tmp_buf[TMP_BUF_SIZE];
	unsigned short i = 0;

	FILE *fp = popen("pactl get-sink-volume @DEFAULT_SINK@ | grep -o '[0-9]*%' | head -n 1", "r");
	char ch;
	while ((ch = fgetc(fp)) != EOF && i < TMP_BUF_SIZE) {
		tmp_buf[i++] = ch;
	}
	tmp_buf[i - 1] = '\0';

	pclose(fp);

	return bprintf("%s", tmp_buf);
}
