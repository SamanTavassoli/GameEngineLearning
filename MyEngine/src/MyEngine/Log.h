#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace MyEngine {

	class MyEngine_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Making Logging easier with macros

// Core log macros
#define HZ_CORE_TRACE(...)    ::MyEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::MyEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::MyEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::MyEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)    ::MyEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)         ::MyEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)          ::MyEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)          ::MyEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)         ::MyEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)         ::MyEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
