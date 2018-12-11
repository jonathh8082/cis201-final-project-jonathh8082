#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void copy(vector<int> fromarr, vector< vector<int> > toarr, int indext)
{
    for (int i = 0; i <= fromarr[0]; i++)
    {
        toarr[indext][i] = fromarr[i];
    }
}

void copy(vector< vector<int> > fromarr, vector<int> toarr, int index)
{
    for (int i = 0; i <= fromarr[index][0]; i++)
    {
        toarr[i] = fromarr[index][i];
    }
}

int search(vector<string> array, int len, string target)
{
    for(int i = 0; i < len; i++)
    {
        if(array[i] == target) return i;
    }
    return -1;
}
void sort(vector<string> wordarray, vector<int> linecount, vector< vector<int> > linenumbersarray, int length)
{
    int minpos = 0;
    for(int i = 0; i < length; i++)
    {
        minpos = i;
        for(int j = 0; j < length; j++)
        {
            if(wordarray[j] > wordarray[minpos])
            string tempword = wordarray[i];
            int tempcount = linecount[i];
            vector<int> tempnums;
            copy(linenumbersarray, tempnums, i );
            
            wordarray[i] = wordarray[minpos];
            linecount[i] = linecount[minpos];
            copy(tempnums, linenumbersarray, minpos);
        }
    }
}
int main(int argc, char* argv[])
{
    vector<string> wordarray;
    vector<int> linecount;
    vector< vector<int> > linenumbersarry;
    int arrayposition = 0;
    int linenumber = 1;
    int wordlength = 0;

    ifstream infile;
    infile.open(argv[1]);

    string aline;
    while (getline(infile, aline))
    {
        istringstream theline(aline);
        string aword;
        
        while (theline >> aword)
        {
            int isupdated = search(wordarray, wordlength, aword);
            if (isupdated == -1)
            {
                wordarray[wordlength] = aword;
                linecount[wordlength] = 1;
                linenumbersarray[wordlength][0] = 1;
                linenumbersarray[wordlength][1] = linenumber;
                wordlength = wordlength +1;
            }
            else
            {
                linecount [isupdated] = linecount[isupdated] + 1;
                if (linenumbersarray[isupdated][linenumbersarray[isupdated][0]] != linenumber)
                    (linenumbersarry[isupdated][++linenumbersarry[isupdated][0]] = linenumber);
            }
        }
        linenumber = linenumber + 1;
    }
    sort(wordarray, linecount, linenumbersarry, wordlength);
    for (int i = 0; i < wordlength; i++)
    {
        ostringstream out;
        for (int j = 1; j <= linenumbersarry[i][0]; j++)
        {
            out << linenumbersarray[i][j];
            j != linenumbersarray[i][0] ? out << " " : out << ".";
        }
        cout << wordarray[i] << " occurs " << linecount [i] << " time(s) on lines " << out.str() << endl;

    }
}

