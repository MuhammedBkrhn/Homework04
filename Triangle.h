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

	/* Ucgen olup olmad���n� kontrol eder.
	 * Bu fonksiyonun t�m yap�c�lar ve setter fonksiyonlar i�inde do�rudan/dolayl� olarak �a�r�lmas� zorunludur.
	 * E�er verilen de�erler bir ��gen olu�turmuyorsa invalid_argument exception f�rlat�lmal� ve bu bu exception kontrol edilmelidir
	 * Program sonland�r�lmamal�d�r.
	 */
	bool isValid() const;

	void printInfo() const noexcept;
	// Ekrana �unu basar:
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