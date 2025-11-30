#include "Phonebook.hpp"


int main()
{
    Phonebook book;
	std::string command;

	while(true)
	{
		std::cout << "ADD | SEARCH | EXIT: ";
		if(!std::getline(std::cin, command))
			break;

		if(command == "ADD")
		{
			std::string first;
			std::string last;
			std::string nick;
			std::string phone;
			std::string secret;

			std::cout << "First name: ";
			if(!std::getline(std::cin, first))
				break;

			std::cout << "Last name: ";
			if(!std::getline(std::cin, last))
				break;

			std::cout << "Nickname: ";
			if(!std::getline(std::cin, nick))
				break;

			std::cout << "Phone number: ";
			if(!std::getline(std::cin, phone))
				break;

			std::cout << "Darkest secret: ";
			if(!std::getline(std::cin, secret))
				break;

			book.add(first, last, nick, phone, secret);
			std::cout << "Contact added.\n" << std::endl;
		}
		else if(command == "SEARCH")
		{
			book.search();
			std::cout << std::endl;
		}
		else if(command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command.\n" << std::endl;
		}
		
	}
	//book.add("Jane","Austen","Jenny", "1234567890", "She never married throughout her life.");
    //book.search();
    return 0;
}

