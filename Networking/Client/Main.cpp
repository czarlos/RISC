#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "client.cpp"

char * host;
void go() {	
	boost::asio::io_service io_service;
	client c(io_service, host);
	c.start();
	io_service.run();
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: client <host>" << std::endl;
		return 1;
	}
	try {
		host = argv[1];

		boost::thread threads[1000];
		
		int i = 0;
		while (true) {			
			std::cin.get();						
			int old = i;
			for (i; i < old + 1 && i< 1000; i++) {
				threads[i] = boost::thread(go);
			}
		}
		for (int j = 0; j < i; j++){
			threads[j].join();
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	//while (true) {  }
	return 0;	
}

