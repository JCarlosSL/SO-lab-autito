#ifndef SYSTEMDIAGN_H
#define SYSTEMDIAGN_H
#include "tools.h"
#include <string>

class command{
public:
	std::string name;
	std::string type;
	std::string payload;
public:
	command(){};
	command(std::string _name,std::string _type,std::string _payload){
		name=_name;
		type=_type;
		payload=_payload;
	}
	command(std::string _name,std::string _payload){
		name=_name;
		payload=_payload;
		type="";
	}

	command(std::string _name){
		name=_name;
		payload="";
		type="";
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
