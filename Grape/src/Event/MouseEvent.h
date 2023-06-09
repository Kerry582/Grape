#pragma once

#include "Event/Event.h"

BEGIN_GP_NAMESPACE

class GP_DLL MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float x, const float y)
		: m_MouseX(x), m_MouseY(y) {}

	float getX() const { return m_MouseX; }
	float getY() const { return m_MouseY; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Mouse Moved Event: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
	float m_MouseX, m_MouseY;
};

class GP_DLL MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) {}

	float getXOffset() const { return m_XOffset; }
	float getYOffset() const { return m_YOffset; }

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Mouse Scrolled Event: " << getXOffset() << ", " << getYOffset();
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
	float m_XOffset, m_YOffset;
};

class GP_DLL MouseButtonEvent : public Event
{
public:
	inline int getMouseButton() const { return m_Button; }

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

protected:
	MouseButtonEvent(int button)
		: m_Button(button) {}

	int m_Button;
};

class GP_DLL MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const int button)
		: MouseButtonEvent(button) {}

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Mouse Button Pressed Event: " << m_Button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class GP_DLL MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const int button)
		: MouseButtonEvent(button) {}

	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Mouse Button Released Event: " << m_Button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};

END_GP_NAMESPACE