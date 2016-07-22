#include "generic_connection.h"

using namespace boost::asio;
using boost::asio::ip::tcp;


generic_connection::generic_connection(const char * URI, const char * port) : request(&req), 
res(service), 
query(URI, port),
endpoint_iter(res.resolve(query)),
sock(service)
{
	boost::system::error_code err = error::host_not_found;
	for (tcp::resolver::iterator end; endpoint_iter != end; endpoint_iter++) {
		sock.close();
		sock.connect(*endpoint_iter, err);
	}

	if (err) {
		throw boost::system::system_error(err);
	}
}

std::ostream & generic_connection::operator<<(std::string inp)
{
	return request << inp;
}

void generic_connection::commit_request() {
	size_t written = write(sock, req);
	req.commit(written);
}
