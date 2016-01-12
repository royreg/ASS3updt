#include <stdlib.h>
#include <boost/locale.hpp>
#include "../../include/connectionHandler.h"
#include "../../include/utf8.h"
#include "../../include/encoder.h"
#include "../../include/SocketHandler.h"
#include "../../include/UserInhandler.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }
	
    UserInhandler usr(connectionHandler);
    SocketHandler sh(connectionHandler);
    boost::thread th1(&UserInhandler::run, &usr);
    boost::thread th2(&SocketHandler::run, &sh);
    th1.join();
    th2.join();

    return 1;
}

