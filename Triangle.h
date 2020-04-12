#pragma once

#include <array>
#include <vector>
#include<iostream>
#include "Point.h"
using namespace std;

class Triangle
{
public:
	constexpr static int NUMBER_OF_CORNERS{ 3 };
	enum class Color { PINK, RED, BLUE, WHITE, BLACK, GREEN };

	// Constructor
	Triangle(const Point& a , const Point& b , const Point& c , const Color& color );
	Triangle(const vector<Point>& pts, const Color& color );
	Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color );

	const Point& a = pts[0];
	Point& b = pts[1];
	Point& c = pts[2];

	// Getter Functions
	Point getA() const noexcept;
	Point getB() const noexcept;
	Point getC() const noexcept;

	Color getColor() const noexcept;
	string getColorAsString() const noexcept;

	double getPerimeter() const noexcept;

	// Setter Functions
	bool setA(const Point& pt);
	bool setB(const Point& pt);
	bool setC(const Point& pt); 

	/* Ucgen olup olmadýðýný kontrol eder.
	 * Bu fonksiyonun tüm yapýcýlar ve setter fonksiyonlar içinde doðrudan/dolaylý olarak çaðrýlmasý zorunludur.
	 * Eðer verilen deðerler bir üçgen oluþturmuyorsa invalid_argument exception fýrlatýlmalý ve bu bu exception kontrol edilmelidir
	 * Program sonlandýrýlmamalýdýr.
	 */
	bool isValid() const;

	void printInfo() const noexcept;
	// Ekrana þunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts;
	Color color;
};