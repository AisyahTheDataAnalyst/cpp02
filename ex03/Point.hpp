/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:58 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/31 20:36:09 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point( float const _x, float const _y );
        Point( const Point &other );
        Point &operator=( const Point &other );
        ~Point();

        // getters
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif 