#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
#include <string.h>
#include <string>

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

std::vector<std::string> split1(std::string word){
	std::ofstream outfile("temp.txt");
	outfile<<word;
	outfile.close();

	std::ifstream file("temp.txt");
	char name[20];
	char value[10];
	char problem[500];
	std::vector<std::string> arr;
	if(!file.eof()){
		file.getline(name,20,'#');
		file.getline(value,10,'#');
		file.getline(problem,500,'#');
		arr.push_back(name);
		arr.push_back(value);
		arr.push_back(problem);
	}
	file.close();
	return arr;
}

#endif
