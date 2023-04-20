#pragma once

#include "Core.h"

BEGIN_GP_NAMESPACE

class GP_DLL Application
{
public:
	Application();
	~Application();

	void run();
};

// To be defined in CLIENT.
Application* createApplication();

END_GP_NAMESPACE