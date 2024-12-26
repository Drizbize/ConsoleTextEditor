#pragma once

#include <iostream>
#include <windows.h>

#include "SETTINGS.h"
#include "Utils/ConsoleColors.h"

class Console_Char
{
public:
	char c;
	int color;

	Console_Char(char character, int color = DEFAULT_CONSOLE_COLOR);
	Console_Char(char character, ConsoleColors color);
	~Console_Char();

	void draw(const HANDLE& hConsole, bool isHighlight = false) const;

	operator char() const;

private:

};