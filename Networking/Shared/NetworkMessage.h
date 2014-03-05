#pragma once

#define REGISTER(classname) \
	private: \
	static const FactoryCreator<classname> creator;

#define REGISTERIMPL(classname, type) \
	const FactoryCreator<classname> classname::creator(type);

#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <iostream>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

#define EOT '\4'

class NetworkMessage
{
private:
	char type;	

	virtual void process_data() {}
	virtual void encode_data() {}

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & type;		
	}

public:
	NetworkMessage(); 
	NetworkMessage(boost::asio::streambuf * da, size_t bytes);
	NetworkMessage(char type);
	NetworkMessage(char type, std::string contents);
	virtual ~NetworkMessage() {}

	char getType();	
	char * getIP();

	void setType(char m_type);
	void setData(char ** contents, size_t s);

	virtual void print();
};

