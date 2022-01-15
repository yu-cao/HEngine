#pragma once

#include "Event.h"

namespace HEngine
{
	/**
	 * Base KeyEvent
	 */
	class HENGINE_API KeyEvent : public Event
	{
	public :
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		int m_KeyCode;

		KeyEvent(int keycode) : m_KeyCode(keycode) {}
	};


	class HENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		/* Expand it is:
		 * static EventType GetStaticType() { return EventType::KeyPressed; }
		 * virtual EventType GetEventType() const override { return GetStaticType(); }
		 * virtual const char* GetName() const override { return "KeyPressed"; }
		 */

	private:
		int m_RepeatCount;
	};


	class HENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
	};
}
