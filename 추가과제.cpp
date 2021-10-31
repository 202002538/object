#include <iostream>

class Shape {
public:
	void draw() {}
};

class RoundedRectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method.";
	}
};

class RoundedSquare : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method.";
	}
};

class Rectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method.";
	}
};

class Square : public Shape {
public:
	void draw() {
		std::cout << "Inside Square::draw() method.";
	}
};

class AbstractFactory {
public:
	virtual Shape getShape(std::string shapeType) {};
};

class ShapeFactory : public AbstractFactory {
public:
	Shape getShape(std::string shapeType) override{
		if (shapeType._Equal("RECTANGLE")) {
			return Rectangle();
		}
		else if (shapeType._Equal("SQUARE")) {
			return Square();
		}
		
	}
};

class RoundedShapeFactory : public AbstractFactory {
public:
	Shape getShape(std::string shapeType) override{
		if (shapeType._Equal("RECTANGLE")) {
			return RoundedRectangle();
		}
		else if (shapeType._Equal("SQUARE")) {
			return RoundedSquare();
		}
		
	}
};

class FactoryProducer {
public:
	static AbstractFactory getFactory(bool rounded) {
		if (rounded) {
			return RoundedShapeFactory();
		}
		else {
			return ShapeFactory();
		}
	}
};

int main() {
		AbstractFactory shapeFactory = FactoryProducer().getFactory(false);
		Shape shape1 = shapeFactory.getShape("RECTANGLE");
		shape1.draw();
		Shape shape2 = shapeFactory.getShape("SQUARE");
		AbstractFactory shapeFactory1 = FactoryProducer().getFactory(true);
		shape2.draw();
		Shape shape3 = shapeFactory1.getShape("RECTANGLE");
		shape3.draw();
		Shape shape4 = shapeFactory1.getShape("SQUARE");
		shape4.draw();
}


