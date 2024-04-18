#include <stdio.h>

typedef struct {
    char* m_brand;
    char* m_model;
    int m_year;
} Car;

typedef struct {
    Car car; 
    char* m_DriveMode; 
} BMW_Car;

typedef struct {
    Car car;
    char* m_DriveMode; 
} AUDI_Car;

typedef struct {
    char* m_brand;
    char* m_model;
    int m_year;
    char* m_DriveMode; 
} BENZ_Car;

void initCar(Car *car, char* brand, char* model, int year) {
    car->m_brand = brand;
    car->m_model = model;
    car->m_year = year;
}

void initBMW(BMW_Car *bmw, char* model, int year, char* driveMode) {
    initCar(&(bmw->car), "BMW", model, year);
    bmw->m_DriveMode = driveMode;
}

void initAUDI(AUDI_Car *audi, char* model, int year, char* driveMode) {
    initCar(&(audi->car), "Audi", model, year);
    audi->m_DriveMode = driveMode;
}

void initBENZ(BENZ_Car *benz, char* model, int year, char* driveMode) {
    benz->m_brand = "Benz";
    benz->m_model = model;
    benz->m_year = year;
    benz->m_DriveMode = driveMode;
}

int main() {
    BMW_Car bmw;
    AUDI_Car audi;
    BENZ_Car benz;

    initBMW(&bmw, "3-Series", 2022, "Rear-wheel");
    printf("Constructing BMW_Car\nBMW: Drive Mode = %s\n", bmw.m_DriveMode);

    initAUDI(&audi, "A4", 2023, "Front-wheel");
    printf("Constructing AUDI_Car\nAudi: Drive Mode = %s\n", audi.m_DriveMode);

    initBENZ(&benz, "E-Class", 2024, "Front-wheel");
    printf("Constructing BENZ_Car\nBenz: Drive Mode = %s\n", benz.m_DriveMode);

    return 0;
}
