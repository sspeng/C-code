/*
	Tier 3 : Part 2	:	Question 6
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct database
{
	char part_name[50];
	char part_section[50];
	int part_number;
	float part_price;
	double part_rating;
}var;

struct database list[10];

int add_parts()
{
	strcpy( list[0].part_name , "16x16 VGA display"); // the only way of putting a name into a struct
	strcpy( list[0].part_section , "Phone Parts");   // is by using strcpy
	list[0].part_number = 1;
	list[0].part_price = 16.50;
	list[0].part_rating = 4.5;
	
	strcpy( list[1].part_name , "AVR ATMEGA16");
	strcpy( list[1].part_section , "MicroControllers");  
	list[1].part_number = 2;
	list[1].part_price = 22.49;
	list[1].part_rating = 8.5;
	
	return 0;
}

int get_information_from_file()
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("part_database.txt","r");
	
	if(FILE_HANDLE == NULL)
	{
		printf("\r\n");
		exit(0);
	}
	else
	{
		int loop_counter;
	
		for(loop_counter=0;loop_counter<10;loop_counter++)
		{
			fscanf(FILE_HANDLE,"%s",&list[loop_counter].part_name);
			fscanf(FILE_HANDLE,"%s",&list[loop_counter].part_section);
			fscanf(FILE_HANDLE,"%d",&list[loop_counter].part_number);
			fscanf(FILE_HANDLE,"%f",&list[loop_counter].part_price);
			fscanf(FILE_HANDLE,"%lf",&list[loop_counter].part_rating);
		}
	}
	close(FILE_HANDLE);
	return 0;
}

int main()
{
	add_parts();
	
	get_information_from_file();
	
	int loop_counter;
	
	for(loop_counter=0;loop_counter<10;loop_counter++)
	{
		printf("Part Name    : %s \r\n",list[loop_counter].part_name);
		printf("Part section : %s \r\n",list[loop_counter].part_section);
		printf("Part number  : %d \r\n",list[loop_counter].part_number);
		printf("Price        : %.2f \r\n",list[loop_counter].part_price);
		printf("part rating  : %.2lf \r\n\n",list[loop_counter].part_rating);
	}
	
	return 0;
}