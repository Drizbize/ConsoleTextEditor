#include "ConsoleColors.h"

int switchConsoleColor(int textColor, int bgColor) {
    return (textColor << 4) | bgColor;
}

int switchConsoleColor(int currentColor) {
    int textColor = currentColor & 0x0F;       // Extract the lower 4 bits (foreground)
    int background = (currentColor >> 4) & 0x0F; // Extract the upper 4 bits (background)

    return switchConsoleColor(textColor, background);
}

int convertToConsoleColorIndex(int textColor, int bgColor) {
    return (bgColor << 4) | textColor;
}

int getIdColor(ConsoleColors color)
{
    return static_cast<int>(color);
}