#include <iostream>
#include <algorithm>
#include <cmath>

void inputArray(int* arr, int size, const char* name) {
    std::cout << "Введіть елементи масиву " << name << ":\n";
    for (int i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        arr[i] = value;
    }
}

void printArray(const int* arr, int size, const char* name) {
    std::cout << "Масив " << name << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* createArrayC(const int* A, int sizeA, const int* B, int sizeB, int& sizeC) {
    int* C = new int[sizeA + sizeB];
    int indexC = 0;

    // Копіюємо парні елементи з A і B в C
    for (int i = 0; i < sizeA; ++i) {
        if (A[i] % 2 == 0) {
            C[indexC++] = A[i];
        }
    }
    for (int i = 0; i < sizeB; ++i) {
        if (B[i] % 2 == 0) {
            C[indexC++] = B[i];
        }
    }
    // Сортуємо парні елементи у порядку спадання
    std::sort(C, C + indexC, std::greater<int>());

    // Копіюємо непарні елементи з A і B в C
    for (int i = 0; i < sizeA; ++i) {
        if (A[i] % 2 != 0) {
            C[indexC++] = A[i];
        }
    }
    for (int i = 0; i < sizeB; ++i) {
        if (B[i] % 2 != 0) {
            C[indexC++] = B[i];
        }
    }
    // Сортуємо непарні елементи у порядку зростання
    std::sort(C + std::count_if(C, C + indexC, [](int x) { return x % 2 == 0; }), C + indexC);

    sizeC = indexC;
    return C;
}

int productBetweenMinMax(const int* A, int size) {
    if (size < 2) return 0;

    int minValue = A[0], maxValue = A[0];
    for (int i = 0; i < size; ++i) {
        if (std::abs(A[i]) < std::abs(minValue)) {
            minValue = A[i];
        }
        if (std::abs(A[i]) > std::abs(maxValue)) {
            maxValue = A[i];
        }
    }

    int product = 1;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (abs(A[i]) > std::abs(minValue) && abs(A[i]) < std::abs(maxValue)) {
            product *= A[i];
            found = true;
        }
    }

    return found ? product : 0;
}

void sortByAbsDesc(int* arr, int size) {
    std::sort(arr, arr + size, [](int a, int b) {
        return std::abs(a) > std::abs(b);
        });
}

int main() {
    system("chcp 1251");
    int n, m;
    std::cout << "Введіть розмір масиву A: ";
    std::cin >> n;
    std::cout << "Введіть розмір масиву B: ";
    std::cin >> m;

    int* A = new int[n];
    int* B = new int[m];

    inputArray(A, n, "A");
    printArray(A, n, "Масив A:");
    inputArray(B, m, "B");
    printArray(B, m, "Масив B:");

    // Завдання 1: Масив C
    int sizeC;
    int* C = createArrayC(A, n, B, m, sizeC);
    printArray(C, sizeC, "C");
    delete[] C;

    // Завдання 2: Добуток між мінімальним і максимальним за модулем
    int product = productBetweenMinMax(A, n);
    std::cout << "Добуток елементів масиву A між мінімальним і максимальним за модулем: " << product << std::endl;

    // Завдання 3: Сортування масивів за спаданням модулів
    sortByAbsDesc(A, n);
    sortByAbsDesc(B, m);
    printArray(A, n, "A після сортування за спаданням модулів");
    printArray(B, m, "B після сортування за спаданням модулів");

    delete[] A;
    delete[] B;

    return 0;
}


