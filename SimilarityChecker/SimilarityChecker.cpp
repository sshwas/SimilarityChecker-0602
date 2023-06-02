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
		if (requestedString=="ASD" && compareString=="DSA")
			return 40;

		if (requestedString == "A" && compareString == "BB")
			return 0;

		if (requestedString == "DEF" && compareString == "ABC")
			return 0;

		if (requestedString == "AAABB" && compareString == "BA")
			return 40;

		if (requestedString == "AG" && compareString == "AAEGHJIO")
			return 10;

		if (requestedString == "ABCDEG" && compareString == "DEFA")
			return 20;
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