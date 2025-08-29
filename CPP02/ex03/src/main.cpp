/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:31:34 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 22:05:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    std::cout << "=== Testing Exercise 00: Canonical Form and Raw Bits ===" << std::endl;
    {
        // Default constructor
        Fixed a;
        std::cout << "a raw bits: " << a.getRawBits() << " (expected 0)" << std::endl;

        // Copy constructor
        Fixed b(a);
        std::cout << "b raw bits: " << b.getRawBits() << " (expected 0)" << std::endl;

        // Assignment operator
        Fixed c;
        c = b;
        std::cout << "c raw bits: " << c.getRawBits() << " (expected 0)" << std::endl;

        // setRawBits
        a.setRawBits(42);
        std::cout << "a raw bits after set: " << a.getRawBits() << " (expected 42)" << std::endl;

        // Self-assignment
        a = a;
        std::cout << "a raw bits after self-assign: " << a.getRawBits() << " (expected 42)" << std::endl;

        // Destructors called at scope end
    }

    std::cout << "\n=== Testing Exercise 01: Constructors, Conversions, and << ===" << std::endl;
    {
        // Default (already 0.0)
        Fixed def;
        std::cout << "Default: " << def << " (expected 0)" << std::endl;
        std::cout << "toInt: " << def.toInt() << " (expected 0)" << std::endl;
        std::cout << "toFloat: " << def.toFloat() << " (expected 0)" << std::endl;

        // Int constructor
        Fixed fromInt(10);
        std::cout << "From int 10: " << fromInt << " (expected 10)" << std::endl;
        std::cout << "toInt: " << fromInt.toInt() << " (expected 10)" << std::endl;
        std::cout << "toFloat: " << fromInt.toFloat() << " (expected 10)" << std::endl;

        // Float constructor
        Fixed fromFloat(42.42f);
        std::cout << "From float 42.42: " << fromFloat << " (expected ~42.4219)" << std::endl;
        std::cout << "toInt: " << fromFloat.toInt() << " (expected 42)" << std::endl;
        std::cout << "toFloat: " << fromFloat.toFloat() << " (expected ~42.4219)" << std::endl;

        // Copy from float-constructed
        Fixed copyFromFloat(fromFloat);
        std::cout << "Copy from float: " << copyFromFloat << " (expected ~42.4219)" << std::endl;

        // Assignment from int-constructed
        Fixed assign;
        assign = fromInt;
        std::cout << "Assigned from int: " << assign << " (expected 10)" << std::endl;

        // Edge cases: Negative
        Fixed negInt(-5);
        std::cout << "Negative int -5: " << negInt << " (expected -5)" << std::endl;
        std::cout << "toInt: " << negInt.toInt() << " (expected -5)" << std::endl;

        Fixed negFloat(-3.14f);
        std::cout << "Negative float -3.14: " << negFloat << " (expected ~-3.14063)" << std::endl;
        std::cout << "toInt: " << negFloat.toInt() << " (expected -3)" << std::endl;

        // Zero
        Fixed zeroFloat(0.0f);
        std::cout << "Zero float: " << zeroFloat << " (expected 0)" << std::endl;

        // Fractional rounding
        Fixed roundUp(0.5f);
        std::cout << "0.5f (round up): " << roundUp << " (expected 0.5)" << std::endl;

        Fixed roundDown(0.499f);
        std::cout << "0.499f (round down): " << roundDown << " (expected ~0.498047)" << std::endl;

        // Max/min values (test overflow boundaries)
        Fixed maxInt(2147483647);  // INT_MAX
        std::cout << "INT_MAX: " << maxInt << " (expected 2147483647)" << std::endl;

        Fixed minInt(INT32_MIN);  // INT_MIN
        std::cout << "INT_MIN: " << minInt << " (expected -2147483648)" << std::endl;

        // Large float (may overflow internally, but test conversion)
        Fixed largeFloat(1e6f);
        std::cout << "Large float 1e6: " << largeFloat << " (expected 1000000)" << std::endl;
    }

    std::cout << "\n=== Testing Exercise 02: Operators, Inc/Dec, Min/Max ===" << std::endl;
    {
        Fixed a(5.5f);
        Fixed b(2.25f);
        Fixed const c(0.0f);
        Fixed const d(-3.0f);

        // Comparison operators
        std::cout << "a > b: " << (a > b) << " (expected 1)" << std::endl;
        std::cout << "a < b: " << (a < b) << " (expected 0)" << std::endl;
        std::cout << "a >= b: " << (a >= b) << " (expected 1)" << std::endl;
        std::cout << "a <= b: " << (a <= b) << " (expected 0)" << std::endl;
        std::cout << "a == a: " << (a == a) << " (expected 1)" << std::endl;
        std::cout << "a != b: " << (a != b) << " (expected 1)" << std::endl;

        // Negative comparisons
        std::cout << "d < c: " << (d < c) << " (expected 1)" << std::endl;
        std::cout << "d == d: " << (d == d) << " (expected 1)" << std::endl;

        // Arithmetic operators
        Fixed sum = a + b;
        std::cout << "a + b: " << sum << " (expected ~7.75)" << std::endl;

        Fixed diff = a - b;
        std::cout << "a - b: " << diff << " (expected ~3.25)" << std::endl;

        Fixed prod = a * b;
        std::cout << "a * b: " << prod << " (expected ~12.375)" << std::endl;

        Fixed quot = a / b;
        std::cout << "a / b: " << quot << " (expected ~2.44444)" << std::endl;

        // Negative arithmetic
        Fixed negSum = a + d;
        std::cout << "a + d: " << negSum << " (expected 2.5)" << std::endl;

        Fixed negProd = b * d;
        std::cout << "b * d: " << negProd << " (expected -6.75)" << std::endl;

        // Division by zero (should crash or undefined, as per module)
        // Uncomment to test: Fixed zeroDiv = a / c;  // c is 0

        // Increment/Decrement
        Fixed inc = a;
        std::cout << "Pre ++inc: " << ++inc << " (expected ~5.50391)" << std::endl;
        std::cout << "Post inc++: " << inc++ << " (expected ~5.50391)" << std::endl;
        std::cout << "After post: " << inc << " (expected ~5.50781)" << std::endl;

        Fixed dec = a;
        std::cout << "Pre --dec: " << --dec << " (expected ~5.49609)" << std::endl;
        std::cout << "Post dec--: " << dec-- << " (expected ~5.49609)" << std::endl;
        std::cout << "After post: " << dec << " (expected ~5.49219)" << std::endl;

        // Min/Max non-const
        Fixed& minRef = Fixed::min(a, b);
        std::cout << "min(a, b): " << minRef << " (expected 2.25)" << std::endl;

        Fixed& maxRef = Fixed::max(a, b);
        std::cout << "max(a, b): " << maxRef << " (expected 5.5)" << std::endl;

        // Min/Max const
        const Fixed& constMin = Fixed::min(c, d);
        std::cout << "min(c, d): " << constMin << " (expected -3)" << std::endl;

        const Fixed& constMax = Fixed::max(c, d);
        std::cout << "max(c, d): " << constMax << " (expected 0)" << std::endl;

        // Edge: min/max with equal
        std::cout << "min(a, a): " << Fixed::min(a, a) << " (expected 5.5)" << std::endl;

        // Overflow tests (arithmetic near limits)
        Fixed max(2147483647.0f);
        Fixed small(1.0f);
        Fixed overflow = max + small;  // May overflow, check behavior
        std::cout << "max + 1: " << overflow << " (may wrap around)" << std::endl;
    }

    std::cout << "\n=== Testing Exercise 03: Point and BSP ===" << std::endl;
    {
        // Point constructors
        Point def;  // Default: (0,0)
        std::cout << "Default Point x: " << def.getX() << ", y: " << def.getY() << " (expected 0,0)" << std::endl;

        Point fromFloats(1.5f, 2.25f);
        std::cout << "From floats: x " << fromFloats.getX() << ", y " << fromFloats.getY() << " (expected 1.5, 2.25)" << std::endl;

        // Copy constructor
        Point copy(fromFloats);
        std::cout << "Copy x: " << copy.getX() << ", y: " << copy.getY() << " (expected 1.5, 2.25)" << std::endl;

        // Assignment (no-op due to const members)
        Point assign;
        assign = fromFloats;
        std::cout << "Assigned x: " << assign.getX() << ", y: " << assign.getY() << " (expected 0,0 - unchanged)" << std::endl;

        // BSP tests
        // Triangle: a(0,0), b(4,0), c(2,3)
        Point triA(0.0f, 0.0f);
        Point triB(4.0f, 0.0f);
        Point triC(2.0f, 3.0f);

        // Inside point (2,1)
        Point inside(2.0f, 1.0f);
        std::cout << "BSP inside: " << bsp(triA, triB, triC, inside) << " (expected 1)" << std::endl;

        // Outside point (5,1)
        Point outside(5.0f, 1.0f);
        std::cout << "BSP outside: " << bsp(triA, triB, triC, outside) << " (expected 0)" << std::endl;

        // On edge (midpoint of a-b: 2,0)
        Point onEdge(2.0f, 0.0f);
        std::cout << "BSP on edge: " << bsp(triA, triB, triC, onEdge) << " (expected 0)" << std::endl;

        // On vertex (a)
        std::cout << "BSP on vertex: " << bsp(triA, triB, triC, triA) << " (expected 0)" << std::endl;

        // Degenerate triangle (collinear points)
        Point degA(0,0), degB(1,1), degC(2,2);
        Point test(0.5f, 0.5f);
        std::cout << "BSP degenerate: " << bsp(degA, degB, degC, test) << " (expected 0)" << std::endl;

        // Negative coordinates
        Point negTriA(-1,-1), negTriB(1,-1), negTriC(0,1);
        Point negInside(0,0);
        std::cout << "BSP negative inside: " << bsp(negTriA, negTriB, negTriC, negInside) << " (expected 1)" << std::endl;

        // Floating-point precision test (close to edge)
        Point closeToEdge(2.0f + 0.0001f, 0.0f);
        std::cout << "BSP close to edge: " << bsp(triA, triB, triC, closeToEdge) << " (expected 0)" << std::endl;

        // Large values (test overflow in area calc)
        Point largeA(1000000, 1000000), largeB(1000001, 1000000), largeC(1000000, 1000001);
        Point largeTest(1000000.4f, 1000000.4f);
        std::cout << "BSP large values: " << bsp(largeA, largeB, largeC, largeTest) << " (expected 1)" << std::endl;
    }

    std::cout << "\n=== Additional Tests: Points Strictly Inside Triangles ===" << std::endl;
    {
        // Test 1: Simple acute triangle, point in center
        Point acuteA(0.0f, 0.0f);
        Point acuteB(3.0f, 0.0f);
        Point acuteC(1.5f, 2.0f);
        Point insideCenter(1.5f, 0.666f);  // Barycentric centroid
        std::cout << "BSP acute center: " << bsp(acuteA, acuteB, acuteC, insideCenter) << " (expected 1)" << std::endl;

        // Test 2: Obtuse triangle, point near obtuse angle
        Point obtuseA(0.0f, 0.0f);
        Point obtuseB(5.0f, 0.0f);
        Point obtuseC(1.0f, 0.5f);  // Obtuse at A
        Point insideObtuse(2.0f, 0.1f);
        std::cout << "BSP obtuse near angle: " << bsp(obtuseA, obtuseB, obtuseC, insideObtuse) << " (expected 1)" << std::endl;

        // Test 3: Triangle with negative coordinates, point inside
        Point negA(-2.0f, -2.0f);
        Point negB(2.0f, -2.0f);
        Point negC(0.0f, 2.0f);
        Point insideNeg(0.0f, -1.0f);
        std::cout << "BSP negative inside: " << bsp(negA, negB, negC, insideNeg) << " (expected 1)" << std::endl;

        // Test 4: Small values (near fixed-point precision limit ~0.0039)
        Point smallA(0.0f, 0.0f);
        Point smallB(0.1f, 0.0f);
        Point smallC(0.05f, 0.1f);
        Point insideSmall(0.05f, 0.033f);
        std::cout << "BSP small values inside: " << bsp(smallA, smallB, smallC, insideSmall) << " (expected 1)" << std::endl;

        // Test 5: Large values (adjusted for inside, as per previous fix)
        Point largeA(1000000.0f, 1000000.0f);
        Point largeB(1000001.0f, 1000000.0f);
        Point largeC(1000000.0f, 1000001.0f);
        Point insideLarge(1000000.3f, 1000000.3f);  // Strictly inside (below hypotenuse)
        std::cout << "BSP large inside: " << bsp(largeA, largeB, largeC, insideLarge) << " (expected 1)" << std::endl;

        // Test 6: Clockwise triangle (to test sign handling)
        Point cwA(0.0f, 0.0f);
        Point cwB(0.0f, 4.0f);  // Reversed order for negative areaABC
        Point cwC(4.0f, 0.0f);
        Point insideCW(1.0f, 1.0f);
        std::cout << "BSP clockwise inside: " << bsp(cwA, cwB, cwC, insideCW) << " (expected 1)" << std::endl;

        // Test 7: Very flat triangle (near-degenerate but not quite)
        Point flatA(0.0f, 0.0f);
        Point flatB(10.0f, 0.0f);
        Point flatC(5.0f, 0.01f);  // Very small height
        Point insideFlat(5.0f, 0.005f);
        std::cout << "BSP flat inside: " << bsp(flatA, flatB, flatC, insideFlat) << " (expected 1)" << std::endl;

        // Test 8: Triangle with fractional coords (test fixed-point precision)
        Point fracA(0.25f, 0.25f);
        Point fracB(1.75f, 0.25f);
        Point fracC(1.0f, 1.5f);
        Point insideFrac(1.0f, 0.75f);
        std::cout << "BSP fractional inside: " << bsp(fracA, fracB, fracC, insideFrac) << " (expected 1)" << std::endl;
    }
	
    std::cout << "\n=== Additional Edge Cases Across Module ===" << std::endl;
    {
        // Const correctness
        const Fixed constFixed(10);
        std::cout << "Const toFloat: " << constFixed.toFloat() << std::endl;
        std::cout << "Const getRawBits: " << constFixed.getRawBits() << std::endl;

        // Operator with const
        std::cout << "constFixed + Fixed(1): " << (constFixed + Fixed(1)) << " (expected 11)" << std::endl;

        // Division near zero (small epsilon)
        Fixed small(0.00390625f);  // 1/256
        Fixed div = Fixed(1) / small;
        std::cout << "1 / epsilon: " << div << " (expected 256)" << std::endl;

        // Multiplication overflow
        Fixed large(1000000);
        Fixed multOverflow = large * large;  // May overflow int
        std::cout << "Large * large: " << multOverflow << " (may be garbage due to overflow)" << std::endl;

        // Inc/dec on min/max
        Fixed minVal(-2147483648.0f);
        std::cout << "--minVal: " << --minVal << " (may underflow)" << std::endl;
    }

    return 0;
}
