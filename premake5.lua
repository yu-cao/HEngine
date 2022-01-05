workspace "HEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HEngine"
	location "HEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HE_PLATFORM_WINDOWS",
			"HE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HEngine/vendor/spdlog/include",
		"HEngine/src"
	}

	links
	{
		"HEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
		optimize "On"