#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string coloring(int k, string m)
{
    auto* Array = new string [k];\
    int highestVertex = 0;
    int tempHighestVertex = 0;
    int isCompleteGraph = 1;
    int isCycleGraph = 1;
    int chromaticNumber = 0;
    string result;

    //Splitting matrix to Array and finding highest Vertex
    for(int i = 0; i < m.length(); i++)
    {
        //Finding highest vertex
        if(m[i] == '1')
            tempHighestVertex++; //
        if( (i+1) % k == 0)
        {
            //if isCompleteGraph != 1 there is no need to check next vertices
            if(isCompleteGraph == 1 && tempHighestVertex != (k - 1))
                isCompleteGraph = 0;

            if(tempHighestVertex != 2)
                isCycleGraph = 0;
            //Finding highest vertex
            if(tempHighestVertex > highestVertex)
                highestVertex = tempHighestVertex;
            tempHighestVertex = 0; //
        }
    }


    if( isCompleteGraph == 1)
        chromaticNumber = highestVertex + 1;
    if(isCycleGraph == 1 && k % 2 == 1)
        chromaticNumber = 3;
    else if( isCycleGraph == 1 && k % 2 == 0)
        chromaticNumber = 2;

    if((isCompleteGraph == 1  || isCycleGraph == 1 ) && chromaticNumber > highestVertex)
        result = "True";
    else
        result = "False";

    delete[] Array;
    return result;
}
int main() {
    int lines = 0;
    cin >> lines;
    int k = 0;
    for(int i = 0; i < lines ; i++)
    {
        scanf("%d", &k);
        char* m = new char[k*k];
        scanf("%s" , m);
        printf("%s\n", coloring(k,m).c_str());
        delete[] m;
    }
    return 0;
}