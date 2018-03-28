#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mpi.h"
#define tag_send 1
#define tag_recv 2
#define tag_done 0

int palindrome (char *);
long long factorial (long long);
char *reverseString (char *);
int stringLength (char *);
int armstrong (int);
long long power (long long , int);
int compareString (char * , char *);
double findMaximum (double *, int);
int linearSearch (double *, int, double);
double *bubbleSort (double *, int);
double *mergeSort (double *, int);
double computation();

/* Construct wrappers to call implemented functions of algorithms and called by function pointers */
char *palindrome_Wrapper(char **input, int num_tok, int line_count)
{  
//	printf("line count : %d\n", line_count);
    // 1. Construct input arguments
    char *in_str = input[1];
    // 2. Call main palinrome function with input arguments constructed in step 1.
    int is_pal = palindrome(in_str);
    // 3. Construct output string and send it back to write in some file.
	char *str = (char *) malloc (1000 * sizeof(char));
    char *dest = (char *) malloc (1000 * sizeof(char));
	strcpy(str, input[0]);
    strcat(str, " ");  
	sprintf(str, "%s%d", str, is_pal);
	sprintf(dest, "%d, %s", line_count, str);
    return dest;
}

char *factorial_Wrapper (char **input, int num_tok, int line_count)
{
    int in_num = atoi(input[1]);
   
    long long fact = factorial(in_num);
    char *str = (char *) malloc (1000 * sizeof(char));
	char *dest = (char *) malloc (1000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%.2lld", str, fact);
	sprintf(dest, "%d, %s", line_count, str);
    return dest; 
}

char *reverseString_Wrapper (char **input, int num_tok, int line_count)
{  
    char *in_str = input[1];
   
    char *out_str = reverseString(in_str);
    char *str = (char *) malloc (10000000 * sizeof(char));
	char *dest = (char *) malloc (10000000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    strcat(str, out_str);
	sprintf(dest, "%d, %s", line_count, str);
    return dest;
}

char *stringLength_Wrapper (char **input, int num_tok, int line_count)
{	
    char *in_str = input[1];
   
    int string_len = stringLength(in_str);
    char *str = (char *) malloc (1000 * sizeof(char));
	char *dest = (char *) malloc (1000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%d", str, string_len);
	sprintf(dest, "%d, %s", line_count, str);
    return dest; 
}

char *armstrong_Wrapper (char **input, int num_tok, int line_count)
{
  
    int in_num = atoi(input[1]);
   
    int is_arm = armstrong(in_num);
    char *str = (char *) malloc (100000 * sizeof(char));
	char *dest = (char *) malloc (100000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%d", str, is_arm);  
	sprintf(dest, "%d, %s", line_count, str);
    return dest;
}

char *power_Wrapper (char **input, int num_tok, int line_count)
{	
    int in_num = atoi(input[1]);
    int pow = atoi(input[2]); 
   
    long long pow_ans = power(in_num, pow);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%lld", str, pow_ans);
	sprintf(dest, "%d, %s", line_count, str);
    return dest;
}

char *compareString_Wrapper (char **input, int num_tok, int line_count)
{  
    char *inStr1 = input[1];
    char *inStr2 = input[2];	
  
    int is_same  = compareString(inStr1, inStr2);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");	
    sprintf(str, "%s%d", str, is_same);
	sprintf(dest, "%d, %s", line_count, str);
    return dest;
}

char *findMaximum_Wrapper (char **input, int num_tok, int line_count)
{  
    int i;
    int array_size = num_tok - 1;
    double *array  = (double *) malloc (array_size * sizeof(double));
  
    for(i = 0; i < array_size ; i++)
    {  
       array[i] = atof(input[i+1]);
    }
  
    double max_num = findMaximum(array, array_size);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");	
    sprintf(str, "%s%.2lf", str, max_num); 
	sprintf(dest, "%d, %s", line_count, str);
    
    free(array);
    return dest;
}

char *linearSearch_Wrapper (char **input, int num_tok, int line_count)
{	
    int i;
	double num_to_search = atof(input[1]);
    int array_size = num_tok - 2;
    double *array  = (double *) malloc (array_size * sizeof(double));

    for(i = 0; i < array_size ; i++)
    {
       array[i] = atof(input[i+2]);
    }
   
    int index_pos = linearSearch(array,array_size, num_to_search);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");	
    sprintf(str, "%s%d", str, index_pos);  
	sprintf(dest, "%d, %s", line_count, str);
    
    free(array);
    return dest;
}

char *bubbleSort_Wrapper (char **input, int num_tok, int line_count)
{  
  
	int i;
    int array_size = num_tok - 1;
    double *array  = (double *) malloc (array_size * sizeof(double));

    for(i = 0; i < array_size ; i++)
    {
       array[i] = atof(input[i+1]);
    }

    double *sorted_array = (double *) malloc (array_size * sizeof(double));
    sorted_array =  bubbleSort(array,array_size);
	
	char *str = (char *) malloc (10000000 * sizeof(char));
	char *dest = (char *) malloc (10000000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    
	for(i = 0; i < array_size ; i++)
    {
       sprintf(str, "%s%.2lf ", str, sorted_array[i]);
    }
    
	sprintf(dest, "%d, %s", line_count, str);
	
    free(array);
    return dest;
}

char *mergeSort_Wrapper (char **input, int num_tok, int line_count)
{

	int i;
    int array_size = num_tok - 1;
    double *array  = (double *) malloc (array_size * sizeof(double));

    for(i = 0; i < array_size ; i++)
    {
       array[i] = atof(input[i+1]);
    }

    double *sorted_array = (double *) malloc (array_size * sizeof(double));
    sorted_array = mergeSort(array,array_size);

	char *str = (char *) malloc (10000000 * sizeof(char));
    char *dest = (char *) malloc (10000000 * sizeof(char));
	
    strcpy(str, input[0]);
    strcat(str, " ");
   
    for(i = 0; i < array_size ; i++)
    {
       sprintf(str, "%s%.2lf ", str, sorted_array[i]);
    }
    
	sprintf(dest, "%d, %s", line_count, str);
	
    free(array);
    return dest;
}

char *comp_Wrapper (char **input, int num_tok, int line_count)
{	
    double res = computation();
    char *str = (char *) malloc (1000 * sizeof(char));
	char *dest = (char *) malloc (1000 * sizeof(char));
	strcpy(str, input[0]);
    strcat(str, " ");	
    sprintf(str, "%s%.2lf", str, res); 
	sprintf(dest, "%d, %s", line_count, str);
    return dest;  
}

char *matrixMult_Wrapper (char **input, int num_tok, int line_count)
{
  
   int i, j, k = 2;
   int array_size = atof(input[1]);
//   printf("%d\n", array_size);
   double *array  = (double *) malloc (array_size * array_size * sizeof(double));
   
   for(i = 0; i < array_size ; i++)
   {
      for(j = 0; j < array_size; j++)
      {
          array[i * array_size + j] = atof(input[k++]);
      }	
   }
   
    double *matrix_mul_result = matrixMult(array, array_size);
  
    char *str = (char *) malloc (100000000 * sizeof(char));
	char *dest = (char *) malloc (100000000 * sizeof(char));
    
	strcpy(str, input[0]);
    strcat(str, " ");
	
    for(i = 0; i < array_size ; i++)
    {  
        for(j = 0; j < array_size; j++)
        {
           sprintf(str, "%s%.2lf ", str, matrix_mul_result[i*array_size+j]);
        }
    }
	
   sprintf(dest, "%d, %s", line_count, str);
  
   free(array); 	
   return dest;
}

char *bfs_Wrapper (char **input, int num_tok, int line_count)
{
	char *str = (char *) malloc (50 * sizeof(char));
	sprintf(str, "%d, %s", line_count, input[0]);
	strcat(str, " NOT IMPLEMENTED");
	return str;
}

char *dfs_Wrapper (char **input, int num_tok, int line_count)
{
	char *str = (char *) malloc (50 * sizeof(char));
	sprintf(str, "%d, %s", line_count, input[0]);
	strcat(str, " NOT IMPLEMENTED");
	return str;
}

/* Create structure array to store function pointers and function names */
const static struct
{
  const char *name;
  char *(*func)(char**, int, int);
} function_map [] = {
  {"palindrome", palindrome_Wrapper},
  {"factorial", factorial_Wrapper},
  {"reverseString", reverseString_Wrapper},
  {"stringLength", stringLength_Wrapper},
  {"armstrong", armstrong_Wrapper},
  {"power", power_Wrapper},
  {"compareString", compareString_Wrapper},
  {"findMaximum",findMaximum_Wrapper},
  {"linearSearch", linearSearch_Wrapper},
  {"bubbleSort", bubbleSort_Wrapper},
  {"mergeSort", mergeSort_Wrapper},
  {"comp", comp_Wrapper},
  {"matrixMult", matrixMult_Wrapper},
  {"bfs", bfs_Wrapper},
  {"dfs", bfs_Wrapper},
};

/* Counter number of tokens in a line through number of space count in a line(token = spaceCount+1)*/
int cnt_tokens(char *ch)
{
  int cnt = 0;
  /*Counting number of space */	
  while (*ch != 0)
  {
     if (*ch == ' ')
       cnt++;
     ch++;
  }
  /* return token = spaceCount+1 */
  return (cnt + 1);
}

void get_command(char *fileName, int argc, char **argv)
{
  int i;
  size_t len = 0;
  ssize_t read;
  char *line;
  char *ans_line;
  int line_count = 0;
  int count = 0;
  int index = 0;
  int line_length;
  int line_lengthM;
  const char delim[2] = " ";
  int numtasks;
  int  rc;
  int rank;
  MPI_Status status;
  
  /* Initialize the MPI environment */
  rc = MPI_Init(&argc, &argv); 
  
  if(rc != MPI_SUCCESS)
  {
     printf ("Error starting MPI program. Terminating. \n");
     MPI_Abort (MPI_COMM_WORLD, rc);
  }
  
  /* Get the number of processes */
  MPI_Comm_size (MPI_COMM_WORLD, &numtasks);

  /* Get the rank of the process */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  
  if(rank == 0) { 
	startT();
	FILE* fp = fopen(fileName, "rb");
	FILE* fp_out = fopen("output.txt", "w");
	char **ptr = (char**) malloc (1000 * sizeof(char*));
	
	// Check for file pointer	
	if(fp == NULL)
	{
		printf("\nError reading file");
		exit(-1);
	}
		 
	/* Get line from a file till the end of the file */
	while ((read = getline(&line, &len, fp)) != EOF)
	{
	  ptr[line_count] = (char *) malloc ((strlen(line)+1) * sizeof(char));
	  strcpy(ptr[line_count], line);
	  
	  if(line != NULL)
	  {
		free(line);
		line = NULL;
	  }
	  line_count++;    	
	}
	
	fclose(fp);
	
	i = 1;
	for (index = 0; index < line_count && index < numtasks - 1; index++)
	{
		line_length = strlen(ptr[index])+1;
		MPI_Send(&index, 1, MPI_INT, i, tag_send, MPI_COMM_WORLD);
//		printf("index : %d\n", index);	
		MPI_Send(&line_length, 1, MPI_INT, i, tag_send, MPI_COMM_WORLD);
//		printf("rank : %d line_length : %d\n",i, line_length);
		MPI_Send(ptr[index], line_length, MPI_CHAR, i, tag_send, MPI_COMM_WORLD);	
//		printf("ptr[index] : %s\n", ptr[index]);	
		i++;
	}	
	
	while (count < line_count)
	{
		/*receive length of resulted string*/
		MPI_Recv(&line_lengthM, 1, MPI_INT, MPI_ANY_SOURCE, tag_recv, MPI_COMM_WORLD, &status);
		ans_line = (char*) malloc (line_lengthM * sizeof(char));
		/*receive resulted string*/
		MPI_Recv(ans_line, line_lengthM, MPI_CHAR, status.MPI_SOURCE, tag_recv, MPI_COMM_WORLD, &status);
//		printf("ans_line : %s\n", ans_line);
//		printf("check for segmentation fault\n");
		count++;
		fprintf(fp_out, "%s",ans_line);
	    fprintf(fp_out, "\n");	
		
		if(index < line_count)
		{
//			printf("status.MPI_SOURCE : %d\n", status.MPI_SOURCE);
			line_length = strlen(ptr[index])+1;
			MPI_Send(&index, 1, MPI_INT, status.MPI_SOURCE, tag_send, MPI_COMM_WORLD);
			MPI_Send(&line_length, 1, MPI_INT, status.MPI_SOURCE, tag_send, MPI_COMM_WORLD);
//			printf("rank : %d line_length : %d\n", status.MPI_SOURCE, line_length);
			MPI_Send(ptr[index], line_length, MPI_CHAR, status.MPI_SOURCE, tag_send, MPI_COMM_WORLD);
	//		printf("line : %s\n", ptr[index]);
			index++;
		}
	}
	
	for(i = 1; i < numtasks; i++)
	{
		MPI_Send(&i, 1, MPI_INT, i, tag_done, MPI_COMM_WORLD);
	}
	
	/* Close the file */
		
	fclose(fp_out);
	stopT();
  } 
  
   if(rank > 0)
   {	  
	int line_lengthR;
	int indexR;
	char line_str[1000000];
	char **input;
	char *token;
	char *temp;
	char *lineR;
	int num_tok = 0;
	int cnt = 0;
	
	do{ 
//		printf("rank = %d\n", rank);
		MPI_Recv(&indexR, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
//		printf("IndexR : %d\n",indexR);
		
		if(status.MPI_TAG != tag_done)
		{	
			MPI_Recv(&line_lengthR, 1, MPI_INT, 0, tag_send, MPI_COMM_WORLD, &status);	
	//		printf("rank : %d line_lengthR: %d\n", rank, line_lengthR);
			lineR = (char *) malloc (line_lengthR * sizeof(char));
			MPI_Recv(lineR, line_lengthR, MPI_CHAR, 0, tag_send, MPI_COMM_WORLD, &status);
//			printf("rank : %d lineR: %s\n", rank, lineR);
			
			sprintf(line_str, "%s", lineR);
	
			// count tokens
			num_tok = cnt_tokens(line_str);
	//		printf("num_tok : %d\n", num_tok);
			/* Allocate memory to 2D pointers which points to line */
			input = (char**) malloc (num_tok * sizeof(char*));
 
			/* Divide line_str into tokens through delimiter  */
			token = strtok(lineR, delim);
		 
		    cnt = 0;
			/*store token from a single line as 1D array */
			while(token != NULL)
			{ 
				input[cnt] = (char *) malloc ((strlen(token)+1) * sizeof(char));
				sscanf(token, "%s", input[cnt]);
				cnt++;
				token = strtok(NULL, delim);
			}
			
			/* Call wrappers by their name and functions match through function pointers stored in structure array */
			for(i = 0; i < (sizeof(function_map) / sizeof(function_map[0])); i++)
			{
				if(!strcmp(function_map[i].name, input[0]) && function_map[i].func)
				{	
					temp = function_map[i].func(input, num_tok, indexR);
					
				}
			}
			/*Length of resulted string */
			line_length = strlen(temp) + 1;
			/* Sending length of the string to master node*/
			MPI_Send(&line_length, 1, MPI_INT, 0, tag_recv, MPI_COMM_WORLD);
			/* Sending resulted string to master node*/
			MPI_Send(temp, line_length, MPI_CHAR, 0, tag_recv, MPI_COMM_WORLD);
			
			free(temp);
			
		}	
		
	}while(status.MPI_TAG != tag_done);
	
  }
 MPI_Finalize();
}