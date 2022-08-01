#include <Strife.h>

class Sandbox : public Strife::Application
{
public:
	Sandbox() {};
	~Sandbox() {};
};

Strife::Application* Strife::CreateApplication()
{
	return new Sandbox();
}