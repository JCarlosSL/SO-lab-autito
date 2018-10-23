#ifndef SYSTEMOBD_H
#define SYSTEMOBD_H
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>

class systemobd{
public:
	std::list<command> comandos;
public:
	systemobd(){
		instrumento();
	}
	bool find(char *date){
		std::list<char *>::iterator *it=comandos.begin();
		while((it)!=comandos.end()){
			if((*it)==date) return 1;
			++it;	
		}
		return 0;
	}

	void parseword(char *_words){
		std::vector<char *> arr=split(_words," ");
		char *_temp;
		for(int i=1;i<arr.size();++i){
			if(find(arr[i])){
				_temp=arr[i];
				break;
			}
		}
		command dato(_temp,arr[0]);t
	}

	void instrumento(){
		ifstream file("comandos.txt");
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

#endif
