#include "sfml.h"

bool window::WindowisOpen() const
{
	if (MainWindow.isOpen())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void window::CloseWindow()
{
	if (event.type == sf::Event::Closed)
	{
		MainWindow.close();
	}
}