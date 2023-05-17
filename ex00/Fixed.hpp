/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:49 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/05/16 18:08:00 by thibaultgir      ###   ########.fr       */
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
		Fixed( const Fixed & );
		~Fixed( void );
		Fixed &operator=(const Fixed&);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif