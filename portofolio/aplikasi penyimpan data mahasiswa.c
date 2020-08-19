#include<stdio.h>
#include<string.h>
#include<conio.h>
char temp[10], nim[10], name[50], gender[50], address[50];

void cont(){
	printf("Press enter to continue...");
	getch();
	system("cls");
}

void add(){
	FILE *app=fopen("responsi.txt", "a");
	printf("======================= Add student data =======================\n");
	gets(temp);
	printf("Please enter the student's NIM (8 digit only) : ");
	gets(nim);
	fprintf(app,"%s\n", nim);
	printf("Please enter the student's name : ");
	gets(name);
	fprintf(app,"%s\n", name);
	printf("Please enter the student's gender (male/female) : ");
	gets(gender);
	fprintf(app,"%s\n", gender);
	printf("Please enter the student's address : ");
	gets(address);
	fprintf(app,"%s\n", address);
	fclose(app);
}

void show_all(){
	FILE *show = fopen("responsi.txt", "r");
	printf("======================= Show student data ======================\n");
	if(show==NULL){
		printf("File is empty\n");
	}
	else {
		int i = 1;
		while(fgets(nim, 10, show) != NULL){
			fgets(name, 50, show);
			fgets(gender, 50, show);
			fgets(address, 50, show);
			printf("No %d\nStudent's NIM \t\t: %s", i , nim);
			printf("Student's name \t\t: %s", name);
			printf("Student's gender \t: %s", gender);
			printf("Student's address \t: %s", address);
			printf("================================================================\n");
			i++;
		}
	}
	fclose(show);
}

void show_male(){
	FILE *show = fopen("responsi.txt", "r");
	printf("======================= Show student data ======================\n");
	if(show==NULL){
		printf("File is empty\n");
	}
	else {
		int i = 1;
		while(fgets(nim, 10, show) != NULL){
			fgets(name, 50, show);
			fgets(gender, 50, show);
			fgets(address, 50, show);
			
			if(strcmp(gender, "male\n")==0){
				printf("No %d\nStudent's NIM \t\t: %s", i , nim);
				printf("Student's name \t\t: %s", name);
				printf("Student's gender \t: %s", gender);
				printf("Student's address \t: %s", address);
				printf("================================================================\n");
				i++;
			}
		}
	}
	fclose(show);
}

void show_female(){
	FILE *show = fopen("responsi.txt", "r");
	printf("======================= Show student data ======================\n");
	if(show==NULL){
		printf("File is empty\n");
	}
	else {
		int i = 1;
		while(fgets(nim, 10, show) != NULL){
			fgets(name, 50, show);
			fgets(gender, 50, show);
			fgets(address, 50, show);
			
			if(strcmp(gender, "female\n")==0){
				printf("No %d\nStudent's NIM \t\t: %s", i , nim);
				printf("Student's name \t\t: %s", name);
				printf("Student's gender \t: %s", gender);
				printf("Student's address \t: %s", address);
				printf("================================================================\n");
				i++;
			}
		}
	}
	fclose(show);
}

void show_even(){
	FILE *show = fopen("responsi.txt", "r");
	printf("======================= Show student data ======================\n");
	if(show==NULL){
		printf("File is empty\n");
	}
	else {
		int i = 1;
		while(fgets(nim, 10, show) != NULL){
			fgets(name, 50, show);
			fgets(gender, 50, show);
			fgets(address, 50, show);
			char temp_nim = nim[7];
			int temp_odd = (int)temp_nim;
			if((int)temp_nim%2==0){
				printf("No %d\nStudent's NIM \t\t: %s", i , nim);
				printf("Student's name \t\t: %s", name);
				printf("Student's gender \t: %s", gender);
				printf("Student's address \t: %s", address);
				printf("================================================================\n");
				i++;
			}
		}
	}
	fclose(show);
}

void show_odd(){
	FILE *show = fopen("responsi.txt", "r");
	printf("======================= Show student data ======================\n");
	if(show==NULL){
		printf("File is empty\n");
	}
	else {
		int i = 1;
		while(fgets(nim, 10, show) != NULL){
			fgets(name, 50, show);
			fgets(gender, 50, show);
			fgets(address, 50, show);
			char temp_nim = nim[7];
			int temp_odd = (int)temp_nim;
			if((int)temp_nim%2==1){
				printf("No %d\nStudent's NIM \t\t: %s", i , nim);
				printf("Student's name \t\t: %s", name);
				printf("Student's gender \t: %s", gender);
				printf("Student's address \t: %s", address);
				printf("================================================================\n");
				i++;
			}
		}
	}
	fclose(show);
}

void reset(){
	FILE *reset=fopen("responsi.txt", "w");
	printf("==================== SIAKID PROGRAM MENU =======================\n");
	printf("File now empty\n");
	fclose(reset);
}

int main(){
	system("color a");
	int jalan=1;
	char menu[100];
	while(jalan){
	printf("==================== SIAKID PROGRAM MENU =======================\n");
	printf("1. Add student data\n");
	printf("2. Show all students data\n");
	printf("3. Show only the male students data\n");
	printf("4. Show only the female students data\n");
	printf("5. Show only the students data with odd NIM\n");
	printf("6. Show only the students data with even NIM\n");
	printf("0. Exit\n\n");
	printf("type 'reset' to delete all data\n\n");
	printf("Choose what do yo want from siakid program menu : ");
	scanf("%s", &menu);
	system("cls");
	if(atoi(menu)==1){
		add();
		cont();
	}
	else if(atoi(menu)==2){
		show_all();
		cont();
	}
	else if(atoi(menu)==3){
		show_male();
		cont();
	}
	else if(atoi(menu)==4){
		show_female();
		cont();
	}
	else if(atoi(menu)==5){
		show_odd();
		cont();
	}
	else if(atoi(menu)==6){
		show_even();
		cont();
	}
	else if(strcmp(menu, "reset")==0){
		reset();
		cont();
	}
	else if(atoi(menu)==0){
		printf("\nThanks you for using our program");
		break;
	}
	else{
		printf("\nIt's not valid\n\n");
		cont();
	}
	}
}
