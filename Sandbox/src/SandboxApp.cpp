#include <Strife.h>
#include <iostream>

class ExampleLayer : public Strife::Layer
{
public:
	ExampleLayer()
		: Strife::Layer("Example") {}

	void OnUpdate() override
	{
		ST_INFO("ExampleLayer::Update");
	}

	void OnEvent(Strife::Event& event) override
	{
		ST_INFO("{0}", event.ToString());
	}
};

class Sandbox : public Strife::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

Strife::Application* Strife::CreateApplication() 
{
	return new Sandbox();
}