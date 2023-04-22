#pragma once

#include "Event/Event.h"

BEGIN_GP_NAMESPACE

class GP_DLL KeyEvent : public Event
{
public:
	inline int getKeyCode() const { return m_keyCode; }
	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(int keycode)
		: m_keyCode(keycode) { }

	int m_keyCode;
};

class GP_DLL KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int keycode, int repeatCount)
		: KeyEvent(keycode), m_repeatCount(repeatCount) { }

	inline int getRepeatCount() const { return m_repeatCount; }
	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Key Pressed Event:" << m_keyCode << " (" << m_repeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)

private:
	int m_repeatCount;
};

class GP_DLL KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int keycode)
		: KeyEvent(keycode) { }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Key Released Event: " << m_keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};

class GP_DLL KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(int keycode)
		: KeyEvent(keycode) { }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Key Typed Event:" << m_keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyTyped)
};


END_GP_NAMESPACE