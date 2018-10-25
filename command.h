#ifndef SYSTEMDIAGN_H
#define SYSTEMDIAGN_H
#include "tools.h"
#include <string>

class command{
public:
	std::string name;
	std::string type;
	std::string payload;
	int pos;
public:
	command(){};
	command(std::string _name,std::string _type,std::string _payload,int _pos){
		name=_name;
		type=_type;
		payload=_payload;
		pos=_pos;
	}
	command(std::string _name,std::string _payload){
		name=_name;
		payload=_payload;
		type="";
		pos=0;
	}

	command(std::string _name){
		name=_name;
		payload="";
		type="";
		pos=0;
	}

	bool operator==(const command &c){
		return name.compare(c.name)==0;
	}

	friend std::ostream& operator<<(std::ostream &out,const command &a){
		out<<a.name<<" "<<a.type<<" "<<a.payload;
		return out;
	}
};


#endif
