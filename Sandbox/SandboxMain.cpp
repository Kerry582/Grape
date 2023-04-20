#include "Grape.h"

class Sandbox : public grape::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

grape::Application* grape::createApplication()
{
	return new Sandbox();
}