/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:00 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/31 17:52:03 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // roundf

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8; // 8 bits means how many decimals you want in binary
    
    public:
        Fixed();
        Fixed( const int i_num );
        Fixed( const float f_num );
        Fixed( const Fixed &other );
        Fixed &operator=(const Fixed &other );
        ~Fixed();
        float toFloat( void ) const;            // converts fixed-point value to floating-point value
        int toInt( void ) const;                // converts fixed-point value to integer value
        int getRawBits() const;
        void setRawBits(int const raw );
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif