/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:54:25 by mesasaki          #+#    #+#             */
/*   Updated: 2025/11/11 19:54:25 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    std::string getName();
    void setName(std::string n);

    std::string getLastName();
    void setLastName(std::string n);

    std::string getNickName();
    void setNickName(std::string n);

    std::string getPhoneNumber();
    void setPhoneNumber(std::string n);

    std::string getDarkestSecret();
    void setDarkestSecret(std::string n);
};

#endif