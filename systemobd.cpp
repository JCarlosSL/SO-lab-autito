#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "system.h"
#include <string>

class systemobd{
public:
	std::list<command> comandos;
public:
	systemobd(){
		instrumento();
	}
	bool find(std::list<command>::iterator _it,command date){
		auto it=comandos.begin();
		while(it!=comandos.end()){
			if((*it)==date){
				_it=it;
				return 1;
			}
			++it;	
		}
		return 0;
	}
	void parseword(char *_words){
		std::vector<std::string> arr=split(_words," ");
		
		std::list<command>::iterator it;
		bool v=0;
		for(int i=0;i<arr.size();++i){
			if(find(it,command(arr[i]))){
				v=1;
				break;
			}
		}
		std::cout<<v<<std::endl;
	}

	void instrumento(){
		std::ifstream file("comandos.txt");
		char name[20];
		char type[5];
		char value[10];
		while(!file.eof()){
			file.getline(name,20,'#');
			file.getline(type,5,'#');
			file.getline(value,10,'#');
			command com(name,type,value);
			comandos.push_back(com);
		}
		file.close();
	}
};
