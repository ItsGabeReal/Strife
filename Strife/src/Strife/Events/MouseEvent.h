#pragma once

#include "Event.h"

namespace Strife {

	class STRIFE_API MouseMovedEvent : public Event
	{

	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << "x, " << m_MouseY << "y";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_MouseX, m_MouseY;

	};

	class STRIFE_API MouseScrollEvent : public Event
	{

	public:
		MouseScrollEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << " x offset, " << m_YOffset << " y offset";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseScroll)

	private:
		float m_XOffset, m_YOffset;

	};

	class STRIFE_API MouseButtonEvent : public Event
	{

	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;

	};

	class STRIFE_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class STRIFE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}