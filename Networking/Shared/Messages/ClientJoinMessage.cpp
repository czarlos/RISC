#include "ClientJoinMessage.h"

REGISTERIMPL(ClientJoinMessage, NetworkMessageType::CLIENT_JOIN);

ClientJoinMessage::ClientJoinMessage() : NetworkMessage(NetworkMessageType::CLIENT_JOIN)
{
}

ClientJoinMessage::ClientJoinMessage(std::string ip, int port_num) : NetworkMessage(NetworkMessageType::CLIENT_JOIN)
{
	this->clientIP = ip;
	this->port = port_num;
}

ClientJoinMessage::ClientJoinMessage(boost::asio::streambuf * da, size_t bytes)
{
	this->parse(da, bytes);
}


ClientJoinMessage::~ClientJoinMessage()
{
}

void ClientJoinMessage::process_data()
{	
	char * f = this->getData();

	char * cIP = new char[16];
	int index = 0;
	for (char * g = f; g < f + 16; g++, index++) {
		cIP[index] = f[index];
		// move over the ',' or null character
		if (f[index] == ',' || f[index] == '\0') {
			break;
		}		
	}
	cIP[index] = '\0';
	this->clientIP = std::string(cIP);
	port = atoi(f + index + 1);
}

void ClientJoinMessage::print()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void ClientJoinMessage::encode_data()
{
	// write format out	
	int size = clientIP.size() + 1 + 6;
	char *f = new char[size];
	clientIP.copy(f, clientIP.size());
	f[clientIP.size()] = ',';
	sprintf(f + clientIP.size() + 1, "%i", port);
	this->setData(&f, size);
}
