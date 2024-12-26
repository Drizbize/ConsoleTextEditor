#pragma once

#include <iostream>
#include <windows.h>
#include <list>
#include <vector>

#include "Utils/Direction.h"
#include "Utils/Vector2.h"
#include "Utils/ConsoleColors.h"

#include "Console_Char.h"
#include "SETTINGS.h"

class Console
{
public:
	Console();
	~Console();

	void setColor(int color) const;
	void setColor(ConsoleColors color);

	void moveCursor(Direction dir);

	void addChar(Console_Char character);
	void deleteAtCursor();

	void render();
	void clear() const;
	Vector2 getConsoleSize() const;
	bool isEmpty();

private:
	std::list<Console_Char> m_buffer;
	std::list<Console_Char>::iterator m_cursor;
	Vector2 m_cursorScreenPos;

	bool m_isAtBegining = true;

	HANDLE m_hConsole;
	CONSOLE_SCREEN_BUFFER_INFO m_csbi;

	void drawDefaultCursor();
};