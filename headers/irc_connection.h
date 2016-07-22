#pragma once
#include "generic_connection.h"
class irc_connection :
	public generic_connection
{
public:
	irc_connection(const char * URI);
	
};

