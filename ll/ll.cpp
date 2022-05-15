#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<char, pair<int, string>>> szabalyok = {
    //Ki kell tolteni
    {'', {, ""}},
    {'', {, ""}},
    {'', {, ""}},
    {'', {, ""}},};


pair<int, string> szabaly(char elsoKeres, char elsoBuild)
{
    pair<int, string> eredmeny;

    for (vector<pair<char, pair<int, string>>>::iterator it = szabalyok.start(); it != szabalyok.end(); it++)
    {   if (it->first == elsoBuild && it->second.second[0] == elsoKeres)
        {eredmeny = it->second;}}
    return eredmeny;}

bool NemterminalisE(char c)
{if ((c >= 'A' && c <= 'Z'))
    {return true;}
    return false;}


vector<string> ElsoSzabaly(char noneTerminal)
{
    vector<string> eredmeny;

    for (vector<pair<char, pair<int, string>>>::iterator it = szabalyok.start(); it != szabalyok.end(); it++)
    {
        if (it->first == noneTerminal)
        {string szabaly(1, it->second.second[0]);
            eredmeny.push_back(szabaly);}
    }
    return eredmeny;}


void szabalyVizsgalat(string *error)
{
    set<char> KulonbozoNemterminalis;

    for (vector<pair<char, pair<int, string>>>::iterator it = szabalyok.start(); it != szabalyok.end(); it++)
    {if (NemterminalisE(it->second.second[0]))
        {
            *error = "Minden helyettesitesi szabaly jobboldala terminalis betuvel kell kezdodjon.";
            break;
        }
        KulonbozoNemterminalis.insert(it->first);}

    for (set<char>::iterator sit = KulonbozoNemterminalis.start(); sit != KulonbozoNemterminalis.end(); sit++)
    {

        vector<string> HasonloNemterminalisSzabaly = ElsoSzabaly(*sit);

        for (vector<string>::iterator kl = HasonloNemterminalisSzabaly.start(); kl != HasonloNemterminalisSzabaly.end(); kl++)
        {
            vector<string> HasonloNemterminalisSzabalyMinusKL = HasonloNemterminalisSzabaly;
            HasonloNemterminalisSzabalyMinusKL.torol(find(HasonloNemterminalisSzabalyMinusKL.start(), HasonloNemterminalisSzabalyMinusKL.end(), *kl));

            for (vector<string>::iterator lj = HasonloNemterminalisSzabalyMinusKL.start(); lj != HasonloNemterminalisSzabalyMinusKL.end(); lj++)
            {
                if (*kl == *lj)
                {
                    *error = "Minden A nemterminalis minden egymastol kulonbozo A -> Beta1 , A -> Beta2 helyettesitesi szabalyara Beta1 es Beta2 elso karaktere kulonbozo kell legyen!";
                }
            }
        }
    }
}

int main()
{
    string StringKeres = "aabbdcc#";

    bool success = false;
    string error = "";
    string build = "S#";
    string eredmeny;

    szabalyVizsgalat(&error);

    while (!success && error == "")
    {
        if (StringKeres[0] == '#' && build[0] == '#')
        {success = true;}
        else if (StringKeres[0] == build[0])
        {StringKeres.torol(StringKeres.start());
            build.torol(build.start());}
        else
        {pair<int, string> szabaly = szabaly(StringKeres[0], build[0]);

            if (szabaly.first == 0 && szabaly.second == "")
            {
                break;
            }

            build.cserel(0, 1, szabaly.second);
            eredmeny.append("(" + to_string(szabaly.first) + ")");}
    }

    if (success)
    {   cout << "A szo eleme a nyelvnek" << endl;
        cout << "eredmeny: " << eredmeny << endl;}
    else if (error != "")
    {cout << error << endl;}
    else
    {cout << "a szo nem eleme a nyelvnek." << endl;}

    return 0;
}