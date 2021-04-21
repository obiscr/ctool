#include "ctool.h"
#include "conv.h"
#include "base64.h"

int main (int argc, char *argv[])
{
	deal_args(argc,argv);
	return 0;
}

void deal_args(int argc, char *argv[])
{
	if (argc == 1 || argc == 2)
	{
		usage("CTools Version 1.0"
				"\nUsage:"
				"\n\tctools conv <type> <number>	--This command will "
				"convert the number to BIN|OCT|DEC|HEX format."
				"\n\te.g."
				"\n\tctools conv -b 1001101000011101100001010	--binary "
				"format convert."
				"\n\tctools conv -o 115035412	--octal format convert."
				"\n\tctools conv -d 20200202	--decimal format convert."
				"\n\tctools conv -h 1343b0a	--hexadecimal format convert.\n");
		return; 
	}
	
	if (!strcmp("conv",argv[1]))
	{
		if (!strcmp("-b",argv[2])){
			convert_bin(argv[3]);
		} else if(!strcmp("-o",argv[2])) {
			convert_oct(argv[3]);
		} else if(!strcmp("-d",argv[2])) {
			convert_dec(argv[3]);
		} else if(!strcmp("-h",argv[2])) {
			convert_hex(argv[3]);
		} else {
			printf("Seems to be missing parameters, need to specify "
					"the type for %s\n", argv[2]);
			usage("Please specify the type <-b -o -d -h>\n");
		}
		return;
	} else if (!strcmp("base64",argv[1])) {
		unsigned char *buf = NULL;

		if(!strcmp("-e",argv[2])){
			buf = base64_encode(argv[3]);
			printf("%s\n",buf);
		} else if (!strcmp("-d",argv[2])) {
			buf = base64_decode(argv[3]);
			printf("%s\n",buf);
		} else {
			usage("Need encrypt or decrypt string!\n");
		}
		free(buf);
	}

}

void usage(const char *output)
{
	printf("%s\n", output);
	exit(0);
}
