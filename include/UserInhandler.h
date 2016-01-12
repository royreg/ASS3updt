/*
 * UserInhandler.h
 *
 *  Created on: Jan 11, 2016
 *      Author: royreg
 */

#ifndef ECHOCLIENT_USERINHANDLER_H_
#define ECHOCLIENT_USERINHANDLER_H_
#include "connectionHandler.h"
#include <boost/thread.hpp>


class UserInhandler {
	private:
		ConnectionHandler* connector_;

	public:
		UserInhandler(ConnectionHandler &connector);
		void run();
	};

#endif /* ECHOCLIENT_USERINHANDLER_H_ */
