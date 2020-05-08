#include <stdio.h>
#include "array.h"

int sqr(int num)
{
  return num * num;
}

Bool is_even(int num)
{
  return num % 2 == 0;
}

int sum(int num1, int num2)
{
  return num1 + num2;
}

void display_array(Array_ptr src)
{
  for (int i = 0; i < src->length; i++)
    printf("%d\n", src->array[i]);
}

int main(void)
{
  int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Array_ptr array = create_array(list, 9);
  display_array(array);
  Array_ptr mapped_array = map(array, sqr);
  display_array(mapped_array);
  Array_ptr filter_array = filter(array, is_even);
  display_array(filter_array);
  int result = reduce(array, 0, sum);
  printf("%d\n", result);
  return 0;
}
