#pragma once

#include "Event.h"

namespace Strife {

	class STRIFE_API WindowCloseEvent : public Event
	{
	public:
		std::string ToString() const override { return "WindowCloseEvent"; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};
	
	class STRIFE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "x, " << m_Height << "y";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};
	
	class STRIFE_API WindowFocusEvent : public Event
	{
	public:
		std::string ToString() const override { return "WindowFocusEvent"; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowFocus)
	};
	
	class STRIFE_API WindowLostFocusEvent : public Event
	{
	public:
		std::string ToString() const override { return "WindowLostFocusEvent"; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowLostFocus)
	};
	
	class STRIFE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int xPosition, int yPosition)
			: m_XPosition(xPosition), m_YPosition(yPosition) {}

		inline int GetXPosition() const { return m_XPosition; }
		inline int GetYPosition() const { return m_YPosition; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << m_XPosition << "x, " << m_YPosition << "y";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowMoved)

	private:
		int m_XPosition, m_YPosition;
	};

	class STRIFE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent(float deltaTime)
			: m_DeltaTime(deltaTime) {}

		inline float GetDeltaTime() const { return m_DeltaTime; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent: " << m_DeltaTime << "deltaTime";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)

	private:
		float m_DeltaTime;
	};

	class STRIFE_API AppUpdateEvent : public Event
	{
	public:

		std::string ToString() const override { return "AppUpdateEvent"; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class STRIFE_API AppRenderEvent : public Event
	{
	public:

		std::string ToString() const override { return "AppRenderEvent"; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};

}