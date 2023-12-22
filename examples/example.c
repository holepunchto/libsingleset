#include <singleset.h>
#include <stdio.h>

struct my_entry {
  int my_id;
  char *value;
};

SINGLESET(my_set, struct my_entry, my_id)

int main () {
  my_set_t set;

  my_set_init(&set);

  struct my_entry a = {
    .value = "a"
  };
  struct my_entry b = {
    .value = "b"
  };

  printf("has a? %i\n", my_set_has(&set, &a));
  printf("has b? %i\n", my_set_has(&set, &b));

  my_set_add(&set, &a);

  printf("has a? %i\n", my_set_has(&set, &a));
  printf("has b? %i\n", my_set_has(&set, &b));

  my_set_add(&set, &b);

  printf("has a? %i\n", my_set_has(&set, &a));
  printf("has b? %i\n", my_set_has(&set, &b));

  SINGLESET_FOR_EACH(&set, struct my_entry *entry, {
    printf("set contains: %s\n", entry->value);
  })

  return 0;
}
