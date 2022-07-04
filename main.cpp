#include <iostream>
#include <string>
using namespace std;

int bananas(int k, string matrix)
{
    //Second exception - if we have ony two connected vertices both are banana and father - return 2
    if(k == 2)
        return 2;

    auto* MatrixArray = new string[k];
    auto* bananass = new string[k];
    auto* rozneBanany = new string[k];
    int rozneBananyIndex = 0;
    int bananassIndex = 0;
    string split = "";
    int bananas = 0;
    int mIndex = 0;
    int fIndex = 0;
    int firstFatherS = 0;

    //Splitting and saving matrix to array
    for(unsigned int i = 0 ; i < matrix.length() ; i++)
    {
        if((i+1) % k != 0)
        {
            split += matrix[i];
        }
        else
        {
            split += matrix[i];
            MatrixArray[mIndex] = split;
            mIndex++;
            split = "";
        }
    }

    //Counting bananas and saving them to array bananass
    for(int i = 0; i < mIndex ; i++)
    {
        int OnesInLine = 0;
        for(int j = 0; j < k; j++)
        {
            if(MatrixArray[i][j] == '1')
                OnesInLine++;
        }
        if(OnesInLine == 1)
        {
            bananas++;
            bananass[bananassIndex] = MatrixArray[i];
            bananassIndex++;
        }
    }

    //Saving all different bananas to array
    for(int i = 0; i < bananassIndex; i++)
    {
        int found = 0;
        for(int j = 0; j < bananassIndex;j++)
        {
            if(bananass[i] == rozneBanany[j])
                found = 1;
        }

        if(found == 0)
        {
            rozneBanany[rozneBananyIndex] = bananass[i];
            rozneBananyIndex++;
        }
    }

    auto* fathers = new string[rozneBananyIndex];
    //Counting and saving all father to array
    for(int i = 0; i < rozneBananyIndex; i++)
    {
        for(int j = 0; j < k;j++)
        {
            if(rozneBanany[i][j] == '1')
            {
                fathers[fIndex] = MatrixArray[j];
                fIndex++;
            }
        }
    }
    //Checking if all fathers appeared the same number of times
    for(int i = 0; i < fIndex ; i ++)
    {
        int nextFatherS = 0;
        if(i == 0)
        {
            //Counting amount of connections to/from father
            for(int j = 0; j < k; j++)
            {
                if(fathers[i][j] == '1')
                    firstFatherS++;
            }
        }
        else
        {
            //Counting amount of connections to/from father
            for(int j = 0; j < k; j++)
            {
                if(fathers[i][j] == '1')
                    nextFatherS++;
            }
        }

        if(i > 0)
        {
            //If connections amount is not equal it isn't banana tree
            if( nextFatherS != firstFatherS)
            {
                bananas = 0;
                break;
            }
        }
    }
    //CONDITION 1 - Banana tree must have one or 0 roots - if 0 then father is root
    if(k - (fIndex + bananas) > 1)
        bananas = 0;
    //CONDITION 2 - There is only 1 root
    if((bananas + fIndex == k) && fIndex != 1)
        bananas = 0;
    delete[] rozneBanany;
    delete[] bananass;
    delete[] MatrixArray;
    delete[] fathers;

    return bananas;
}
int main() {
    int lines = 0;
    cin >> lines;
    int i = 0;
    int k;
    string m;
    while (i < lines)
    {
        cin >> k >> m;
        int result = bananas(k,m);
        if(result == 0)
            cout << result << " bananas :(" << endl;
        else
            cout << result << " bananas :)" << endl;
        i++;
    }
    return 0;
}