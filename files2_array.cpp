#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream fin("in.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл." << endl;
        return EXIT_FAILURE;
    }
    
    int arr_size = 0;
    string in_text_buf;
    fin >> in_text_buf;
    arr_size = stoi(in_text_buf);

    int* arr = new int[arr_size] {};
    for (int i = 0; i < arr_size; ++i)
    {
        if (!fin.eof())
        {
            fin >> in_text_buf;
            arr[i] = stoi(in_text_buf);
        }
    }

    for (int i = arr_size - 1; i >= 0; --i)
        cout << arr[i] << ' ';
    cout << endl;

    delete[] arr;
    fin.close();
    return EXIT_SUCCESS;
}

