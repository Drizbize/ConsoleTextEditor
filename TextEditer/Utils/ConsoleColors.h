#pragma once

enum class ConsoleColors
{
    BLACK = 0,
    D_BLEU, D_GREEN, D_CYAN, D_RED, D_PINK, D_YELLOW, D_WHITE,
    L_BLACK, L_BLUE, L_GREEN, L_CYAN, L_RED, L_PINK, L_YELLOW, L_WHITE
};

int switchConsoleColor(int textColor, int bgColor);
int switchConsoleColor(int color);
int convertToConsoleColorIndex(int textColor, int bgColor);
int getIdColor(ConsoleColors color);