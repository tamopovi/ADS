#ifndef FUNKCIJOS1_H_INCLUDED
#define FUNKCIJOS1_H_INCLUDED
#define HEALTHY 1
#define UNHEALTHY 0
#define TRUE 1
#define FALSE 0
#include <stdbool.h>
#include "BigInt.h"
#include <time.h>
typedef struct Patient{
	int timeSpent;
	int needsSpecialistType;
	int goesToType;
	bool goesDirectly;
	bool health;
	bool handled;
}Patient;
typedef struct Queue{//structure of a queue
	Patient Front, Back;
	int elementCount, size;	
	Patient *Data;
}Queue;
typedef struct Specialist{
	int cost;
	Queue *patientQueue;
	int workedMinutes;
	int queueSize;
	int incorrectlyAssignedPatients;
	Int *bigIntCost;
	char *strCost;
}Specialist;
typedef struct Doctor{
    int timeWorked;
    int patientsAssigned;
    int estimatedWorkTime;
    Queue *patientQueue;
    int cost;
    char *strCost;
    Int *bigIntCost;
}Doctor;
typedef struct Clinic{
	Specialist specialist[100];
	Doctor doctor[100];
	int specialistAmount;
	int doctorAmount;
	int incorrectlyAssignedPatientAmount;
	char *strCost;
	Int *bigIntCost;
	int workingTime;
	int baseSpecialistCost;
	int servicedPatients;
	float averagePatientTime;
	int maxSpecialistWorkingTime;
}Clinic;
typedef struct Stats{
    int minPatientTime;
    int minPatientAmount;
    float avgPatientTime;
    int avgPatientAmount;
    int maxPatientTime;
    int maxPatientAmount;
    char *strClinicCost;
    Int *clinicBigIntCost;
    int maxSpecialistWorkingTime;
    int incorrectlyAssignedPatientAmount;
    int servicedPatients;
}Stats;
int isFull(struct Queue **gotQueue);
int isEmpty(struct Queue **gotQueue);
Patient peekFront(struct Queue **gotQueue);
Patient peekBack(struct Queue **gotQueue);
void Enqueue(struct Queue **gotQueue, Patient thing);
Patient Dequeue(struct Queue **gotQueue);
void printElement(int Number);
void printQueue(struct Queue **theQueue);
void createQueue(struct Queue **theQueue, int size);
void destroyQueue(struct Queue **theQueue);
void inputParameters(Clinic *clinic, int *pPatientAmount);
Patient *handlePatientArray1(Clinic *clinic, int *patientAmount);
void generateEmptyPatientArray(Patient **patientArr, int patientAmount);
void generateQueue(Patient **patientArr, int *patientAmount, Clinic *clinic);
void generateClinic(Clinic *clinic);
void generatePatientArray(Patient **patientArr, int *patientAmount, int *specialistAmount);
void curePatient (Patient *patient, int specialistIndex, Clinic *clinic);
int returnMaxSpecialistTime (Clinic *clinic);
int returnRandomNumber(int lower, int upper);
void calculateProcess1Effectiveness(Clinic *clinic, Patient *patientArray, int *patientAmount);
void printStatistic (Stats *statistic);
Stats returnStatistics (Clinic *clinic, Patient *patientArr);
Doctor generateDoctor(int cost);
void generatePatientArray2(Patient **patientArr, int *patientAmount);
void generateDoctorQueue (Patient **patientArr, int *patientAmount, Clinic *clinic);
void visitDoctor(Patient *patient, Clinic *clinic, Doctor *doc);
Patient *handlePatientArray2(Clinic *clinic, int *patientAmount);
void calculateProcess2Effectiveness(Clinic *clinic, Patient *patientArray, int *patientAmount);
#endif // FUNKCIJOS1_H_INCLUDED
