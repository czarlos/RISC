#pragma once

#include "NetworkMessage.h"
#include "Messages/NetworkMessageType.h"

class Creator {
public:	
	Creator(const NetworkMessageType& type);

	/**
	 * Creates a GPB
	 * 
	 * @return       [description]
	 */
	virtual void * create() = 0;
};

template <typename T>
class FactoryCreator : public Creator {
public:
	FactoryCreator(const NetworkMessageType& type) : Creator(type) {}

	void * create() 
	{
		return new T();
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

	static NetworkMessage * parseMessage(NetworkMessageType nm);
	static NetworkMessage * parseMessage(NetworkMessageType nm, std::string * data);	
};