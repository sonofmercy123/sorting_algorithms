#ifndef SORT_H
#define SORT_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void node_swapper(listint_t *current);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_alt(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void forward_Shake(listint_t *current);
void backward_shake(listint_t *current);
void cocktail_shaker(listint_t **list);
void cocktail_sort_list(listint_t **list);
void start_of_list(listint_t **list);
void counting_sort(int *array, size_t size);
void value_checker(int *array, int *new_array, size_t size);
void array_for_print(int *new_array, size_t size);
void rewrite_array(int *array, int *new_array, int *third_array, size_t size);
void merge_sort(int *array, size_t size);
void split_array(int *array, int *temp, size_t begin, size_t end);
void rebuild_array(int *array, int *temp, size_t begin, size_t mid,
			size_t end);
void print_before_merge(int *array, int *temp, size_t begin, size_t mid,
			size_t end);
void radix_sort(int *array, size_t size);
void lsd_sort(int *array, int *count, int *temp, size_t size,
			size_t digit_pointer);

#endif
