#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void get_command (char fileName[]);

typedef enum bool { false , true } bool;

int palindrome(char *string)
{
    int check, str_len, i, j = 0;
    char *reverse_str;
    char ch;
    str_len = strlen(string) + 1;	
    reverse_str = (char *) malloc (str_len * sizeof(reverse_str));	
    strcpy (reverse_str, string);
	
    for(i = str_len - 1; i > j; i--)
    {
        ch = string[i];
        string[i]= reverse_str[j];
        reverse_str[j] = ch;
        j++;
    }
	
    check = strcmp (string, reverse_str);
	
    if (check == 0)
	{
		free (reverse_str);
		return 1;
	}	
    else
	{
		free (reverse_str);
		return 0;
	}	
}

long long factorial (int number)
{
    long long fact = 1;
    int i;
	
    if (number == 0 || number == 1)
 	return fact;
    else 
    {	
		for(i = number; i > 1; i--)
		{
            fact = fact * i;
		}	
    }	
    return fact;
}



char *reverseString (char *string)
{
    int i, j;
    char ch;
   
    j = strlen(string) - 1;

    for(i = 0; i < j; i++) 
	{	
      ch = string[i];
      string[i] = string[j];
      string[j] = ch;
      j--;
   }
	
	return string;
}



int stringLength (char *string)
{
    int str_len;	
    for(str_len = 0; string[str_len] != '\0'; str_len++);	
    return str_len;
}



int armstrong (int number)
{
    int temp, reminder, result = 0;
    temp = number;

    while (temp != 0)
    {	
	reminder = temp % 10;
	result = result + reminder * reminder * reminder;
	temp = temp / 10;
    }

    if (result == number)
	return 1;
    else 
	return 0;
}


long long power (long long number, int pow)
{
    int i;
    long long result = 1;
	
    for (i = 0; i < pow; i++)
    {
	result = result * number;
    }		
	
    return result;
}

int compareString (char* str1, char *str2)
{
    if (strcmp(str1, str2) == 0)
 	return 1;
    else 
	return 0;
}



double findMaximum (double *array, int array_size)
{	
    double maximum = array[0];
    int i;
    for(i = 1; i < array_size ; i++)
    {
	if (array[i] > maximum)
	maximum = array[i];
    }	
	return maximum;
}



int linearSearch (double *array, int array_size, double num_to_search)
{
    int i;
    for (i = 1; i < array_size; i++)
    {
	if (num_to_search == array[i])
	    return i;
    }		
    return -1;
}


double *bubbleSort (double *array, int array_size)
{
    int i, j;
    double swap = 0.0;

    for(i = 0 ; i < ( array_size - 1 ); i++)
    {
       for(j = 0 ; j < (array_size - i - 1); j++)
       {
//          printf("%lf/%lf\n", array[j], array[j+1]);
          if(array[j] > array[j+1])
          {
             swap = array[j];
             array[j] = array[j+1];
             array[j+1] = swap;
           }
//           printf("%lf/%lf/%lf \n\n", array[j], array[j+1], swap);
        }
     }

    return array;
}


double *mergeSort (double *array, int array_size)
{
    int mid, i, j, k, l_count, r_count;
    double *left, *right;
	
    if(array_size < 2) 
	 return;  

     mid = array_size/2; 
     l_count = mid;
     r_count = array_size - mid;	
	
     left = (double*) malloc (l_count * sizeof(double)); 
     right = (double*) malloc (r_count * sizeof(double)); 
	
     for(i = 0; i < l_count; i++)
     { 
	left[i] = array[i];
     }		
    
     for(i = l_count; i < array_size; i++) 
     {	 right[i - l_count] = array[i];
     }	
  
     mergeSort(left, mid);   
     mergeSort(right, (array_size - mid));  
  
     i = j = k = 0;

     while(i < l_count && j < r_count)
     {
	if(left[i] < right[j]) 
	   array[k++] = left[i++];
	else 
  	   array[k++] = right[j++];
     }
     while(i < l_count) 
	array[k++] = left[i++];
     while(j < r_count) 
	array[k++] = right[j++];
    
     free(left);
     free(right);
	
     return array;
}


double computation()
{
	long i;
	double res = 0;
	double b = 6.4534534;
	double c = 7.86768;	
	
	// for(i = 0; i < INT_MAX; i++)
	// {
		// double a = (double)i;
		// res += ((b*c) + a)/(a+1) - c - b - a;
	// }

	return res;
}

double *matrixMult (double *Matrix, int array_size)
{
     double *Matrix_Mul_Result;
     double result = 0;
     int i, j, k;
	 
     Matrix_Mul_Result = (double *)malloc(array_size * array_size * sizeof(double));
    		
     for(i = 0; i < array_size; i++)
     {   	
	  for(j = 0; j < array_size; j++)
	  {  
	       result = 0;
	       for(k = 0; k < array_size; k++)
	       {	
	            result = result + Matrix[i * array_size + k] * Matrix[k * array_size + j]; 
	       }	
	       Matrix_Mul_Result[i * array_size + j] = result;
	   }
     }	
     return Matrix_Mul_Result;
}


int main (int argc, char *argv[])
{
	startT();
    get_command (argv[1]);
	stopT();
    return 0;
}

