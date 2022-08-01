#pragma once


#ifdef ST_PLATFORM_WINDOWS

extern Strife::Application* Strife::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Strife::CreateApplication();
	app->Run();
	delete app;
}

#endif // ST_PLATFORM_WINDOWS