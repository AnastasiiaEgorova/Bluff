#pragma once

namespace Category
{
	enum Type
	{
		None				= 0,			// 000000000
		Table				= 1 << 0,
		Board				= 2 << 0,		// 000000001
		Dice				= 3 << 0,
		Button				= 4 << 0,
	};
}