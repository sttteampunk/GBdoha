#include <fstream>
#include <cmath>
#include <iostream>
#include <string>


using namespace std;

int** Create(size_t n, size_t m) {
    int** M = new int* [n];
    for (size_t i = 0; i < n; ++i) {
        M[i] = new int[m];
    }
    return M;
}

void Free(int** M, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        delete[] M[i];
    }
    delete[] M;
}

void Input(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
           cout << "M[" << i << "][" << j << "] = ";
           cin >> M[i][j];
        }
    }
}

void yasper(int** matrix, const size_t rows, const size_t columns)
{
    srand((unsigned int)time(0));

    for (size_t row = 0; row < rows; row++)
        for (size_t column = 0; column < columns; column++)
            matrix[row][column] = rand() % 100;
}

void Print(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
}

void copirovka(ifstream& fin, ofstream& fout)
{
    string str;
    while (!fin.eof())
    {
        getline(fin, str);
        fout << str << endl;
    }
}

void chevertka()
{
    cout << "введите название файла 1: ";
    string name1, name2, sumname;
    cin >> name1;
    cout << "введите название файла 2: ";
    cin >> name2;
    cout << "введите название общего файла: ";
    cin >> sumname;

    ifstream fin1(name1);
    ifstream fin2(name2);
    ofstream fout(sumname);

    if (fin1.is_open() && fin2.is_open() && fout.is_open())
    {
        copirovka(fin1, fout);
        fin1.close();

        copirovka(fin2, fout);
        fin2.close();

        fout.close();
    }
}

void tusk5()
{
    ifstream fin;
    fin.open("name1.txt");
    if (fin.is_open() == false)
    {
        cerr << "не удалось открыть файл roflanpominki\n";
        exit(EXIT_FAILURE);
    }
    string item;
    cout << " это ваш файл: ";
    while (getline(fin, item, '.'))
    {
        cout << item;
        item += '.';
    }
    cout << " введите искомое слово: ";
    string word;
    cin >> word;
    if (item.find(word) != string::npos)
        cout << " есть такое слово да ";
    else
        cout << " нет такого слова ";

    cout << "\n";
    fin.close();
}

void obzac()
{
	setlocale(LC_ALL, "Rus");
	cout << "\n\n//================================задание================================//\n\n";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    {
        obzac();
        //задание 1
        int* ptrArr;
        int n;
        std::cout << "введите число: ";
        std::cin >> n;
        ptrArr = new int[n];
        int temp = 1;
        std::cout << "результ: ";
        for (size_t i = 0; i < n; i++)
        {
            ptrArr[i] = temp;
            std::cout << ptrArr[i] << " ";
            temp *= 2;
        }

        delete[] ptrArr;

    }

    obzac();
    //задание 2
    size_t n, m;

    std::cout << "Введите количество строк матрицы: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> m;

    int** A = Create(n, m);

    yasper(A, n, m);

    Print(A, n, m);
    Free(A, n);

    obzac();
    //задание 3
   
    string path = "name1.txt";
    cout << "введите текст в файле: ";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        string a;
        cin >> a;
        fout << a;
    }
    cout << "файл создан1\n";
    fout.close();

    cout << "файл создан2\n";
    string path2 = "name2.txt";
    ofstream fout2;
    fout2.open(path2);
    if (!fout2.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        fout2 << "Счет древних русов придумал ученый и преподаватель Юрий Степанович Рыбников.\n";
        fout2 << "На самом же деле это полная выдумка Рыбникова. В научном сообществе его не воспринимают всерьез. \n";
        fout2 << "В научном сообществе его не воспринимают всерьез.\n";

    }
    fout2.close();

    obzac();
    //задание 4
    chevertka();
    cout << "файлы объеденины ";

    obzac();
    //задание 5
    tusk5();

}