/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:52:06 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 14:35:07 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) // : _value(other._value) {} // - this manual way also can
{
    std::cout << "Copy constructor called" << std::endl;
    
    *this = other;  
    // use assignment
    // this = pointer to the curr obj, *this = the actual obj
    // =other - calls assignment operator fn
    // situation in main.cpp: Fixed b(a);
}

// syntax for copy assignment operator's prototype
// Fixed & - return type (reference to curr obj = *this)
// operator= - special function name that defines what '=' means for this class
// “I’m defining what happens when you assign one Fixed object to another object with =.”
// () - parameter - the obj you're copying from
// &other (in param) = passing by reference
// &other in {} = address of pointer, coz 'this' is pointer to curr obj, prevent self assign ( a = a )
Fixed &Fixed::operator=( const Fixed &other )       
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
    // this is obj c and other is obj b (situation in main.cpp: c = b)
    // *this = the actual obj
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}