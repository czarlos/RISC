#include "ClientJoinMessage.h"

BOOST_CLASS_EXPORT_GUID(ClientJoinMessage, "ClientJoinMessage")
REGISTERIMPL(ClientJoinMessage, NetworkMessageType::CLIENT_JOIN)

ClientJoinMessage::ClientJoinMessage() : NetworkMessage(NetworkMessageType::CLIENT_JOIN)
{
}

ClientJoinMessage::~ClientJoinMessage() { 

}

ClientJoinMessage::ClientJoinMessage(std::string ip, int port_num) : NetworkMessage(NetworkMessageType::CLIENT_JOIN)
{
	this->clientIP = ip;
	this->port = port_num;
}

ClientJoinMessage::ClientJoinMessage(boost::asio::streambuf * da, size_t bytes)
{
	// this->parse(da, bytes);
}


void ClientJoinMessage::process_data()
{	
	
}

void ClientJoinMessage::print()
{
	std::cout << "Client Joined the Game." << std::endl;
	std::cout << "\t " << this->clientIP << ":" << this->port << std::endl;
}

void ClientJoinMessage::encode_data()
{

}
