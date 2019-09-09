#include <stdio.h>
#include <stdlib.h>

typedef struct { int digits; int hits; } results;

results count_fours(int num, int base) {
    results result = { .hits = 0, .digits = 0 };
    for (int divisor = 1; divisor <= num; divisor *= base) {
        if (num / divisor % base == 4) result.hits++;
        result.digits++;
    }
    return result;
}

int find_base(int num) {
    struct { int hits; int base; } best = { .hits = 0, .base = 5 };
    for (int i = 5; i < num; i++) {
        results r = count_fours(num, i);
        if (r.hits == r.digits) return i; // all 4s is best possible
        if (r.digits < best.hits) return best.base; // digit count decreases
        if (r.hits > best.hits) {
            best.hits = r.hits;
            best.base = i;
        }
    }
    return best.base;
}

int main(int argc, char **argv) {
    printf("%d\n", find_base(atoi(argv[1])));
    return 0;
}
