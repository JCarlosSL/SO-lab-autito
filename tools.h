#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
#include <string.h>
#include <string>

char * word(char *words,int &i){
	char *p;
	for(int j=i;;++j){
		if(words[j]==' ') break;
		p+=words[j];
		++i;
	}
	return p;
}

std::vector<std::string> split(char *str,std::string sep){
	char *current;
	current=strtok(str,sep.c_str());
	std::vector<std::string> arr;
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}	

#endif
