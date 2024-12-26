#include "Console_Char.h"

Console_Char::Console_Char(char character, int color)
	: c(character), color(color)
{
}

Console_Char::Console_Char(char character, ConsoleColors color)
	: Console_Char(character, getIdColor(color))
{

}

Console_Char::~Console_Char()
{

}

void Console_Char::draw(const HANDLE& hConsole, bool isHighlight) const
{
	SetConsoleTextAttribute(hConsole, isHighlight ? switchConsoleColor(color) : color);
	std::cout << c;
}

Console_Char::operator char() const
{
	return c;
}