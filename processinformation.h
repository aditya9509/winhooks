#include <string>
#ifndef PROCESSINFORMATION_H  // Include guard to prevent multiple inclusion
#define PROCESSINFORMATION_H

class ProcessInformation{
	std::string pnme;
	std::string elementType;
	
	public :

	std::string getPnme(){
		return pnme;
	}
	
	std::string getElementType(){
		return elementType;
	}
	
	
	void setPnme(std::string p){
		pnme = p;
	}
	
	void setElementType(std::string e){
		elementType = e;
	}
};

ProcessInformation getProcessInformation( POINT p);

#endif 