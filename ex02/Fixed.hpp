/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:49 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/05/16 19:08:12 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	
	private :
		int					_value;
		static const int	_bit = 8;
		
	public :
		Fixed( void );
		Fixed( int );
		Fixed( float );
		Fixed( const Fixed &f );
		~Fixed( void );
		Fixed &operator=(const Fixed &f);
		
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed operator+ ( const Fixed &f );
		Fixed operator- ( const Fixed &f );
		Fixed operator* ( const Fixed &f );
		Fixed operator/ ( const Fixed &f );

		Fixed operator++ ( int );
		Fixed operator-- ( int );
		Fixed &operator++ ( void );
		Fixed &operator-- ( void );
		
		Fixed operator< ( const Fixed &f );
		Fixed operator> ( const Fixed &f );
		Fixed operator<= ( const Fixed &f );
		Fixed operator>= ( const Fixed &f );
		Fixed operator== ( const Fixed &f );
		Fixed operator!= ( const Fixed &f );
		
		static const Fixed	&min(	const Fixed &f1, const Fixed &f2 );
		static const Fixed	&max(	const Fixed &f1, const Fixed &f2 );
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif