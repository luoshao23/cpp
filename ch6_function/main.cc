#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
		if ( strncmp("--", argv[i], 2) )
		{
			//handle --
			std::cout << argv[i] + 2 << std::endl;
		} 
		else if ( argv[i][0] == '-')
		{
			//handle -
			std::cout << argv[i] + 2 << std::endl;
		}
		else
		{
			//handle value
			;
		}
	}
	return 0;
}
