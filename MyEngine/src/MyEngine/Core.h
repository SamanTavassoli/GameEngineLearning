#pragma once

#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_BUILD_DLL
		#define MyEngine_API __declspec(dllexport)
	#else
		#define MyEngine_API __declspec(dllimport)
	#endif
#else
	#error MyEngine only supports Windows
#endif