#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int arr_size = 0;
    cout << "Введите размер массива: ";
    cin >> arr_size;
    int* arr = new int[arr_size] {};
    for (int i = 0; i < arr_size; ++i)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    ofstream fout("out.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
        return EXIT_FAILURE;
    }
    fout << arr_size << endl;
    for (int i = arr_size - 1; i >= 0; --i)
    {
        fout << arr[i] << ' ';
    }
    
    delete[] arr;
    fout.close();
    return EXIT_SUCCESS;
}

