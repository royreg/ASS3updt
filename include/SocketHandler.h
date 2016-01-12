/*
 * SocketHandler.h
 *
 *  Created on: Jan 11, 2016
 *      Author: royreg
 */

#ifndef SOCKETHANDLER_H_
#define SOCKETHANDLER_H_
#include "connectionHandler.h"
#include <boost/thread.hpp>


class SocketHandler {
private:
	ConnectionHandler *connector_;

public:
	SocketHandler(ConnectionHandler &connection);
	void run();
};

#endif /* SOCKETHANDLER_H_ */
