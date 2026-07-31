#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    char buf[10];

    printf("Read count = %d\n", getreadcount());

    read(0, buf, sizeof(buf));

    printf("Read count = %d\n", getreadcount());

    exit(0);
}
