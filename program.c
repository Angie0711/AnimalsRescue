#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    struct Animal {
    char typeOfAnimal[50];
    char nameOfAnimal[20];
    char dateOfAccommodation[50];
    char dateOfCastration[50];
    char dateOfAdoption[50];
    };

    struct Animal Animal1;
    struct Animal Animal2;
    struct Animal Animal3;
    struct Animal Animal4;
    struct Animal Animal5;
    struct Animal Animal6;
    struct Animal Animal7;
    struct Animal Animal8;
    struct Animal Animal9;
    struct Animal Animal10;
    struct Animal read_from_file;

// Create information for the animals

    strcpy(Animal1.typeOfAnimal, "cat"); 
    strcpy(Animal1.nameOfAnimal, "Mila");
    strcpy(Animal1.dateOfAccommodation, "01.01.2019");
    strcpy(Animal1.dateOfCastration, "12.01.2019");
    strcpy(Animal1.dateOfAdoption, "11.01.2020");

    strcpy(Animal2.typeOfAnimal, "dog"); 
    strcpy(Animal2.nameOfAnimal, "Denis");
    strcpy(Animal2.dateOfAccommodation, "12.12.2019");
    strcpy(Animal2.dateOfCastration, "12.01.2019");
    strcpy(Animal2.dateOfAdoption, "11.02.2020");
    
    strcpy(Animal3.typeOfAnimal, "cat"); 
    strcpy(Animal3.nameOfAnimal, "Kulie");
    strcpy(Animal3.dateOfAccommodation, "03.09.2020");
    strcpy(Animal3.dateOfCastration, "13.10.2020");
    strcpy(Animal3.dateOfAdoption, "01.11.2020");
    
    strcpy(Animal4.typeOfAnimal, "dog"); 
    strcpy(Animal4.nameOfAnimal, "Polie");
    strcpy(Animal4.dateOfAccommodation, "02.02.2020");
    strcpy(Animal4.dateOfCastration, "03.03.2020");
    strcpy(Animal4.dateOfAdoption, "09.01.2021");
    
    strcpy(Animal5.typeOfAnimal, "dog"); 
    strcpy(Animal5.nameOfAnimal, "Strike");
    strcpy(Animal5.dateOfAccommodation, "17.03.2020");
    strcpy(Animal5.dateOfCastration, "12.04.2020");
    strcpy(Animal5.dateOfAdoption, "02.12.2020");
    
    strcpy(Animal6.typeOfAnimal, "dog"); 
    strcpy(Animal6.nameOfAnimal, "Sinty");
    strcpy(Animal6.dateOfAccommodation, "19.08.2020");
    strcpy(Animal6.dateOfCastration, "07.04.2021");
    strcpy(Animal6.dateOfAdoption, "30.06.2021");
    
    strcpy(Animal7.typeOfAnimal, "cat"); 
    strcpy(Animal7.nameOfAnimal, "Nora");
    strcpy(Animal7.dateOfAccommodation, "01.01.2019");
    strcpy(Animal7.dateOfCastration, "01.01.2020");
    strcpy(Animal7.dateOfAdoption, "01.01.2021");
    
    strcpy(Animal8.typeOfAnimal, "dog"); 
    strcpy(Animal8.nameOfAnimal, "Pendo");
    strcpy(Animal8.dateOfAccommodation, "17.07.2020");
    strcpy(Animal8.dateOfCastration, "06.08.2020");
    strcpy(Animal8.dateOfAdoption, "15.11.2020");
    
    strcpy(Animal9.typeOfAnimal, "cat"); 
    strcpy(Animal9.nameOfAnimal, "Isabelle");
    strcpy(Animal9.dateOfAccommodation, "06.06.2019");
    strcpy(Animal9.dateOfCastration, "19.07.2021");
    strcpy(Animal9.dateOfAdoption, "30.08.2021");
    
    strcpy(Animal10.typeOfAnimal, "cat"); 
    strcpy(Animal10.nameOfAnimal, "Berry");
    strcpy(Animal10.dateOfAccommodation, "11.11.2020");
    strcpy(Animal10.dateOfCastration, "11.02.2020");
    strcpy(Animal10.dateOfAdoption, "11.11.2021");

// Container - array of structures

    struct Animal animal[10] = {Animal1, Animal2, Animal3, 
        Animal4, Animal5, Animal6, 
        Animal7, Animal8, Animal9, 
        Animal10};

// Write

	pid_t childId=0;
	int pipe_fd = 0;
	mkfifo("test", 0666);
	childId= fork();
	if(0 == childId)
	{
	  	pipe_fd = open("test", O_WRONLY);
	  
		    for(int i = 0; i < (sizeof animal / sizeof animal[0]); i++)
		    {
		        write (pipe_fd, &animal[i], sizeof (struct Animal));
		    }
  
   		close (pipe_fd);
	} 
	else if (0 < childId)
	{ 
		pipe_fd = open("test", O_WRONLY);
		    while(read(pipe_fd,&read_from_file, sizeof(struct Animal)))
		    { 
		    	
		        printf ("%s %s %s %s %s\n", read_from_file.typeOfAnimal, read_from_file.nameOfAnimal, read_from_file.dateOfAccommodation, read_from_file.dateOfCastration, read_from_file.dateOfAdoption); 
      		}
    }
    close (pipe_fd);

    return 0;
}
