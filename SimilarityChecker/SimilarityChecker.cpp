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
		if (requestedString.length() == compareString.length())
			return 60;
		else
			return 0;
	}

private:
	string requestedString;
};