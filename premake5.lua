workspace "Grape"
	startproject "Sandbox"
	configurations { "Debug", "Release", "Dist" }
	platforms { "Win32", "Win64" }
	
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x86"
	filter { "platforms:Win64" }
		system "Windows"
		architecture "x86_64"

outputDir = "%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}/"

project "Grape"
	location "Grape"
	kind "SharedLib"
	language "C++" 
	staticruntime "off"
	targetdir (outputDir .. "%{prj.name}/bin")
	objdir (outputDir .. "%{prj.name}/temp")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/External/spdlog/include"
	}

	filter "system:Windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"GP_PLATFORM_WINDOWS",
			"_WINDLL",
			"GP_BUILD_DLL",
			"GP_DYNAMIC_LNK"
		}

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} \"../" .. outputDir .. "Sandbox/bin/\"") }

	filter "configurations:Debug"
		defines { "GP_DEBUG", "GP_ENABLE_ASSERTS" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GP_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"
	targetdir (outputDir .. "%{prj.name}/" .. "bin")
	objdir (outputDir .. "%{prj.name}/" .. "temp")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Grape/src",
		"Grape/External/spdlog/include"
	}

	links
	{
		"Grape"
	}

	filter "system:Windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{ 
			"GP_PLATFORM_WINDOWS",
			"GP_DYNAMIC_LNK",
			"_WIN32"
		}

	filter "configurations:Debug"
		defines "GP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GP_DIST"
		runtime "Release"
		optimize "on"