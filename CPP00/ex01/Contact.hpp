/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:15:35 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 09:54:36 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ios>
#include <sstream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		std::string	_get_input(std::string str) const;
	public:
		Contact();
		~Contact();
		int		index;
		int		add(void);
		void	print(int index) const;
		void	print_contact() const;
};
#endif