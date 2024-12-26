#include "Console.h"

Console::Console()
	: m_hConsole(GetStdHandle(STD_OUTPUT_HANDLE))
{
	if (m_hConsole == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("Unable to get console handle");
	}

	GetConsoleScreenBufferInfo(m_hConsole, &m_csbi);
	m_csbi.wAttributes = 0;
}

Console::~Console()
{
}

void Console::setColor(int color = DEFAULT_CONSOLE_COLOR) const
{
	SetConsoleTextAttribute(m_hConsole, color);
}

void Console::setColor(ConsoleColors color)
{
	setColor(getIdColor(color));
}

void Console::moveCursor(Direction dir)
{
	if (isEmpty())
	{
		return;
	}

	switch (dir)
	{
	case Direction::UP:
		break;
	case Direction::DOWN:
		break;
	case Direction::RIGHT:
		if (m_cursor == --m_buffer.end())
			break;

		if (m_isAtBegining)
		{
			m_isAtBegining = false;
		}
		else
		{
			m_cursor++;
		}
		
		break;
	case Direction::LEFT:
		if (m_isAtBegining)
			break;

		if (m_cursor == m_buffer.begin())
		{
			m_isAtBegining = true;
		}
		else
		{
			m_cursor--;
		}
		
		break;
	default:
		break;
	}
}

void Console::addChar(Console_Char character)
{
	m_isAtBegining = false;

	if (isEmpty())
	{
		m_buffer.push_back(character);
		m_cursor = m_buffer.begin();
		return;
	}

	if (m_cursor == std::prev(m_buffer.end()))
	{
		m_buffer.push_back(character);
		m_cursor++;
	}
	else
	{
		m_cursor++;
		m_cursor = m_buffer.insert(m_cursor, character);
	}
}

void Console::deleteAtCursor()
{
	if (m_isAtBegining)
	{
		return;
	}

	m_cursor = m_buffer.erase(m_cursor);
	if (m_cursor != m_buffer.begin())
	{
		moveCursor(Direction::LEFT);
	}
	else
	{
		m_isAtBegining = true;
	}
}

void Console::render()
{
	clear();

	if (isEmpty())
	{
		drawDefaultCursor();
		return;
	}

	for (auto it = m_buffer.begin(); it != m_buffer.end(); ++it)
	{
		if (it == m_buffer.begin())
		{
			it->draw(m_hConsole, m_isAtBegining);
			continue;
		}

		it->draw(m_hConsole, std::prev(it) == m_cursor);
	}

	if (std::prev(m_buffer.end()) == m_cursor)
	{
		drawDefaultCursor();
	}

	/*Vector2 size = getConsoleSize();
	int consoleSize = size.x * size.y;*/

	//std::vector<CHAR_INFO> buffer(size.x * size.y);
	//for (int i = 0; i < consoleSize; i++) {
	//	buffer[i].Char.AsciiChar = ' ';  // Fill with spaces
	//	buffer[i].Attributes = m_csbi.wAttributes;  // Use default attributes
	//}
}

void Console::clear() const
{
	Vector2 size = getConsoleSize();

    COORD topLeft = { 0, 0 };
	DWORD charsWritten = 0;

	//setColor(convertToConsoleColorIndex(0, 0));
	SetConsoleCursorPosition(m_hConsole, topLeft);
	FillConsoleOutputCharacter(m_hConsole, ' ', size.x * size.y, topLeft, &charsWritten);
	FillConsoleOutputAttribute(m_hConsole, m_csbi.wAttributes, size.x * size.y, topLeft, &charsWritten);
	SetConsoleCursorPosition(m_hConsole, topLeft);
}

Vector2 Console::getConsoleSize() const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(m_hConsole, &csbi)) {
		throw std::runtime_error("Unable to retrieve console screen buffer info");
	}

	return Vector2(m_csbi.dwSize.X, m_csbi.dwSize.Y);
}

bool Console::isEmpty()
{
	return m_buffer.size() == 0;
}

void Console::drawDefaultCursor()
{
	setColor(convertToConsoleColorIndex(0, DEFAULT_CONSOLE_COLOR));
	std::cout << ' ';
}
