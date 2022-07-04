#include <iostream>

using namespace std;
int OutputArray[127];

bool isPrime(int a)
{
    bool ans= false;
    if (a == 0 || a == 1)
    {
        ans = false;
    }
    if (a == 2 || a == 3)
    {
        ans = true;
    }
    for(int i = 2 ; i <= a/2 ; ++i)
    {
        if (a % i == 0)
        {
            ans = false;
            break;
        }
        else
            ans =  true;
    }
    return ans;
}
void printArray(int index)
{
    for(int i = 0; i < index ; i++)
    {
        if (i+1 == index) cout << OutputArray[i];
        else cout << OutputArray[i] << "+";
    }
    cout << endl;
}
void primePartition(int numberToPartition, int firstElement, int index) // 27 17 -> (10, 17, 0)
{
    if(numberToPartition == 0)
    {
        printArray(index);
        return;
    }
    for (int i = 2 ; i <= firstElement ; i++)
    {
        if(!isPrime(i) || i > numberToPartition) continue;
        else if(i <= numberToPartition)
        {
            OutputArray[index] = i;
            primePartition(numberToPartition - i, i, index+1);
        }
    }
}
int main() {
    int n=0;
    int k=0;
    int lines=0;
    int index = 0;
    cin >> lines;
    int *InputArray = new int[lines*2];
    for (int i = 0 ; i < lines * 2 ; i = i + 2)
    {
        cin >> n >> k;
        if (!isPrime(k) || n < k)
        {
            InputArray[i] = InputArray[i+1] = 0;
        }
        else
        {
            InputArray[i] = n;
            InputArray[i+1] = k;
        }
    }
    for (int i = 0 ; i < (lines * 2) ; i = i + 2)
    {
        if (InputArray[i] == 0 || InputArray[i+1] == 0) continue;
        OutputArray[index] = InputArray[i+1];
        primePartition(InputArray[i] - InputArray[i+1], InputArray[i+1], index+1);
    }
    delete [] InputArray;
    return 0;
}
