#include <iostream>
#include "TypeTraits.h"


int main()
{
	constexpr auto IC = TT::IsConst_v<const int>;
	constexpr auto IV = TT::IsVolatile_v<volatile int>;
	constexpr auto IS = TT::IsSame_v<int, int>;
	constexpr auto II = TT::IsInteger_v<int>;

  return 0;
}
