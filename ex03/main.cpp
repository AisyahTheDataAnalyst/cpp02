/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:46 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 20:16:05 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a;
    Point b(0, 10);
    Point c(10, 0);
    Point point_inside(3, 3);
    Point point_outside(10, 5);

    std::cout << "point_inside is inside? " << bsp(a, b, c, point_inside) << std::endl;
    std::cout << "point_outside is inside? " << bsp(a, b, c, point_outside) << std::endl;
    
    return 0;
}