/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_Awesome_PhoneBook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:54:10 by mesasaki          #+#    #+#             */
/*   Updated: 2025/11/11 19:54:10 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <sstream>
#include "Phonebook.hpp"

// class Contact {
//     std::string firstname;
//     std::string lastname;
//     std::string nickname;
//     std::string phoneNumber;
//     std::string darkestSecret;
// public:
//     std::string getName() const
//     { 
//         return firstname; 
//     }
   
//     void setName(std::string n)
//     {
//         firstname = n;
//     }

//     std::string getLastName() const
//     {
//         return lastname;
//     }
//     void setLastName(std::string n)
//     {
//         lastname = n;
//     }

// 	std::string getNickName() const 
// 	{
// 		return nickname;
// 	}
//     void setNickName(std::string n)
//     {
//         nickname = n;
//     }

//     std::string getPhoneNumber() const 
//     {
//         return phoneNumber;
//     }
//     void setPhoneNumber(std::string n)
//     {
//         phoneNumber = n;
//     }

// 	std::string getDarkestSecret() const 
// 	{
// 		return darkestSecret;
// 	}
//     void setDarkestSecret(std::string n)
//     {
//         darkestSecret = n;
//     }
// };

std::string Contact::getName()
{ 
    return firstname; 
}
   
void Contact::setName(std::string n)
{
    firstname = n;
}

std::string Contact::getLastName()
{
    return lastname;
}

void Contact::setLastName(std::string n)
{
    lastname = n;
}

std::string Contact::getNickName()
{
	return nickname;
}

void Contact::setNickName(std::string n)
{
    nickname = n;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

void Contact::setPhoneNumber(std::string n)
{
    phoneNumber = n;
}

std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}

void Contact::setDarkestSecret(std::string n)
{
    darkestSecret = n;
}

//---------------------------------------------------------------------
// ヘルパ
// 10文字幅に合わせる（超える場合は先頭9文字+'.'、短い場合は右寄せで空白埋め）
static std::string fit10(const std::string& s)
{
    if (s.size() > 10)
    return s.substr(0, 9) + ".";
    return std::string(10 - (int)s.size(), ' ') + s;
}

//数字のみか確認（空文字は false）
static bool is_number(std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i)
    { 
        if (!std::isdigit((unsigned char)s[i])) return false;
    }
        return true;
}

static std::string int_to_string(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

//--------------------------------------------------------


Phonebook::Phonebook()
{
    nxt_idx = 0;
    count = 0;
}

void Phonebook::add(std::string new_name, std::string new_lastname, std::string new_nickname, std::string new_number, std::string new_darkestsecret)
{
    contacts[nxt_idx].setName(new_name);
	contacts[nxt_idx].setLastName(new_lastname);
	contacts[nxt_idx].setNickName(new_nickname);
    contacts[nxt_idx].setPhoneNumber(new_number);
	contacts[nxt_idx].setDarkestSecret(new_darkestsecret);
    nxt_idx = (nxt_idx + 1) % 8;
    if(count < 8)
        count++;// to keep track of number of contacts added
}

   
bool Phonebook::printContact(int index)
{
    if (index < 1 || index > count) return false;
    Contact &c = contacts[index - 1];
    std::cout << "First name:     " << c.getName() << std::endl;
    std::cout << "Last name:      " << c.getLastName() << std::endl;
    std::cout << "Nickname:       " << c.getNickName() << std::endl;
    std::cout << "Phone number:   " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
    return true;
}

void Phonebook::search()
{
	//電話帳になにもなかったら
	if(count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

   //リストを表示
	displayContacts();

	std::cout << "Enter index to view details: ";
	std::string line;
	if(!std::getline(std::cin, line))
		return;
	if(!is_number(line) || line.empty())
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	int idx = std::atoi(line.c_str());
    if(idx < 1 || idx > count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
       if (!printContact(idx)) 
           std::cout << "Invalid index." << std::endl;
}
	
void Phonebook::displayContacts()
{
    std::cout	<< fit10("index") << "|" 
				<< fit10("first name") << "|"
				<< fit10("last name") << "|"
				<< fit10("nickname") << "|"
				<< std::endl;

    for (int i = 0; i < count; ++i)
    {
        std::cout   << fit10(int_to_string(i + 1)) << "|"
                    << fit10(contacts[i].getName()) << "|"
                    << fit10(contacts[i].getLastName()) << "|"
                    << fit10(contacts[i].getNickName()) << "|"
					<< std::endl;
    }
}

// class Phonebook 
// {
//     Contact contacts[8];
//     int nxt_idx;
//     int count;
// public:
//    Phonebook()
//    {
//        nxt_idx = 0;
//        count = 0;
//    }

//    void add(std::string new_name, std::string new_lastname, std::string new_nickname, std::string new_number, std::string new_darkestsecret)
//    {
//     contacts[nxt_idx].setName(new_name);
// 	contacts[nxt_idx].setLastName(new_lastname);
// 	contacts[nxt_idx].setNickName(new_nickname);
//     contacts[nxt_idx].setPhoneNumber(new_number);
// 	contacts[nxt_idx].setDarkestSecret(new_darkestsecret);
//     nxt_idx = (nxt_idx + 1) % 8;
//     if(count < 8)
//         count++;// to keep track of number of contacts added
//    }

   
// 	bool printContact(int index) const
// 	{
//     	if (index < 1 || index > count) return false;
//     	const Contact &c = contacts[index - 1];
//     	std::cout << "First name:     " << c.getName() << std::endl;
//     	std::cout << "Last name:      " << c.getLastName() << std::endl;
//     	std::cout << "Nickname:       " << c.getNickName() << std::endl;
//     	std::cout << "Phone number:   " << c.getPhoneNumber() << std::endl;
//     	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
//     	return true;
// 	}

//    void search()
//    {
// 	//電話帳になにもなかったら
// 	if(count == 0)
// 	{
// 		std::cout << "Phonebook is empty." << std::endl;
// 		return;
// 	}

//    //リストを表示
// 	displayContacts();

// 	std::cout << "Enter index to view details: ";
// 	std::string line;
// 	if(!std::getline(std::cin, line))
// 		return;
// 	if(!is_number(line) || line.empty() || std::stoi(line) < 1 || std::stoi(line) > count)
// 	{
// 		std::cout << "Invalid index." << std::endl;
// 		return;
// 	}
// 	 int idx = std::stoi(line);
//        if (!printContact(idx)) 
//            std::cout << "Invalid index." << std::endl;
// 	}
	
//    void displayContacts() const
//    {
//         std::cout	<< fit10("index") << "|" 
// 					<< fit10("first name") << "|"
// 					<< fit10("last name") << "|"
// 					<< fit10("nickname") << "|"
// 					<< std::endl;

//     	for (int i = 0; i < count; ++i)
//         {
//             std::cout   << fit10(std::to_string(i + 1)) << "|"
//                         << fit10(contacts[i].getName()) << "|"
//                         << fit10(contacts[i].getLastName()) << "|"
//                     	<< fit10(contacts[i].getNickName()) << "|"
// 						<< std::endl;
//         }
// 	}
// };

// int main()
// {
//     Phonebook book;
// 	std::string command;

// 	while(true)
// 	{
// 		std::cout << "ADD | SEARCH | EXIT: ";
// 		if(!std::getline(std::cin, command))
// 			break;

// 		if(command == "ADD")
// 		{
// 			std::string first;
// 			std::string last;
// 			std::string nick;
// 			std::string phone;
// 			std::string secret;

// 			std::cout << "First name: ";
// 			if(!std::getline(std::cin, first))
// 				break;

// 			std::cout << "Last name: ";
// 			if(!std::getline(std::cin, last))
// 				break;

// 			std::cout << "Nickname: ";
// 			if(!std::getline(std::cin, nick))
// 				break;

// 			std::cout << "Phone number: ";
// 			if(!std::getline(std::cin, phone))
// 				break;

// 			std::cout << "Darkest secret: ";
// 			if(!std::getline(std::cin, secret))
// 				break;

// 			book.add(first, last, nick, phone, secret);
// 			std::cout << "Contact added.\n" << std::endl;
// 		}
// 		else if(command == "SEARCH")
// 		{
// 			book.search();
// 			std::cout << std::endl;
// 		}
// 		else if(command == "EXIT")
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			std::cout << "Invalid command.\n" << std::endl;
// 		}
		
// 	}
// 	//book.add("Jane","Austen","Jenny", "1234567890", "She never married throughout her life.");
//     //book.search();
//     return 0;
// }

