#include <stdbool.h>
#include <stdlib.h>

#ifndef SINGLESET_H
#define SINGLESET_H

#define SINGLESET_ID(value, id) value->id

#define SINGLESET_FOR_EACH(set, value, blk) \
  for (int singleset__ite = (set)->len - 1; singleset__ite >= 0; singleset__ite--) { \
    value = (set)->values[singleset__ite]; \
    blk \
  }

#define SINGLESET(name, entry, id) \
  typedef struct { \
    entry **values; \
    int len; \
    int max_len; \
  } name##_t; \
  \
  void \
  name##_init (name##_t *set) { \
    set->len = 0; \
    set->max_len = 4; \
    set->values = malloc(set->max_len * sizeof(entry *)); \
  } \
  \
  void \
  name##_destroy (name##_t *set) { \
    free(set->values); \
    set->values = NULL; \
  } \
  \
  void \
  name##_grow (name##_t *set) { \
    set->max_len *= 2; \
    set->values = realloc(set->values, sizeof(entry *) * set->max_len); \
  } \
  \
  bool \
  name##_has (name##_t *set, entry *value) { \
    return SINGLESET_ID(value, id) < set->len && set->values[SINGLESET_ID(value, id)] == value; \
  } \
  \
  void \
  name##_add (name##_t *set, entry *value) { \
    if (name##_has(set, value)) return; \
    if (set->len == set->max_len) name##_grow(set); \
    SINGLESET_ID(value, id) = set->len++; \
    set->values[SINGLESET_ID(value, id)] = value; \
  } \
  \
  bool \
  name##_remove (name##_t *set, entry *value) { \
    if (!name##_has(set, value)) return false; \
    entry *last = set->values[--(set->len)]; \
    SINGLESET_ID(last, id) = SINGLESET_ID(value, id); \
    set->values[SINGLESET_ID(last, id)] = last; \
    return true; \
  }

#endif
