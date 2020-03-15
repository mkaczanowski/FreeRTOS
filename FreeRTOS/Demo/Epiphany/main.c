#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#include <e-hal.h>

int main(int argc, char *argv[])
{
    unsigned row, col, coreid, i, j;
    e_platform_t platform;
    e_epiphany_t dev;

    uint64_t initial = 0;

    // Initialize the Epiphany HAL and connect to the chip
    e_init(NULL);

    // Reset the system
    e_reset_system();

    // Get the platform information
    e_get_platform_info(&platform);

    // Create a workgroup using all of the cores    
    e_open(&dev, 0, 0, platform.rows, platform.cols);
    e_reset_group(&dev);

    // Load the device code into each core of the chip, and don't start it yet
    e_load_group("e_main.srec", &dev, 0, 0, platform.rows, platform.cols, E_FALSE);

    // Set the maximum per core test value on each core at address 0x7020
    e_write(&dev, 0, 0, 0x7020, &initial, sizeof(uint64_t));

    // Start all of the cores
    e_start_group(&dev);

    // Read updated value
    uint64_t total = 0;
    uint64_t total2 = 0;
    uint64_t debug = 0;

    int z = 0;
    for (z = 0; z < 50; z++) {
        if(e_read(&dev, 0, 0, 0x7020, &total, sizeof(uint64_t)) != sizeof(uint64_t))
            fprintf(stderr, "Failed to read\n");
        if(e_read(&dev, 0, 0, 0x7080, &total2, sizeof(uint64_t)) != sizeof(uint64_t))
            fprintf(stderr, "Failed to read\n");
        if(e_read(&dev, 0, 0, 0x7010, &debug, sizeof(uint64_t)) != sizeof(uint64_t))
            fprintf(stderr, "Failed to read\n");
        printf("Debug: %" PRIu64 "; Count: %" PRIu64 "; Count2: %" PRIu64 "\n", debug, total, total2);
        sleep(1);
    }

    e_finalize();

    return 0;
}
