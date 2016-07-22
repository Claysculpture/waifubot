#include <iostream>
#include "http_connection.h"

const char * LINEFEED = "\r\n";

int main(int argc, char ** argv) {
	http_connection example("myanimelist.net");
	example.assign_eof_callback([](std::string arg) {
		std::cout << arg << std::endl;
	});
	example << "GET /api/anime/search.xml?q=full+metal HTTP/1.1" << LINEFEED;
	example << "Host: myanimelist.net" << LINEFEED;
	example << LINEFEED;
	example.commit_request();
	example.listen();

	std::cin.get();
}