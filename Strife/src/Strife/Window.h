#pragma once

#include "stpch.h"

#include "Strife/Core.h"
#include "Events/Event.h"

namespace Strife {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string title = "Strife Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop-system based window
	class STRIFE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0; // Any event originating from this window will be sent to this callback
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0; // Each rendering API has a different window class (like GLFWWindow, HWND, etc) they can all be accessed through void*

		static Window* Create(const WindowProps& props = WindowProps());
	};
}