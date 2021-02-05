#pragma once

namespace Category
{
	enum Type
	{
		None				= 0,			// 000000000
		Table				= 1 << 0,
		Board				= 2 << 0,		// 000000001
		EverythingElse		= 3 << 0,
	};
}