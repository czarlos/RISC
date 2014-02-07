#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <iostream>


#define EOT '\4'

class NetworkMessage
{
private:
	char type;
	char * data;
	char * ip;

	size_t data_size;

	virtual void process_data();

public:
	NetworkMessage(); 
	NetworkMessage(char type, std::string contents);
	~NetworkMessage();

	void parse(boost::asio::streambuf * da, size_t bytes);
	void encode(char ** buffer, size_t * s);

	char getType();
	char * getData();
	char * getIP();

	void setType(char m_type);
	void setData(char ** contents, size_t s);

	void print();
};