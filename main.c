#include <stdio.h>
#include "strutils.h"

int main() {
    printf("=== System Utility Test ===\n");
    print_current_user();
    print_current_directory();
    print_system_info();
    return 0;
}
