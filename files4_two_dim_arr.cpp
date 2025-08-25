#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    string in_text_buf;
    ifstream fin("in.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл." << endl;
        return EXIT_FAILURE;
    }
    fin >> in_text_buf;
    int rows = stoi(in_text_buf);
    fin >> in_text_buf;
    int cols = stoi(in_text_buf);

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols] {};
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            fin >> in_text_buf;
            if (in_text_buf == "\n")
                break;
            arr[i][j] = stoi(in_text_buf);
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }


    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;
    fin.close();
    return EXIT_SUCCESS;
}

