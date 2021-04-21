#ifndef BASE64_H
#define BASE64_H

#include <stdlib.h>
#include <string.h>

unsigned char *base64_encode(char *str);

unsigned char *base64_decode(char *code);

#endif /* BASE64_H */
