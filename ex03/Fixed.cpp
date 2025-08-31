/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:32 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/31 18:52:26 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor & destructors

Fixed::Fixed() : value(0) {}

Fixed::Fixed( const int i_num )
{
    this->value = i_num << fractionalBits;
}
Fixed::Fixed( const float f_num )
{
    this->value = roundf(f_num * (1 << fractionalBits)); 
}

Fixed::Fixed( const Fixed &other )
{
    *this = other;
}

Fixed &Fixed::operator=( const Fixed &other )
{
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}



// converters

float Fixed::toFloat() const
{
    return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return this->value >> fractionalBits;
}



// setter & getter

int Fixed::getRawBits() const
{
    return(this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}



// enabling to print out object's value directly from obj only

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}



// operators

bool Fixed::operator>( Fixed const &right_side ) const
{
    return this->value > right_side.value;
}

bool Fixed::operator<( Fixed const &right_side ) const
{
    return this->value < right_side.value;
}

bool Fixed::operator>=( Fixed const &right_side ) const
{
    return this->value >= right_side.value;
}

bool Fixed::operator<=( Fixed const &right_side ) const
{
    return this->value <= right_side.value;    
}

bool Fixed::operator==( Fixed const &right_side ) const
{
    return this->value == right_side.value;
}

bool Fixed::operator!=( Fixed const &right_side ) const
{
    return this->value != right_side.value;
}

Fixed Fixed::operator+( Fixed const &right_side ) const
{
    return Fixed(this->toFloat() + right_side.toFloat());
}

Fixed Fixed::operator-( Fixed const &right_side ) const
{
    return Fixed(this->toFloat() - right_side.toFloat());
}

Fixed Fixed::operator*( Fixed const &right_side ) const
{
    return Fixed(this->toFloat() * right_side.toFloat());
}

Fixed Fixed::operator/( Fixed const &right_side ) const
{
    return Fixed(this->toFloat() / right_side.toFloat());
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
    // ++a (pre-increment)
    // increasing this->value by 1 means +1/256 ≈ 0.00390625 in value.
}

Fixed Fixed::operator++(int)      
{
    Fixed temp = *this;
    this->value++;
    return temp;
    // a++ (post-increment)
}

Fixed &Fixed::operator--()        
{
    this->value--;
    return *this;
    // --a (pre-decrement)
}


Fixed Fixed::operator--(int)      
{
    Fixed temp = *this;
    this->value--;
    return temp;
    // a-- (post-decrement)
}



// min & max

Fixed &Fixed::min( Fixed &fp_num_1, Fixed &fp_num_2 )
{
    if (fp_num_1 > fp_num_2)
        return fp_num_2;
    return fp_num_1;
}

Fixed const &Fixed::min( Fixed const &fp_num_1, Fixed const &fp_num_2 )
{
    if (fp_num_1 > fp_num_2)
        return fp_num_2;
    return fp_num_1;
}

Fixed &Fixed::max( Fixed &fp_num_1, Fixed &fp_num_2 )
{
    if (fp_num_1 > fp_num_2)
        return fp_num_1;
    return fp_num_2;
}

Fixed const &Fixed::max( Fixed const &fp_num_1, Fixed const &fp_num_2 )
{
    if (fp_num_1 > fp_num_2)
        return fp_num_1;
    return fp_num_2;
}