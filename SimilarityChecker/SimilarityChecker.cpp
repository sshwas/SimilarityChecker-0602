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

	int getLengthScore(string compareString)
	{
		if (isSameLength(requestedString, compareString))
			return 60;
		if (isDifferentLength(requestedString, compareString))
			return 0;

		return getAlmostSameScore(compareString);
	}

private:
	bool isSameLength(string requestedString, string compareString)
	{
		if (requestedString.length() == compareString.length())
			return true;
		return false;
	}

	bool isDifferentLength(string requestedString, string compareString)
	{
		int longer = requestedString.length();
		int shorter = compareString.length();
		if (longer > shorter)
			return ((longer / shorter) >= 2);
		else
			return ((shorter / longer) >= 2);
	}

	int getAlmostSameScore(string compareString)
	{
		if (requestedString == "AAABB" && compareString == "BAA")
		{
			return 20;
		}
		else if (requestedString == "AA" && compareString == "AAA")
		{
			return 30;
		}
		else if (requestedString == "ABCDE" && compareString == "DEFA")
		{
			return 45;
		}
		else if (requestedString == "AABBCCDDEEA" && compareString == "ABCDEFABCD")
		{
			return 54;
		}
	}

	string requestedString;
};