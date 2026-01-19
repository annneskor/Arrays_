#include "array.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// ==================== ЛАБОРАТОРНАЯ 11 ===================
#define SIZE_F 100
#define SIZE_A_HW 10

float f(float x) {
    return x - 3 * pow(cos(1.04 * x), 2);
}

void task11(void) {
    float F[SIZE_F];
    const float minX = 0.15f;
    const float maxX = 2.1f;
    const float step = (maxX - minX) / (SIZE_F - 1);

    int countP = 0, countN = 0;
    float sumP = 0.0f, sumN = 0.0f;

    for (int i = 0; i < SIZE_F; i++) {
        float x = minX + i * step;
        F[i] = f(x);
    }

    for (int i = 0; i < SIZE_F; i++) {
        if (F[i] < 0) {
            sumN += F[i];
            countN++;
        }
        else {
            sumP += F[i];
            countP++;
        }
    }

    float averageP = (countP > 0) ? sumP / countP : 0.0f;

    printf("|---------|-----------|-----------|----------|----------|----------|\n");
    printf("|   Имя   |  Накопл + |  Накопл - |  Число + |  Число - |  Среднее |\n");
    printf("|---------|-----------|-----------|----------|----------|----------|\n");
    printf("|    F    | %9.3f | %9.3f |%8d  |%8d  | %8.3f |\n", sumP, sumN, countP, countN, averageP);
    printf("|---------|-----------|-----------|----------|----------|----------|\n\n");
}

void task11_hw(void) {
    int A[SIZE_A_HW];
    printf("=== Домашнее задание к лаб. 11 ===\n");
    printf("Заполните массив из %d целых чисел:\n", SIZE_A_HW);
    for (int i = 0; i < SIZE_A_HW; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%d", &A[i]);
    }

    int firstNull = -1, lastNull = -1;
    for (int i = 0; i < SIZE_A_HW; i++) {
        if (A[i] == 0) {
            firstNull = i;
            break;
        }
    }
    for (int i = SIZE_A_HW - 1; i >= 0; i--) {
        if (A[i] == 0) { lastNull = i; break; }
    }

    if (firstNull == -1) {
        printf("В массиве нет нулевых элементов!\n");
    }
    else if (firstNull == lastNull) {
        printf("В массиве только один нулевой элемент!\n");
    }
    else {
        int countBetween = lastNull - firstNull - 1;
        printf("Индекс первого нулевого: %d\n", firstNull);
        printf("Индекс последнего нулевого: %d\n", lastNull);
        printf("Количество элементов между ними: %d\n\n", countBetween);
    }

    firstNull = -1;
    int secondNull = -1;
    for (int i = 0; i < SIZE_A_HW; i++) {
        if (A[i] == 0) {
            firstNull = i;
            break;
        }
    }
    if (firstNull != -1) {
        for (int i = firstNull + 1; i < SIZE_A_HW; i++) {
            if (A[i] == 0) {
                secondNull = i;
                break;
            }
        }
    }

    if (firstNull == -1) {
        printf("Нет нулевых элементов!\n");
    }
    else if (secondNull == -1) {
        printf("Только один нулевой элемент!\n");
    }
    else {
        int product = 1;
        for (int i = firstNull + 1; i < secondNull; i++) {
            product *= A[i];
        }
        printf("Индекс первого нулевого: %d\n", firstNull);
        printf("Индекс второго нулевого: %d\n", secondNull);
        printf("Произведение между ними: %d\n", product);
    }
    printf("\n");
}

// ==================== ЛАБОРАТОРНАЯ 14 ====================
#define N_MAX 100
#define CONST_VAL 1
#define EPSILON 1e-4

double F(double x) {
    return x - 3 * pow(cos(1.04 * x), 2);
}

double* full_elements(double* ptr_array, int n) {
    const double minX = 0.15;
    const double maxX = 2.1;
    const double step = (maxX - minX) / (n - 1);
    for (int i = 0; i < n; i++) {
        double x = minX + step * i;
        ptr_array[i] = F(x);
    }
    return ptr_array;
}

void put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.4lf\n", ptr_array[i]);
    }
}

double* calc_element(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] -= CONST_VAL;
    }
    return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double a) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - a) < EPSILON) {
            return i;
        }
    }
    return -1;
}

double min_element(double* ptr_array, int n, double A, double B) {
    double min = 0.0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > A && ptr_array[i] < B) {
            if (!found) {
                min = ptr_array[i];
                found = 1;
            }
            else if (ptr_array[i] < min) {
                min = ptr_array[i];
            }
        }
    }
    return found ? min : NAN;
}

int find_index(double* ptr_array, int n, int type) {
    int firstIndex = -1, lastIndex = -1;

    if (type == 1) {
        for (int i = 0; i < n; i++) if (ptr_array[i] > 0) { firstIndex = i; break; }
        for (int i = n - 1; i >= 0; i--) if (ptr_array[i] > 0) { lastIndex = i; break; }
    }
    else if (type == 2) {
        for (int i = 0; i < n; i++) if (ptr_array[i] < 0) { firstIndex = i; break; }
        for (int i = n - 1; i >= 0; i--) if (ptr_array[i] < 0) { lastIndex = i; break; }
    }
    else {
        for (int i = 0; i < n; i++) if (ptr_array[i] == 0) { firstIndex = i; break; }
        for (int i = n - 1; i >= 0; i--) if (ptr_array[i] == 0) { lastIndex = i; break; }
    }

    if (firstIndex == -1 || lastIndex == -1) return -1;
    return (firstIndex + lastIndex) / 2;
}

int task14(int size) {
    if (size <= 0 || size > N_MAX) {
        printf("Некорректный размер массива (должен быть 1–%d)!\n", N_MAX);
        return -1;
    }

    double array[N_MAX];
    int begin, end, index_a, select, index_middle;
    double a, A, B, sum, min;

    printf("\n=== Лабораторная работа 14 ===\n");
    full_elements(array, size);
    printf("\n>>> Исходный массив <<<\n");
    put_elements(array, size);

    calc_element(array, size);
    printf("\n>>> Массив после обработки (вычитание %d) <<<\n", CONST_VAL);
    put_elements(array, size);

    printf("\n>>> Сумма элементов от индекса ... до ... <<<\n");
    printf("Начальный индекс: "); scanf("%d", &begin);
    printf("Конечный индекс: "); scanf("%d", &end);
    if (begin > end || begin < 0 || end >= size) {
        printf("Ошибка: неверные индексы!\n");
        return -1;
    }
    sum = sum_elements(array, begin, end);
    printf("Сумма = %.4lf\n", sum);

    printf("\n>>> Поиск элемента, равного a <<<\n");
    printf("a = "); scanf("%lf", &a);
    index_a = find_element(array, size, a);
    if (index_a == -1) {
        printf("Элемент не найден!\n");
    }
    else {
        printf("Найден по индексу %d\n", index_a);
    }

    printf("\n>>> Минимальный элемент в интервале (A, B) <<<\n");
    printf("A = "); scanf("%lf", &A);
    printf("B = "); scanf("%lf", &B);
    if (A >= B) {
        printf("Ошибка: A должно быть < B!\n");
        return -1;
    }
    min = min_element(array, size, A, B);
    if (isnan(min)) {
        printf("Нет элементов в интервале!\n");
    }
    else {
        printf("Минимум = %.4lf\n", min);
    }

    printf("\n>>> Индекс середины между первым и последним ... <<<\n");
    printf("1. положительным\n2. отрицательным\n3. нулевым\nВыбор: ");
    scanf("%d", &select);
    if (select < 1 || select > 3) {
        printf("Неверный выбор!\n");
        return -1;
    }
    index_middle = find_index(array, size, select);
    if (index_middle == -1) {
        printf("Невозможно найти пару элементов!\n");
    }
    else {
        printf("Индекс середины = %d\n", index_middle);
    }

    return 0;
}

// ==================== ЛАБОРАТОРНАЯ 16 ====================
void fill_array(double* ptr_array, int size) {
    const double min = -1.0;
    const double max = 1.0;
    for (int i = 0; i < size; i++) {
        ptr_array[i] = min + (max - min) * rand() / RAND_MAX;
    }
}

void display_array(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%10.4f", ptr_array[i]);
    }
    printf("\n");
}

int delete_1(double* ptr_array, int size, int k) {
    for (int i = k; i < size - 1; i++) {
        ptr_array[i] = ptr_array[i + 1];
    }
    return size - 1;
}

int delete_2(double* ptr_array, int size, int k) {
    int write_index = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % k != 0) {
            ptr_array[write_index++] = ptr_array[i];
        }
    }
    return write_index;
}

int delete_3(double* ptr_array, int size, int k, int n) {
    int write_index = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) < n || (i + 1) >= n + k) {
            ptr_array[write_index++] = ptr_array[i];
        }
    }
    return write_index;
}

double* insert_1(double* ptr_array, int size, int index, double num) {
    double* new_ptr = realloc(ptr_array, (size + 1) * sizeof(double));
    if (!new_ptr) return NULL;

    for (int i = size; i > index; i--) {
        new_ptr[i] = new_ptr[i - 1];
    }
    new_ptr[index] = num;
    return new_ptr;
}

double* insert_2(double* ptr_array, int size, double num) {
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (ptr_array[i] < ptr_array[min_idx]) {
            min_idx = i;
        }
    }

    double* new_ptr = realloc(ptr_array, (size + 2) * sizeof(double));
    if (!new_ptr) return NULL;

    for (int i = size + 1; i > min_idx + 1; i--) {
        new_ptr[i] = new_ptr[i - 1];
    }
    new_ptr[min_idx + 1] = num;

    for (int i = size + 2; i > min_idx; i--) {
        new_ptr[i] = new_ptr[i - 1];
    }
    new_ptr[min_idx] = num;

    return new_ptr;
}

int task16(int size) {
    if (size <= 0) {
        printf("Некорректный размер!\n");
        return -1;
    }

    srand((unsigned)time(NULL));

    double* arr = malloc(size * sizeof(double));
    if (!arr) {
        printf("Ошибка выделения памяти!\n");
        return -1;
    }

    fill_array(arr, size);
    printf("\n=== Лабораторная работа 16 ===\n");
    printf("Исходный массив:\n");
    display_array(arr, size);

    int insert_choice;
    printf("\nВыберите вставку:\n1 — по индексу\n2 — до/после минимума\n> ");
    scanf("%d", &insert_choice);

    double num = -999.0;
    switch (insert_choice) {
    case 1: {
        int idx;
        printf("Позиция (0–%d): ", size); scanf("%d", &idx);
        if (idx < 0 || idx > size) { printf("Неверная позиция!\n"); break; }
        printf("Число: "); scanf("%lf", &num);
        double* new_arr = insert_1(arr, size, idx, num);
        if (!new_arr) { free(arr); return -1; }
        arr = new_arr;
        size++;
        break;
    }
    case 2:
        arr = insert_2(arr, size, num);
        if (!arr) return -1;
        size += 2;
        break;
    default:
        printf("Вставка пропущена.\n");
    }

    if (size > 0) {
        printf("После вставки:\n");
        display_array(arr, size);
    }

    int del_choice;
    printf("\nВыберите удаление:\n1 — по номеру\n2 — каждый k-й\n3 — K элементов с n\n> ");
    scanf("%d", &del_choice);

    int k, n;
    switch (del_choice) {
    case 1:
        printf("Номер (1–%d): ", size); scanf("%d", &k);
        if (k < 1 || k > size) { printf("Неверный номер!\n"); break; }
        size = delete_1(arr, size, k - 1);
        break;
    case 2:
        printf("k: "); scanf("%d", &k);
        if (k <= 0) { printf("k > 0!\n"); break; }
        size = delete_2(arr, size, k);
        break;
    case 3:
        printf("K: "); scanf("%d", &k);
        printf("n (1–%d): ", size); scanf("%d", &n);
        if (k <= 0 || n < 1 || n + k - 1 > size) {
            printf("Неверные параметры!\n");
            break;
        }
        size = delete_3(arr, size, k, n);
        break;
    default:
        printf("Удаление пропущено.\n");
    }

    if (size > 0) {
        printf("После удаления:\n");
        display_array(arr, size);
    }

    free(arr);
    return 0;
}

// ==================== ЛАБОРАТОРНАЯ 17: СОРТИРОВКИ ====================

// Пузырьковая сортировка
void bubble_sort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Шейкерная сортировка
void shaker_sort(double* arr, int n) {
    if (n <= 1) return;
    int left = 0;
    int right = n - 1;
    int flag = 1;

    while (left < right&& flag) {
        flag = 0;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                double tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                flag = 1;
            }
        }
        if (!flag) break;
        right--;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                double tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                flag = 1;
            }
        }
        left++;
    }
}

// Сортировка выбором
void selection_sort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            double tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}

// Сортировка вставками
void insertion_sort(double* arr, int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Основная функция лаб. 17
int task17(int size) {
    if (size <= 0 || size > 100) {
        printf("Некорректный размер для сортировки!\n");
        return -1;
    }

    srand((unsigned)time(NULL));

    double* arr1 = malloc(size * sizeof(double));
    double* arr2 = malloc(size * sizeof(double));
    double* arr3 = malloc(size * sizeof(double));
    double* arr4 = malloc(size * sizeof(double));

    if (!arr1 || !arr2 || !arr3 || !arr4) {
        printf("Ошибка памяти в лаб. 17!\n");
        free(arr1); free(arr2); free(arr3); free(arr4);
        return -1;
    }

    for (int i = 0; i < size; i++) {
        double val = -10.0 + 20.0 * rand() / RAND_MAX;
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = val;
    }

    printf("\n=== Лабораторная работа 17: Сортировки ===\n");
    printf("Исходный массив (первые 10 элементов):\n");
    int print_size = (size > 10) ? 10 : size;
    for (int i = 0; i < print_size; i++) {
        printf("%8.2f ", arr1[i]);
    }
    printf("\n\n");

    // Пузырьком
    bubble_sort(arr1, size);
    printf("После пузырьковой сортировки:\n");
    for (int i = 0; i < print_size; i++) printf("%8.2f ", arr1[i]);
    printf("\n");

    // Шейкерная
    shaker_sort(arr2, size);
    printf("После шейкерной сортировки:\n");
    for (int i = 0; i < print_size; i++) printf("%8.2f ", arr2[i]);
    printf("\n");

    // Выбором
    selection_sort(arr3, size);
    printf("После сортировки выбором:\n");
    for (int i = 0; i < print_size; i++) printf("%8.2f ", arr3[i]);
    printf("\n");

    // Вставками
    insertion_sort(arr4, size);
    printf("После сортировки вставками:\n");
    for (int i = 0; i < print_size; i++) printf("%8.2f ", arr4[i]);
    printf("\n");

    free(arr1); free(arr2); free(arr3); free(arr4);
    return 0;
}

// ==================== ДЗ К ЛАБОРАТОРНОЙ 16 ====================
#define MIN_SIZE 10
#define MAX_SIZE 50

void fill_array_hw(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = MIN_SIZE + (MAX_SIZE - MIN_SIZE) * (double)rand() / RAND_MAX;
    }
}

void display_array_hw(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%8.2f", ptr_array[i]);
    }
    printf("\n\n");
}

double* insert_arrays(double* ptr_d, double* ptr_c, int size_c, double* ptr_a, int size_a) {
    int max_idx = 0;
    for (int i = 1; i < size_c; i++) {
        if (ptr_c[i] > ptr_c[max_idx]) {
            max_idx = i;
        }
    }

    int idx = 0;
    for (int i = 0; i < max_idx; i++) {
        ptr_d[idx++] = ptr_c[i];
    }
    for (int i = 0; i < size_a; i++) {
        ptr_d[idx++] = ptr_a[i];
    }
    for (int i = max_idx; i < size_c; i++) {
        ptr_d[idx++] = ptr_c[i];
    }

    return ptr_d;
}

int task16_hw(void) {
    srand((unsigned)time(NULL));

    int size_a = MIN_SIZE + rand() % (MAX_SIZE - MIN_SIZE + 1);
    int size_b = MIN_SIZE + rand() % (MAX_SIZE - MIN_SIZE + 1);
    int size_c = MIN_SIZE + rand() % (MAX_SIZE - MIN_SIZE + 1);
    int size_d = size_a + size_c;

    double* a = malloc(size_a * sizeof(double));
    double* b = malloc(size_b * sizeof(double));
    double* c = malloc(size_c * sizeof(double));
    double* d = malloc(size_d * sizeof(double));

    if (!a || !b || !c || !d) {
        printf("Ошибка выделения памяти в ДЗ 16!\n");
        free(a); free(b); free(c); free(d);
        return -1;
    }

    fill_array_hw(a, size_a);
    fill_array_hw(b, size_b);
    fill_array_hw(c, size_c);

    insert_arrays(d, c, size_c, a, size_a);

    printf("\n=== Домашнее задание к лаб. 16 ===\n");
    printf(">>> Массив A <<<\n\n");
    display_array_hw(a, size_a);
    printf(">>> Массив B <<<\n\n");
    display_array_hw(b, size_b);
    printf(">>> Массив C <<<\n\n");
    display_array_hw(c, size_c);
    printf(">>> Массив D (C с вставленным A перед максимумом) <<<\n\n");
    display_array_hw(d, size_d);

    free(a); free(b); free(c); free(d);
    return 0;
}