#pragma once

#include "Core.h"

namespace Strife {
	class STRIFE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

