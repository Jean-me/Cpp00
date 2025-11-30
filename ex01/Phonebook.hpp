/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:59:00 by mesasaki          #+#    #+#             */
/*   Updated: 2025/11/12 14:59:00 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include "Contact.hpp"


class Phonebook
{
    Contact contacts[8];
    int nxt_idx;
    int count;
public:
   Phonebook();

   void add(std::string new_name, std::string new_lastname, std::string new_nickname, std::string new_number, std::string new_darkestsecret);
   bool printContact(int index);
   void search();
   void displayContacts();
};

#endif