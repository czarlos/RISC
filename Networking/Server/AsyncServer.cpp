#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "TCPServer.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT_GUID(NetworkMessage, "NetworkMessage");
BOOST_CLASS_EXPORT_GUID(ClientJoinMessage, "ClientJoinMessage");

using boost::asio::ip::tcp;

int main() {
	try {
		boost::asio::io_service io_service;

		TCPServer server(io_service, 13);

		io_service.run();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	while (true) {}
	return 0;
}