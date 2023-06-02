#include <string>
using namespace std;

class SimilarityChecker
{
public:
	SimilarityChecker(string str) : requestedString(str)
	{}

	void setRequestedString(string str)
	{
		requestedString = str;
	}

	int getLengthScore(const string& compareString)
	{
		if (isSameLength(compareString))
			return MAX_LENGTH_SCORE;
		if (isBigDifferentLength(compareString))
			return 0;

		return getAlmostSameScore(compareString);
	}

	int getAlphaScore(const string& compareString)
	{
		int totalAlphaCount = getTotalAlphaCount(compareString);
		int sameAlphaCount = getSameAlphaCount(compareString);

		if (isAllSameAlpha(sameAlphaCount, compareString))
			return MAX_ALPHA_SCORE;
		if (sameAlphaCount == 0)
			return 0;
				
		int score = sameAlphaCount * 40 / totalAlphaCount;
		return score;
	}

private:
	bool isSameLength(const string& compareString)
	{
		if (requestedString.length() == compareString.length())
			return true;
		return false;
	}

	bool isBigDifferentLength(const string& compareString)
	{
		int reqLength = requestedString.length();
		int compareLength = compareString.length();
		if (reqLength > compareLength)
			return ((reqLength / compareLength) >= 2);
		else
			return ((compareLength / reqLength) >= 2);
	}

	int getAlmostSameScore(const string& compareString)
	{
		int longer, shorter;
		if (requestedString.length() > compareString.length())
			longer = requestedString.length(), shorter = compareString.length();
		else
			longer = compareString.length(), shorter = requestedString.length();

		int gap = longer - shorter;
		int score = 60 - (60 * gap / shorter);
		return score;
	}

	bool isAllSameAlpha(const int sameAlphaCount, const string& compareString)
	{
		if (sameAlphaCount == compareString.length() && sameAlphaCount == requestedString.length())
			return true;
		return false;
	}

	int getTotalAlphaCount(const string& compareString)
	{
		int totalAlphaCount = 0;
		char alphaCount[128] = { 0, };
		for (int i = 0; i < requestedString.length(); ++i)
			alphaCount[requestedString[i]]++;
		for (int i = 0; i < compareString.length(); ++i)
			alphaCount[compareString[i]]++;
		for (int i = 65; i < 128; ++i)
			if (alphaCount[i])
				totalAlphaCount++;

		return totalAlphaCount;
	}

	int getSameAlphaCount(const string& compareString)
	{
		int sameAlphaCount = 0;
		for (int i = 0; i < compareString.length(); i++)
		{
			int index = requestedString.find(compareString[i]);
			if (index == -1) continue;
			sameAlphaCount++;
		}
		return sameAlphaCount;
	}

	const int MAX_LENGTH_SCORE = 60;
	const int MAX_ALPHA_SCORE = 40;
	string requestedString;
};