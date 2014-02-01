#include <iostream>
#include <boost\array.hpp>
#include <boost\asio.hpp>
#include <boost\thread.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {	
		try {
			if (argc != 2) {
				std::cerr << "Usage: client <host>" << std::endl;
				return 1;
			}			

			boost::asio::io_service io_service;
			tcp::resolver resolver(io_service);
			tcp::resolver::query query(argv[1], "daytime");
			tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
			tcp::resolver::iterator end;
			while (true) {
				tcp::socket socket(io_service);
				boost::system::error_code error = boost::asio::error::host_not_found;
				while (error && endpoint_iterator != end) {
					socket.close();
					socket.connect(*endpoint_iterator++, error);
				}

				if (error) {
					throw boost::system::system_error(error);
				}
				while (true) {
					boost::array<char, 128> obuf;
					for (;;) {
						boost::array<char, 128> buf;
						boost::system::error_code error;
						size_t len = socket.read_some(boost::asio::buffer(buf), error);

						if (error == boost::asio::error::eof) {
							break;
						}
						else if (error) {
							throw boost::system::system_error(error);
						}
						obuf = buf;
						std::cout.write(buf.data(), len);
					}
					socket.write_some(boost::asio::buffer(obuf));
					//std::cin.get();
				}
			}
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cin.get();
	}
