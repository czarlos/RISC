#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <deque>
#include "TCPConnection.h"
#include <boost/enable_shared_from_this.hpp>
#include "..\Server\NetworkMessage.h"

using boost::asio::ip::tcp;


class client {
private:	
	tcp::resolver resolver_;
	boost::thread queue_handler;
	
	TCPConnection::pointer conn;

	void handle_resolve(const boost::system::error_code& err,
		tcp::resolver::iterator endpoint_iterator) {
		if (!err) {
			tcp::endpoint endpoint = *endpoint_iterator;

			conn->getSocket()->async_connect(endpoint,
				boost::bind(&client::handle_connect, this, boost::asio::placeholders::error, ++endpoint_iterator));
		}
		else {
			std::cout << "Error: " << err.message() << "\n";
		}
	}

	void handle_connect(const boost::system::error_code &err, tcp::resolver::iterator endpoint_itr) {
		if (!err) {
			conn->start();
		}
		else if (endpoint_itr != tcp::resolver::iterator()) {
			// the connection failed - try the next one
			tcp::endpoint endpoint = *endpoint_itr;
			conn->getSocket()->async_connect(endpoint,
				boost::bind(&client::handle_connect, this, boost::asio::placeholders::error, ++endpoint_itr));
		}
		else {
			std::cout << "Error: " << err.message() << "\n";
		}
	}

	void process_queue() {
		while (true) {			
			//std::cout << "Reading Queue" << std::endl;						
			while (!conn->getMessages()->empty()) {
				NetworkMessage msg = conn->getMessages()->front();
				std::cout << "Client " << this << " Received Message: " << std::endl;
				msg.print();
				conn->getMessages()->pop_front();
			}
			boost::this_thread::sleep(boost::posix_time::milliseconds(100));
		}
	}

public:
	client(boost::asio::io_service& io_service, const std::string& server) : resolver_(io_service) {
		conn = TCPConnection::create(io_service);

		tcp::resolver::query query(server, "daytime");
		resolver_.async_resolve(query,
			boost::bind(&client::handle_resolve, this, 
			boost::asio::placeholders::error,
			boost::asio::placeholders::iterator));

	}

	void start() {
		queue_handler = boost::thread(&client::process_queue, this);
	}

	void send(NetworkMessage * msg) {
		conn->send(msg);
	}

};


