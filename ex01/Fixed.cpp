/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:51:39 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/08 11:27:04 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int i_num )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = i_num << _fractionalBits;
    // i_num << 8 = 10 * 2^8 = 10 * 256 = 2560 
    // (represents 10.0 in fixed-point -> looks comments in toFloat)
}
Fixed::Fixed( const float f_num )

{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(f_num * (1 << _fractionalBits)); 
    // 1 << 8 = 256 , 1 << n = 2^n
    // 1 << 8 = 2^fractionalBits = 256 - to shift those decimals into the integer space.
    // roundf ensures the nearest integer is chosen instead of blindly cutting off - keep precision by rounding to the nearest int.
    // store it in int value
}

Fixed::Fixed( const Fixed &other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return (float)this->_value / (1 << _fractionalBits);
    // "compress" the float into int & "decompress" it back when needed
    // toFloat keeps fractional precision (ex: 42.421875) - keep the decimals
    //
    // for i_num = 2560 (originally 10)
    // (float)2560 / (1 << 8)
    // = 2560 / 256
    // 10.0
    //
    // for f_num = 10860(originally 42.421875)
    // (float)10860 / (1<<8)
    // = 10860 / 256
    // = 42.421875
}

int Fixed::toInt() const
{
    return this->_value >> _fractionalBits;
    // toInt throws fractional part away (ex: 42 from 42.421875)
}

int Fixed::getRawBits() const
{
    return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}