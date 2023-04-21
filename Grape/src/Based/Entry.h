#pragma once

#ifdef GP_PLATFORM_WINDOWS

extern grape::Application* grape::createApplication();

int main(int argc, char** argv)
{
	printf("Grape Engine\n");
	auto app = grape::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif // GP_PLATFORM_WINDOWS