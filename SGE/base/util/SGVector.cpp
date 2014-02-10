#include <math.h>
#include "SGVector.h"

namespace sge_base {

SGVector::SGVector() : SGVector(0,0) {
}

sge_base::SGVector::SGVector(float x0, float y0) {
	x = x0;
	y = y0;
}

sge_base::SGVector::~SGVector() {
}

bool sge_base::SGVector::operator ==(const SGVector& v) {
	return x == v.x && y == v.y;
}

bool sge_base::SGVector::operator !=(const SGVector& v) {
	return x != v.x || y != v.y;
}

SGVector& sge_base::SGVector::operator =(const SGVector& v) {
	x = v.x;
	y = v.y;
	return *this;
}

const SGVector& sge_base::SGVector::operator -(void) const {
	return SGVector(-x, -y);
}

const SGVector& sge_base::SGVector::operator +(const SGVector& v) const {
	return SGVector(x + v.x, y + v.y);
}

const SGVector& sge_base::SGVector::operator -(const SGVector& v) const {
	return SGVector(x - v.x, y - v.y);
}

const SGVector& sge_base::SGVector::operator *(const float num) const {
	SGVector v = (*this);
	return v *= num;
}

const SGVector& sge_base::SGVector::operator /(const float num) const {
	SGVector v = (*this);
	return v /= num;
}

const SGVector& sge_base::SGVector::operator +=(const SGVector& v) {
	return SGVector(x + v.x, y + v.y);
}

const SGVector& sge_base::SGVector::operator -=(const SGVector& v) {
	return SGVector(x - v.x, y - v.y);
}

const SGVector& sge_base::SGVector::operator /=(const float num) {
	x /= num;
	y /= num;
	return *this;
}

const SGVector& SGVector::operator *=(const float num) {
	x *= num;
	y *= num;
	return *this;
}

float sge_base::SGVector::operator *(const SGVector& v) const {
	return v.x * x + v.y * y;
}

float sge_base::SGVector::length(void) {
	return (float) (sqrt(*this * *this));
}

float sge_base::SGVector::direction() {
	return atan2(y, x);
}

void sge_base::SGVector::direction(float val) {
	x = cos(val) * length();
	y = cos(val) * length();
}

void sge_base::SGVector::length(float val) {
	float dir = direction();
	x = cos(dir) * val;
	y = cos(dir) * val;
}

void sge_base::SGVector::normalize(void) {
	*this /= length();
}

void sge_base::SGVector::reflect(SGVector& v) {
	SGVector orig(*this);
	project(v);
	*this = ((*this * 2) - orig);
}

void sge_base::SGVector::project(const SGVector& v) {
	*this = v * (*this * v) / (v * v);
}

SGVector sge_base::SGVector::normalized() {
	return *this / length();
}

SGVector sge_base::SGVector::projected(const SGVector& v) {
	return v * (*this * v) / (v * v);
}

};
