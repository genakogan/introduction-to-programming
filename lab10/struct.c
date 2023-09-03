#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sizestr 20
#define CODE_ERROR -1
#define SUCCESS 1

struct date {
	int day, month, year;
};
struct lecturer {
	char *name;
	struct date birthdate;
	int num_of_course;
	char**courses;
};

int InputLecturer(struct lecturer *pLect);
int InitLecturer(struct lecturer **plecturer);
void InputDate(struct date* pDate);
int InputLecturer(struct lecturer *pLect);
void FreeAll(struct lecturer** plecturer, int count);
int CourseLecturers(struct lecturer *plecturer, int sizeInMain, char *nameOfCourse);
int CommonCurses(struct lecturer *plecturer, int sizeInMain, char *name1, char *name2);
void inputNameOfLec(char *name1, char *name2);
int old(struct lecturer *plecturer, int sizeInMain, struct date pDate);


//--------------------------------------------------------------------

int main() {

	struct lecturer *sce = NULL;
	struct date *numDate = (struct date*)malloc(sizeof(struct date));
	int size, len;
	char nameOfCourse[sizestr], name1[sizestr], name2[sizestr];
	//-------------------------------------------------
	size = InitLecturer(&sce);
	//-------------------------------------------------
	printf("\nEnter name of course to search:---> ");
	//getchar();
	/*fgets(nameOfCourse, sizestr - 1, stdin);*/
	scanf("%s", nameOfCourse);

	len = strlen(nameOfCourse);
	/*if (len > 0 && nameOfCourse[len - 1] == '\n')
	nameOfCourse[len - 1] = '\0';*/
	//-------------------------------------------------
	CourseLecturers(sce, size, nameOfCourse);
	//-------------------------------------------------
	inputNameOfLec(name1, name2);
	CommonCurses(sce, size, name1, name2);
	//-------------------------------------------------
	printf("\n=========================================================\n");
	InputDate(numData);
	old(sce, size, *numData);
	//-------------------------------------------------
	FreeAll(&sce, size);
	free(numData);

	return 0;
}

//--------------------------------------------------------------------

int InitLecturer(struct lecturer **plecturer) {

	int sizelec, i, status;
	//-------------------------------------------------
	printf("\nEnter the number of lecturer:---> ");
	scanf("%d", &sizelec);
	*plecturer = (struct lecturer*)malloc(sizeof(struct lecturer)*sizelec);
	if (*plecturer == NULL) {
		printf("Not enouth memory");
		exit(1);
	}
	//printf("\nEnter data for  %d lecture:\n", sizelec);
	for (i = 0;i < sizelec;i++) {

		status = InputLecturer(&(*plecturer)[i]);
		if (status == CODE_ERROR) {
			printf("Not enouth memory");
			//Input free function
			exit(1);
		}
	}
	return sizelec;
}

//--------------------------------------------------------------------
//input date of lecture
void InputDate(struct date* pDate) {

	printf("\nEnter date of lecture:---> ");
	scanf("%d%d%d", &pDate->day, &pDate->month, &pDate->year);

}

//--------------------------------------------------------------------

int InputLecturer(struct lecturer *pLect) {
	char buffer[sizestr];
	char buffer2[sizestr];
	int i, len;
	//-------------------------------------------------
	printf("\nEnter a lrcturer's name:---> ");
	getchar();
	fgets(buffer, sizestr - 1, stdin);
	len = strlen(buffer);
	if (len > 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	pLect->name = (char*)malloc(strlen(buffer) + 1);
	strcpy(pLect->name, buffer);
	//-------------------------------------------------
	InputDate(&pLect->birthdate);
	//-------------------------------------------------
	printf("\nEnter number of courses:---> ");
	scanf("%d", &pLect->num_of_course);
	pLect->courses = (char**)malloc(sizeof(char*)*pLect->num_of_course);
	if (pLect->courses == NULL) {
		printf("Not enouth memory");
		return CODE_ERROR;
	}
	//printf("\nEnter name of courses:---> ");
	for (i = 0;i < pLect->num_of_course;i++) {
		printf("\nEnter name of %d courses:---> ", i + 1);

		getchar();
		/*fgets(buffer2, sizestr-1, stdin);

		len = strlen(buffer2);
		if (len > 0 && buffer2[len - 1] == '\n')
		buffer2[len - 1] = '\0';*/

		scanf("%s", buffer2);

		len = strlen(buffer2);

		pLect->courses[i] = (char*)malloc(strlen(buffer2) + 1);
		strcpy(pLect->courses[i], buffer2);
	}
	printf("\n=========================================================\n");

	return SUCCESS;
}



//--------------------------------------------------------------------

void FreeAll(struct lecturer** plecturer, int count) {

	int i;
	for (i = 0;i < count;i++) {
		free((*plecturer)[i].name);
	for(int j=0;j<(*plecturer)[j].num_of_course;j++)
		free((*plecturer)[i].courses[j]);
	}
	free(*plecturer);

}

//--------------------------------------------------------------------

int CourseLecturers(struct lecturer *plecturer, int sizeInMain, char *nameOfCourse) {
	
	int i, j;
	printf("\nLecturers of course [%s] is:\n", nameOfCourse);
	for (i = 0;i < sizeInMain;i++) {
		for (j = 0;j < plecturer[i].num_of_course;j++) {
			if (strcmp(plecturer[i].courses[j], nameOfCourse) == 0)
				printf("\n\t%s\n", plecturer[i].name);

		}
	}
	printf("\n");

	return 0;
}

//--------------------------------------------------------------------


int CommonCurses(struct lecturer *plecturer, int sizeInMain, char *name1, char *name2) {

	int i, j, indexname1=-1, indexname2=-1;
	for (i = 0;i <sizeInMain;i++) {
		if (strcmp(plecturer[i].name, name1) == 0)
			indexname1 = i;
		if (strcmp(plecturer[i].name, name2) == 0)
			indexname2 = i;
	}
	if (indexname1 == -1|| indexname2 == -1){
		printf("Not found\n");

		return 0;
	} 
	printf("\nThe names of the lecturers of all the common courses: \n");
	int flag = 0;
	for (i = 0;i < plecturer[indexname1].num_of_course;i++) {
		for (j = 0;j < plecturer[i].num_of_course;j++) {
			//if (strcmp(plecturer[indexname1].courses[i], plecturer[indexname2].courses[j]) != 0)
			
			if (strcmp(plecturer[indexname1].courses[i], plecturer[indexname2].courses[j]) == 0)
				printf("\n\t%s\n", plecturer[indexname1].courses[i]);
		}
	}
	
		
	return 0;
}

void inputNameOfLec(char *name1, char *name2) {
	printf("\n=========================================================\n");
	int len = 0;
	printf("\nEnter name of first lecturer:---> ");
	getchar();
	fgets(name1, sizestr - 1, stdin);
	len = strlen(name1);
	if (len > 0 && name1[len - 1] == '\n')
		name1[len - 1] = '\0';


	printf("\nEnter name of second lecturer:---> ");


	fgets(name2, sizestr - 1, stdin);
	len = strlen(name2);
	if (len > 0 && name2[len - 1] == '\n')
		name2[len - 1] = '\0';

}
int old(struct lecturer *plecturer, int sizeInMain, struct date pDate) {


	int i;
	printf("The lecturers who were born before this date is:\n");
	for (i = 0;i < sizeInMain;i++) {
		if (pDate.year > plecturer[i].birthdate.year)
			printf("\n\t%s\n", plecturer[i].name);
		if (pDate.year == plecturer[i].birthdate.year && pDate.month > plecturer[i].birthdate.month)
			printf("\n\t%s\n", plecturer[i].name);
		if (pDate.year == plecturer[i].birthdate.year && pDate.month == plecturer[i].birthdate.month && pDate.day > plecturer[i].birthdate.day)
			printf("\n\t%s\n", plecturer[i].name);

	}



	return 0;
}



