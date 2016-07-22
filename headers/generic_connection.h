#pragma once
#include <boost/asio.hpp>

///generic_connection represents the bare minimum requirements to establish a connection to an external server
///generic_connection does not support listening to responses in any way, only sending requests.
///The construction of generic_connection will throw an exception if a URI cannot be resolved
class generic_connection
{
public:
	generic_connection(const char * URI, const char * port);

	///Adds the supplied string to the stream buffer
	///This method DOES NOT send any data to the server
	std::ostream & operator<<(std::string inp);

	///Sends data stored in the buffer to the remote server
	///Note that this is not garunteed to empty the entire buffer, but it should
	void commit_request();
protected:
	std::ostream request;
	boost::asio::streambuf req;
	boost::asio::io_service service;
	boost::asio::ip::tcp::socket sock;
	boost::asio::ip::tcp::resolver res;
	boost::asio::ip::tcp::resolver::query query;
	boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint_iter;
};

