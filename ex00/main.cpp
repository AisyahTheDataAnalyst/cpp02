/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:50:46 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/30 16:51:27 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;      // default constructor
    Fixed b(a);   // copy constructor (obj b is created as a copy of obj a) - being born as a copy = copy constructor
    Fixed c;

    c = b;        // Copy assignment operator (obj c already exists, now takes obj b's value) - already alive, then becoming a copy = copy assignment

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}