#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
    map<string, string> rules = {
        //ki kell tölteni
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
    };

    string text = "ababab";
    map<string, string>::iterator it;
    vector<vector<string>> piramis;

    for (int i = 0; i < text.length(); i++)
    {
        string textChar(1, text[i]);
        string ertek = rules.at(textChar);
        vector<string> sor;
        sor.push_back(ertek);
        piramis.push_back(sor);
    }

    for (int i = 1; i < piramis.size(); i++)
    {
        for (int j = 0; j < piramis.size() - i; j++)
        {
            string ujBetu;
            for (int k = 0; k < i; k++)
            {
                string bal = piramis[j][k];
                string jobb = piramis[j + k + 1][i - k - 1];
                string StringKeres;

                if (bal.find(",") == string::npos && jobb.find(",") == string::npos)
                {
                    StringKeres = bal + jobb;
                    it = rules.find(StringKeres);
                    if (it != rules.end())
                    {
                        if (ujBetu.empty())
                        {ujBetu.append(it->second);}
                        else
                        {ujBetu.append("," + it->second);}
                    }
                }
                else
                {
                    vector<string> elvalasztottBal;
                    vector<string> elvalasztottJobb;

                    stringstream baloldal(bal);
                    stringstream jobboldal(jobb);

                    string token;
                    while (getline(baloldal, token, ','))
                    {elvalasztottBal.push_back(token);}

                    while (getline(jobboldal, token, ','))
                    {elvalasztottJobb.push_back(token);}

                    for (int x = 0; x < elvalasztottBal.size(); x++)
                    {
                        for (int y = 0; y < elvalasztottJobb.size(); y++)
                        {
                            StringKeres = elvalasztottBal[x] + elvalasztottJobb[y];
                            it = rules.find(StringKeres);
                            if (it != rules.end())
                            {
                                if (ujBetu.empty())
                                {
                                    ujBetu.append(it->second);
                                }
                                else
                                {
                                    ujBetu.append("," + it->second);
                                }
                            }
                        }
                    }
                }
            }
            if (ujBetu.empty())
            {ujBetu.append("-");}

            piramis[j].push_back(ujBetu);
        }
    }

    int i = 0;
    int j = piramis[i].size() - 1;
    cout << string(j + 1, ' ');
    while (j >= 0)
    {

        cout << piramis[i][j] << " ";

        if (piramis[i].size() - 1 == j)
        {
            i = 0;
            j--;

            cout << endl;
            cout << string(j + 1, ' ');
        }
        else {i++;}
    }

    cout << endl;
    if (piramis[0][piramis[0].size() - 1] != "-")
    {cout << "LEVEZETHETŐ SZÓ" << endl;}
    else
    {cout << "NEM LEVEZETHETO SZÓ" << endl;}

    return 0;
}