#include <stdio.h>
#include <conio.h>
#include <string.h>
struct record {
  char name[20];
  char gender[10];
  char  disease[40];
  int age;
  int id;
};
  // Created a count attempt variable to store the user attempts.
  int countAttempt = 0;
  struct record r[500]; // to record 500 datas in structure record

void loading() //defining function loading with no argument and no return type
{ 
   int i; 
   system("cls");
   system("COLOR 2F"); //to  bring green background and white font
   printf("\nLOADING..."); 
   for(i=0;i<105;i++) //to bring number of shape in loading
   {  
    Sleep(10); //to sleep for some seconds 
    printf("%c",222); // to display the desired shape in loading
   } 
}

void search() //defining search function with no arguments and return types
{ 
   	FILE *fp;
   	fp=fopen("Records.txt","r"); //opening file in  reading mode whcih reads the data beginning from the file
   	int id,i=0,j;
   	system("cls");
   	system("COLOR 1F"); //to  bring blue background and white font 
   	printf("\t\t\tEnter the id you want to search:");
   	scanf("%d",&id);
	while(!feof(fp)) //reads all the datas stored in a file till the end of file
	{  
    fscanf(fp,"%d\n%s\n%d\n%s\n%s\n",&r[i].id,&r[i].name,&r[i].age,&r[i].gender,&r[i].disease);
	i++;
	}
    printf("The ID you searched for %d details:\n",id);
    for(j=0;j<i;j++){
    if(id==r[j].id)// to compare the datas entered by the user and the datas stores stores in the file and if it matches then it will print the datas
	{ 
    printf("INDEX=%d\nUNIQUE id=%d\nName=%s\nAge=%d\nGender=%s\nDisease=%s\n",j,r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);
    printf("___________________________________________________________________________________________________________\n");
    break; //to terminate the program once the given continue is found true
    getch();
	}
    if(id>i){ // if the entered data is more than the data stored in a file then it will show the id is not found
	printf("\nID NOT FOUND....................\n");
	getch();
    }	
    }
    printf("............Press any key to go back..........");
    getch();
    fclose(fp);	//to close the file
}	

void update() //defining update function with no arguments and no return types
{    
	system("cls"); //to clear the screen and displaying the new screen
	system("COLOR 4F"); //to  bring red background and white font
	FILE *fp;
    int i=0,j;
    int up;
	fp=fopen("Records.txt","r"); //opening file in  reading mode which reads the data beginning from the file
    while(!feof(fp)){
    fscanf(fp,"%d\n%s\n%d\n%s\n%s\n",&r[i].id,&r[i].name,&r[i].age,&r[i].gender,&r[i].disease);
	i++;
    }
   	for(j=0;j<i;j++){
   	printf("INDEX=%d\nID=%d\nName=%s\nAge=%d\nGender=%s\nDisease=%s\n",j,r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);
   	printf("_____________________________________________________________________________________\n");
    }
   	fclose(fp);
	fp=fopen("Records.txt","w"); //opening file in writing mode
   	printf("\n\t\t\tEnter the index of patient you want to update:");
    scanf("%d",&up);
    printf("Enter UNIQUE id:");
	scanf("%d",&r[up].id);
	printf("Enter the name of patient:");
 	scanf("%s",&r[up].name);
 	printf("Enter the age of patient:");
 	scanf("%d",&r[up].age);
 	printf("Enter the gender of patient:");
 	scanf("%s",&r[up].gender);
 	printf("Enter for what  problem the patient is at hospital:");
 	scanf("%s",r[up].disease);
 	printf("\n");
 	printf(".............Thank you data of %s is updated successfully.............",r[up].name);
   	for(j=0;j<i;j++){	    	
	fprintf(fp,"%d\n%s\n%d\n%s\n%s\n\n",r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);	
	}
	fclose(fp);	
} 	

void deleterecord() //defining delete function with no arguments and return types
{
	system("cls");
	system("COLOR 5F"); //to  bring purple background and white font
	FILE *fp;
    int i=0,j;
    int del;
	fp=fopen("Records.txt","r"); //opening file in reading mode    
	while(!feof(fp)){
	fscanf(fp,"%d\n%s\n%d\n%s\n%s\n",&r[i].id,&r[i].name,&r[i].age,&r[i].gender,&r[i].disease);	
	i++;
   	}
   	for(j=0;j<i;j++)  	
	{
	printf("INDEX=%d\nUNIQUE id=%d\nName=%s\nAge=%d\nGender=%s\nDisease=%s\n",j,r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);		 
    printf("_____________________________________________________________________________________________________________________\n");
    }
	fclose(fp); 	
	fp=fopen("Records.txt","w");
   	printf("Enter the index of patient you want to delete:");
   	scanf("%d",&del);
  	for(j=0;j<i;j++)
    {
    if(j==del){ //the value will run but when j equals del then at that point the value will not display and again the value starts to display
	continue; //to program will run till the condition is found true and skip the equal condition value and again start to display the output	    	
	}
	fprintf(fp,"%d\n%s\n%d\n%s\n%s\n\n",r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);		
	}
	printf("............Press any key to go back..........");
	fclose(fp);	
}

void list()
{
	system("cls");
	system("COLOR 2F"); //to  bring green background and white font
	FILE *fp;
    int i=0,j;
	fp=fopen("Records.txt","r");
    printf("THE LIST OF PATIENTS:\n");
    printf("*********************\n");
    printf("*********************\n\n");
	while(!feof(fp)){
	fscanf(fp,"%d\n%s\n%d\n%s\n%s\n",&r[i].id,&r[i].name,&r[i].age,&r[i].gender,&r[i].disease);
	i++;
   	}
   	for(j=0;j<i;j++){		
    printf("ID=%d\nName=%s\nAge=%d\nGender=%s\nDisease=%s\n",r[j].id,r[j].name,r[j].age,r[j].gender,r[j].disease);    
    printf("==================================================================\n");}
    printf("............Press any key to go back..........");
    getch();
    fclose(fp);
}

void addrecords() //defining records function with no arguments and return types
{
	FILE *fp;
	int i;
	char ch;
	struct record r[500];
	system ("cls");
	system("COLOR 4F"); //to  bring red background and white font
	while(1){	
	fp = fopen("Records.txt","a"); //opening file in appending mode
	for(i=0;i<1;i++)
 	{
 	printf("Enter UNIQUE id:");
	scanf("%d",&r[i].id);
	printf("Enter the name of patient:");
 	scanf("%s",&r[i].name);
 	printf("Enter the age of patient:");
 	scanf("%d",&r[i].age);
 	printf("Enter the gender of patient:");
 	scanf("%s",&r[i].gender);
 	printf("Enter for what  problem the patient is at hospital:");
 	scanf("%s",r[i].disease);        
	fprintf(fp,"%d\n%s\n%d\n%s\n%s\n\n",r[i].id,r[i].name,r[i].age,r[i].gender,r[i].disease);
	}
	fclose(fp);
	printf ("\n\tDo you want to add the name of patient(Y/N): "); //asking user if the user wants to enter another record or not
	scanf (" %c", &ch);
    if(ch == 'y' || ch == 'Y')
    {
	}
    else
    {
   	loading();
    printf("\n\tThank you data is saved..."); 
    break;
	}
	}
}

void  main() //declearing main function which calls other function and it is callled by operating system itself
{
	int i,j;
 	int choice,patientnumber,wardnumber;
	char pass;
    char ch;
    char password[10];
 	system ("cls"); 
 	loading();
 	char username[10],name[20],gender[10],disease[40];	
    system("COLOR 1F"); //to  bring blue background and white font
    system ("cls");
    printf("\n\tWant to enter into the main page of hospital?");
    printf("\n\t    Provide the following information");
    printf("\n\t    *Username and Password required*\n\n");
    password:
    printf("\tEnter username: ");
    scanf("%s",username);
    printf("\tEnter password: ");
    for(i=0;i<5;i++)
    {
 	pass = getch();
    //Take user input if it the character is not backspace
 	if(pass != '\b'){
	password[i] = pass;
	printf("*");
	} 
	else
	{
    // if the user input is backspace ignore increment of i value.	
 	i--;
	}
    }
    // increase the user attempt by 1
    countAttempt = countAttempt+1; 	
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) //to compare the given string
    {
    printf("\nAccess granted\n");
    }
    else
    {		
	system ("cls");
	system("COLOR 5F"); //to  bring purple background and white font
	Beep(400, 350); //to produce a beep sound in program when user press incorrect username and password
	printf("Your number of attempts are: %d\n", countAttempt);
	printf("Sorry you entered wrong username and password!!");
    //If user attempt is greater than 3, stop the program.
	if(countAttempt>=3){
	goto cancel;
	} 
	printf("\n\n\n\n\t\t\t*Access Denied*\n");
	printf("\t\tPassword Hint: Starts with 'a'\n");
	printf("\t\tDo you want to enter it one more time\n");
	printf("\t\tNote: You can re-enter username and password only 3 times!!\n");
	printf("\t\tIf yes please enter either 'Y' or 'y' from your keyboard:"); 
	scanf (" %c", &ch);
	if(ch == 'Y' || ch == 'y') //when user press either Y or Y then it will again ask user to enter username and password
	{
	goto password;
	}
	else 
	if(ch!='Y'|| ch!='y') //if user does not press either Y or y then under such condition program will terminate
    goto cancel;
	}	
    loading();
 	while(1){ //the loop will continue till the user presses the incorrect choice 
	system("cls");
	system("cls");
	system("COLOR 1F"); //to  bring blue background and white font
	printf("\n\t\t\t\tWelcome to Mission Mars Hospital");
	printf("\n\t\t\t\t     Jorpati-7,Kathmandu");
	printf("\n\t\t\t\t  Contact Number:9843722829");
	printf("\n\t\t\t    <'Throw your disease before they grow'>");
 	printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 	printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
 	printf("\n\t\t\t  'What operation do you want to perform?'");
 	printf("\n\t\t\t\t'Choose the below options'");
 	printf("\n\t\t______________________________________________________________");
 	printf("\n\t\t______________________________________________________________\n");
 	printf("\n\t\t\t\tThe options are:");
 	printf("\n\t\t\t\t1.)Record of new patients in hospital \n\t\t\t\t2.)list of admitted patients in hospital \n\t\t\t\t3.)Search of patient by id \n\t\t\t\t4.)Update patient information by index number \n\t\t\t\t5.)Deleting records of discharged patient \n\t\t\t\t6.)Exit");
 	printf("\n\t\t****************************************************************");
	printf("\n\t\t====>Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
	case 1:
	system ("cls");
	addrecords(); //calling function for records()
	getch();
	break;
	case 2:
	system ("cls");
	list(); // calling function for list()
	getch();
	break;
	case 3:
	system ("cls");
	search(); // calling function for search()
	break;
	case 4:
	system ("cls");
    update(); // calling function for update()
	getch();
	break;
	case 5:
	system ("cls");
	deleterecord(); // calling function for delete()
	getch();
	break;
	case 6:
	loading();
	system("color 3F"); //to  bring aqua background and white font
	system("cls");
	printf("\n\n\n\t\t\t\tThank you!!!!!\n\n\n\n");	
    cancel:
	return; //exit function
	default:
	printf("Invalid choice"); //default function when user press non of the above
	sleep(1); //to sleep the program for sometimes
    }
    }
}

