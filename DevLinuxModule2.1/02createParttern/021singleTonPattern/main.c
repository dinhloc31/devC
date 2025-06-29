
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int node1;
    int node2;
}sensornode;

static sensornode* sensormanager01 = NULL;

void createSensorManager(sensornode** sensormanager, int newNode1, int newNode2);

int main()
{
    printf("Singleton Pattern - Add new sensor\n");
    createSensorManager(&sensormanager01, 1, 2);
    printf("Singleton Pattern - Trying to add new sensor\n");
    createSensorManager(&sensormanager01, 3, 4);
    printf("Singleton Pattern - Sensor list\n");
    printf ("Sensor 1: %d \n", sensormanager01->node1);
    printf ("Sensor 2: %d \n", sensormanager01->node2);

}

void createSensorManager(sensornode** sensormanager, int newNode1, int newNode2)
{
    if (*sensormanager != NULL)
    {
        printf("Error: This sensor list is created \n");
        return ;
    }
    
    *sensormanager = (sensornode*)malloc(sizeof(sensornode));
    if(*sensormanager != NULL)
    {
        (*sensormanager)->node1 = newNode1;
        (*sensormanager)->node2 = newNode2;
    }
    return ;


}