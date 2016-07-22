#include "http_connection.h"
#include <array>


http_connection::http_connection(const char * URI) : generic_connection(URI, "80"){}

void http_connection::assign_eof_callback(void(*arg)(std::string))
{
	callback = arg;
}

void http_connection::listen() {
	using namespace boost::asio;
	using namespace boost::system;

	if (callback == nullptr) throw std::exception("Callback function is null");

	std::string tosend;

	while (true) {
		std::array<char, 65536> buff;
		error_code err;
		sock.read_some(buffer(buff), err);
		if (err == error::eof) {
			break;
		}
		else if (err) {
			throw system_error(err);
		}

		tosend += buff.data();
	}

	callback(tosend);
}

