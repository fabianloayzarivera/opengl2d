#include <Vec2.h>

Vec2::Vec2(float xNew = 0, float yNew = 0) {
	x = xNew;
	y = yNew;
}

Vec2 Vec2::operator+(const Vec2& other) {
	Vec2 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	
	return ret;
}

Vec2 Vec2::operator-(const Vec2& other) {
	Vec2 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;

	return ret;
}

Vec2 Vec2::operator*(const Vec2& other) {
	Vec2 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;

	return ret;
}

Vec2 Vec2::operator/(const Vec2& other) {
	Vec2 ret;
	ret.x = x / other.x;
	ret.y = y / other.y;

	return ret;
}

Vec2 Vec2::abs() {
	Vec2 ret;
	if (x < 0)
		ret.x = x * -1;
	else
		ret.x = x;

	if (y < 0)
		ret.y = y * -1;
	else
		ret.y = y;

	return ret;

}

float Vec2::lenght() {
	return static_cast<float>(sqrt(powf(x, 2) + powf(y, 2)));
}

Vec2 Vec2::norm() {
	Vec2 ret;
	float len = this->lenght();
	ret.x = x / len;
	ret.y = y / len;

	return ret;
}

float Vec2::dot(const Vec2 &other){
	return ((x * other.x) + (y * other.y));
}

float Vec2::angle(const Vec2& other) const {
	return atanf((other.y - y) / (other.x - x));
}