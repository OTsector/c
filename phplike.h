#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substr(char *text, int start, int end) {
	if(start<0 || start>strlen(text) || start>=end)
		return (char*)"";
	char *output=malloc(sizeof(char)*(end-start)+1);
	for(int i=start; i<=end; i++)
		*(output+strlen(output))=*(text+i);
	*(output+end)='\0';
	return output;
}

int strpos(char *haystack, char *needle) {
	for(int i=0; haystack[i] != '\0'; i++)
		if(strcmp(substr(haystack, (i+1), i+strlen(needle)), needle) == 0)
			return (i+1);
	return 0;
}

int strrpos(char *haystack, char *needle) {
	for(int i=strlen(haystack); i>=0; i--)
		if(strcmp(substr(haystack, (i+1), i+strlen(needle)), needle) == 0)
			return (i+1);
	return 0;
}

char *str_replace(char *str, char *replaceable, char *substitude) {
	char *output;
	int i, cnt = 0;
	int substitudelen = strlen(substitude);
	int replaceablelen = strlen(replaceable);
	for (i = 0; *(str+i) != '\0'; i++) {
		if (strstr(&*(str+i), replaceable) == &*(str+i)) {
			cnt++;
			i += replaceablelen - 1;
		}
	} 
	output = (char *)malloc(i+cnt*(substitudelen-replaceablelen)+1); 
	i = 0;
	while (*str) {
		if (strstr(str, replaceable) == str) {
			strcpy(&*(output+i), substitude);
			i += substitudelen;
			str += replaceablelen;
		} 
		else
			*(output+i++) = *str++; 
	} 
	*(output+i) = '\0'; 
	return output; 
} 

int substr_count(char *haystack, char *needle) {
	int output=0;
	while(haystack = strstr(haystack, needle)) {
		output++;
		haystack+=strlen(needle);
	}
	return output;
}
char *strtolower(char *input) {
	char *output=(char*)malloc(sizeof(input)+1);
	for(int i=0; input[i] != '\0'; i++) {
		if(input[i] >= 65 && input[i] <= 90)
			output[i]=input[i]+32;
		else
			output[i]=input[i];
	}
	return output;
}

char *strtoupper(char *input) {
	char *output=(char*)malloc(sizeof(input)+1);
	for(int i=0; input[i] != '\0'; i++) {
		if(input[i] >= 97 && input[i] <= 122)
			output[i]=input[i]-32;
		else
			output[i]=input[i];
	}
	return output;
}

char *bin2hex(char *input) {
	char *output=(char*)malloc(sizeof(input)*2+1);
	int o=0;
	for(int i=0; input[i] != '\0'; i++) {
		sprintf((char*)(output+o), "%02x", input[i]);
		o+=2;
	}
	return output;
}

char *hex2bin(char *input) {
	char *output=(char*)malloc(sizeof(input)/2+1);
	for(int i=0; i<strlen(input); i+=2) {
		char buf[3];
		sprintf(buf, "%c%c", input[i], input[i+1]);
		sscanf(buf, "%02x", buf);
		if (i == 0) strcpy(output, buf);
		else strcat(output, buf);
	}
	return output;
}
