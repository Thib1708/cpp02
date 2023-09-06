/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:49 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/06 16:42:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif