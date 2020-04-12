#include <iostream>
#include <vector>
#include<random>
#include<ctime>
#include<algorithm>
#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* 
   Triangle nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle>& v, int numberOfItems = 100)
{
		default_random_engine engine(static_cast<unsigned int>(time(0)));
		uniform_real_distribution <double> pointRandom(0, numberOfItems); //0-100 arasi sayilar olusturur.
		uniform_int_distribution <int> colorRandom(0, 5);
		int randColor = colorRandom(engine);

		for (auto i = 0; i < numberOfItems; ++i) {
			Point point_a;
			point_a.x = pointRandom(engine);
			point_a.y = pointRandom(engine);

			Point point_b;
			point_b.x = pointRandom(engine);
			point_b.y = pointRandom(engine);

			Point point_c;
			point_c.x = pointRandom(engine);
			point_c.y = pointRandom(engine);

			Triangle::Color color;
			if (randColor == 0) { color = Triangle::Color::PINK; }
			if (randColor == 1) { color = Triangle::Color::RED; }
			if (randColor == 2) { color = Triangle::Color::BLUE; }
			if (randColor == 3) { color = Triangle::Color::WHITE; }
			if (randColor == 4) { color = Triangle::Color::BLACK; }
			if (randColor == 5) { color = Triangle::Color::GREEN; }

			Triangle triangle{ point_a,point_b,point_c,color };
			v.push_back(triangle);
		}
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* 
   Quadrilateral nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral>& v, int numberOfItems = 100)
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_real_distribution <double> pointRandom(0, numberOfItems); //0-100 arasi sayilar olusturur.
	uniform_int_distribution <int> colorRandom(0, 4);
	int randColor = colorRandom(engine);

	for (auto i = 0; i < numberOfItems; ++i) {
		Point point_a;
		point_a.x = pointRandom(engine);
		point_a.y = pointRandom(engine);

		Point point_b;
		point_b.x = pointRandom(engine);
		point_b.y = pointRandom(engine);

		Point point_c;
		point_c.x = pointRandom(engine);
		point_c.y = pointRandom(engine);

		Point point_d;
		point_d.x = pointRandom(engine);
		point_d.y = pointRandom(engine);

		Quadrilateral::Color color;
		if (randColor == 0) { color = Quadrilateral::Color::RED; }
		if (randColor == 1) { color = Quadrilateral::Color::BLUE; }
		if (randColor == 2) { color = Quadrilateral::Color::WHITE; }
		if (randColor == 3) { color = Quadrilateral::Color::BLACK; }
		if (randColor == 4) { color = Quadrilateral::Color::GREEN; }

		Quadrilateral quadrilateral{ point_a,point_b,point_c,point_d,color };
		v.push_back(quadrilateral);
	}
	
}

/* Verilen Triangle veya Rectangle vektörününde çevre uzunluðu ve renk deðeri eþleþen ilk elemanýn indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template <class T>
int search(const vector<T>& v, const T& key)
{
	int size = v.size();
	for (auto i = 0; i < size; ++i) {
		if (v[i].getPerimeter() == key.getPerimeter() && v[i].getColor() == key.getColor()) {
			return i;
			break;
		}
	}
	return -1;
}

template<class T>
int sortByPerimeter(vector<T>& v)
{
	//sort(v.begin().getPerimeter(), v.end().getPerimeter());
	int size = v.size();
	T sortT;
	for (auto i = 0; i < size-1; ++i)
	{
		for (auto j = i+1; j < size; ++j)
		{
			if (v[j].getPerimeter() < v[i].getPerimeter())
			{
				sortT= v[i];
				v[i]= v[j];
				v[j] = sortT;
			}
		}
	}
}

int main()
{

	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 ,Quadrilateral::Color::BLACK};
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15),Triangle::Color::RED};
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	// Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};

	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	sampleTriangle.printInfo();
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	 sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	sampleTriangle.printInfo();
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0},Triangle::Color::RED };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} ,Triangle::Color::RED };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14},Triangle::Color::RED };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} ,Quadrilateral::Color::BLACK };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0},Quadrilateral::Color::BLACK };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} ,Quadrilateral::Color::BLACK };
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}