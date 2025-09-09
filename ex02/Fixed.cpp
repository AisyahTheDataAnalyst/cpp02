/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:04:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 20:23:04 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor & destructors

Fixed::Fixed() : _value(0) {}

Fixed::Fixed( const int i_num )
{
    this->_value = i_num << _fractionalBits;
}

Fixed::Fixed( const float f_num )
{
    this->_value = roundf(f_num * (1 << _fractionalBits)); 
}

Fixed::Fixed( const Fixed &other )
{
    *this = other;
}

Fixed &Fixed::operator=( const Fixed &other )
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

//------------------------------------------------------------------------------------
// converters

float Fixed::toFloat() const
{
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return this->_value >> _fractionalBits;
}

// ------------------------------------------------------------------------------------
// setter & getter

int Fixed::getRawBits() const
{
    return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

// ------------------------------------------------------------------------------------
// enabling to print out object's _value directly from obj

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}


// -------------------------------------------------------------------------------------
// operators overloading

bool Fixed::operator>( Fixed const &right_side ) const
{
    return this->_value > right_side._value;
}

bool Fixed::operator<( Fixed const &right_side ) const
{
    return this->_value < right_side._value;
}

bool Fixed::operator>=( Fixed const &right_side ) const
{
    return this->_value >= right_side._value;
}

bool Fixed::operator<=( Fixed const &right_side ) const
{
    return this->_value <= right_side._value;    
}

bool Fixed::operator==( Fixed const &right_side ) const
{
    return this->_value == right_side._value;
}

bool Fixed::operator!=( Fixed const &right_side ) const
{
    return this->_value != right_side._value;
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
    this->_value++;
    return *this;
    // ++a (pre-increment)
    // increasing this->_value by 1 means +1/256 ≈ 0.00390625 in _value.
    // pre - return type without reference - return the copy of the local variable , cannot use reference on local variable coz it will die after function ends
}

Fixed Fixed::operator++(int) // int is just a dummy parameter - not used at all - justa syntac trick so compiler know this is a post-increment, not pre-increment. compiler dosent care about the value int 
{
    Fixed temp(*this); // saves the old value - syntax method: direct init - calls copy constrctor
    this->_value++;
    return temp;
    // a++ (post-increment)
    // post - return copy of the old value - no reference
}

Fixed &Fixed::operator--()        
{
    this->_value--;
    return *this;
    // --a (pre-decrement)
}

Fixed Fixed::operator--(int)      
{
    Fixed temp = *this; // copy init - calls copy constructor // this syntax could allow implicit conversions (if *this were not already the same type).
    this->_value--;
    return temp;
    // a-- (post-decrement)
}


// ------------------------------------------------------------------------------------------
// min & max

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
    if (a > b)
        return b;
    return a;
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b )
{
    if (a > b)
        return b;
    return a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
    if (a > b)
        return a;
    return b;
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b )
{
    if (a > b)
        return a;
    return b;
}