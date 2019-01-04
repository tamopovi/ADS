#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcijos1.h"
#include "BigInt.h"
int isFull(struct Queue **gotQueue){//function to check if there are a lot of things
	if ((((*gotQueue)->elementCount) == ((*gotQueue)->size) )|| ((*gotQueue)->size == 0)) return 1;
	else return 0;
}

int isEmpty(struct Queue **gotQueue){//function to check if there are no things
	if(((*gotQueue)->elementCount) == 0 ) return 1;
	else return 0;
}

Patient peekFront(struct Queue **gotQueue){//function to get the element that you can take out
	return ((*gotQueue) -> Front);
}

Patient peekBack(struct Queue **gotQueue){//function to get the element that was just inserted
	return ((*gotQueue) -> Back);
}

void Enqueue(struct Queue **gotQueue, Patient thing){//function to put a thing in a thing
	if(!isFull(&*gotQueue)){
		if ((*gotQueue)->elementCount != 0){
			(*gotQueue)->elementCount++;
			(*gotQueue)->Back = thing;
			for(int o = (*gotQueue) -> elementCount - 1; o > 0 ; o--){
				(*gotQueue)->Data[o] = (*gotQueue)->Data[o-1];	
			}
			(*gotQueue)->Data[0] = thing;
		}
		else{
			(*gotQueue)->elementCount++;
			(*gotQueue)->Front = thing;
			(*gotQueue)->Back = thing;
			(*gotQueue)->Data[0] = thing;
		}
	}	
}

Patient Dequeue(struct Queue **gotQueue){//function to take a thing out of a thing
	Patient temp;
	if(!isEmpty(&*gotQueue)){
		if ((*gotQueue)->elementCount != 1){
			(*gotQueue)->elementCount--;
			temp = (*gotQueue)->Front;
			(*gotQueue)->Front = (*gotQueue)->Data[(*gotQueue)->elementCount - 1];
			return temp;
		}
		else{
			//(*gotQueue)->Front = 0;
			//(*gotQueue)->Back = 0;
			//(*gotQueue)->elementCount--;
			return ((*gotQueue)->Front);
		}
	}
}

void printElement(int Number){//function to print a thing
	printf("Gautas elementas: %d\n", Number);
}
void printQueue(struct Queue **theQueue){
	printf("Front: %d\n", (*theQueue) -> Front.needsSpecialistType);
	printf("Back: %d\n", (*theQueue) -> Back.needsSpecialistType);
	printf("Element Count: %d\n", (*theQueue) -> elementCount);
	for (int o = 0; o < (*theQueue) -> elementCount; o++) {
		printf("Pacientas nr. %d: %d\n", o ,(*theQueue) -> Data[o].needsSpecialistType);
		}
	
}

void createQueue(struct Queue **theQueue, int size){//function to create a place where you can put a limited number of things
	if (size > 0){
		*theQueue = (struct Queue*)malloc(sizeof(struct Queue));
 		(*theQueue) -> Data = malloc(size * sizeof(Patient));
		//(*theQueue) -> Front = 0;
		//(*theQueue) -> Back = 0;
		(*theQueue) -> elementCount = 0;
		(*theQueue) -> size = size;	
	}
	else return ;
}
void destroyQueue(struct Queue **theQueue)
{
	free((*theQueue)->Data);
	free(*theQueue);
}
void inputParameters(Clinic *clinic, int *pPatientAmount){
	int baseCost = 0;
	printf("Iveskite pacientu kieki: ");
	scanf("%d",pPatientAmount);
	printf("Iveskite specialistu kieki: ");
	scanf("%d",&(*clinic).specialistAmount);
	printf("Iveskite specialistu pradini atlyginima: ");
	scanf("%d",&baseCost);
	printf("Iveskite darbo dienos trukme valandomis: ");
	scanf("%d",&(*clinic).workingTime);
	printf("Iveskite gydytoju kieki: ");
	scanf("%d",&(*clinic).doctorAmount);
	printf("Iveskite gydytoju atlyginima: ");
	scanf("%d",&(*clinic).doctor->cost);
	(*clinic).workingTime *= 60;
	(*clinic).baseSpecialistCost = baseCost;
	for (int i = 0; i < (*clinic).specialistAmount; i++){
		if (i > (*clinic).specialistAmount*0.75)
			(*clinic).specialist[i].cost = baseCost * 1.25;
		else
			(*clinic).specialist[i].cost = baseCost;
	}
	//for (int i = 0; i < (*amount); i++){
	//	printf("specialist[%d], %d\n",i,(*clinic).specialist[i].cost);
	//}
}
int returnRandomNumber(int lower, int upper){
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}
void curePatient (Patient *patient, int specialistIndex, Clinic *clinic){
	int checkUp = returnRandomNumber(10,15);
	int treatment = returnRandomNumber(35,45);
    if (patient->goesDirectly ) {
        if(patient->health == HEALTHY && patient->handled == FALSE){    //if patient is healthy, spends only 10-15min for check-up
            patient->timeSpent += checkUp;
            (*clinic).specialist[specialistIndex].workedMinutes += patient->timeSpent;
			patient->handled = true;
        }
        else{
			patient->timeSpent += checkUp;
			patient->timeSpent += treatment;		//check-up: 10-15min + treatment: 35-45min
            patient->health = HEALTHY;
            (*clinic).specialist[specialistIndex].workedMinutes += patient->timeSpent;
			patient->handled = true;
        }
    }
    if (!(patient->goesDirectly)){
		(*clinic).incorrectlyAssignedPatientAmount++;
		(*clinic).specialist[patient->goesToType].incorrectlyAssignedPatients++;
        if(patient->health == HEALTHY){    //if patient is healthy, spends time on two different check-ups
			patient->timeSpent += checkUp;	//check-up 1
			(*clinic).specialist[patient->goesToType].workedMinutes += patient->timeSpent;
			patient->timeSpent += checkUp;	//check-up 2
            (*clinic).specialist[patient->needsSpecialistType].workedMinutes += checkUp;
			patient->handled = true;
        }
        else{
            //patient->timeSpent += 70;     //if patient in unhealthy, spends time on two check-ups and 40min treatment
			patient->timeSpent += checkUp;	//check-up 1
			(*clinic).specialist[patient->goesToType].workedMinutes += patient->timeSpent;
			patient->timeSpent += checkUp;	//check-up 2
			(*clinic).specialist[patient->needsSpecialistType].workedMinutes += checkUp;
			patient->timeSpent += treatment;
			(*clinic).specialist[patient->needsSpecialistType].workedMinutes += treatment;
            patient->handled = true;
            patient->health = HEALTHY;
            }
    }

}
int returnMaxSpecialistTime (Clinic *clinic){
    int maxTime = -1;
    for (int i = 0; i < (*clinic).specialistAmount; i++){
        if ((*clinic).specialist[i].workedMinutes > maxTime)
            maxTime = (*clinic).specialist[i].workedMinutes;
    }
    return maxTime;
}
Patient *handlePatientArray1(Clinic *clinic, int *patientAmount) {
    Patient *patientArr;
    int maxSpecialistTime = -1;
    generateEmptyPatientArray(&patientArr, (*patientAmount)+1);
    unsigned patientCount = 0;
    while (patientCount < (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 30){
        for (int i = 0; i < (*clinic).specialistAmount; i++){
            if(!isEmpty(&(*clinic).specialist[i].patientQueue)){
                patientArr[patientCount] = Dequeue(&(*clinic).specialist[i].patientQueue);
                curePatient(&patientArr[patientCount],i,&(*clinic));
                maxSpecialistTime = returnMaxSpecialistTime(&(*clinic));
                patientCount++;
                if (patientCount >= (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 45) break;
            }
        }
        if (patientCount >= (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 45) break;

    }
	(*clinic).servicedPatients = patientCount;
	(*clinic).maxSpecialistWorkingTime = maxSpecialistTime;
	/*for (int i = 0; i < (*patientAmount); i++){
		printf("[%d],%d\n",i,patientArr[i].health);
	}*/
	/*for (int i = 0; i < patientCount; i++){
		printf("Pacientas [%d] isgydytas per: %d\n",i,patientArr[i].timeSpent);
	}*/
    return patientArr;
}
void generateEmptyPatientArray(Patient **patientArr, int patientAmount){		//creating a dynamicaly allocated
	if (patientAmount > 0){													//patient array of size patientAmount
		*patientArr = (Patient*)malloc (sizeof(Patient)*patientAmount);
	}
}
void generateQueue(Patient **patientArr, int *patientAmount, Clinic *clinic){
	//get queue sizes
	for (int i = 0; i < (*patientAmount); i++){
		(*clinic).specialist[(*patientArr)[i].goesToType].queueSize++;
	}
	
	//create queues
	for (int i = 0; i < (*clinic).specialistAmount; i++){

		createQueue(&(*clinic).specialist[i].patientQueue, (*clinic).specialist[i].queueSize);
		//printf("Speialist[%d] queue size %d\n",i,(*clinic).specialist[i].queueSize);
	}
	
	//add elements to queues
	for (int i = 0; i < (*patientAmount); i++){
		Enqueue(&(*clinic).specialist[(*patientArr)[i].goesToType].patientQueue,(*patientArr)[i]);
	}
	
	//check if valid
	/*for (int i = 0; i < (*clinic).specialistAmount; i++){
		printf("Specialisto[%d] eile: \n",i);
		printQueue(&(*clinic).specialist[i].patientQueue);
		printf("---------------------------------\n");
	}*/
}
void generateDoctorQueue (Patient **patientArr, int *patientAmount, Clinic *clinic){
	if ((*clinic).workingTime / (*clinic).doctorAmount <= 9 && (*clinic).workingTime / (*clinic).doctorAmount > 6){
		printf("Rastas tinkamiausias kiekis gydytoju.\n");
	}
	//create queues
	for (int i = 0; i < (*clinic).doctorAmount; i++) {
		createQueue(&(*clinic).doctor[i].patientQueue, 48);	///10 - max Doctor work time
	}

	//add elements to queues
	int docIndex = 0;
	for (int i = 0; i < (*patientAmount); i++){
		if (!isFull(&(*clinic).doctor[docIndex].patientQueue)){
			Enqueue(&(*clinic).doctor[docIndex].patientQueue,(*patientArr)[i]);
			(*clinic).doctor[docIndex].estimatedWorkTime +=10;
			(*clinic).doctor[docIndex].patientsAssigned++;
		} else{
			docIndex++;
			if (docIndex == (*clinic).doctorAmount) break;
		}
	}
	/*for (int i = 0; i < (*clinic).doctorAmount;i++){
		printf("Gydytojo [%d] eile\n",i);
		printQueue(&(*clinic).doctor[i].patientQueue);
		printf("---------------------------\n");
	}*/
}
void generateClinic(Clinic *clinic){
	//inputParameters(&clinic,&patientAmount);
	//--------------------------------------------------

	//Instead of input params
	/*(*clinic).specialistAmount = 20;
	(*clinic).doctorAmount = 6;
	(*clinic).workingTime = 8*60;
	(*clinic).baseSpecialistCost = 2000;*/
	(*clinic).servicedPatients = 0;
	(*clinic).incorrectlyAssignedPatientAmount = 0;
	(*clinic).bigIntCost = BigInt.create(0);
	(*clinic).averagePatientTime = 0;
	(*clinic).strCost = (char*) malloc (sizeof(char)*500);
	BigInt.fromInt((*clinic).bigIntCost,0);
	
	
	
	//specialist initialization
	for (int i = 0; i < (*clinic).specialistAmount; i++){
		(*clinic).specialist[i].strCost = (char*) malloc (sizeof(char)*5);
		if (i > (*clinic).specialistAmount*0.75){	//25% of specialists get a larger pay of +25%
			(*clinic).specialist[i].cost = (*clinic).baseSpecialistCost * 1.25;
			//(*clinic).specialist[i].bigIntCost = BigInt.create(0);
			//BigInt.toString((*clinic).specialist[i].bigIntCost,(*clinic).specialist[i].strCost,4);
		}
		else{
			//(*clinic).specialist[i].bigIntCost = BigInt.create(0);
			(*clinic).specialist[i].cost = (*clinic).baseSpecialistCost;
		}
		(*clinic).specialist[i].bigIntCost = BigInt.create(0);
		BigInt.fromInt((*clinic).specialist[i].bigIntCost,(*clinic).specialist[i].cost);
		BigInt.toString((*clinic).specialist[i].bigIntCost, (*clinic).specialist[i].strCost, 5);
		 
		 (*clinic).specialist[i].queueSize = 0;
		 (*clinic).specialist[i].workedMinutes = 0;
		(*clinic).specialist[i].incorrectlyAssignedPatients= 0;
	}
	for (int i = 0; i < (*clinic).doctorAmount; i++){
		(*clinic).doctor[i] = generateDoctor((*clinic).doctor->cost);
	}
	
	
	
	
}
void generatePatientArray(Patient **patientArr, int *patientAmount, int *specialistAmount){
	time_t t;
	srand((unsigned) time(&t));
	
	if ((*patientAmount) > 0){
		*patientArr = (Patient*)malloc (sizeof(Patient)*(*patientAmount));
	}
	for (int i = 0; i < (*patientAmount); i++){
		(*patientArr)[i].needsSpecialistType = rand() % (*specialistAmount); //randomly assigning needed
                                                                                    //specialists to patients
        (*patientArr)[i].timeSpent = 0;


		if (rand() % 100 < 35){				//35 percent chance that a patient is healthy
			(*patientArr)[i].health = HEALTHY;
		} else (*patientArr)[i].health = UNHEALTHY;
		(*patientArr)[i].handled = FALSE;	//no patient is handled
		if (rand() % 100 < 70)		//70 percent chance, that a patient knows which specialist to visit
			(*patientArr)[i].goesDirectly = TRUE;
		else
			(*patientArr)[i].goesDirectly = FALSE;
		
		if ((*patientArr)[i].goesDirectly){			//assigning needed specialists
			(*patientArr)[i].goesToType = (*patientArr)[i].needsSpecialistType;
		}
		else{								//assigning incorrect specialists
			if((*patientArr)[i].needsSpecialistType != 0){
				(*patientArr)[i].goesToType = rand() % (*patientArr)[i].needsSpecialistType;
			}
			else{
				(*patientArr)[i].goesToType = 0;
			}
		}
		//printf("Pacientui[%d] reikia pas: %d\n",i,(*patientArr)[i].needsSpecialistType);
		//printf("Pacientas eina tiesiogiai?: %d\n",(*patientArr)[i].goesDirectly);
	}
}
void generatePatientArray2(Patient **patientArr, int *patientAmount){
	time_t t;
	srand((unsigned) time(&t));

	if ((*patientAmount) > 0){
		*patientArr = (Patient*)malloc (sizeof(Patient)*(*patientAmount));
	}
	for (int i = 0; i < (*patientAmount); i++){
		(*patientArr)[i].timeSpent = 0;
		(*patientArr)[i].handled = FALSE;	//no patient is handled
		if (rand() % 100 < 35){				//35 percent chance that a patient is healthy
			(*patientArr)[i].health = HEALTHY;
		}
		else{
			(*patientArr)[i].health = UNHEALTHY;
		}
	}
}
void calculateProcess1Effectiveness(Clinic *clinic, Patient *patientArray, int *patientAmount){
    float averagePatientSpentTime = 0;
    for (int i = 0; i < (*clinic).specialistAmount; i++){
        BigInt.add((*clinic).bigIntCost,(*clinic).specialist[i].bigIntCost);
    }
    BigInt.toString((*clinic).bigIntCost, (*clinic).strCost, 500);
    //printf("Klinikos kaina: %s\n", (*clinic).strCost);
    for (int i = 0; i < (*patientAmount); i++){
        averagePatientSpentTime += patientArray[i].timeSpent;
    }
    averagePatientSpentTime /= (*patientAmount);
    (*clinic).averagePatientTime = averagePatientSpentTime;
    //printf("Pacientu laukimo laiko vidurkis: %f\n",averagePatientSpentTime);
}
void calculateProcess2Effectiveness(Clinic *clinic, Patient *patientArray, int *patientAmount){
	float averagePatientSpentTime = 0;
	for (int i = 0; i < (*clinic).specialistAmount; i++){
		BigInt.add((*clinic).bigIntCost,(*clinic).specialist[i].bigIntCost);
	}
	for (int i = 0; i < (*clinic).doctorAmount; i++){
		BigInt.add((*clinic).bigIntCost,(*clinic).doctor[i].bigIntCost);
	}
	BigInt.toString((*clinic).bigIntCost, (*clinic).strCost, 500);
	//printf("Klinikos kaina: %s\n", (*clinic).strCost);
	for (int i = 0; i < (*patientAmount); i++){
		averagePatientSpentTime += patientArray[i].timeSpent;
	}
	averagePatientSpentTime /= (*patientAmount);
	(*clinic).averagePatientTime = averagePatientSpentTime;
	//printf("Pacientu laukimo laiko vidurkis: %f\n",averagePatientSpentTime);
}
Stats returnStatistics (Clinic *clinic, Patient *patientArr){
	Stats statistic;
	statistic.avgPatientAmount = 0;
	statistic.minPatientAmount = 0;
	statistic.maxPatientAmount = 0;
	statistic.minPatientTime = 100;
	statistic.maxPatientTime = -1;
	statistic.clinicBigIntCost = BigInt.create(0);
	statistic.strClinicCost = (char*) malloc (sizeof(char)*500);
	statistic.strClinicCost = (*clinic).strCost;
	BigInt.fromInt(statistic.clinicBigIntCost,0);
	statistic.clinicBigIntCost = (*clinic).bigIntCost;;
	statistic.avgPatientTime = (*clinic).averagePatientTime;
	statistic.incorrectlyAssignedPatientAmount = (*clinic).incorrectlyAssignedPatientAmount;
	statistic.servicedPatients = (*clinic).servicedPatients;
	statistic.maxSpecialistWorkingTime = (*clinic).maxSpecialistWorkingTime;
	for (int i = 0; i < (*clinic).servicedPatients; i++){
		if(abs((*clinic).averagePatientTime - patientArr[i].timeSpent) <= 8){
			statistic.avgPatientAmount++;
		}
		else if((*clinic).averagePatientTime - patientArr[i].timeSpent > 8){
			statistic.minPatientAmount++;
		}
		if((*clinic).averagePatientTime - patientArr[i].timeSpent < -8){
			statistic.maxPatientAmount++;
		}
		if (statistic.minPatientTime > patientArr[i].timeSpent)
			statistic.minPatientTime = patientArr[i].timeSpent;
		if (statistic.maxPatientTime < patientArr[i].timeSpent)
			statistic.maxPatientTime = patientArr[i].timeSpent;
	}
	return statistic;
}
void printStatistic (Stats *statistic){
	printf("Max darbo laikas: %d\n", (*statistic).maxSpecialistWorkingTime);
	printf("Aptarnauta pacientu: %d\n",(*statistic).servicedPatients);
	printf("Neteisingai priskirti pacientai: %d\n",(*statistic).incorrectlyAssignedPatientAmount);
	printf("Pacientu sk., kurie buvo aptarnauti per minimaliai minuciu: %d\n",(*statistic).minPatientAmount);
	printf("Pacientu sk., kurie buvo aptarnauti per vidutiniskai: %d\n",(*statistic).avgPatientAmount);
	printf("Pacientu sk., kurie buvo aptarnauti perdaugiausiai: %d\n",(*statistic).maxPatientAmount);
	printf("Trumpiausias aptarnavimo laikas: %dmin.\n",(*statistic).minPatientTime);
	printf("Vidutiniskas aptarnavimo laikas: %.2fmin.\n",(*statistic).avgPatientTime);
	printf("Ilgiausias aptarnavimo laikas: %dmin.\n",(*statistic).maxPatientTime);
	printf("Klinikos kaina: %s\n",(*statistic).strClinicCost);
}
Doctor generateDoctor (int cost){
	Doctor doc;
	doc.patientsAssigned = 0;
	doc.cost = 1000;
	doc.timeWorked = 0;
	doc.bigIntCost = BigInt.create(0);
	doc.strCost = (char*) malloc (sizeof(char)*500);
	BigInt.fromInt(doc.bigIntCost,doc.cost);
	BigInt.toString(doc.bigIntCost, doc.strCost, 5);
	doc.estimatedWorkTime = 0;
	return doc;
}
void visitDoctor(Patient *patient, Clinic *clinic, Doctor *doc){
	if ((*patient).health){
		(*patient).timeSpent += returnRandomNumber(6,10);
		(*doc).timeWorked +=10;
		(*patient).handled = TRUE;
	} else{
		(*patient).needsSpecialistType = rand() % (*clinic).specialistAmount;
		(*patient).goesDirectly = TRUE;
		(*patient).goesToType = (*patient).needsSpecialistType;
		(*patient).timeSpent += returnRandomNumber(6,10);
		(*doc).timeWorked +=10;
		(*patient).handled = FALSE;
		//printf("Pacientui reikia pas: %d\n",(*patient).goesToType);
	}
}
Patient *handlePatientArray2(Clinic *clinic, int *patientAmount){
	Patient *patientArr;
	int maxSpecialistTime = -1;
	generateEmptyPatientArray(&patientArr, (*patientAmount)+1);
	unsigned patientCount = 0;
	while (patientCount < (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 30) {
		for (int i = 0; i < (*clinic).doctorAmount; i++) {
			if (!isEmpty(&(*clinic).doctor[i].patientQueue)) {
				patientArr[patientCount] = Dequeue(&(*clinic).doctor[i].patientQueue);
				visitDoctor(&patientArr[patientCount], &(*clinic), &(*clinic).doctor[i]);
				if (patientArr[patientCount].handled) {
					(*clinic).servicedPatients++;
				} else {
					curePatient(&patientArr[patientCount], patientArr[patientCount].needsSpecialistType, &(*clinic));
					maxSpecialistTime = returnMaxSpecialistTime(&(*clinic));
					(*clinic).servicedPatients++;
					if (patientCount >= (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 45) break;
				}
				//printf("pacientas %d, laikas praleistas: %d, isgydytas?: %d\n",patientCount,patientArr[patientCount].timeSpent, patientArr[patientCount].handled);
				patientCount++;
			}
		}
		if (patientCount >= (*patientAmount) || maxSpecialistTime > (*clinic).workingTime - 45) break;
	}
	(*clinic).servicedPatients = patientCount;
	(*clinic).maxSpecialistWorkingTime = maxSpecialistTime;
	return patientArr;
}