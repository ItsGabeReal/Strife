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