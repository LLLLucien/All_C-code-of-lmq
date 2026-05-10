#include <stdio.h>

int main(void)
{
    // int height, length, width, volume, weight;
    int volume;
    // height = 8;
    // length = 12;
    // width = 10;
    int height = 8;
    int length = 12;
    int width = 10;
    volume = height * length * width;
    // weight = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

    return 0;
}