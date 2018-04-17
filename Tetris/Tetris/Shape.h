#pragma once
class Direction {
public:
	enum GlobalDirection { N = 1, E = 2 , S = -1, W = -2}; // North/East/South/West
	static GlobalDirection getOppositeDirection(const GlobalDirection & d);
};
using gDirection = Direction::GlobalDirection;

class Point {
private:
	short x;
	short y;
public:
	Point(short x, short y) : x(x), y(y) {}
	Point() : Point(0, 0) {}
	short & getx() { return x; }
	short & gety() { return y; }
	void setPoint(short x, short y);
	void movePoint(const gDirection & d);
};

class Shape {
public:
	static const short AMOUNT_OF_TYPES = 7;
	static const short AMOUNT_OF_POINTS = 4;
	enum Type { RED, LIGHT_GREY, CYAN, YELLOW, MAGENTA, BLUE, GREEN };
	enum Rotation { LEFT, RIGHT };
private:
	Type type;
	Point * points;
	char body;

	void movePoints(short x, short y);
public:
	Shape(Type type, char body, short x, short y, short x1, short y1, short x2, short y2, short x3, short y3);
	Shape(const Shape &) = delete;
	virtual ~Shape() { delete[] points; }
	Type getType() const { return type; }
	char & getBody() { return body; }
	Point & getPoint(int i) { return points[i]; }

	void rotate(Rotation r = Rotation::LEFT);
	void movePoints(const gDirection & d);

	static Type getRandomType();
};
namespace ConcreteShapes {
	class RedShape : public Shape {
	public:
		RedShape(short x, short y) : Shape(Shape::Type::RED, 'R', x, y, 0, 1, 0, 2, 0, 3) {}
	};
	class LightGreyShape : public Shape {
	public:
		LightGreyShape(short x, short y) : Shape(Shape::Type::LIGHT_GREY, 'L', x, y, -1, 0, 1, 0, 0, 1) {}
	};
	class CyanShape : public Shape {
	public:
		CyanShape(short x, short y) : Shape(Shape::Type::CYAN, 'C', x, y, 0, 1, 1, 0, 1, 1) {}
	};
	class YellowShape : public Shape {
	public:
		YellowShape(short x, short y) : Shape(Shape::Type::YELLOW, 'Y', x, y, 0, 1, 0, 2, 1, 2) {}
	};
	class MagentaShape : public Shape {
	public:
		MagentaShape(short x, short y) : Shape(Shape::Type::MAGENTA, 'M', x, y, 0, 1, 0, 2, -1, 2) {}
	};
	class BlueShape : public Shape {
	public:
		BlueShape(short x, short y) : Shape(Shape::Type::BLUE, 'B', x, y, 0, 1, -1, 1, 1, 0) {}
	};
	class GreenShape : public Shape {
	public:
		GreenShape(short x, short y) : Shape(Shape::Type::GREEN, 'G',x, y, 0, 1, -1, 1, 1, 0) {}
	};
}

class ShapeFactory {
public:
	static ShapeFactory * getInstance() {
		static ShapeFactory factory;
		return &factory;
	}
	Shape * getShape(short x, short y, Shape::Type type);
	Shape * getRandomShape(short x, short y);
private:
	ShapeFactory() {};
	ShapeFactory(ShapeFactory &) = delete;
};
