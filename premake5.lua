workspace "Strife"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Strife/vendor/GLFW/include"
IncludeDir["Glad"] = "Strife/vendor/Glad/include"
IncludeDir["ImGui"] = "Strife/vendor/ImGui"


group "Dependencies"
	include "Strife/vendor/GLFW"
	include "Strife/vendor/Glad"
	include "Strife/vendor/ImGui"

group ""

project "Strife"
	location "Strife"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "stpch.h"
	pchsource "Strife/src/stpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"ST_PLATFORM_WINDOWS",
			"ST_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ST_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
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
		"Strife/vendor/spdlog/include",
		"Strife/src"
	}

	links
	{
		"Strife"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"ST_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ST_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		optimize "On"