#pragma once

#include "Log.h"

#ifdef GP_PLATFORM_WINDOWS

extern grape::Application* grape::createApplication();

int main(int argc, char** argv)
{
	grape::Log::init();
	GP_CORE_INFO("Welcome to Grape");
	auto app = grape::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif // GP_PLATFORM_WINDOWS