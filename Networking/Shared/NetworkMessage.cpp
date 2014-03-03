#include "NetworkMessage.h"

CEREAL_REGISTER_TYPE(NetworkMessage);

NetworkMessage::NetworkMessage()
{
	type = '1';
}

NetworkMessage::NetworkMessage(char type, std::string contents)
{
	this->setType(type);
}

NetworkMessage::NetworkMessage(boost::asio::streambuf * da, size_t bytes)
{

}

NetworkMessage::NetworkMessage(char type)
{
	this->setType(type);
}

void NetworkMessage::setType(char m_type)
{
	this->type = m_type;
}


void NetworkMessage::print()
{
	std::cout << "Message Received: " << std::endl;
	std::cout << "\tType:\t\t" << this->type << std::endl;	
}


char NetworkMessage::getType()
{
	return type;
}


