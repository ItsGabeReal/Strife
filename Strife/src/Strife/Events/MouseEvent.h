#pragma once

#include "Event.h"

namespace Strife {

	class STRIFE_API MouseMovedEvent : public Event
	{

	public:
		MouseMovedEvent(int mouseX, int mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline const int& GetX() const { return m_MouseX; }
		inline const int& GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << "x, " << m_MouseY << "y";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved)

	private:
		int m_MouseX, m_MouseY; // Cherno made these floats for some reason. Personally I think he's about as smart as a box of cigars

	};

	class STRIFE_API MouseScrolledEvent : public Event
	{

	public:
		MouseScrolledEvent(int xOffset, int yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline const int& GetXOffset() const { return m_XOffset; }
		inline const int& GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << " x offset, " << m_YOffset << " y offset";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		int m_XOffset, m_YOffset;

	};

	class STRIFE_API MouseButtonEvent : public Event
	{

	public:
		inline const int& GetMouseButton() const { return m_Button; }

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