#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "array.h"

int main() {
    setlocale(LC_ALL, "");

    puts("Лабораторные работы 11, 14, 16, 17 и ДЗ ===\n");

    // Лаб. 11
    task11();
    task11_hw();

    // Лаб. 14 и 16
    int size;
    printf("Укажите размер массива для лаб. 14, 16, 17 (1–100): ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 100) {
        printf("Некорректный ввод!\n");
        return 1;
    }

    task14(size);
    task16(size);

    // Лаб. 17: сортировки
    task17(size);

    // ДЗ к лаб. 16
    task16_hw();

    return 0;
}