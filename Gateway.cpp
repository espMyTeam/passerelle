#include "Gateway.h"
extern "C" {
#include "string.h"
}

uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ipLocal(192,168,1,100);


//constructeur
Gateway::Gateway(){
	this->ip=ipLocal;
	this->serveur="pluviodic2-dgiesp.rhcloud.com";
	this->urlServer="testClient.php?donnees=";
	
	if (Ethernet.begin(mac) == 0) {
    Ethernet.begin(mac, this->ip);
  }
  this->client.connect(this->serveur, 80);
}
//constructeur
Gateway::Gateway(char * serveur){
	this->ip=ipLocal;
	this->serveur=serveur;
	this->urlServer="testClient.php?donnees=";
	
	if (Ethernet.begin(mac) == 0) {
    Ethernet.begin(mac, this->ip);
  }
  this->client.connect(this->serveur, 80);
}
//constructeur
Gateway::Gateway(IPAddress client, char* server){
	this->ip=client;
	this->serveur=server;
	this->urlServer="testClient.php?donnees=";
	
	if (Ethernet.begin(mac) == 0) {
    Ethernet.begin(mac, this->ip);
  }
  this->client.connect(this->serveur, 80);
}


//<<destructor>>
Gateway::~Gateway(){
	this->client.stop();
}

int Gateway::isConnect(){
	return this->client.connect(this->serveur, 80);
}

void Gateway::envoi(char* msg){
	if(this->client.connected()){
	   this->client.print("GET /");
	   this->client.print(this->urlServer);
	   this->client.print(msg);
	   this->client.println(" HTTP/1.1");
	   this->client.print("Host: ");
	   this->client.println(this->serveur);
	   this->client.println("Connection: close");
	   this->client.println();
	}
}

