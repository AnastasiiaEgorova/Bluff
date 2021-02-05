#pragma once

namespace Category
{
	enum Type
	{
		None				= 0,			// 000000000
		Board				= 1 << 0,		// 000000001
		EverythingElse		= 2 << 0,
	};
}