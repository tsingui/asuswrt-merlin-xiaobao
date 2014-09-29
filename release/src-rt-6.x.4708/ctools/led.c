#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>

#include <bcmgpio.h>

#define BCMGPIO_DIRN_OUT  1

static int led_control(int port, int boolOn)
{
    int gpiomap;
    if (bcmgpio_connect(port, BCMGPIO_DIRN_OUT))
    {
        return 1;
    }
    gpiomap = (1 << port);
    bcmgpio_out(gpiomap, boolOn? gpiomap: 0);
    bcmgpio_disconnect(port);
    return 0;
}

int main() {
    led_control(7, 0);
    led_control(8, 0);
    led_control(9, 1);
}
