/*
 * UserInhandler.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: royreg
 */

#include "../../include/UserInhandler.h"

UserInhandler::UserInhandler(ConnectionHandler &connector) {
	connector_ = &connector;

}

void UserInhandler::run() {
	bool keepGoin =true;
	while (keepGoin) {
		const short bufsize = 1024;
		char buf[bufsize];
		std::cin.getline(buf, bufsize);
		std::string line(buf);
		int len = line.length();
		if (!connector_->sendLine(line)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}

	}
}

