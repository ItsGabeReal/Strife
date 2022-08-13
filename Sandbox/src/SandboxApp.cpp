#include <Strife.h>     
#include "ImGui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Wassu");
		ImGui::End();
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