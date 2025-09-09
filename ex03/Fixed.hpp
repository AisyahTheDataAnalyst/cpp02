/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:36 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 20:20:47 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8; // 8 bits means how many decimals you want in binary
    
    public:
        Fixed();
        Fixed( const int i_num );
        Fixed( const float f_num );
        Fixed( const Fixed &other );
        Fixed &operator=( const Fixed &other );
        ~Fixed();
        
        //converters
        float toFloat( void ) const;            // converts fixed-point value to floating-point value
        int toInt( void ) const;                // converts fixed-point value to integer value
       
        // getter & setter
        int getRawBits() const;
        void setRawBits(int const raw );
        
        // 6 comparison operators
        bool operator>( Fixed const &right_side ) const;
        bool operator<( Fixed const &right_side ) const;
        bool operator>=( Fixed const &right_side ) const;
        bool operator<=( Fixed const &right_side ) const;
        bool operator==( Fixed const &right_side ) const;
        bool operator!=( Fixed const &right_side ) const;

        // 4 arithmetic operators
        Fixed operator+( Fixed const &right_side ) const;
        Fixed operator-( Fixed const &right_side ) const;
        Fixed operator*( Fixed const &right_side ) const;
        Fixed operator/( Fixed const &right_side ) const;

        // 4 increment/decrement
        Fixed &operator++();        // ++a (pre-increment)
        Fixed operator++(int);      // a++ (post-increment)
        Fixed &operator--();        // --a (pre-decrement)
        Fixed operator--(int);      // a-- (post-decrement)

        // math functions
        static Fixed &min( Fixed &fp_num_1, Fixed &fp_num_2 );
        static Fixed const &min( Fixed const &fp_num_1, Fixed const &fp_num_2 );
        static Fixed &max( Fixed &fp_num_1, Fixed &fp_num_2 );
        static Fixed const &max( Fixed const &fp_num_1, Fixed const &fp_num_2 );
};

// stream insertion operator
std::ostream& operator<<(std::ostream &out, Fixed const &value);

#endif