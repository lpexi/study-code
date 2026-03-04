#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SAMPLE_SIZE 3000
#define MAX_INTERVALS 100
struct SensorData
{
    float time;
    double probability;
};

struct Sensor
{
    int id;
    double threshold;
    int object_detection[SAMPLE_SIZE];
    struct SensorData data[SAMPLE_SIZE];
};

int read_sensor_data(const char *p_filename, struct Sensor *p_sensor)
{
    FILE *p_file = fopen(p_filename, "r");
        if(p_file == 0)
        {
            printf("Error: Could not open file %s\n", p_filename);
            return -1;
        }

    int i = 0;
    while(i < SAMPLE_SIZE)
    {
        if (fscanf(p_file, "%f %lf", 
            &p_sensor->data[i].time, 
            &p_sensor->data[i].probability) != 2)
        {
            printf("Incorrect file format detected or insufficient data. Stopping program.\n");
            fclose(p_file);
            return -1;
        }
        i++;

        fclose(p_file);
    }
    return 0;
}

