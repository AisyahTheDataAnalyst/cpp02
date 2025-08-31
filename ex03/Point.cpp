/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:55 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/31 19:46:05 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point( float const _x, float const _y ) : x(_x), y(_y) {}

Point::Point( Point const &other ) : x(other.x), y(other.y) {}
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
    return this->x;    
}

Fixed Point::getY() const
{
    return this->y;
}

