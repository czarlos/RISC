#define _SCL_SECURE_NO_WARNINGS
#pragma once
#include "../NetworkMessage.h"
#include <boost/serialization/base_object.hpp>
#include "../NetworkMessageFactory.h"


class ClientJoinMessage :
	public NetworkMessage
{
	REGISTER(ClientJoinMessage);

private:
	std::string clientIP;
	int port;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<NetworkMessage>(*this);		
		ar & clientIP;
		ar & port;		
	}
public:

	ClientJoinMessage(boost::asio::streambuf * da, size_t bytes);
	ClientJoinMessage(std::string contents) : NetworkMessage(NetworkMessageType::CLIENT_JOIN, contents) {}
	ClientJoinMessage(std::string ip, int port_num);
	ClientJoinMessage();
	~ClientJoinMessage();

	virtual void process_data();

	virtual void print();

	virtual void encode_data();

};