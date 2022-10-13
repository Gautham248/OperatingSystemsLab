#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

int main()
{
	
	void *shared_memory;
	int shmid;
	shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
	printf("Key of shared memory = %d",shmid);
	shared_memory=shmat(shmid,NULL,0); //process attatched to shared memory
	printf("Process attatched at %p\n",shared_memory);
	
	
	printf("Enter some data into the shared memory");
	char buff[100];
	read(0,buff,100);
	strcpy(shared_memory,buff);
	printf("You wrote :%s\n",(char*)shared_memory);
}

//RECIEVER 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

int main()
{		
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid=shmget((key_t)2345,1024,0666);
	shared_memory=shmat(shmid,NULL,0);
	printf("Key of shared memory : %d",shmid);
	printf("Process attatched at : %p\n",shared_memory);
	printf("Data read from shared memory :%s ",(char*)shared_memory);
	
}

