#include<windows.h>
int wherex()

{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

	return (pBuffer.dwCursorPosition.X + 1);

}
int wherey()

{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

	return (pBuffer.dwCursorPosition.Y + 1);

}
void gotoxy(int x, int y)

{
	COORD c;

	c.X = x - 1;

	c.Y = y - 1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
#pragma once
