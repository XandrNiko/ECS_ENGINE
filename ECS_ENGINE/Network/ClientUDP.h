#pragma once
#include "UDPSocket.h"

namespace ECS_ENGINE::Network
{
	class ClientUDP
	{
	public:
		ClientUDP();
	public:
		void update();
	public:
		bool isConnected() const;
	public:
		void connect(sf::IpAddress ip, sf::Uint16 port);
		void disconnect();
		sf::IpAddress getServerIp() const;
		sf::Uint16 getServerPort() const;
	private:
		sf::IpAddress serverIp;
		sf::Uint16 serverPort;
		UDPSocket socket;
	};
}