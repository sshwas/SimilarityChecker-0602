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
			return 60;
		if (isBigDifferentLength(compareString))
			return 0;

		return getAlmostSameScore(compareString);
	}

	int getAlphaScore(const string& compareString)
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

		int sameAlphaCount = 0;
		for (int i = 0; i < compareString.length(); i++)
		{
			int index = requestedString.find(compareString[i]);
			if (index == -1) continue;
			sameAlphaCount++;
		}

		if (sameAlphaCount == compareString.length() && sameAlphaCount == requestedString.length())
			return 40;

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

	string requestedString;
};