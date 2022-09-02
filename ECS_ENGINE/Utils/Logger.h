#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <array>

#define STR_(x) #x
#define STR(x) STR_(x)

#define LOG_TRACE(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::TRACE_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_DEBUG(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::DEBUG_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_INFO(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::INFO_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_WARN(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::WARN_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_ERROR(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::ERROR_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_FATAL(message)	ECS_ENGINE::Utils::Logger::getGlobalLogger().log(ECS_ENGINE::Utils::Logger::Level::FATAL_LEVEL, __FILE__ ":" STR(__LINE__), (message))


namespace ECS_ENGINE::Utils
{
	class FileSink final
	{
	public:
		FileSink(const std::string& filename, std::size_t bufferSize = 4096u);
		~FileSink();

		void write(const std::string& data);
	private:
		void flush();

		std::vector<char>	buffer;
		std::ofstream		output;
		std::size_t			offset;
	};
}

namespace ECS_ENGINE::Utils
{
	class Logger final
	{
	public:
		enum class Level
		{
			TRACE_LEVEL = 0,
			DEBUG_LEVEL = 1,
			INFO_LEVEL = 2,
			WARN_LEVEL = 3,
			ERROR_LEVEL = 4,
			FATAL_LEVEL = 5,
		};

		static inline std::array<std::string, static_cast<std::size_t>(Level::FATAL_LEVEL) + 1u> LevelStr =
		{
			"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL",
		};

		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;

		static Logger& getGlobalLogger();
		void log(Level level, const char* source, const std::string& message);
	private:
		Logger(const std::string& filename);

		FileSink sink;
	};
}