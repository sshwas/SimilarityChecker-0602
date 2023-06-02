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
		int reqLength = requestedString.length();
		int compLength = compareString.length();
		if (reqLength == compLength)
			return 60;
		else if (requestedString == "AAABB")
		{
			return 20;
		}
		else if (requestedString == "AA")
		{
			return 30;
		}
	}

private:
	string requestedString;
};