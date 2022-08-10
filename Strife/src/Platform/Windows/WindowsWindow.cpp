#include "stpch.h"
#include "WindowsWindow.h"

#include "Strife/Events/ApplicationEvent.h"
#include "Strife/Events/KeyEvent.h"
#include "Strife/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Strife {

	static bool s_GLFWInitialized = false; // Make sure we don't initialize the global instance of glfw more than once

	void GLFWErrorCallback(int error_code, const char* description)
	{
		ST_CORE_ERROR("GLFW error (code {0}): {1}", error_code, description);
	}

	Window* Window::Create(const WindowProps& props /* = WindowProps() */)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props); // I guess putting initialization in a separate function is good coding practice
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown(); // It seems like you should have as little as possible the constructor & destructor
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		ST_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ST_CORE_ASSERT(success, "Failed to initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback); // Handle cases where glfw runs into an error
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window); // We need this, and I don't know why
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ST_CORE_ASSERT(status, "Failed to initialize Glad");
		glfwSetWindowUserPointer(m_Window, &m_Data); // We can store any data we want in here and get a reference to said data from glfw when we need it. Pretty cool :)
		SetVSync(true);

		LinkGLFWEvents(); // Handle window and input events
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::LinkGLFWEvents()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowResizeEvent event(width, height);
				data.Width = width;
				data.Height = height;
				data.EventCallback(event); // Set width and height first just in case anything uses them to get the updated size
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (focused)
				{
				case 0: // Window Lost Focus
				{
					WindowLostFocusEvent event;
					data.EventCallback(event);
					break;
				}
				case 1: // Window Focused
				{
					WindowFocusEvent event;
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event(static_cast<float>(xoffset), static_cast<float>(yoffset));
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event(static_cast<float>(xpos), static_cast<float>(ypos));
				data.EventCallback(event);
			});
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents(); // Triggers the callbacks of pending window and input events. In other words, we don't receive events if we don't poll them
		glfwSwapBuffers(m_Window); // Swaps the front buffer (what the monitor displays) with the back buffer (what the computer writes to)
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1); // Delivers the current frame the NEXT time the buffers are swapped. This prevents screen tearing (I could be wrong about this)
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
	
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}