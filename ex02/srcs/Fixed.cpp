/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:43:01 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/06 18:07:30 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed( int value ) {
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bit;
	return ;
}

Fixed::Fixed( float value ) {
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1<< this->_bit));
	return ;
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &f) {
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return *this;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->_value) / static_cast<float>(1 << this->_bit);
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_bit;
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( const int raw ) {
	this->_value = raw;
	return ;
}

Fixed Fixed::operator+( const Fixed &f ) {
	return (this->_value + f._value);
}

Fixed Fixed::operator-( const Fixed &f ) {
	return (this->_value - f._value);
}

Fixed Fixed::operator*( const Fixed &f ) {
	return (this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/( const Fixed &f ) {
	return (this->toFloat() / f.toFloat());
}


Fixed Fixed::operator++( int value ) {
	Fixed temp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return temp;
}

Fixed Fixed::operator--( int value ) {
		Fixed temp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return temp;
}

Fixed Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}


Fixed Fixed::operator<( const Fixed &f ) {
	return (this->_value < f._value);
}

Fixed Fixed::operator>( const Fixed &f ) {
	return (this->_value > f._value);
}

Fixed Fixed::operator<=( const Fixed &f ) {
	return (this->_value <= f._value);
}

Fixed Fixed::operator>=( const Fixed &f ) {
	return (this->_value >= f._value);
}

Fixed Fixed::operator==( const Fixed &f ) {
	return (this->_value == f._value);
}

Fixed Fixed::operator!=( const Fixed &f ) {
	return (this->_value != f._value);
}

const Fixed& Fixed::min( const Fixed &f1, const Fixed &f2 ) {
	if (f1.toFloat() < f2.toFloat())
		return f1;
	return f2;
}

const Fixed& Fixed::max( const Fixed &f1, const Fixed &f2 ) {
	if (f1.toFloat() > f2.toFloat())
		return f1;
	return f2;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}