#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
#include <string.h>

char * word(char *words,int &i){
	char *p;
	for(int j=i;;++j){
		if(words[j]==" ") break;
		p+=words[j];
		++i;
	}
	return p;
}

std::vector<char *> split(char * str,char *sep){
	char *current;
	current=strtok(str,sep);
	std::vector<char *> arr;
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep);
	}
	return arr;
}	

#endif
