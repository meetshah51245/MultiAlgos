#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindrome (char *string);
long long factorial (long long number);
char *reverseString (char *string);
int stringLength (char *string);
int armstrong (int number);
long long power (long long number, int pow);
int compareString (char* str1, char *str2);
double findMaximum (double *array, int array_size);
int linearSearch (double *array, int array_size, double num_to_search);
double *bubbleSort (double *array, int array_size);
double *mergeSort (double *array, int array_Size);
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
	char *str = (char *) malloc (100 * sizeof(char));
    char *dest = (char *) malloc (100 * sizeof(char));
	strcpy(str, input[0]);
    strcat(str, " ");  
	sprintf(str, "%s%d", str, is_pal);
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
    return dest;
}

char *factorial_Wrapper (char **input, int num_tok, int line_count)
{
    int in_num = atoi(input[1]);
   
    long long fact = factorial(in_num);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%.2lld", str, fact);
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
    return dest; 
}

char *reverseString_Wrapper (char **input, int num_tok, int line_count)
{  
    char *in_str = input[1];
   
    char *out_str = reverseString(in_str);
    char *str = (char *) malloc (100000 * sizeof(char));
	char *dest = (char *) malloc (100000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    strcat(str, out_str);
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
    return dest;
}

char *stringLength_Wrapper (char **input, int num_tok, int line_count)
{	
    char *in_str = input[1];
   
    int string_len = stringLength(in_str);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%d", str, string_len);
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
    return dest; 
}

char *armstrong_Wrapper (char **input, int num_tok, int line_count)
{
  
    int in_num = atoi(input[1]);
   
    int is_arm = armstrong(in_num);
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    sprintf(str, "%s%d", str, is_arm);  
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
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
	free(str);
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
	free(str);
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
	free(str);
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
	free(str);
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
	
	char *str = (char *) malloc (1000000 * sizeof(char));
	char *dest = (char *) malloc (1000000 * sizeof(char));
    strcpy(str, input[0]);
    strcat(str, " ");
    
	for(i = 0; i < array_size ; i++)
    {
       sprintf(str, "%s%.2lf ", str, sorted_array[i]);
    }
    
	sprintf(dest, "%d, %s", line_count, str);
	
    free(array);
	free(str);
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

	char *str = (char *) malloc (1000000 * sizeof(char));
    char *dest = (char *) malloc (1000000 * sizeof(char));
	
    strcpy(str, input[0]);
    strcat(str, " ");
   
    for(i = 0; i < array_size ; i++)
    {
       sprintf(str, "%s%.2lf ", str, sorted_array[i]);
    }
    
	sprintf(dest, "%d, %s", line_count, str);
	
    free(array);
	free(str);
    return dest;
}

char *comp_Wrapper (char **input, int num_tok, int line_count)
{	
    double res = computation();
    char *str = (char *) malloc (100 * sizeof(char));
	char *dest = (char *) malloc (100 * sizeof(char));
	strcpy(str, input[0]);
    strcat(str, " ");	
    sprintf(str, "%s%.2lf", str, res); 
	sprintf(dest, "%d, %s", line_count, str);
	free(str);
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
  
    char *str = (char *) malloc (1000000 * sizeof(char));
	char *dest = (char *) malloc (1000000 * sizeof(char));
    
	strcpy(str, input[0]);
    strcat(str, " ");
	
    for(i = 0; i < array_size ; i++)
    {  
        for(j = 0; j < array_size; j++)
        {
           sprintf(str, "%s%.2lf ", str, matrix_mul_result[i * array_size + j]);
        }
    }
	
   sprintf(dest, "%d, %s", line_count, str);
  
   free(matrix_mul_result); 
   free(array);
   free(str);
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
  {"dfs", dfs_Wrapper}
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

void get_command(char fileName[])
{
  int j;
  int i;
  char *token = NULL;
  char **input = NULL;
  int num_tok = 0;
  int cnt = 0;
  size_t len = 0;
  ssize_t read;
  char *line = NULL;
  int line_count = 0;
  char line_str[1000000];
  const char delim[2] = " ";
  FILE* fp = fopen(fileName, "rb");
  FILE* fp_out = fopen("output.txt", "w");

  // Check for file pointer
  if(fp == NULL)
  {
    printf("\nError reading file");
    exit(-1);
  }
  
  /* Get line from a file till the end of the file */
  while ((read = getline(&line, &len, fp)) != EOF)
  {
      cnt = 0;
      num_tok = 0;
      /* copy line into line_str */
      sprintf(line_str, "%s", line);
      /* Count Tokens */
      num_tok = cnt_tokens(line_str);
      /* Allocate memory to 2D pointers which points to line */
      input = (char **) malloc (num_tok * sizeof (char*));
      /* Divide line_str into tokens through delimiter  */
      token = strtok(line_str, delim);
      /*store token from a single line as 1D array */
      while(token != NULL)
      {
          input[cnt] = (char *) malloc (strlen(token) * sizeof(char));
          sscanf(token, "%s", input[cnt]);
          cnt++;
          token = strtok(NULL, delim);
      }
      /* Call wrappers by their name and functions match through function pointers stored in structure array */
      for (i = 0; i < (sizeof(function_map) / sizeof(function_map[0])); i++)
      {
          if (!strcmp(function_map[i].name, input[0]) && function_map[i].func)
          {
            char *temp = function_map[i].func(input, num_tok, line_count);
//            printf("%s\n", temp);
            fprintf(fp_out, "%s",temp);
			fprintf(fp_out, "\n");	
			free(temp);
		  }
      }
	  
	  for(i = 0; i <= cnt; i++)
	  {
		  input[cnt];
	  }
	  free(input);	
	  
	  line_count++;
      /* free memory for line and define it as null  */    	
      if (line != NULL)
      {
        free(line);
		line = NULL;
      }
  }
  /* Close the file */
  fclose(fp_out);
  fclose (fp);
}
