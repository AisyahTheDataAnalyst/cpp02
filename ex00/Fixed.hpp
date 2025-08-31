/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:51:51 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/30 20:48:21 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;        // 8 is written here , not in constructor's initializer list, because its a static const = compile-time const -- init in class
        
    public:									        // Orthodox Canonical Form:
        Fixed();                                    // default constructor
        Fixed( const Fixed &other );                // copy constructor
        Fixed &operator=( const Fixed &other );     // copy assignment operator
        ~Fixed();   						        // destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif