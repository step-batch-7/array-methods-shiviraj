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

int main(void)
{
  int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Array_ptr array = create_array(list, 9);
  Array_ptr mapped_array = map(array, sqr);
  Array_ptr filter_array = filter(array, is_even);
  Array_ptr reduce_array = reduce(array, 0, sum);
  return 0;
}
