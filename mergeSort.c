#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100
#define MIN 1


void mergeSort(int *arr, int *aux, int left, int right);
void merge(int *arr, int p, int q, int r);
void fill(int *arr, const int n, const int range, const int min);
void printArray(int *arr, const int n);

int main(int argc, char **argv)
{   int n;
    int *aux;
    int *arr;
    if(argc<2)
    {   printf("\033[1;31mERROR, NOT ENOUGH PARAMETERS INSERT, YOU MUST PUT THE LENGHT OF THE VECTOR OR THE ARGUMENTS OF THE VECTOR, WITH -f AT THE BEGINNGING\n\n\033[0m");

        return -1;
    }
    if(argv[1][0]=='-'&&argv[1][1]=='f'&&argv[1][2]=='\0')
    {
        if(argc>2)
        {   int i;
            n=argc-2;
            arr=malloc(sizeof(int)*n);
            for(i=2; i<argc; i++)
            {
                arr[i-2]=atoi(argv[i]);
            }
            aux=malloc(sizeof(int)*n);
        }
        else
        {
            printf("\033[1;31mYOU CAN'T USE THE SECOND OPTION OF THE PROGRAM WITHOUT TYPING A NUMBER, TYPE -help TO SEE THE MANUAL\n\n\033[0m");

            return -1;
        }
    }
    else if((argv[1][0]=='-'&&argv[1][1]=='h'&&argv[1][2]=='e'&&argv[1][3]=='l'&&argv[1][4]=='p'&&argv[1][5]=='\0')||(argv[1][0]=='-'&&argv[1][1]=='h'&&argv[1][2]=='\0'))
    {   
         printf("\033[0;32mHELP:\n\n\033[0m");
         printf("\033[0;32mTo that's a sorting software that work in command line.\n\033[0m");
         printf("\033[0;32mYou can typer \"-f\" to insert by yourself the input numbers,\n\033[0m");
         printf("\033[0;32mIt's even possible to generate casual numbers(form 1 to 100) by typing how many do you want\n\033[0m");
        return 0;
    }
    else
    {
        arr=(int*)malloc(sizeof(int)*atoi(argv[1]));
        n=atoi(argv[1]);
        aux=(int*)malloc(sizeof(int)*n);
        

        
        fill(arr, n, RANGE, MIN);
        printArray(arr, n);
    }
    



    

    mergeSort(arr, aux, 0, n-1);

    printArray(arr, n);
    
    free(aux);
    free(arr);

    return 0;
}

void mergeSort(int *arr, int *aux, int left, int right)
{
    
    if(left>=right) return; //int theory if the indexes are equal we are wasting time, so we can end the function

    int mid= (left+right)/2;
    mergeSort(arr, aux, left, mid);
    mergeSort(arr, aux, mid+1, right);


    int i = left, j= mid + 1, k= left;
    while(i<=mid&&j<=right) 
    {
        aux[k++]=(arr[i]<=arr[j])?arr[i++]:arr[j++];
    }
    while(i<=mid)aux[k++]=arr[i++];
    while(j<=right)aux[k++]=arr[j++];

    for(i=left; i<=right; i++) arr[i]=aux[i];
}



void fill(int *arr, const int n, const int range, const int min)
{   
    srand(time(NULL));

    int i;

    for(i=0; i<n; i++)
    {
        arr[i]=rand()%range+min;
    }
}

void printArray(int *arr, const int n)
{   

    int i;
    

    for(i=0; i<n; i++)
    {
        printf(" %3.0d", arr[i]);
        if(i!=(n-1))
        {
            printf(",");
        }
        else
        {
            printf("\n\n");
        }
    }
}