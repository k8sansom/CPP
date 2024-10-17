/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:14:38 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/19 10:14:42 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

//These are global states across all instances of the Account class
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    this->_displayTimestamp();
	_amount = initial_deposit;
    _totalAmount += _amount;
    _accountIndex = this->getNbAccounts();
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
    _nbAccounts++;
}

Account::~Account( void ) {
    this->_displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" << std::endl;
    _nbAccounts--;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout	<< "accounts:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposits:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	_amount += deposit;
	this->_nbDeposits++;
	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
    std::cout 	<< "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:" ;
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout 	<< "amount:" << _amount << ";"
                << "nb_deposit:" << _nbDeposits << std::endl;
    return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
    this->_displayTimestamp();
    std::cout	<< "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	present = std::time(NULL);
	std::tm* local_time = std::localtime(&present);
	char buffer[19];

	std::strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", local_time);
	std::cout << buffer;
}
