/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:55 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 14:14:38 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point( float const x, float const y ) : _x(x), _y(y) {}

Point::Point( Point const &other ) : _x(other._x), _y(other._y) {}
// {
//     this->x = other.x;
//     this->y = other.y;
// }
// not allowed to do above because x and y are consts

Point &Point::operator=( Point const &other )
{
    (void)other; // because this->x & this->y are consts
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
    return this->_x;    
}

Fixed Point::getY() const
{
    return this->_y;
}

