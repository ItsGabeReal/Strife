#include "Application.h"
#include "Events/KeyEvent.h"
#include "Log.h"

namespace Strife {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		KeyPressedEvent keyPressed(120, 0);
		ST_TRACE(keyPressed.ToString());
		while (true);
	}

}

