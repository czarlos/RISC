/*
 * SGVector.h
 *
 *  Created on: Jan 2, 2014
 *      Author: jonno
 */

#ifndef SGVECTOR_H_
#define SGVECTOR_H_

namespace sge_base {


class SGVector {
public:
	float x;
	float y;

	SGVector();
	SGVector(float x0, float y0);

	virtual ~SGVector();

	bool operator==(const SGVector &v);
	bool operator!=(const SGVector &v);

	SGVector &operator=(const SGVector &v);

	const SGVector &operator-(void) const;

	const SGVector &operator+(const SGVector &v) const;
	const SGVector &operator-(const SGVector &v) const;
	const SGVector &operator*(const float num) const;
	const SGVector &operator/(const float num) const;

	const SGVector &operator+=(const SGVector &v);
	const SGVector &operator-=(const SGVector &v);
	const SGVector &operator/=(const float num);
	const SGVector &operator*=(const float num);

	float operator *(const SGVector &v) const;

	float length(void);
	float direction();

	void direction(float val);
	void length(float val);


	void normalize(void);
	void reflect(SGVector &v);
	void project(const SGVector &v);

	SGVector normalized();
	SGVector projected(const SGVector &v);
};

} /* namespace sge_base */

#endif /* SGVECTOR_H_ */
