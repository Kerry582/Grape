#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

BEGIN_GP_NAMESPACE

class GP_DLL Log
{
public:
	static void init();
	inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
	inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_coreLogger;
	static std::shared_ptr<spdlog::logger> s_clientLogger;
};

END_GP_NAMESPACE

// Core log macros
#define GP_CORE_INFO(...)		::grape::Log::getCoreLogger()->info(__VA_ARGS__)
#define GP_CORE_TRACE(...)		::grape::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GP_CORE_ERROR(...)		::grape::Log::getCoreLogger()->error(__VA_ARGS__)
#define GP_CORE_WARN(...)		::grape::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GP_CORE_CRITICAL(...)	::grape::Log::getCoreLogger()->critical(__VA_ARGS__)
// Client log macros
#define GP_INFO(...)			::grape::Log::getClientLogger()->info(__VA_ARGS__)
#define GP_TRACE(...)			::grape::Log::getClientLogger()->trace(__VA_ARGS__)
#define GP_ERROR(...)			::grape::Log::getClientLogger()->error(__VA_ARGS__)
#define GP_WARN(...)			::grape::Log::getClientLogger()->warn(__VA_ARGS__)
#define GP_CRITICAL(...)		::grape::Log::getClientLogger()->critical(__VA_ARGS__)

