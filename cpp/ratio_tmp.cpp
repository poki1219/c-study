#include	<iostream>
#include	<typeinfo>

template <int X, int Y>
struct GCD{
	static const int value = GCD<Y, X%Y>::value;
};

template <int X>
struct GCD<X, 0>{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio{
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};

template <typename R1, typename R2>
struct _Ratio_add{
	typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_add : _Ratio_add<R1, R2>:: type {};

template <typename R1, typename R2>
struct _Ratio_subtract{
	typedef Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_subtract: : _Ratio_subtract<R1, R2>::type {};

template <typename R1, typename R2>
struct _Ratio_mult{
	typedef Ratio<R1::num * R2::num, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_mult : _Ratio_mult <R1, R2>::type {};

int main(){
	typedef Ratio<2, 3> rat;
	typedef Ratio<3, 2> rat2;
	typedef Ratio_add<rat, rat2> rat3;

	std::cout << rat3::num << " / " << rat3::den << std::endl;

	return 0;
}


//typedef Ratio_add<rat, rat2> rat3;
//using rat3 = Ratio_add<rat, rat2> 같음
