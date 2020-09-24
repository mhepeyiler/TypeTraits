#ifndef TYPETRAITS_H_
#define TYPETRAITS_H_

namespace TT {

	template<typename T, T arg>
	struct IntegralConstants
	{
		static constexpr T value{ arg };
		using ValueType = T;
		using Type = IntegralConstants;
		constexpr operator ValueType() const noexcept { return value; }
		constexpr ValueType operator()() const noexcept { return value; }
	};

	using TrueType = IntegralConstants<bool, true>;
	using FalseType = IntegralConstants<bool, false>;

	constexpr bool TrueType_v = TrueType::value;
	constexpr bool FalseType_v = FalseType::value;

	/********Const-Volatiliy Specifiers*********/

	template<typename T> struct RemoveCV { using Type = T; };
	template<typename T> struct RemoveCV<const T> { using Type = T; };
	template<typename T> struct RemoveCV<volatile T> { using Type = T; };
	template<typename T> struct RemoveCV<const volatile T> { using Type = T; };

	template<typename T> struct RemoveConst { using Type = T; };
	template<typename T> struct RemoveConst<const T> { using Type = T; };

	template<typename T> struct RemoveVolatile { using Type = T; };
	template<typename T> struct RemoveVolatile<volatile T> { using Type = T; };

	template<typename T> using RemoveCV_t = typename RemoveCV<T>::Type;
	template<typename T> using RemoveConst_t = typename RemoveConst<T>::Type;
	template<typename T> using RemoveVolatile_t = typename RemoveVolatile<T>::Type;


	template<typename T> struct AddCV { using Type = const volatile T; };
	template<typename T> struct AddCV<const T> { using Type = volatile T; };
	template<typename T> struct AddCV<volatile T> { using Type = const T; };
	template<typename T> struct AddCV<const volatile T> { using Type = T; };

	template<typename T> struct AddConst { using Type = const T; };
	template<typename T> struct AddConst<const T> { using Type = T; };

	template<typename T> struct AddVolatile { using Type = volatile T; };
	template<typename T> struct AddVolatile<volatile T> { using Type = T; };

	template<typename T> using AddCV_t = typename AddCV<T>::Type;
	template<typename T> using AddConst_t = typename AddConst<T>::Type;
	template<typename T> using AddVolatile_t = typename AddVolatile<T>::Type;

	/****************Type Properties*********************/

	template<typename T>
	struct IsConst : FalseType {};

	template<typename T>
	struct IsConst<const T> : TrueType {};

	template<typename T>
	constexpr bool IsConst_v = IsConst<T>::value;

	template<typename T>
	struct IsVolatile : FalseType{};

	template<typename T>
	struct IsVolatile<volatile T> : TrueType{};

	template<typename T>
	constexpr bool IsVolatile_v = IsVolatile<T>::value;


	template<typename T, typename U>
	struct IsSame : FalseType {	};
		
	template<typename T>	
	struct IsSame<T, T> : TrueType {};

	template<typename T, typename U>
	constexpr bool IsSame_v = IsSame<T, U>::value;

	template<typename T>
	struct IsInteger : FalseType {};

	template<>
	struct IsInteger<int> : TrueType {};
	
	template<typename T>
	constexpr bool IsInteger_v = IsInteger<T>::value;

}


#endif
