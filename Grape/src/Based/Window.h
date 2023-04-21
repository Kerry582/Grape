#pragma once

#include "Core.h"

BEGIN_GP_NAMESPACE

class GP_DLL Window
{
public:
	static Window* createWindow();
	inline HWND getWin32Window() { return m_hwnd; }
	
	inline void setTitle(std::string title) { m_title = title; }
	inline void setDisplaySize(int width, int height) {}

private:
	std::string m_title;
	int m_width, m_height;
	HWND m_hwnd;
};

END_GP_NAMESPACE