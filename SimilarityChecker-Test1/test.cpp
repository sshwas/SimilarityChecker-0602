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

	sc.setRequestedString("AAABCDEFGHI");
	EXPECT_EQ(0, sc.getLengthScore("ABC"));
}

TEST(TestCaseName, LengthAlmostSame)
{
	SimilarityChecker sc("AAABB");
	EXPECT_EQ(20, sc.getLengthScore("BAA"));

	sc.setRequestedString("AA");
	EXPECT_EQ(30, sc.getLengthScore("AAA"));

	sc.setRequestedString("ABCDE");
	EXPECT_EQ(45, sc.getLengthScore("DEFA"));

	sc.setRequestedString("AABBCCDDEEA");
	EXPECT_EQ(54, sc.getLengthScore("ABCDEFABCD"));
}

TEST(TestCaseName, AlphaSame)
{
	SimilarityChecker sc("ASD");
	EXPECT_EQ(40, sc.getAlphaScore("DSA"));
}

TEST(TestCaseName, AlphaDifferent)
{
	SimilarityChecker sc("A");
	EXPECT_EQ(0, sc.getAlphaScore("BB"));

	sc.setRequestedString("DEF");
	EXPECT_EQ(0, sc.getAlphaScore("ABC"));
}

TEST(TestCaseName, AlphaAlmostSame)
{
	SimilarityChecker sc("AAABB");
	EXPECT_EQ(40, sc.getAlphaScore("BA"));

	sc.setRequestedString("AG");
	EXPECT_EQ(10, sc.getAlphaScore("AAEGHJIO"));

	sc.setRequestedString("ABCDEG");
	EXPECT_EQ(20, sc.getAlphaScore("DEFA"));
}