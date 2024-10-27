#include <stdio.h>
#include <ctype.h>
#include <string.h>

void camelCase(char *str){
	int i;
for (i = 0; str[i] != '\0'; i++){
	if (i == 0 || str[i-1] == ''){
	str[i] = toupper(str[i]);
} else {

str[i] = tolower(str[i]);
}
}

// remove spaces to create camel case format

for (i = 0; str[i] != '\0'; i++){
	if (str[i] == ' '){
	int j = i;
	while (str[j] != '\0'){
	str[j] = str[j + 1];
	j++;
}	
}
}
}


