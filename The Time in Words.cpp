#include <iostream>
#include <string>
#include <map>
using namespace std;

void evaluate(int H, int M)
{
	map<int, string> convert;
	convert[1] = "one";
	convert[2] = "two";
	convert[3] = "three";
	convert[4] = "four";
	convert[5] = "five";
	convert[6] = "six";
	convert[7] = "seven";
	convert[8] = "eigth";
	convert[9] = "nine";
	convert[10] = "ten";
	convert[11] = "eleven";
	convert[12] = "twelve";
	convert[13] = "thirteen";
	convert[14] = "fourteen";
	convert[15] = "fifteen";
	convert[16] = "sixteen";
	convert[17] = "seventeen";
	convert[18] = "eighteen";
	convert[19] = "nineteen";
	convert[20] = "twenty";


	if (M == 0)
		cout << convert[H] << " o' clock" << endl;
	else if (M > 0 && M <= 20 && M != 15)
		cout << convert[M] << " " << (M == 1 ? "minute" : "minutes") << " past " << convert[H] << endl;
	else if (M == 15)
		cout << "quarter past " << convert[H] << endl;
	else if (M > 20 && M < 30)
	{
		cout << convert[M - (M % 10)];
		if (M % 10 > 0)
			cout << " " << convert[M % 10];
		cout << " minutes past " << convert[H] << endl;
	}
	else if (M == 30)
		cout << "half past " << convert[H] << endl;
	else if (M > 30 && M < 45)
	{
		if (60 - M >= 20)
		{
			cout << convert[60 - M - ((60 - M) % 10)]; 
			if ((60 - M) % 10 > 0)
				cout << " " << convert[((60 - M) % 10)];
			cout << " " << (60 - M == 1 ? "minute" : "minutes") << " to " << convert[H + 1] << endl;
		}
		else 
			cout << convert[60 - M] << " " << (60 - M == 1 ? "minute" : "minutes") << " to " << convert[H + 1] << endl;
	}
	else if (M == 45)
		cout << "quarter to " << convert[H + 1] << endl;
	else if (M > 45 && M < 60)
		cout << convert[60 - M] << " " << (60 - M == 1 ? "minute" : "minutes") << " to " << convert[H + 1] << endl;
}

int main(int argc, char *argv[])
{
	int H, M;

	cin >> H >> M;
	evaluate(H, M);
	return 0;
}