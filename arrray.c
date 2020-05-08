#include <stdlib.h>
#include "array.h"

Array_ptr create_array(int *numbers, int length)
{
  Array_ptr array = malloc(sizeof(Array));
  array->length = length;
  array->array = malloc(sizeof(int) * array->length);
  for (int i = 0; i < length; i++)
    array->array[i] = numbers[i];
  return array;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr mapped_array = malloc(sizeof(Array));
  mapped_array->length = src->length;
  mapped_array->array = malloc(sizeof(int) * mapped_array->length);
  for (int i = 0; i < src->length; i++)
    mapped_array->array[i] = mapper(src->array[i]);
  return mapped_array;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  int length = 0;
  int filter_array[length];
  for (int i = 0; i < src->length; i++)
  {
    if (predicate(src->array[i]) == True)
    {
      filter_array[++length];
      filter_array[length - 1] = src->array[i];
    }
  }
  return create_array(filter_array, length);
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
  for (int i = 0; i < src->length; i++)
    init = reducer(init, src->array[i]);
  return init;
};
