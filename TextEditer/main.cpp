#include <iostream>
#include <windows.h>
#include <conio.h>
#include <list>

#include "Console/Console.h"
#include "Utils/ConsoleColors.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_BACKSPACE 8   // Backspace Key
#define KEY_ENTER 13

int main()
{
    Console console;

    while (true)
    {
        console.render();
        char ch = _getch();

        if (ch == 0 || ch == 224) {
            ch = _getch();

            switch (ch) {
            case KEY_LEFT:
                console.moveCursor(Direction::LEFT);
                break;
            case KEY_RIGHT:
                console.moveCursor(Direction::RIGHT);
                break;
            case KEY_UP:
                console.moveCursor(Direction::UP);
                break;
            case KEY_DOWN:
                console.moveCursor(Direction::DOWN);
                break;
            default:
                break;
            }
        }
        else {
            // Handle regular keys
            switch (ch) {
            case KEY_BACKSPACE:
                console.deleteAtCursor();
                break;
            case KEY_ENTER:
                console.addChar(Console_Char('\n'));
                break;
            default:
                console.addChar(Console_Char(ch));
                break;
            }
        }
        
        
    }

	return 0;
}