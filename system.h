#ifndef SYSTEMDIAGN_H
#define SYSTEMDIAGN_H
#include "tools.h"

class command{
public:
	char name[20];
	char type[5];
	char payload[3];
public:
	command(){};
	command(char *_name,char *_type,char *_payload){
		name=_name;
		type=_type;
		payload=_payload;
	}
	command(char *_name,char *_payload){
		name=_name;
		type="";
		payload=_payload;
	}

	bool operator==(const command &c){
		return name==c.name;
	}
};


#endif
