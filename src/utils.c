#include "../include/utils.h"
#include <string.h>

void clean_input(char *str) {
    str[strcspn(str, "\n")] = 0;
}
