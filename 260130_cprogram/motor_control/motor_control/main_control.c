#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define CHIPNAME "gpiochip0"

/* ULN2003 Pin */
int pins[4] = { 17, 27, 22, 23 };

struct gpiod_line* lines[4];

/* step sequence */
int seq[4][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
};

/* Half-step sequence */
int seq_half[8][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,1},
    {0,0,0,1},
    {1,0,0,1}
};

int pos = 0;


int main()
{
    struct gpiod_chip* chip;
    chip = gpiod_chip_open_by_name(CHIPNAME);

    /* GPIO init */
    if (!chip) {
        perror("chip open failed");
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        lines[i] = gpiod_chip_get_line(chip, pins[i]);
        if (!lines[i]) {
            perror("get line failed");
            return -1;
        }

        if (gpiod_line_request_output(lines[i],
            "stepper",
            0) < 0) {
            perror("request output failed");
            return -1;
        }
    }

    /*
    Parameters  for specific RPM
    2048 step = 1 revolution */
    int idx = 0;
    int rpm = 15;
    int steps_per_rev = 2048;
    double steps_per_sec =
        (rpm * steps_per_rev) / 60.0;
    int delay_us = 1000000 / steps_per_sec;

    int seq_n = 4;  // 4 or 8
    int dir = 1; // 1 or -1

    printf("Stepper running...\n");

    while (1) {
        // Make commnad
        for (int i = 0; i < 2048; i++) {

            if (idx < 0)
                idx = seq_n - 1;
            if (idx > seq_n - 1)
                idx = 0;
            // 1 0 0 0 / 0 1 0 0 / 0 0 1 0 / 0 0 0 1
            for (int j = 0; j < 4; j++) {
                gpiod_line_set_value(lines[j], seq[idx][j]);
            }
            idx += dir;
            usleep(delay_us);
        }

    }

    gpiod_chip_close(chip);
    return 0;
}