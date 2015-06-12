#include "LexicalAnalysis.h"

int main(int argc, char argv[])
{
	string fileName;
	while (1)
	{
		cout << "please input the file name:";
		cin >> fileName;
		LexicalAnalysis la(fileName.c_str());
		if (!la.Analyze())
			continue;
		la.Print();
	}

	system("puase");
	return true;
}