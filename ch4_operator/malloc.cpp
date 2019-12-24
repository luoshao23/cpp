#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	if (auto p = (std::string*)std::malloc(4 * sizeof(std::string)))
	{
		int i = 0;
		try
		{
			for (; i != 4; ++i)
				new(p + i) std::string(5, 'a' + i);
			for (int j = 0; j != 4; ++j)
				std::cout << "p[" << j << "] == " << p[j] << std::endl;
		}
		catch(...) {return 1;}

		for (; i != 0; --i)
			p[i - 1].~basic_string();

		std:free(p);
	}

	return 0;
}
