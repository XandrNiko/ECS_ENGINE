#pragma once
#include <SFML/Network.hpp>
#include "../Network/UDPConnection.h"

#include <map>

namespace ECS_ENGINE::Network
{
	class UDPSocket final
	{
	public:
		UDPSocket();
	public:
		void setSocketId(sf::Uint16 id);
		void setServerId(sf::Uint16 id);

		sf::Uint16 getSocketId() const;
		sf::Uint16 getServerId() const;
	public:
		bool bind(sf::Uint16 port);
		void unbind();
		void update();
		void send(sf::Packet& packet, sf::Uint16 id);
		void send(sf::Packet& packet, sf::IpAddress& ip, sf::Uint16 port);

		void addConnection(sf::Uint16 id, sf::IpAddress ip, sf::Uint16 port);
		void removeConnection(sf::Uint16 id);
	private:
		sf::Packet getPreparedPacket(sf::Packet& packet);
	private:
		sf::UdpSocket socket;
		sf::Uint16 socketId;
		sf::Uint16 serverId;
		std::map<sf::Uint16, UDPConnection> connections;
	};
}