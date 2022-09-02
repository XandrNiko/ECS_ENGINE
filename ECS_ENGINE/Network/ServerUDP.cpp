#include "ServerUDP.h"
#include "../Utils/Logger.h"

namespace ECS_ENGINE::Network
{
	ServerUDP::ServerUDP()
		: workingFlag(false), socket(), clientsIds()
	{
	}

	void ServerUDP::start(sf::Uint16 port)
	{
		workingFlag = socket.bind(port);

		if (!workingFlag)
		{
			LOG_ERROR("Failed to start the server by port: [" + std::to_string(port) + "]");
			throw std::runtime_error("Failed to start the server");
		}

		LOG_INFO("The server was successfully started by port: [" + std::to_string(port) + "]");
	}

	void ServerUDP::stop()
	{
		for (sf::Uint16 clientid : clientsIds)
		{
			// TODO: Send Disconnect message to all clients
		}
		clientsIds.clear();

		socket.unbind();
		workingFlag = false;

		LOG_INFO("The server was killed");
	}

	void ServerUDP::update()
	{
		if (!workingFlag)
			return;

		while (processMessages())
		{
		}

		socket.update();
	}

	bool ServerUDP::isWorking() const
	{
		return workingFlag;
	}

	// Return true if message was received.
	bool ServerUDP::processMessages()
	{
		return true;
	}
}