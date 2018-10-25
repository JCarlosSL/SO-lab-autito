#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "command.h"
#include <string>

class systemobd{
public:
	std::vector<command> comandos;
public:
	systemobd(){
		instrumento();
	}
	bool find(std::vector<command>::iterator &_it,command date){
		auto it=comandos.begin();
		while((it)!=comandos.end()){
			if((*it)==date){
				_it=it;
				return 1;
			}
			++it;	
		}
		return 0;
	}

	void menu_solution(int it,std::string &solution){
		std::string sol="problem solvd in ";
		switch(it){
			case 0:	solution=sol+comandos[0].name;
				break;
			case 1:	solution=sol+comandos[1].name;
				break;
			case 2:	solution=sol+comandos[2].name;
				break;
			case 3:	solution=sol+comandos[3].name;
				break;
			case 4:	solution=sol+comandos[4].name;
				break;
			case 5:	solution=sol+comandos[5].name;
				break;
			case 6:	solution=sol+comandos[6].name;
				break;
			case 7:	solution=sol+comandos[7].name;
				break;
			case 8:	solution=sol+comandos[8].name;
				break;
			case 9:	solution=sol+comandos[9].name;
				break;
		}
		
	}

	void menu_change(std::string &solution,char *_words){
		std::vector<std::string> arr=split1(_words);
		std::vector<command>::iterator it;
		bool v=0;
		if(find(it,command(arr[0]))){
			v=1;
		}
		if(v){
			(*it).payload=arr[1];
			if(arr[2]!="0"){
				menu_solution((*it).pos,solution);
			}
			else{
				solution="perfect";
			}
		}
		else{
			solution="the command was not found";
		}
		
	}

	void instrumento(){
		std::ifstream file("comandos.txt");
		char name[20];
		char type[5];
		char value[10];
		int pos=0;
		while(!file.eof()){
			file.getline(name,20,'#');
			file.getline(type,5,'#');
			file.getline(value,10,'#');
			command com(name,type,value,pos);
			pos++;
			comandos.push_back(com);
		}
		file.close();
	}
};
