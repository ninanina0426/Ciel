#pragma once


//template<class T> class テンプレートクラス名
template< class T> class Vector2template
{
public:
	Vector2template();
	Vector2template(T x, T y);
	~Vector2template();
	T x_;
	T y_;

	//代入演算子
	Vector2template& operator =(const Vector2template& vec);
	//添え字演算子
	int& operator[](int i);
	//単項演算子
	Vector2template& operator +=(const Vector2template& vec);
	Vector2template& operator -=(const Vector2template& vec);
	Vector2template& operator *=(const Vector2template& vec);
	Vector2template& operator /=(const Vector2template& vec);
	Vector2template& operator %=(const Vector2template& vec);
	Vector2template operator +()const;
	Vector2template operator -()const;

	//二項演算子
	Vector2template operator + (Vector2template vec);
	Vector2template operator - (Vector2template vec);
	Vector2template operator / (Vector2template vec);
	Vector2template operator * (Vector2template vec);
	Vector2template operator % (Vector2template vec);

	//比較演算子

	bool operator == (const Vector2template& vec)const;
	bool operator != (const Vector2template& vec)const;
	bool operator <= (const Vector2template& vec)const;
	bool operator >= (const Vector2template& vec)const;
	bool operator > (const Vector2template& vec)const;
	bool operator < (const Vector2template& vec)const;
};
template<class T>
Vector2template<T> operator * (const Vector2template<T>& vec,T num);
template<class T>
Vector2template<T> operator * ( T num, const Vector2template<T>& vec);


using Vector2 = Vector2template<int>;
using Vector2Flt = Vector2template<float>;
using Vector2Dbl = Vector2template<double>;

#include "./details/Vector2.h"
