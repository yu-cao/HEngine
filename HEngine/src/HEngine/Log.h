#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace HEngine
{
	class HENGINE_API Log
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

// Core Log MACRO
#define HE_CORE_FATAL(...)	::HEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HE_CORE_ERROR(...)	::HEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_WARN(...)	::HEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_INFO(...)	::HEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_TRACE(...)	::HEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log MACRO
#define HE_FATAL(...)	::HEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
#define HE_ERROR(...)	::HEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HE_WARN(...)	::HEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HE_INFO(...)	::HEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HE_TRACE(...)	::HEngine::Log::GetClientLogger()->trace(__VA_ARGS__)