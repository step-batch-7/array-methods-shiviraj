#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

Object sqr(Object num)
{
  int *result = malloc(sizeof(int));
  int *number = (int *)num;
  *result = (*number * *number);
  return result;
}

Bool is_even(Object num)
{
  int *number = (int *)num;
  return *number % 2 == 0;
}

Object sum(Object item1, Object item2)
{
  int *num1 = (int *)item1;
  int *num2 = (int *)item2;
  int *result = malloc(sizeof(int));
  *result = *num1 + *num2;
  return result;
}

void display_num(Object address_of_num)
{
  int *num = (int *)address_of_num;
  printf("%d\n", *num);
}

void display_void_array(ArrayVoid_ptr src, Displayer displayer)
{
  for (int i = 0; i < src->length; i++)
    (*displayer)(src->array[i]);
}

int main(void)
{
  int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ArrayVoid_ptr void_array = create_void_array(list, 9);
  display_void_array(void_array, display_num);
  ArrayVoid_ptr mapped_array = map_void(void_array, sqr);
  display_void_array(mapped_array, display_num);
  ArrayVoid_ptr filter_array = filter_void(void_array, is_even);
  display_void_array(filter_array, display_num);
  int *init = malloc(sizeof(int));
  *init = 0;
  Object result = reduce_void(void_array, init, sum);
  printf("%d\n", *(int *)result);
  return 0;
}
