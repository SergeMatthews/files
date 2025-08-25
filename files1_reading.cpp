#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    string word;
    ifstream fin("in.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл." << endl;
        return EXIT_FAILURE;
    }
    while (!fin.eof())
    {
        fin >> word;
        cout << word << endl;
    }
    
    fin.close();
    return EXIT_SUCCESS;
}


