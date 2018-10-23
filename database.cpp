#include <fstream>

void guardar(const char* filename){
	ifstream file(filename);
	char keyName[80];
	char information[5000];
	long address = 0;
	while(!file.eof()){
		file.getline(keyName,80,'#');
		file.getline(information,5000,'@');
	}
	file.close();
}


