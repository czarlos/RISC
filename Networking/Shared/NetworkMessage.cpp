#include "NetworkMessage.h"


NetworkMessage::NetworkMessage()
{
	type = '1';
}

NetworkMessage::NetworkMessage(char type, std::string contents) : NetworkMessage(type)
{
	char * h = new char[contents.size() + 1];
	memcpy(h, contents.c_str(), contents.size());
	h[contents.size()] = '\0';
	this->setData(&h, contents.size() + 1);
}

NetworkMessage::NetworkMessage(boost::asio::streambuf * da, size_t bytes)
{
	this->parse(da, bytes);
}

NetworkMessage::NetworkMessage(char type)
{
	this->setType(type);
}


NetworkMessage::~NetworkMessage()
{
}

void NetworkMessage::parse(boost::asio::streambuf * da, size_t bytes)
{
	try {
		// Type Byte + EOT are ignored
		this->data_size = bytes - sizeof(type) - sizeof(EOT);

		// Extract Type
		da->sgetn(&type, sizeof(type));

		// Extract Data
		this->data = new char[this->data_size + 1];
		da->sgetn(data, this->data_size);
		data[this->data_size] = '\0';

		// Check for EOT
		char * eot = new char[1];
		da->sgetn(eot, sizeof(EOT));
		if (*eot != '\4') {
			throw std::exception("EOT was not encountered in frame.");
		}
		this->process_data();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}

void NetworkMessage::setType(char m_type)
{
	this->type = m_type;
}

void NetworkMessage::setData(char ** contents, size_t s)
{
	this->data_size = s + 1;
	this->data = new char[this->data_size];		
	memcpy(this->data, *contents, this->data_size);	

	// end the string with null character to make it easier to see
	this->data[this->data_size - 1] = '\0';
}

void NetworkMessage::encode(char ** buffer, size_t * s)
{
	this->encode_data();

	*s = sizeof(type) + data_size + sizeof(EOT);
	// type, data, EOT

	*buffer = new char[*s];
	**buffer = type;
	memcpy((*buffer + 1), data, data_size);
	(*buffer)[*s - 1] = EOT;	
}

void NetworkMessage::print()
{
	std::cout << "Message Received: " << std::endl;
	std::cout << "\tType:\t\t" << this->type << std::endl;
	std::cout << "\tMessage:\t" << this->data << std::endl;
}

char NetworkMessage::getType()
{
	return type;
}

char * NetworkMessage::getData()
{
	return data;
}
