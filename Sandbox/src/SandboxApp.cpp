#include <Strife.h>
#include <iostream>

class ExampleLayer : public Strife::Layer
{
public:
	ExampleLayer()
		: Strife::Layer("Example") {}

	void OnUpdate() override
	{
		if (Strife::Input::IsKeyPressed(ST_KEY_ENTER))
			ST_TRACE("ENTER is being pressed");
	}

	void OnEvent(Strife::Event& event) override
	{
		if(event.GetEventType() != Strife::EventType::MouseMoved)
			ST_INFO("{0}", event.ToString());
	}
};

class Sandbox : public Strife::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Strife::ImGuiLayer());
	}
	~Sandbox() {}
};

Strife::Application* Strife::CreateApplication() 
{
	return new Sandbox();
}