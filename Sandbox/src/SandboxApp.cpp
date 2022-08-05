#include <Strife.h>
#include <iostream>

class Sandbox : public Strife::Application
{
public:
	Sandbox()
	{
		for (int i = 0; i < 4; i++) {
			int value = (128 >> i);
			std::cout << "128 >> " << i << ": " << value << std::endl;
		}
		
	};
	~Sandbox() {};
};

Strife::Application* Strife::CreateApplication()
{
	return new Sandbox();
}