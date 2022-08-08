#pragma once

#ifdef ST_PLATFORM_WINDOWS
	#ifdef ST_BUILD_DLL
		#define STRIFE_API __declspec(dllexport)
	#else
		#define STRIFE_API __declspec(dllimport)
	#endif // ST_BUILD_DLL
#else
	#error Strife only supports Windows :(
#endif // ST_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#ifdef ST_ENABLE_ASSERTS
	#define ST_CORE_ASSERT(x, ...) { if(!(x)) { ST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ST_ASSERT(x, ...) { if(!(x)) { ST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ST_CORE_ASSERT(x, ...)
	#define ST_ASSERT(x, ...)
#endif // ST_ENABLE_ASSERTS