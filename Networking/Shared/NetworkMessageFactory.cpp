#include "NetworkMessageFactory.h"

NetworkMessageFactory::NetworkMessageFactory() {
	
}


NetworkMessageFactory::~NetworkMessageFactory()
{
}


static NetworkMessage * parseMessage(NetworkMessageType nm) 
{
	Creator * c = NetworkMessageFactory::getCreator(nm);
	if (c != NULL) {
		return c->create();
	}
	return (NetworkMessage *)NULL;
}

static NetworkMessage * parseMessage(NetworkMessageType nm, std::string * data)
{
	NetworkMessage * msg = NetworkMessage::parseMessage(nm);
	msg->ParseFromString(data);
	return msg;
}

void NetworkMessageFactory::registerMessageType(NetworkMessageType n, Creator * creator)
{
	getTable()[n] = creator;
}

Creator * NetworkMessageFactory::getCreator(NetworkMessageType n)
{
	message_map::iterator i;
	i = getTable().find(n);
	if (i != getTable().end()) {		
		return i->second;
	}
	return (Creator *)NULL;
}

NetworkMessageFactory::message_map & NetworkMessageFactory::getTable()
{
	static message_map table;
	return table;
}

Creator::Creator(const NetworkMessageType& type)
{
	NetworkMessageFactory::registerMessageType(type, this);
}
