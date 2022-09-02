#pragma once
#include <SFML/Network.hpp>

namespace ECS_ENGINE::Network
{
	class UDPConnection final
	{
	public:
		UDPConnection();
		UDPConnection(sf::Uint16 id, sf::IpAddress ip, sf::Uint16 port);
	public:
		sf::Uint16 getId() const;
		sf::IpAddress getIp() const;
		sf::Uint16 getPort() const;
	public:
		void update();
		void send(sf::UdpSocket& socket, sf::Packet& packet);
	private:
		sf::Uint16 id;
		sf::IpAddress ip;
		sf::Uint16 port;
	};
}