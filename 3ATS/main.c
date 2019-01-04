#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "BigInt.h"
#include "funkcijos1.h"
#define HEALTHY 1
#define UNHEALTHY 0
#define TRUE 1
#define FALSE 0

int main()
{
	Clinic clinic;
	Patient *patientArray;
	int patientAmount = 0;
	inputParameters(&clinic,&patientAmount);
	generateClinic(&clinic);
	Patient *newPatientArray;
	
	generatePatientArray(&patientArray,&patientAmount,&clinic.specialistAmount);
	generateQueue(&patientArray,&patientAmount,&clinic);
    generateEmptyPatientArray(&newPatientArray,patientAmount);
    newPatientArray = handlePatientArray1(&clinic,&patientAmount);
    calculateProcess1Effectiveness(&clinic,newPatientArray,&patientAmount);
	printf("PIRMA STATISTIKA\n");
	printf("-------------------------------------------------\n");
    Stats statistic1 = returnStatistics(&clinic,newPatientArray);
	printStatistic(&statistic1);



	Clinic clinic2;
	inputParameters(&clinic2,&patientAmount);
	generateClinic(&clinic2);
	Patient *patientArray2, *newPatientArray2;
	generatePatientArray2(&patientArray2,&patientAmount);
	generateEmptyPatientArray(&newPatientArray2,patientAmount);
	generateDoctorQueue(&patientArray2,&patientAmount,&clinic2);
	newPatientArray2 = handlePatientArray2(&clinic2,&patientAmount);
	/*
	 Isvados:
	 	gydytojus laiko atzvilgiu apsimoka tureti, kai didzioji dalis pacientu yra sveiki.

	 *2/
	 * */
	calculateProcess2Effectiveness(&clinic2,newPatientArray2,&patientAmount);
	Stats statistic2 = returnStatistics(&clinic2,newPatientArray2);
	printf("ANTRA STATISTIKA\n");
	printf("-------------------------------------------------\n");
	printStatistic(&statistic2);
	free(newPatientArray);
	free(newPatientArray2);
	for (int i = 0; i < clinic.specialistAmount; i++){
	    destroyQueue(&clinic.specialist[i].patientQueue);
	}
    for (int i = 0; i < clinic2.specialistAmount; i++){
        destroyQueue(&clinic2.specialist[i].patientQueue);
    }
    for (int i = 0; i < clinic2.doctorAmount; i++){
        destroyQueue(&clinic2.doctor[i].patientQueue);
    }

    return 0;
}
