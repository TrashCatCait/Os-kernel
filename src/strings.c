#include "includes/strings.h"

//compare non null terminated strings
int strn_cmp(char *str1, char *str2, int len) {
    int i = 0;
    while(i < len){
	if (*str1 != *str2){ //if at any point they are not the same return null
	    return 0;
	}
	str1++;
	str2++;
	i++;	
    }
    return 1;
}
