/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:09:21 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/09 19:13:10 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed       a;
    Fixed const b( Fixed(5.05f) * Fixed(2)); // explicit construction (directly put value on class without object)
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a,b ) << std::endl;

    return 0;
}


// int main() {
//     std::cout << "===== Constructors =====" << std::endl;
//     Fixed a;          // default constructor
//     Fixed b(2);       // int constructor
//     Fixed c(3.5f);    // float constructor
//     Fixed d(b);       // copy constructor
//     a = Fixed(5);     // assignment

//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;

//     std::cout << "\n===== Comparison Operators =====" << std::endl;
//     std::cout << "b < c  = " << (b < c) << std::endl;   // expect 1
//     std::cout << "b > c  = " << (b > c) << std::endl;   // expect 0
//     std::cout << "b <= d = " << (b <= d) << std::endl;  // expect 1
//     std::cout << "b >= d = " << (b >= d) << std::endl;  // expect 1
//     std::cout << "b == d = " << (b == d) << std::endl;  // expect 1
//     std::cout << "b != c = " << (b != c) << std::endl;  // expect 1

//     std::cout << "\n===== Arithmetic Operators =====" << std::endl;
//     Fixed e = b + c;   // 2 + 3.5
//     Fixed f = c - b;   // 3.5 - 2
//     Fixed g = b * c;   // 2 * 3.5
//     Fixed h = c / b;   // 3.5 / 2

//     std::cout << "b + c = " << e << std::endl;   // expect ~5.5
//     std::cout << "c - b = " << f << std::endl;   // expect ~1.5
//     std::cout << "b * c = " << g << std::endl;   // expect ~7
//     std::cout << "c / b = " << h << std::endl;   // expect ~1.75

//     std::cout << "\n===== Increment / Decrement =====" << std::endl;
//     Fixed x(1);
//     std::cout << "x   = " << x << std::endl;
//     std::cout << "++x = " << ++x << std::endl;   // expect 2
//     std::cout << "x   = " << x << std::endl;     // expect 2
//     std::cout << "x++ = " << x++ << std::endl;   // expect 2 (then x=3)
//     std::cout << "x   = " << x << std::endl;     // expect 3
//     std::cout << "--x = " << --x << std::endl;   // expect 2
//     std::cout << "x   = " << x << std::endl;     // expect 2
//     std::cout << "x-- = " << x-- << std::endl;   // expect 2 (then x=1)
//     std::cout << "x   = " << x << std::endl;     // expect 1

//     std::cout << "\n===== Min / Max =====" << std::endl;
//     Fixed y(2);
//     Fixed z(5);

//     std::cout << "min(y, z) = " << Fixed::min(y, z) << std::endl; // expect 2
//     std::cout << "max(y, z) = " << Fixed::max(y, z) << std::endl; // expect 5

//     Fixed const cy(3);
//     Fixed const cz(4);

//     std::cout << "min(cy, cz) = " << Fixed::min(cy, cz) << std::endl; // expect 3
//     std::cout << "max(cy, cz) = " << Fixed::max(cy, cz) << std::endl; // expect 4

//     return 0;
// }