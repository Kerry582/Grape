#pragma once

#include "Event/Event.h"

BEGIN_GP_NAMESPACE

class GP_DLL WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int width, unsigned int height)
		: m_width(width), m_height(height) { }

	inline unsigned int getWidth() const { return m_width; }
	inline unsigned int getHeight() const { return m_height; }
	std::string toString() const override
	{
		std::stringstream ss;
		ss << "Window Resize Event:" << m_width << ", " << m_height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
	unsigned int m_width, m_height;
};

class GP_DLL WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

END_GP_NAMESPACE