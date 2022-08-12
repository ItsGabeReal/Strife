#pragma once

#include "stpch.h"
#include "Strife/Core.h"

namespace Strife {

	// Events in Strife are blocking, meaning it will pause
	// the entire engine to deal with the event.

	enum class EventType { // Every specific event
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll
	};

	enum EventCategory { // Categories that can be used to filter events
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual EventType GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class STRIFE_API Event
	{
		friend class EventDispatcher; // Give EventDispatcher access to m_Handled
	public:
		virtual EventType GetEventType() const = 0; // Included in EVENT_CLASS_TYPE
		virtual const char* GetName() const = 0;    // Included in EVENT_CLASS_TYPE
		virtual int GetCategoryFlags() const = 0;   // Included in EVENT_CLASS_CATEGORY
		virtual std::string ToString() const { return GetName(); } // For debugging

		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & category;
		}

		inline bool IsHandled() const { return m_Handled; }

	protected:
		bool m_Handled = false; // Once the event is handled, nothing else will receive it (eg: a button absorbing a click event so that the player doesn't also shoot their gun)
	};

	class EventDispatcher // An easy way to call a certain function if the event matches a certain type
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		// Call the supplied function if the supplied type matches the supplied event's type. I hope that makes since.
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event); // Call the provided function and use the bool it returns to determine if the event should be absorbed
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& lhs, const Event& rhs)
	{
		return lhs << rhs.ToString();
	}
}