/*
 * SocketHandler.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: royreg
 */

#include "../../include/SocketHandler.h"

SocketHandler::SocketHandler(ConnectionHandler &connector) {
	connector_ = &connector;

}
void SocketHandler::run() {

	while (true) {
		std::string answer;
		if (!connector_->getLine(answer)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}
		answer = answer.substr(0, answer.length() - 1);
		std::cout << "\n" << answer << "\n" << std::endl;
		if(answer=="bye"){
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}

	}

}

