#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"


TEST(TestCaseName, LengthSame)
{
	SimilarityChecker sc("ASD");
	EXPECT_EQ(60, sc.getLengthScore("DSA"));
}

TEST(TestCaseName, LengthDifferent)
{
	SimilarityChecker sc("A");
	EXPECT_EQ(0, sc.getLengthScore("BB"));
}

TEST(TestCaseName, LengthAlmostSame)
{
	SimilarityChecker sc("AAABB");
	EXPECT_EQ(20, sc.getLengthScore("BAA"));

	sc.setRequestedString("AA");
	EXPECT_EQ(30, sc.getLengthScore("AAA"));
}