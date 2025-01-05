/* Created by Harrison DiAmbrosio */
#include <stdbool.h>
#include "../util.h"

// BE SURE TO CHANGE MAKEFILE AND SLSTATUS.H

#define TMP_BUF_SIZE 12
const char* base_component(void) {
	char tmp_buf[TMP_BUF_SIZE];

	return bprintf("%s", tmp_buf);
}
