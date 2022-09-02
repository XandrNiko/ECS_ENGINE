#include "ClientUDP.h"
#include "../Utils/Logger.h"

namespace ECS_ENGINE::Network
{
	ClientUDP::ClientUDP()
		: serverIp(), serverPort(), socket()
	{
	}

	void ClientUDP::update()
	{
		socket.update();
	}

	bool ClientUDP::isConnected() const
	{
		return socket.getSocketId();
	}

	void ClientUDP::connect(sf::IpAddress ip, sf::Uint16 port)
	{
		serverIp = ip;
		serverPort = port;

		socket.addConnection(socket.getServerId(), ip, port);

		LOG_INFO("Connecting to the server with ip: [" + ip.toString() + "], port: [" + std::to_string(port) + "]");
	}

	void ClientUDP::disconnect()
	{
		LOG_INFO("Timeout from the server");
	}

	sf::IpAddress ClientUDP::getServerIp() const
	{
		return serverIp;
	}

	sf::Uint16 ClientUDP::getServerPort() const
	{
		return serverPort;
	}
}