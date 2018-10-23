#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "system.h"
#include <iostream>
#include <string>

class systemobd{
public:
	std::list<command> comandos;
public:
	systemobd(){
		instrumento();
	}
	bool find(char *date){
		std::list<command>::iterator it=comandos.begin();
		while((it)!=comandos.end()){
			if((*it).name==date) return 1;
			++it;	
		}
		return 0;
	}

	void parseword(char *_words){
		std::vector<char *> arr=split(_words," ");
		char *_temp;
		for(int i=0;i<arr.size();++i){
			if(find(arr[i])){
				_temp=arr[i];
				break;
			}
		}
		command dato(_temp,0);
		printf("%s\n ",dato.name);
	}

	void instrumento(){
		std::ifstream file("comandos.txt");
		char name[20];
		char type[5];
		char value[10];
		while(!file.eof()){
			file.getline(name,20,'#');
			file.getline(type,5,'#');
			file.getline(value,10,'\n');
			command com(name,type,value);
			comandos.push_back(com);
		}
		file.close();
	}
};
