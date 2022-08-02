#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Strife
{
	class STRIFE_API Log
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

// Core log macros
#define ST_CORE_TRACE(...)     Strife::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ST_CORE_INFO(...)      Strife::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ST_CORE_WARN(...)      Strife::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ST_CORE_ERROR(...)     Strife::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ST_CORE_CRITICAL(...)  Strife::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ST_TRACE(...)          Strife::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ST_INFO(...)           Strife::Log::GetClientLogger()->info(__VA_ARGS__)
#define ST_WARN(...)           Strife::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ST_ERROR(...)          Strife::Log::GetClientLogger()->error(__VA_ARGS__)
#define ST_CRITICAL(...)       Strife::Log::GetClientLogger()->critical(__VA_ARGS__)