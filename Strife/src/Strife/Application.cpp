#include "stpch.h"
#include "Application.h"

#include "Log.h"

#include <glad/glad.h>

namespace Strife {

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

	Application::Application()
	{
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
			glClearColor(0.05, 0.1, 0.4, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();

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
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

