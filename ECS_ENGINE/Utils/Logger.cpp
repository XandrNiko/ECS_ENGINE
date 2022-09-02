#include "Logger.h"

namespace ECS_ENGINE::Utils
{
	FileSink::FileSink(const std::string& filename, std::size_t bufferSize)
		: buffer(bufferSize), output(filename), offset(0u)
	{
		if (!output.is_open())
			throw std::runtime_error("File was not created");
	}

	FileSink::~FileSink()
	{
		flush();
	}

	void FileSink::write(const std::string& data)
	{
		const std::size_t dataSize = data.size();
		if (dataSize + offset >= buffer.size())
		{
			flush();
		}

		std::copy(begin(data), end(data), begin(buffer) + offset);
		offset += dataSize;
	}

	void FileSink::flush()
	{
		if (offset != 0u)
		{
			output.write(buffer.data(), offset);
			offset = 0u;
		}
	}
}

namespace ECS_ENGINE::Utils
{
	Logger& Logger::getGlobalLogger()
	{
		static Logger logger("log_data.txt");
		return logger;
	}

	void Logger::log(Level level, const char* source, const std::string& message)
	{
		const std::string formatedMessage = "[" + LevelStr[static_cast<std::size_t>(level)] + "] - " + source + " - " + message + "\n";
		std::cout << formatedMessage;
		sink.write(formatedMessage);
	}

	Logger::Logger(const std::string& fileName)
		: sink(fileName)
	{
	}
}