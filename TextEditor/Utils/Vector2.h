#pragma once
#include <string>
#include <iostream>

class Vector2
{
public:
	int x, y;
	
	Vector2(): x(0), y(0) {}
	Vector2(int x, int y) : x(x), y(y) {}
	
	~Vector2() {}

	Vector2 operator+ (const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator- (const Vector2& other) {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator* (int coef) {
		return Vector2(x * coef, y * coef);
	}

	bool operator== (const Vector2& other) {
		return (x == other.x && y == other.y);
	}

	std::string to_str() const {
		return std::to_string(x) + ", " + std::to_string(y);
	}

private:
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		return os << vector.to_str();
	}
};