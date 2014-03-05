#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

#include "NetworkMessage.h"

BOOST_CLASS_EXPORT_GUID(NetworkMessage, "NetworkMessage");

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


