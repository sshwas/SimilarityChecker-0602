#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"


TEST(TestCaseName, LengthChecker)
{
	SimilarityChecker sc("ASD");
	EXPECT_EQ(60, sc.getLengthScore("DSA"));

	sc.setRequestedString("A");
	EXPECT_EQ(0, sc.getLengthScore("BB"));
}