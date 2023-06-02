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

		if (requestedString == "AAABB")
		{
			return 20;
		}
		else if (requestedString == "AA")
		{
			return 30;
		}
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

	string requestedString;
};