#include "stpch.h"
#include "Application.h"

#include "Log.h"

#include <glad/glad.h>

namespace Strife {

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ST_CORE_ASSERT(!s_Instance, "Application is a singleton. Please don't define it more than once. Strife get's confused when you do that");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(&Application::OnEvent)); // Now when EventCallback is called (like in WindowsWindow::LinkGLFWEvents), we end up calling OnEvent
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

			glClearColor(0.05, 0.1, 0.4, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(&Application::OnWindowClose)); // Dispatch every WindowCloseEvent to OnWindowClose

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e); // Move the iterator forward by 1, de-reference the layer, and send the event to the layer

			if (e.IsHandled())
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

