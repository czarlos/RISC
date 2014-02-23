#pragma once
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/interprocess/streams/bufferstream.hpp>
#include "NetworkMessage.h"
#include "Messages/NetworkMessageType.h"

class Creator {
public:
	
	Creator(const NetworkMessageType& type);

	virtual NetworkMessage * create(boost::asio::streambuf & da, size_t bytes) = 0;
	// virtual NetworkMessage * create(char type, std::string contents) = 0;
};

template <typename T>
class FactoryCreator : public Creator {
public:
	FactoryCreator(const NetworkMessageType& type) : Creator(type) {}

	NetworkMessage * create(boost::asio::streambuf & da, size_t bytes) {				
		T val;
		std::istream reader(&da);
		try {			
			boost::archive::text_iarchive msg(reader);
			msg & val;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		return &val;
	}
};



class NetworkMessageFactory
{
private:	
	typedef std::map<NetworkMessageType, Creator *> message_map;
	static message_map & getTable();	
	// typedef std::pair<NetworkMessageType, Creator> map_entry;

	static Creator * getCreator(NetworkMessageType n);

public:
	NetworkMessageFactory();
	~NetworkMessageFactory();

	static void registerMessageType(NetworkMessageType n, Creator * creator);

	static NetworkMessage * parseMessage(boost::asio::streambuf & da, size_t bytes);
	// static NetworkMessage * parseMessage(char type, std::string contents);

	
};