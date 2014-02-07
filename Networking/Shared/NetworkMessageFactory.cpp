#include "NetworkMessageFactory.h"

NetworkMessageFactory::NetworkMessageFactory() {
	
}


NetworkMessageFactory::~NetworkMessageFactory()
{
}

NetworkMessage * NetworkMessageFactory::parseMessage(boost::asio::streambuf * da, size_t bytes)
{
	char type;
	da->sgetn(&type, sizeof(type));
	da->sungetc();

	Creator * c = NetworkMessageFactory::getCreator((NetworkMessageType)type);
	if (c != NULL) {
		return c->create(da, bytes);
	}
	// read the stream
	da->consume(bytes);
	return (NetworkMessage *)NULL;
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
