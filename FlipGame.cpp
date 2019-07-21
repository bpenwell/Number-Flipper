#include <iostream>

using namespace std;

bool RunFlipGame(string input, string& output);

int main()
{
	string input;
	do
	{
		cout << endl << "Input the cards to test: ";
		cin >> input;

		if(input == "-1")
		{

		}
		else
		{
			string out;
			bool ret = RunFlipGame(input, out);
			if(ret == 1)
			{
				cout << "Solution is: ";
				for (int i = 0; i < out.size(); ++i)
				{
					cout << out[i];
					if(i != out.size() - 1)
					{
						cout << " -> ";
					}
				}
			}
			else
			{
				cout << "no solution" << endl;
			}
		}
	}while(1);
}

int FlippableCheck(string input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if(input[i] == '1')
		{
			return i;
		}
	}

	return -1;
}

bool RIGHTVALID(string input, int index)
{
	if(index == input.size() - 1)
	{
		return false;
	}

	return true;
}

bool LEFTVALID(string input, int index)
{
	if(index == 0)
	{
		return false;
	}

	return true;
}

void FlipCard(string& input, int index)
{
	input[index] = '.';

	if(LEFTVALID(input, index))
	{
		if(input[index-1] == '0')
		{
			input[index-1] = '1';
		}
	}

	if(RIGHTVALID(input, index))
	{
		if(input[index+1] == '0')
		{
			input[index+1] = '1';
		}		
	}
}

bool RunFlipGame(string input, string& output)
{
	int flipCardIndex = FlippableCheck(input);

	if(flipCardIndex != -1)
	{
		output.append(to_string(flipCardIndex));
		FlipCard(input, flipCardIndex);
		cout << "Updated Cards: " << input << endl;

		return RunFlipGame(input, output);
	}
	else
	{
		cout << "input: " << input << endl;
		for (int i = 0; i < input.size(); ++i)
		{
			if(input[i] == '0')
			{
				return false;
			}
		}
		return true;
	}
}