#include "Program.h"


void printMenu()
{
    printf("*******************************************\n");
    printf("---CHUONG TRINH QUAN LY DAY SO BANG MANG---\n");
    printf("*******************************************\n");
    printf("1. Nhap 'c' de tao mang so nguyen\n");
    printf("2. Nhap 'p' de in day\n");
    printf("3. Nhap 'i' de them phan tu vao day\n");
    printf("4. Nhap 'd' de xoa phan tu o vi tri k\n");
    printf("5. Nhap 's' de sap xep day so tang dan\n");
    printf("6. Nhap 'x' de sap xep day so giam dan\n");
    printf("7. Nhap 't' de tim kiem 1 so x co trong day khong (x nhap tu ban phim)\n");
    printf("8. Nhap 'e' de thoat chuong trinh\n");
    printf("----\n");
}

//bug
void printArray(int** arr, int* size)
{  
    if(*arr == NULL)
    {
        printf("Day trong\n");
        Sleep(500);
    } 
    else 
    {
        int i;
        for(i = 0; i<*size; i++)
        {
            printf(" %d", (*arr)[i]);
        }
        printf("\n");
    }
    Sleep(1500);
}


void createArray(int** dynamicArray, int* n)
{         
    if (*dynamicArray != NULL) 
    {
    	free(*dynamicArray);
	}

    printf("Nhap so phan tu n: "); 
    scanf(" %d", n);
    *dynamicArray = (int*)calloc(*n, sizeof(int));  

    if (*dynamicArray == NULL) 
    {
        printf("Memory not allocated\n");
    } 
    else 
	{
		printf("Array created\n");
		Sleep(500);
	}
}

//Check loi func 
//void insert(int** arr, int* size)
//{
//    int i;
//    for(i=0; i<*size; i++)
//	{
//        printf("Nhap a[%d]: ", i);
//        scanf("%d", &(*arr)[i]);
//    }
//}

void insert(int** arr, int* size)
{
    static int i;
    
    if(i < *size)
    {
    	printf("Nhap a[%d]: ", i);
    	scanf("%d", &(*arr)[i]);
    	i++;
	}
	else
	{
		printf("Array da full\n");
		Sleep(500);
	}
}


void deleteElement(int** arr, int* n)
{
    int k, i;
    printf("Nhap index muon xoa: "); 
    scanf("%d", &k);
    if (k <= *n-1 && k >= 0 )
    {
        for(i=k; i<*n; i++)
        {
            (*arr)[i] = (*arr)[i+1];
        }
        *n -= 1;
    } 
    else 
    {
        printf("Khong co phan tu k\n");
        Sleep(500);
    }
}


void increSort(int** arr, int* size)
{
    int i, j;
    for(i = 0; i < *size; i++)
	{
        for(j = i+1; j < *size; j++)
		{
            if( (*arr)[i] >= (*arr)[j] )
			{
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}


void decreSort(int** arr, int* size)
{
    int i, j;
    for(i=0; i<*size; i++)
	{
        for(j = i+1; j < *size; j++)
		{
            if ( (*arr)[i] <= (*arr)[j] )
			{
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}


void search(int** arr, int* size)
{
    int x, i;
    int count = 0;
    printf("Nhap so can tim: ");
	scanf("%d", &x);
    for(i=0; i<*size; i++)
	{
        if(x == (*arr)[i]) 
		count++;
    }

    if(count == 0)
	{
        printf("Khong ton tai %d trong day\n", x);
    } 
	else 
	{
        printf("Ton tai %d so %d trong day\n", count, x);
    }
}

void exitProgram(int** dynamicArray, bool* state)
{	
	free(*dynamicArray);
	*state = true;
}
