#include <Strife.h>
#include <iostream>

class Sandbox : public Strife::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox() {}
};

Strife::Application* Strife::CreateApplication() 
{
	return new Sandbox();
}