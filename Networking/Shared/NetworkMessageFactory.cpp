#include "NetworkMessageFactory.h"

NetworkMessageFactory::NetworkMessageFactory() {
	
}


NetworkMessageFactory::~NetworkMessageFactory()
{
}

NetworkMessage * NetworkMessageFactory::parseMessage(boost::asio::streambuf & da, size_t bytes)
{		
	std::istream is (&da);
	NetworkMessage * m = nullptr;	
	try {
		boost::archive::text_iarchive ia(is);		
		ia & m;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::istream isa(&da);

	NetworkMessage * mm;
	{
		boost::archive::text_iarchive ia(isa);
		ia & mm;
	}

	Creator * c = NetworkMessageFactory::getCreator((NetworkMessageType)m->getType());
	if (c != NULL) {
		return c->create(da, bytes);
	}
	// read the stream		
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

NetworkMessage * NetworkMessageFactory::createMessage(char type)
{
	Creator * c = NetworkMessageFactory::getCreator((NetworkMessageType)type);
	return c->create();
}

Creator::Creator(const NetworkMessageType& type)
{
	NetworkMessageFactory::registerMessageType(type, this);
}
