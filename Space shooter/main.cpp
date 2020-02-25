#include "game.h"

int main()
{
	try
	{
		Game game;
		game.menu();
	}
	catch (std::string err)
	{
		std::cout << err << std::endl;
	}
	return 0;
}
