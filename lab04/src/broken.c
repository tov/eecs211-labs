#include <stdio.h>

#include "lab4_funs.h"


int main(int argc, const char* argv[])
{
    // Array of ten lab scores
    // Note: sum should be 45 (calculated manually)
    unsigned int lab_scores[10] = {1, 2, 3, 7, 6, 5, 0, 4, 9, 8};
    printf("Sum of scores is: %d\n", sum_array(lab_scores, 10));
}

