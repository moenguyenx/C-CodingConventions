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


statusResult printArray(int** arr, int* size)
{  
	statusResult status;
    if(*arr == NULL)
    {
        printf("Array empty\n");
        status = E_ARR_EMPTY;
    } 
    else 
    {
    	if(*size == 0)
    	{
    		printf("Array empty\n");
        	status = E_ARR_EMPTY;
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
    }
    Sleep(1500);
    return status;
}


statusResult createArray(int** dynamicArray, int* n)
{         
	statusResult status;
	
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
        status = E_CANNOT_ALLOC_MEM;
    } 
    else 
	{
		printf("Array created\n");
		status = E_OK;
	}
	Sleep(500);
	return status;
}

 
//void insert(int** arr, int* size)
//{
//    int i;
//    for(i=0; i<*size; i++)
//	{
//        printf("Nhap a[%d]: ", i);
//        scanf("%d", &(*arr)[i]);
//    }
//}

statusResult insert(int** arr, int* size)
{
	statusResult status;
	
	if(*arr == NULL)
	{
		printf("Please create an array before inserting\n");
		status = E_ARR_EMPTY;
	}
	else
	{
		static int i;
    
	    if(i < *size)
	    {
	    	printf("Nhap a[%d]: ", i);
	    	scanf("%d", &(*arr)[i]);
	    	i++;
	    	status = E_OK;
		}
		else
		{
			printf("Array da full\n");
			status = E_ARR_IS_FULL;
		}
	}
    
	Sleep(1000);
	return status;
}


statusResult deleteElement(int** arr, int* n)
{
	statusResult status;
	
    if(*arr == NULL)
    {
    	printf("Empty array\n");
    	status = E_ARR_EMPTY;
	}
	else
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
	        status = E_OK;
	    } 
	    else 
	    {	
	        printf("Khong co phan tu k\n");
	        status = E_NO_ELEMENT;
	    }	
	}
	Sleep(1000);
    return status;
}


statusResult increSort(int** arr, int* size)
{
	statusResult status;
	
	if(*arr == NULL)
	{
		printf("Empty array\n");
		status = E_ARR_EMPTY;
	}
	else
	{
		int i, j;
	    for(i=0; i<*size; i++)
		{
	        for(j = i+1; j < *size; j++)
			{
	            if ( (*arr)[i] >= (*arr)[j] )
				{
	                int temp = (*arr)[i];
	                (*arr)[i] = (*arr)[j];
	                (*arr)[j] = temp;
	            }
	        }
	    }
	    printf("Sorted in Increment order\n");
	    status = E_OK;
	}
	Sleep(1000);
    return status;
}


statusResult decreSort(int** arr, int* size)
{
	statusResult status;
	
	if(*arr == NULL)
	{
		printf("Empty array\n");
		status = E_ARR_EMPTY;
	}
	else
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
	    printf("Sorted in Decrement order\n");
	    status = E_OK;
	}
	Sleep(1000);
    return status;
}


statusResult search(int** arr, int* size)
{
	statusResult status;
	
	if(*arr == NULL)
	{
		printf("Please create an array\n");
		status = E_ARR_EMPTY;
	}
	else
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
	        status = E_ELEMENT_NOT_EXIST;
	    } 
		else 
		{
	        printf("Ton tai %d so %d trong day\n", count, x);
	        status = E_OK;
	    }
	}
	Sleep(1000);
    return status;
}

void exitProgram(int** dynamicArray, bool* state)
{	
	free(*dynamicArray);
	*state = true;
}
