#include "UDPSocket.h"
#include "../Utils/Logger.h"

namespace ECS_ENGINE::Network
{
	UDPSocket::UDPSocket()
		: socket(), socketId(), serverId(), connections()
	{
	}

	void UDPSocket::setSocketId(sf::Uint16 id)
	{
		socketId = id;

		LOG_TRACE("Set socket id to id: [" + std::to_string(id) + "]");
	}

	void UDPSocket::setServerId(sf::Uint16 id)
	{
		serverId = id;

		LOG_TRACE("Set server id to id: [" + std::to_string(id) + "]");
	}

	sf::Uint16 UDPSocket::getSocketId() const
	{
		LOG_TRACE("Return socket id: [" + std::to_string(socketId) + "]");

		return socketId;
	}

	sf::Uint16 UDPSocket::getServerId() const
	{
		LOG_TRACE("Return server id: [" + std::to_string(serverId) + "]");

		return serverId;
	}

	bool UDPSocket::bind(sf::Uint16 port)
	{
		return socket.bind(port) == sf::Socket::Status::Done;
	}

	void UDPSocket::unbind()
	{
	}

	void UDPSocket::update()
	{
	}

	void UDPSocket::send(sf::Packet& packet, sf::Uint16 id)
	{
		if (connections.find(id) == connections.end())
		{
			LOG_INFO("Cannot find UDP connection by id: [" + std::to_string(id) + "]");

			return;
		}

		sf::Packet preparedPacked = getPreparedPacket(packet);
		socket.send(preparedPacked, connections[id].getIp(), connections[id].getPort());

		LOG_INFO("Send pocket by id : [" + std::to_string(id) + "] , ip : [" + connections[id].getIp().toString() + "] , port : [" + std::to_string(connections[id].getPort()) + "] ");
	}

	void UDPSocket::send(sf::Packet& packet, sf::IpAddress& ip, sf::Uint16 port)
	{
		sf::Packet preparedPacked = getPreparedPacket(packet);
		socket.send(preparedPacked, ip, port);

		LOG_INFO("Send pocket by ip : [" + ip.toString() + "] , port : [" + std::to_string(port) + "] ");
	}

	void UDPSocket::addConnection(sf::Uint16 id, sf::IpAddress ip, sf::Uint16 port)
	{
		connections[id] = UDPConnection(id, ip, port);

		LOG_INFO("Add Connection with id : [" + std::to_string(id) + "] , ip : [" + ip.toString() + "] , port : [" + std::to_string(port) + "] ");
	}

	void UDPSocket::removeConnection(sf::Uint16 id)
	{
		connections.erase(id);

		LOG_INFO("Remove Connection with id : [" + std::to_string(id) + "]");
	}

	sf::Packet UDPSocket::getPreparedPacket(sf::Packet& packet)
	{
		sf::Packet preparedPacket;
		preparedPacket << socketId << false << serverId;
		preparedPacket.append(packet.getData(), packet.getDataSize());
		return preparedPacket;
	}
}