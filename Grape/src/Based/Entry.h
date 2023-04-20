#pragma once

extern grape::Application* grape::createApplication();

/*
int WINAPI _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	auto app = grape::createApplication();
	app->run();
	delete app;
	return 0;
}
*/

int main()
{
	auto app = grape::createApplication();
	app->run();
	delete app;
	return 0;
}