#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

// === Лаб. 11 ===
float f(float x);
void task11(void);
void task11_hw(void);

// === Лаб. 14 ===
double F(double x);
double* full_elements(double* ptr_array, int n);
void put_elements(double* ptr_array, int n);
double* calc_element(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double a);
double min_element(double* ptr_array, int n, double A, double B);
int find_index(double* ptr_array, int n, int type);
int task14(int size);

// === Лаб. 16 ===
void fill_array(double* ptr_array, int size);
void display_array(double* ptr_array, int size);
int delete_1(double* ptr_array, int size, int k);
int delete_2(double* ptr_array, int size, int k);
int delete_3(double* ptr_array, int size, int k, int n);
double* insert_1(double* ptr_array, int size, int index, double num);
double* insert_2(double* ptr_array, int size, double num);
int task16(int size);

// === Лаб. 17: сортировки ===
void bubble_sort(double* arr, int n);
void shaker_sort(double* arr, int n);
void selection_sort(double* arr, int n);
void insertion_sort(double* arr, int n);
int task17(int size);

// === ДЗ к лаб. 16 ===
int task16_hw(void);

#endif