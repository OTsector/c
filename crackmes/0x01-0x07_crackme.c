/*
        _ 
 07    [|] 0ffensive 7ester

 License: GLP v2.0
 original name: 0x01-0x07_crackme.c
 written by: -07 @ github.com/OTsector
 use: tcc 0x01-0x07_crackme.c -o crackme.bin


 ,= kid: cp %; pro: a+; legend: w+
 |
 |
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(int end) {
	char *g="Access Granted";
	char *b="Access Denied";
	if(end==0) {
		puts(g); exit(0);
	} else {
		puts(b); exit(1);
	}
}

int checker(char *input, char *passwd, int status) {
	if(status == 2) {
		if(strcmp(input, passwd) == 0)
			return 0;
		else
			return 1;
	} else {
		if(strcmp(input, passwd) == 0)
			return 2;
		else return 1;
		}
}

void checkerPlatform(char *input, char *passwd) {
	output(checker(input, passwd, checker(input, passwd, 3)));
}

int main(int argc, char *argv[]) {

	char *data="grihf@ise!njewo";
//	            |||||||||||||||
//	            000000000011111
//	            012345678901234

	int parser[]={13, 1, 14, 10, 0};
//	              |   |  |   |   |
//	              w   r  o   n   g

	char *passwd=(char*)malloc(sizeof(char)*sizeof(parser)/sizeof(int));
	for(int a=0; a<sizeof(parser)/sizeof(int); a++) {
		for(int b=0; b<strlen(data); b++) {
			if(b == parser[a]) {
				*(passwd+a)=*(data+b);
			}
		}
	}

	if(argc<2) {
		puts("input a argument dude!"); return 1;
	}

	checkerPlatform(argv[1], passwd);

	return 0;
}
