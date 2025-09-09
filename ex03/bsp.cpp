/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:26 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 20:13:03 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib> // abs()

// using the determinant formula to compute the signed area of a triangle given three points vertices A(x₁,y₁), B(x₂,y₂), C(x₃,y₃),
// Area(A,B,C)= 1/2​ × ∣x1​(y2​−y3​) + x2​(y3−y1​) + x3​(y1​−y2​)∣
static Fixed area( Point const &a, Point const &b, Point const &c)
{
    // float area_value = 
    //             a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
    //             b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
    //             c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
                
    // return Fixed(std::abs(area_value) / 2.0f);
    Fixed value_1 = a.getX() * (b.getY() - c.getY());
    Fixed value_2 = b.getX() * (c.getY() - a.getY());
    Fixed value_3 = c.getX() * (a.getY() - b.getY());
    
    Fixed area_value = value_1 + value_2 + value_3;

    if (area_value < Fixed(0))
        area_value = area_value * Fixed(-1);
    
    return area_value / Fixed(2);
}


// area of the big triangle ABC: A=Area(A,B,C)
// if point is inside triangle: A=A1+A2+A3
// if any of A1/A2/A3 == 0, the point is on edge or outside
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0)) // if equals to 0 = on edge
        return false;
    return (A == A1 + A2 + A3); // inside - A is a sum of all 3, outside = A > sum of all 3
}