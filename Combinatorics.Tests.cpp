#include "pch.h"
#include <iostream>
#include "../Combinatorics/Combinatorics.hpp"

TEST(CombinatoricsTests, CombinatoricsTest)
{
	LexPermute(3);
}

TEST(CombinatoricsTests, CombinatoricsTest2)
{
	PermTr(4);
}

TEST(CombinatoricsTests, CombinatoricsTest3)
{
	CodåGrey(3);
}

TEST(CombinatoricsTests, CombinatoricsTest4)
{
	std::vector<std::vector<bool>> result = CodeGreys(3);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
			std::cout << result[i][j];
		std::cout << std::endl;
	}
}