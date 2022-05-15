#include "ctype.h"
#include "string"
#include "vector"
#include "iostream"
#include "map"

using namespace std;

bool findit(vector<string> v, string search)
{
	for (string s : v)
	{if (s == search)
	return true;}

	return false;}

int main()
{
	string rule = "", nonterminal = "", terminal = "", storage = "", word = "", word2 = "", copy = "";
	int i = 0, storage_char = 0;
	multimap<string, string> rules;
	multimap<string, string>::iterator position;
	vector<string> result, notAResult, solve;
	bool found = false;

	cout << "insert rules without white scpaces!" << endl << "when done, type 'done' "<< endl;

	while (cin >> rule)
	{
		if (rule == "done")
			break;

		nonterminal = "";
		terminal = "";
		i = 0;

		while (rule[i] != '-' && rule[i + 1] != '>')
		{nonterminal = nonterminal + rule[i];
			i++;}

		i = i + 2;

		while (i < rule.size())
		{terminal = terminal + rule[i];
			i++;}

		storage = storage + nonterminal;
		storage_char = 0;

		for (char c : storage)
		{if (c == nonterminal[0])
				storage_char++;}

		rules.insert(pair<string, string>(nonterminal + to_string(storage_char), terminal));
	}

	cout << endl << "given rules: " << endl;

	for (position = rules.begin(); position != rules.end(); position++)
	{cout << position->first << " -> " << position->second << endl;}

	cout << endl << "Give me a word!" << endl;
	cin >> word;
	cout << endl;
	word2 = word;

	solve.push_back("S");

	while (word2.size() != 0)
	{
		while (solve[solve.size() - 1][0] == word2[0] && word2.size() != 0)
		{solve[solve.size() - 1].erase(solve[solve.size() - 1].begin());
        word2.erase(word2.begin());}

		found = false;

		for (position = rules.begin(); position != rules.end(); position++)
		{
			if (position->first[0] == solve[solve.size() - 1][0])
			{
				copy = solve[solve.size() - 1];

				copy = copy.replace(0, 1, position->second);

				if (!findit(notAResult, copy))
				{
					found = true;

					solve.push_back(copy);
					result.push_back(position->first);
				}
			}
		}

		if (!found && word2.size() != 0)
		{if (solve.size() == 1)
			{
				cout << endl << "Given '" << word << "' not solveable! " << endl;

				return 0;
			}
			notAResult.push_back(solve[solve.size() - 1]);

			solve.pop_back();
			result.pop_back();}
	}

	cout << endl << "Given '" << word << "' not solveable! Left solve: " << endl;
	for (string s : result)
	{cout << s << " ";}

	cout << endl;

	return 0;
}