#include <stdio.h>
#include <stdlib.h>

void check(int res, const char *msg) {
  if(!res) {
    perror(msg);
    exit(1);
  }
}

typedef struct {
  int a, b, c;
} Cube;

int getMaxLen(Cube *cubes, size_t n) {
  int *lengths = malloc(n * sizeof(int));

  for(size_t i = 0; i < n; i++) {
    lengths[i] = 1;
  }

  for(size_t i = 1; i < n; i++) {
    for(size_t j = 0; j < i; j++) {
      if(cubes[i].a > cubes[j].a && cubes[i].b > cubes[j].b && cubes[i].c > cubes[j].c
        && lengths[i] <= lengths[j]
      ) {
        lengths[i] = lengths[j] + 1;
      }
    }
  }
  int maxLen = 0;

  for(size_t i = 0; i < n; i++) {
    if(lengths[i] > maxLen) {
      maxLen = lengths[i];
    }
  }
  return maxLen;
}

int main() {
  size_t n;
  check(scanf("%zd", &n) == 1, "can't read value");
  Cube *cubes = malloc(n * sizeof(Cube));

  for(size_t i = 0; i < n; i++) {
    check(scanf("%d%d%d", &cubes[i].a, &cubes[i].b, &cubes[i].c) == 3,
      "can't read value");
  }
  printf("%d\n", getMaxLen(cubes, n));

  return 0;
}
