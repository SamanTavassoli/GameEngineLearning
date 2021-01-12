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

#ifdef ME_ENABLE_ASSERTS
	#define ME_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
	#define ME_CORE_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed : {0}", __VA_ARGS__} __debugbreak(); } }
#else
	#define ME_ASSERT(x, ...)
	#define ME_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)