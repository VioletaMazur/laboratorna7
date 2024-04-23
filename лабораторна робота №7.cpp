/*
* Варіант 11. Задайте два масиви А(n) і В(m). Виконайте такі завдання:
* – визначте масив С(n+m) з елементів масивів А і В, спочатку парних у порядку
* спадання, а потім непарних у порядку зростання;
* – знайдіть добуток елементів масиву А, розташованих між максимальними і
* мінімальними за модулем елементами;
* – упорядкуйте елементи масивів за спаданням модулів елементів
*/

#include <iostream>
#include <fstream>
using namespace std;
void printArray(int* (arr), int sizeArr);
// функція сортує масив А за правилом byGrowth (true - зростанням, false - спаданням)
void sortArray(int* (arr), int sizeArr, bool byGrowth);
void sortArrayByAbs(int* (arr), int sizeArr);
void createArray(int* (A), int sizeA, int* (B), int sizeB, int* (C), int sizeC);
int countElements(int* (A), int sizeA, bool even);
int productElements(int* (A), int sizeA);
int main()
{


    // визначення вказівників 


    int sizeA, sizeB, sizeC;

    // Читаю массиви з потоку
    // Дані в потоці подано в вигляді 3 рядків.
    // 1 - 2 числа, довжина масиву А та довжина масиву В
    // 2 - елементи масиву А
    // 3 - елементи масиву В

    // читаю довжини масивів з першого рядка

    cout << "Введіть розміри масивів А та В (2 числа) : \n";
    cin >> sizeA >> sizeB;
    // читаю перший масив
    cout << "Введіть елементи масиву A," << sizeA << " чисел через Enter: \n";
    int* A = new int[sizeA];
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }
    cout << "Масив A:\n";
    printArray(A, sizeA);

    // читаю другий масив
    cout << "Введіть елементи масиву В," << sizeB << " чисел через Enter: \n";
    int* B = new int[sizeB];
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }
    cout << "Масив B:\n";
    printArray(B, sizeB);

    cout << "1. Визначте масив С(n+m) з елементів масивів А і В, спочатку парних у порядку спадання, а потім непарних у порядку зростання; \n";
    cout << "Масив C:\n";
    sizeC = sizeA + sizeB;
    int* C = new int[sizeC];
    createArray(A, sizeA, B, sizeB, C, sizeC);
    printArray(C, sizeC);

    cout << endl;
    cout << "2. знайдіть добуток елементів масиву А, розташованих між максимальними і мінімальними за модулем елементами\n";

    int prod = productElements(A, sizeA);
    cout << "Результат => " << prod << endl;
    cout << endl;
    cout << "3. упорядкуйте елементи масивів за спаданням модулів елементів \n";
    sortArrayByAbs(A, sizeA);
    sortArrayByAbs(B, sizeB);

    cout << "Масив A:\n";
    printArray(A, sizeA);
    cout << "Масив B:\n";
    printArray(B, sizeB);



    delete A;
    delete B;
    delete C;
    system("pause");
    return 0;
}
void printArray(int* (arr), int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void sortArray(int* (arr), int sizeArr, bool byGrowth) {
    // Сортування методом вибору
    for (int i = 0; i < sizeArr - 1; i++) {
        int m = i;
        for (int j = i + 1; j < sizeArr; j++) {
            if (arr[j] < arr[m] == byGrowth) {
                m = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }

}
void sortArrayByAbs(int* (arr), int sizeArr) {
    // Сортування методом вибору
    for (int i = 0; i < sizeArr - 1; i++) {
        int m = i;
        for (int j = i + 1; j < sizeArr; j++) {
            if (abs(arr[j]) > abs(arr[m])) {
                m = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }
}
int countElements(int* (A), int sizeA, bool even) {
    int countEven = 0;
    for (int i = 0; i < sizeA; i++) {
        if ((abs(A[i]) % 2 == 0) == even) {
            countEven++;
        }
    }
    return countEven;
}
void createArray(int* (A), int sizeA, int* (B), int sizeB, int* (C), int sizeC) {
    /*
    * – визначте масив С(n+m) з елементів масивів А і В, спочатку парних у порядку
    * спадання, а потім непарних у порядку зростання;
    */
    // Довжина масиву С. В нього входять всі елементи А і В

    // Визначаю кількість парних та непарних елементів в масивах А та В
    int countEven = countElements(A, sizeA, true) + countElements(B, sizeB, true);
    int countOdd = countElements(A, sizeA, false) + countElements(B, sizeB, false);
    // Створюю масив для парних елементів
    int* arrayEven = new int[countEven];
    int indexEven = 0;
    for (int i = 0; i < sizeA; i++) {
        if (abs(A[i]) % 2 == 0) {
            arrayEven[indexEven] = A[i];
            indexEven++;
        }
    }
    for (int i = 0; i < sizeB; i++) {
        if (abs(B[i]) % 2 == 0) {
            arrayEven[indexEven] = B[i];
            indexEven++;
        }
    }
    // Створюю масив для непарних елементів
    int* arrayOdd = new int[countOdd];
    int indexOdd = 0;
    for (int i = 0; i < sizeA; i++) {
        if (abs(A[i]) % 2 == 1) {
            arrayOdd[indexOdd] = A[i];
            indexOdd++;
        }
    }
    for (int i = 0; i < sizeB; i++) {
        if (abs(B[i]) % 2 == 1) {
            arrayOdd[indexOdd] = B[i];
            indexOdd++;
        }
    }
    // Сортую масив з парними елементами за спаданням
    sortArray(arrayEven, countEven, false);
    // Сортую масив з непарними елементами за зростанням
    sortArray(arrayOdd, countOdd, true);
    // З'єдную масиви
    int index = 0;
    for (int i = 0; i < countEven; i++) {
        C[index] = arrayEven[i];
        index++;
    }
    for (int i = 0; i < countOdd; i++) {
        C[index] = arrayOdd[i];
        index++;
    }


}

int productElements(int* (A), int sizeA) {
    // максимальний за модулем елемент
    int maxAbs = 0;
    for (int i = 0; i < sizeA; i++) {
        if (abs(A[maxAbs]) < abs(A[i])) {
            maxAbs = i;
        }
    }
    // мінімальний за модулем елемент
    int minAbs = 0;
    for (int i = 0; i < sizeA; i++) {
        if (abs(A[minAbs]) > abs(A[i])) {
            minAbs = i;
        }
    }

    // визначення початку та кінця діапазону елементів
    int indStart = maxAbs, indEnd = minAbs;
    if (maxAbs > minAbs) {
        indStart = minAbs;
        indEnd = maxAbs;
    }
    // визначення добутку
    int prod = 1;
    for (int i = indStart; i <= indEnd; i++) {
        prod *= A[i];
    }
    return prod;
}

