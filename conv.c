#include "conv.h"

// ================== convert binary to other ===================
int bin2dec(long int binarynum)
{
	int decimalnum = 0, temp = 0, remainder;
    while (binarynum != 0) {
        remainder = binarynum % 10;
        binarynum = binarynum / 10;
		decimalnum = decimalnum + remainder * pow(2,temp);
		temp++;
    }
	return decimalnum;
}

int bin2oct(long int binarynum)
{
	int decimalnum = bin2dec(binarynum);
	int octalnum = 0, i = 1;
    while (decimalnum != 0) {
		octalnum  = octalnum + (decimalnum % 8) * i;
		decimalnum = decimalnum / 8;
		i = i * 10;
    }
	return octalnum;
}

int bin2hex(long int binarynum)
{
	int hexadecimalnum = 0;
	int i = 1, remainder;
    while (binarynum != 0) {
		remainder = binarynum % 10;
		hexadecimalnum = hexadecimalnum + remainder * i;
		i = i * 2;
		binarynum = binarynum / 10;
    }
	return hexadecimalnum;
}

// ================== convert octal to other ===================
int oct2dec(int octalnum)
{
	int decimalnum = 0, temp = 0;
	while (octalnum != 0)
	{
		decimalnum = decimalnum + (octalnum % 10) * pow(8,temp);
		temp++;
		octalnum = octalnum / 10;
	}
	return decimalnum;
}

long long oct2bin(int octalnum)
{
	int decimalnum, i = 1;
	long long binarynum = 0;
	decimalnum = oct2dec(octalnum);
	while (decimalnum != 0)
	{
		binarynum = binarynum + (decimalnum % 2) * i;
		decimalnum = decimalnum / 2;
		i = i * 10;
	}
	return binarynum;
}

int oct2hex(int octalnum)
{
	long long temp_binarynumber = oct2bin(octalnum);
	int hexadecimalnum = 0;
	hexadecimalnum = bin2hex(temp_binarynumber);
	return hexadecimalnum;
}


// ================== convert decimal to other ===================
long long dec2bin(int decimalnum) {
    long long binarynum = 0;
	int remainder,temp = 1;
    while (decimalnum != 0) {
        remainder = decimalnum % 2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + remainder * temp;
		//printf("temp_binarynumber %lld\n",binarynum);
        temp = temp * 10;
    }
    return binarynum;
}

int dec2oct(int decimalnum)
{
	int octalnum = 0,temp = 1;
	while (decimalnum != 0)
	{
		octalnum = octalnum + (decimalnum % 8) * temp;
		decimalnum = decimalnum / 8;
		temp = temp * 10;
	}
	return octalnum;
}

int dec2hex(int decimalnum)
{
	long long temp_binarynumber = dec2bin(decimalnum);
	int hexadecimalnum = 0;
	hexadecimalnum = bin2hex(temp_binarynumber);
	return hexadecimalnum;
}

// ================== convert hexadecimal to other ===================
#define ARRAY_SIZE 20
long long hex2dec(const char hex[ARRAY_SIZE])
{
	int len = strlen(hex), i = 0, value;
	long long decimal = 0, base = 1;
	for(i = len--; i >=0 ;i--)
	{
		if(hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base = base * 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base = base * 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base = base * 16;
		}
	}
	return decimal;
}

int hex2oct(const char hex[ARRAY_SIZE])
{
	long long decimal = hex2dec(hex);
	int octalnum = 0;
	octalnum = dec2oct((int) decimal);
	return octalnum;
}

long long hex2bin(const char hex[ARRAY_SIZE])
{
	long long decimal = hex2dec(hex);
	long long binarynum = 0;
	binarynum = dec2bin((int) decimal);
	return binarynum;
}

void convert_bin(const char *str)
{
	printf("[2]%s = [8]%d\n",str,bin2oct(atol(str)));
	printf("[2]%s = [10]%d\n",str,bin2dec(atol(str)));
	printf("[2]%s = [16]%x\n",str,bin2hex(atol(str)));
}

void convert_oct(const char *str)
{
	printf("[8]%s = [2]%lld\n",str,oct2bin(atol(str)));
	printf("[8]%s = [10]%d\n",str,oct2dec(atol(str)));
	printf("[8]%s = [16]%x\n",str,oct2hex(atol(str)));
}

void convert_dec(const char *str)
{
	printf("[10]%s = [2]%lld\n",str,dec2bin(atoi(str)));
	printf("[10]%s = [8]%d\n",str,dec2oct(atoi(str)));
	printf("[10]%s = [16]%x\n",str,dec2hex(atoi(str)));
}

void convert_hex(const char *str)
{
	printf("[16]%s = [2]%lld\n",str,hex2bin(str));
	printf("[16]%s = [8]%d\n",str,hex2oct(str));
	printf("[16]%s = [10]%lld\n",str,hex2dec(str));
}
