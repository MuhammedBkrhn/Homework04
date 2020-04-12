#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color) :pts{a,b,c},color{color}
{
    this->isValid();
}

Triangle::Triangle(const vector<Point>& pts, const Color& color):pts{pts[0],pts[1],pts[2]},color{color}
{
	this->isValid();
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color) :pts{ pts }, color{ color }//pts{ pts[0],pts[1],pts[2] },color{ color }
{
	this->isValid();
}

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	if (color==Triangle::Color::PINK) { return "Pink";}
	if (color == Triangle::Color::RED) {return "Red";}
	if (color == Triangle::Color::BLUE) {return "Blue";}
	if (color == Triangle::Color::WHITE) {return "White";}
	if (color == Triangle::Color::BLACK) {return "Black";}
	if (color == Triangle::Color::GREEN) {return "Green";}
	else {return "";}
}

double Triangle::getPerimeter() const noexcept
{
		double side_ab = a.distanceTo(b);
		double side_ac = a.distanceTo(c);
		double side_bc = b.distanceTo(c);
		double perimeter = side_ab + side_ac + side_bc;
		return perimeter;
}

bool Triangle::setA(const Point& pt)
{
	Triangle triangle{ pt,b,c,color};
	if (triangle.isValid ()== true) {
		a.x = pt.x;
		a.y = pt.y;
		return true;
	}
	else {
		return false;
	}

	
}

bool Triangle::setB(const Point& pt)
{
	Triangle triangle{ a,pt,c,color };
	if (triangle.isValid() == true) {
		b.x = pt.x;
		b.y = pt.y;
		return true;
	}
	else {
		return false;
	}

}

bool Triangle::setC(const Point& pt)
{
	Triangle triangle{ a,b,pt,color };
	if (triangle.isValid() == true) {
		c.x = pt.x;
		c.y = pt.y;
		return true;
	}
	else {
		return false;
	}

}

bool Triangle::isValid() const
{
	double side_ab = a.distanceTo(b);
	double side_ac = a.distanceTo(c);
	double side_bc = b.distanceTo(c);

	if (side_ab > side_ac - side_bc && side_ab<side_ac + side_bc && side_ac>side_ab - side_bc && side_ac<side_ab + side_bc && side_bc>side_ab - side_ab && side_bc < side_ab + side_ac) {
		return true;
	}
	else {
		throw invalid_argument("Invalid Triangle");
		return false;
	}
}

void Triangle::printInfo() const noexcept
{
	cout << "Triangle" << endl;
	cout << "Number Of Points: " << NUMBER_OF_CORNERS<<endl;
	cout << "Points: " << "(" << a.x << "," << a.y << ")" <<","<< "(" << b.x << "," << b.y << ")" <<","<< "(" << c.x << "," << c.y << ")" << endl;
	cout << " Primeter: " << getPerimeter() << endl;
	cout << "Color: " << getColorAsString();
}

