#include "..//Vector2.h"

template<class T>
Vector2template<T>::Vector2template()
{
	x_ = 0;
	y_ = 0;
}

template<class T>
Vector2template<T>::~Vector2template()
{

}
template<class T>
Vector2template<T>::Vector2template(T x, T y)
{
	Vector2template<T>::x_ = x;
	Vector2template<T>::y_ = y;
}

template<class T>
Vector2template<T>& Vector2template<T>::operator=(const Vector2template<T>& vec)
{
	x_ = vec.x_;
	y_ = vec.y_;
	return *this;
}
template<class T>
int& Vector2template<T>::operator[](int i)
{
	/*if (i == 0 || i >= 2)
	{
		return x_;
	}
	if (i == 1)
	{
		return y_;
	}*/
	
	switch (i)
	{
	case 0:
		return x_;
		//break;
	case 1:
		return y_;
		//break;
	default:
		return x_;
		//break;
	}
}

template<class T>
Vector2template<T>& Vector2template<T>::operator+=(const Vector2template<T>& vec)
{
	x_ += vec.x_;
	y_ += vec.y_;

	return *this;
	
}

template<class T>
Vector2template<T>& Vector2template<T>::operator-=(const Vector2template<T>& vec)
{
	x_ -= vec.x_;
	y_ -= vec.y_;

	return *this;
}

template<class T>
Vector2template<T>& Vector2template<T>::operator*=(const Vector2template<T>& vec)
{
	x_ *= vec.x_;
	y_ *= vec.y_;

	return *this;
}

template<class T>
Vector2template<T>& Vector2template<T>::operator/=(const Vector2template<T>& vec)
{
	if (vec.x_)
	{
		x_ /= vec.x_;
	}
	else
	{
		x_ = 0;
	}
	if (vec.y_)
	{
		y_ /= vec.y_;
	}
	else
	{
		y_ = 0;
	}

	return *this;
}

template<class T> 
Vector2template<T>& Vector2template<T>::operator%=(const Vector2template<T>& vec)
{
	if (vec.x_)
	{
		x_ %= vec.x_;
	}
	else
	{
		x_ = 0;
	}
	if (vec.y_)
	{
		y_ %= vec.y_;
	}
	else
	{
		y_ = 0;
	}
	return *this;
}

template<class T>
Vector2template<T> Vector2template<T>::operator+() const
{
	return *this;
}

template<class T>
Vector2template<T> Vector2template<T>::operator-() const
{
	return  Vector2template<T>{ -x_,-y_ };
}

template<class T>
Vector2template<T> Vector2template<T>::operator+(Vector2template<T> vec)
{
	return Vector2template<T>{ x_ + vec.x_,y_ + vec.y_ };
}

template<class T>
Vector2template<T> Vector2template<T>::operator-(Vector2template<T> vec)
{
	return Vector2template<T>{ x_ - vec.x_,y_ - vec.y_ };
}

template<class T>
Vector2template<T> Vector2template<T>::operator/(Vector2template<T> vec)
{
	return Vector2template<T>{ x_ / vec.x_,y_ / vec.y_ };
}

template<class T>
Vector2template<T> Vector2template<T>::operator*(Vector2template<T> vec)
{
	return Vector2template<T>{ x_ * vec.x_,y_ * vec.y_ };
}

template<class T>
Vector2template<T> Vector2template<T>::operator%(Vector2template<T> vec)
{
	return Vector2template<T>{ x_ % vec.x_,y_ % vec.y_ };
}
template<class T>
bool Vector2template<T>::operator==(const Vector2template<T>& vec) const
{
	return (x_ == vec.x_ && y_ == vec.y_);
}
template<class T>
bool Vector2template<T>::operator!=(const Vector2template<T>& vec) const
{
	return !(x_ == vec.x_ && y_ == vec.y_);
}
template<class T>
bool Vector2template<T>::operator<=(const Vector2template<T>& vec) const
{
	return (x_ <= vec.x_ && y_ <= vec.y_);
}
template<class T>
bool Vector2template<T>::operator>=(const Vector2template<T>& vec) const
{
	return (x_ >= vec.x_ && y_ >= vec.y_);
}
template<class T>
bool Vector2template<T>::operator>(const Vector2template<T>& vec) const
{
	return (x_ > vec.x_&& y_ > vec.y_);
}
template<class T>
bool Vector2template<T>::operator<(const Vector2template<T>& vec) const
{
	return (x_ < vec.x_ && y_ < vec.y_);
}



template<class T>
Vector2template<T> operator*(const Vector2template<T>& vec, T num)
{
	return Vector2template<T>{ vec.x_ * num,vec.y_ * num };
}

template<class T>
Vector2template<T> operator*(T num, const Vector2template<T>& vec)
{
	return Vector2template<T>{ num * vec.x_,num * vec.y_ };
}




