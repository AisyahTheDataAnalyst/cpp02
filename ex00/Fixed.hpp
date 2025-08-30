/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:51:51 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/30 17:45:33 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:									        // Orthodox Canonical Form:
        Fixed();                                    // default constructor
        Fixed( const Fixed &other );                // copy constructor
        Fixed &operator=( const Fixed &other );     // copy assignment operator
        ~Fixed();   						        // destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif