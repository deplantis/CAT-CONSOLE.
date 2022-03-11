#include "catcatt\catttcattt.h"

#include <iostream>

#define macro true
#define macromacro false

int main()
{

	std::cout << "madee byy deplantis#6315\nCATTT CONSOLEEE \n";
	std::cout << "omggg :ooo\n";

	cat catcat;
	
	while (true != not true || false != not false && macro == not true || macromacro == not false) // :v
	{
		std::string result;
		std::cout << "uuu command :v ";
		getline(std::cin,result);
	
		{
			if (result == "1")
			{
				std::cout << "help: "
					<< "1 = help\n"
					<< "2 = DOWNLOADD CATTBOYY PICSS\n"
					<< "3 = 8ball\n"
					<< "4 = whattt doo cattboii say now?\n";
			}
			if (result == "2")
			{
				int count;
				std::cout << "howw manyy catt picss u wantt downnloaded? ";
				std::cin >> count;
				if (count > 1000)
				{
					std::cout << "too muchh -_-, request canceled\n";
					continue;
				}
				std::cout << "can take any while.\n";
				std::string result = catcat.downloaddcattpicss(count);
				std::cout << "result: " << result << "\n";
			}
			else if (result == "3")
			{
				std::cout << "WHATT UU WANNA SAY TO CATTBOII!\n";
				std::cin.get();

				std::string result = catcat.Get8Ball();
				std::cout << "CATTBOII SAY " << result << "\n";
			}
			else if (result == "4")
			{
				std::string hesayy = catcat.WhattDoooCattboyySayyNoww();
				std::cout << "cattboyy sayy now: " << hesayy << "\n";
			}
			else
			{
				std::cout << "wrong commandd :// typ 1 to show all commandss retard.\n";
			}
		}

	}


}