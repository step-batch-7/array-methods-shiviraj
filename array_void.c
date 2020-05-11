#include <stdlib.h>
#include "array_void.h"

Object void_converter(int num)
{
  int *void_address = malloc(sizeof(int));
  *void_address = num;
  return void_address;
}

ArrayVoid_ptr create_void_array(int *list, int length)
{
  ArrayVoid_ptr void_array = malloc(sizeof(ArrayVoid));
  void_array->length = length;
  void_array->array = malloc(sizeof(Object) * length);
  for (int i = 0; i < length; i++)
    void_array->array[i] = void_converter(list[i]);
  return void_array;
}

ArrayVoid_ptr copy_void_array(Object *list, int length)
{
  ArrayVoid_ptr void_array = malloc(sizeof(ArrayVoid));
  void_array->length = length;
  void_array->array = malloc(sizeof(Object) * length);
  for (int i = 0; i < length; i++)
    void_array->array[i] = list[i];
  return void_array;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = malloc(sizeof(ArrayVoid_ptr));
  mapped_array->length = src->length;
  mapped_array->array = malloc(sizeof(Object) * mapped_array->length);
  for (int i = 0; i < mapped_array->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }
  return mapped_array;
};

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  int length = 0;
  Object filter_array[src->length];
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filter_array[length] = src->array[i];
      length++;
    }
  }
  return copy_void_array(filter_array, length);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
    init = (*reducer)(init, src->array[i]);
  return init;
};
