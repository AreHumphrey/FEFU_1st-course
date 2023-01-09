//Выполнить RLE Сжатие файла
#include <iostream>
#include <fstream>
using namespace std;

ofstream OutFILE("output.txt");

void FlushSame(int Len, char(&ArrA)[127])
{
    string OutPut = "1 " + to_string(Len) + " " + to_string(ArrA[0]);
    cout << OutPut << endl;
    OutFILE << OutPut << endl;
}
void FlushDiff(int Len, char(&ArrA)[127])
{
    string OutPut = "0 " + to_string(Len) + " ";
    cout << OutPut;
    OutFILE << OutPut;
    for(int i = 0; i < Len; i++)
    {
        OutPut = to_string(ArrA[i]) + " ";
        cout << OutPut;
        OutFILE << OutPut;
    }
    cout << endl;
    OutFILE << endl;
}

int main()
{
    ifstream InFile("input.txt");

    char Case [127]{0};
    int CountCase = 1;

    char SymbA = InFile.get();
    char SymbB = InFile.get();
    Case[0] = SymbA;
    bool StateCase = (SymbA == SymbB); // True - одинаковые. False - разные

    while(SymbB != '\377')
    {
        bool NowState = (SymbA == SymbB);
        if (NowState != StateCase && CountCase > 1)
        {
            if (StateCase)
            {
                FlushSame(CountCase, Case);
                StateCase = NowState;
                Case[0] = SymbB;
                if (StateCase)
                {
                    CountCase = 2;
                }
                else
                {
                    CountCase = 1;
                }
            }
            else
            {
                FlushDiff(CountCase - 1, Case);
                StateCase = NowState;
                Case[0] = SymbB;
                if (StateCase)
                {
                    CountCase = 2;
                }
                else
                {
                    CountCase = 1;
                }
            }
        }
        else
        {
            if (!StateCase)
            {
                Case[CountCase] = SymbB;
            }
            CountCase ++;
        }
        SymbA = SymbB;
        SymbB = InFile.get();


        if (CountCase == 127)
        {
            if(StateCase)
            {
                FlushSame(CountCase, Case);
                Case[0] = SymbB;
                CountCase = 1;
            }
            else
            {
                FlushDiff(CountCase, Case);
                Case[0] = SymbB;
                CountCase = 1;
            }
            SymbA = SymbB;
            SymbB = InFile.get();

        }
    }

    InFile.close();
    if (CountCase != 0)
    {
        if(StateCase)
        {
            FlushSame(CountCase, Case);
        }
        else
        {
            FlushDiff(CountCase, Case);
        }
    }

}
