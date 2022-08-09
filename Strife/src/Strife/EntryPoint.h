#pragma once

#ifdef ST_PLATFORM_WINDOWS

// The client defines this function to return a new instance of their custom implementation of Strife::Application
extern Strife::Application* Strife::CreateApplication();

int main(int argc, char** argv)
{
	Strife::Log::Init();

	auto app = Strife::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // ST_PLATFORM_WINDOWS