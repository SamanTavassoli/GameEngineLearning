#pragma once

#include "MyEngine/Core.h"

namespace MyEngine {

	// Events in MyEngine are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then and there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// this is so that we can filter by events
	// we want to be able to apply multiple event categories to every event 
	// type so we just bit representation not just numbers
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)

	};

	// these are just so we don't have to write them in the subclasses of Event class
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MyEngine_API Event
	{
		friend class EventDispatcher;
	public:
		// these virtual functions wil need to be implemented by the subclasses
		// note that not all of these will be included in the final version
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	// This calls allows us to provide IT functions that will run when certain events occur
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>; // describing the type of function that can be passed in
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// because we pass in a static type to the function, whenever we get an incoming event
			// we check if the event is of the same type as the static type passed in and if so
			// we execute the function on the event casted to the static type provided
			if (m_Event.GetEventType() == T::GetStaticType()) // we don't compare classes here, just the enum for event types we declared
			{
				m_Event.m_Handled = func(*(T*)&m_Event); // cast m_Event to type T and dereference and apply func to it
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	// makes logging events easier
	inline std::ostream& operator <<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

