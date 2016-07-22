#pragma once
#include "generic_connection.h"
class http_connection :
	public generic_connection
{
public:
	http_connection(const char * URI);
	void assign_eof_callback(void(*arg)(std::string));
	///Listens for reply from server, executes callback when done
	///If callback function is null, this throws an exception
	void listen();

private:
	void(*callback)(std::string);
};

