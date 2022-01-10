#pragma once

#ifdef HE_PLATFORM_WINDOWS
	#ifdef HE_BUILD_DLL
		#define HENGINE_API __declspec(dllexport)
	#else
		#define HENGINE_API __declspec(dllimport)
	#endif
#else
	#error HEngine now just support Windows!
#endif

#define BIT(x) (1 << x)