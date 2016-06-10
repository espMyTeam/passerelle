#include "Arduino.h"
#include <SPI.h>
#include <Ethernet.h>


#ifndef Gateway_H
#define Gateway_H

class Pluvio {
private: 
	char * urlServer;
	IPAddress ip;
	char * serveur;
	EthernetClient client;
public:
	
	Gateway();
	Gateway(char* serveur);
	Gateway(IPAddress client, char* server);
	~Gateway();
	int isConnect();
	void envoi(char * msg);
	char * getMessage();
	
};

#endif
