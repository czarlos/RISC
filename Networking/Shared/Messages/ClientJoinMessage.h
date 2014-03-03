#define _SCL_SECURE_NO_WARNINGS
#pragma once
#include "../NetworkMessage.h"
#include "../NetworkMessageFactory.h"
#include <cereal/access.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

class ClientJoinMessage :
	public NetworkMessage
{
	REGISTER(ClientJoinMessage);

private:
	std::string clientIP;
	int port;

	friend class cereal::access;

	template<class Archive>
	void serialize(Archive& ar) {
		ar(cereal::base_class<NetworkMessage>(this), clientIP, port);
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