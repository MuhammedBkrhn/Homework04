#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color):pts{a,c},color{color}
{
	this->isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color):pts{a},color{color}
{
	width = c.x - a.x;
	height = a.y - c.y;
	this->isValid();
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
	:pts{pts[0],pts[1],pts[2],pts[3]},color{color} //pts{pts}||pts{a,b,c,d}
{
	this->isValid();
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color):pts{pts},color{color}//pts{a,b,c,d}
{
	this->isValid();
}

Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	if (color == Quadrilateral::Color::RED) { return "Red"; }
	if (color == Quadrilateral::Color::BLUE) { return "Blue"; }
	if (color == Quadrilateral::Color::WHITE) { return "White"; }
	if (color == Quadrilateral::Color::BLACK) { return "Black"; }
	if (color == Quadrilateral::Color::GREEN) { return "Green"; }
	else { return "";}
}

double Quadrilateral::getPerimeter() const noexcept
{
	double side_ab = a.distanceTo(b);
	double side_ad = a.distanceTo(d);
	double perimeter = 2 * (side_ab + side_ab);
	return perimeter;
}

bool Quadrilateral::isValid() const
{
	double m1 = (b.y - a.y) / (b.x - a.x);
	double m2 = (b.y - c.y) / (b.x - c.x);
	double m3 = (d.y - a.y) / (d.x - a.x);
	double m4 = (d.y - c.y) / (d.x - c.x);

	if (m1 * m2 == -1 && m2 * m4 == -1 && m3 * m4 == -1) {
		return true;
	}
	else {
		throw invalid_argument("Invalid Quadrilateral");
		return false;
	}
}

bool Quadrilateral::setA(const Point& pt)
{
	Quadrilateral quadrilateral{ pt,b,c,d,color };
	if (quadrilateral.isValid() == true) {
		a.x = pt.x;
		a.y = pt.y;
		return true;
	}
	else {
		return false;
	}
}

bool Quadrilateral::setB(const Point& pt)
{
	Quadrilateral quadrilateral{ a,pt,c,d,color };
	if (quadrilateral.isValid() == true) {
		b.x = pt.x;
		b.y = pt.y;
		return true;
	}
	else {
		return false;
	}
}

bool Quadrilateral::setC(const Point& pt)
{
	Quadrilateral quadrilateral{ a,b,pt,d,color };
	if (quadrilateral.isValid() == true) {
		c.x = pt.x;
		c.y = pt.y;
		return true;
	}
	else {
		return false;
	}
}

bool Quadrilateral::setD(const Point& pt)
{
	Quadrilateral quadrilateral{ a,b,c,pt,color };
	if (quadrilateral.isValid() == true) {
		d.x = pt.x;
		d.y = pt.y;
		return true;
	}
	else {
		return false;
	}
}

void Quadrilateral::printInfo() const noexcept
{
	cout << "Rectangle" << endl;
	cout << " Number of points: " << NUMBER_OF_CORNERS<<endl;
	cout << "(" << a.x << "," << a.y << ")" << "," << "(" << b.x << "," << b.y << ")" << "," << "(" << c.x << "," << c.y << ")" << "," << "(" << d.x << "," << d.y << ")" << endl;
	cout << "Priperhal: " << getPerimeter()<<endl;
	cout << "Color: " <<getColorAsString();
}


















