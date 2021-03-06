#ifndef MSTRING_H
#define MSTRING_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* Definitions */
char* reverse(char*);
int strfchr(char*,char);
char* lower(char*);
char* upper(char*);
void strdel(char*,char);
void stridel(char*,int);
int strfind(char* src,char* value);

/* Implementations */
int strfind(char* src,char* value){ // Find a char* in a char*
    int length = strlen(value);
    int i = 0;
    char tmp[length];
    int o = -1;
    while(src[i]){
        if(src[i] == value[0]){

            memcpy(tmp,&src[i],length);
            if(strcmp(value,tmp) == 0){
                o = i;
                break;
            }
        }
        i++;
    }
    return o;
}
void strdel(char* str,char c){ /* String delete character */
	int index = strfchr(str,c);
	while(index != 0){
		strcpy(&str[index],&str[index+1]);
		index = strfchr(str,c);
	}	
}
void stridel(char* str,int index){ /* Delete a index in string */
		if(index >= strlen(str)){
				printf("Index out of range");
				exit(1);
		}else{
				strcpy(&str[index],&str[index+1]);
		}
}
int strfchr(char* str,char c){ /* String find character */
	int i = 0;
	int o = 0;
	while(str[i]){
		if(str[i] == c){
			o = i;
			break;
		}
		i++;
	}
	return o;
}


char* reverse(char* str){/* reverse a string */	
	char* tstr = (char*)malloc(strlen(str));
	int offs = 0;
	for(int i = strlen(str)-1;i >= 0;i--){
		tstr[ offs] = str[i];
		offs++;	
	}	
	return (char*)tstr;
}

char* lower(char* str){ /* lowercase a string */
	int len = strlen(str);
	char* tstr = (char*)malloc(len);
	int i = 0;
	while(str[i]){
		tstr[i] = tolower(str[i]);
		i++;
	}
	return (char*)tstr;
}
char* upper(char* str){ /* upeercase a string */
	int len = strlen(str);
	char* tstr = (char*)malloc(len);
	int i = 0;
	while(str[i]){
		tstr[i] = toupper(str[i]);
		i++;
	}
	return (char*)tstr;
}

#endif
