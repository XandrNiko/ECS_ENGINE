#include "UDPConnection.h"
#include "../Utils/Logger.h"

namespace ECS_ENGINE::Network
{
	UDPConnection::UDPConnection()
		: id(), ip(), port()
	{
		LOG_INFO("Create UDP Connection with id: [" + std::to_string(id) + "], ip: [" + ip.toString() + "], port: [" + std::to_string(port) + "]");
	}

	UDPConnection::UDPConnection(sf::Uint16 id, sf::IpAddress ip, sf::Uint16 port)
		: id(id), ip(ip), port(port)
	{
		LOG_INFO("Create UDP Connection with id: [" + std::to_string(id) + "], ip: [" + ip.toString() + "], port: [" + std::to_string(port) + "]");
	}

	sf::Uint16 UDPConnection::getId() const
	{
		return id;
	}

	sf::IpAddress UDPConnection::getIp() const
	{
		return ip;
	}

	sf::Uint16 UDPConnection::getPort() const
	{
		return port;
	}

	void UDPConnection::update()
	{
	}

	void UDPConnection::send(sf::UdpSocket& socket, sf::Packet& packet)
	{
		socket.send(packet, ip, port);

		LOG_INFO("Send packet to remote address: [" + ip.toString() + "], remote port: [" + std::to_string(port) + "]");
	}
}