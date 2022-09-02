#pragma once
#include "UDPSocket.h"

#include <vector>

namespace ECS_ENGINE::Network
{
	class ServerUDP
	{
	public:
		ServerUDP();
	public:
		void start(sf::Uint16 port);
		void stop();
		void update();
	public:
		bool isWorking() const;
	private:
		bool processMessages();
	private:
		bool workingFlag;

		UDPSocket socket;
		std::vector<sf::Uint16> clientsIds;
	};
}