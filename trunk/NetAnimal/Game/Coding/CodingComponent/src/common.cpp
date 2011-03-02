#include "CodingComponentStableHeaders.h"
#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include <elitee.h>
#include "common.h"



/*
	Print an array in Hex.	
	Parameters:
		fp[in]  : file pointer  
		data[in]: data to be printed
		len[in] : data length
		
	Return:
		none.

	Remarks:
		none.
*/
void hexprint(FILE *fp, void *data, int len)
{
	unsigned char *pdata = (unsigned char *)data;
	int i = 0;

	for (; i<len ;i++)
	{
		if (!(i%16))
			fprintf(fp,"\n");
		fprintf(fp, "%02x ",*(pdata+i));
	}
	fprintf(fp, "\n");
}


/*
	Reset and close specified Elite-E device.	
	Parameters:
		pEleDevCtx[in] : pointer to Elite-E context: ELE_DEVICE_CONTEXT  
		
	Return:
		none.

	Remarks:
		Use this function instead of EleClose() may enhance security in certain
		circumstances.
*/
void ResetAndCloseEle(PELE_DEVICE_CONTEXT pEleDevCtx)
{	
	BOOL bRet = FALSE;
	DWORD dwRet = 0;
	DWORD dwRealLen = 0;
	
	//reset
	bRet = EleControl(pEleDevCtx, ELE_RESET_DEVICE, NULL, 0, NULL, 0, &dwRealLen);
	if (!bRet)
	{
		dwRet = EleGetLastError();
		printf("Reset device failed! <error code: 0x%08x>\n", dwRet);
		
		getch();
		return;
	}
	
	//close
	bRet = EleClose(pEleDevCtx);
	if (!bRet)
	{
		dwRet = EleGetLastError();
		printf("Close device failed! <error code: 0x%08x>\n", dwRet);
		
		getch();
		return;
	}
	
	//set pointer "pEleDevCtx" to NULL
	//to avoid it being wild
	pEleDevCtx = NULL; 
}


/*
	Select and open specified Elite-E device  
	Parameters:
		dwIndex[in]      : device index
		pEleDevCtx[out] : pointer to Elite-E context
		
	Return: 
		If the function succeeds, it will TRUE, otherwise 
		it returns FALSE.

	Remarks:
		none.
*/
BOOL OpenEleByIndex(DWORD dwIndex, PELE_DEVICE_CONTEXT pEleDevCtx)
{
	BOOL bRet = FALSE;
	DWORD dwRet = 0;
	ELE_DEVICE_CONTEXT EleCtx = {0}, EleTempCtx = {0};
	unsigned long ulTempIndex = 0;
	
	
	//open first device
	EleCtx.ulSize = sizeof(ELE_DEVICE_CONTEXT);
	bRet = EleOpenFirstDevice(NULL, NULL, NULL, ELE_SHARE_MODE, &EleCtx);
	if (!bRet)
	{		
		dwRet = EleGetLastError();
		if (dwRet == ELE_NO_MORE_DEVICE)
		{
			printf("No Elite-E device present!\n");
			
			getch();
			return FALSE;
		}
		else
		{
			printf("Open Elite-E device failed! <error code: 0x%08x>\n", dwRet);

			getch();
			return FALSE;
		}
	}

	//open the first device
	if (dwIndex == 0)
	{
		//copy context for returning out
		memcpy(pEleDevCtx, &EleCtx, sizeof(ELE_DEVICE_CONTEXT));
		return TRUE;
	}
	else
	{
		//copy context to open remained device(s)
		memcpy(&EleTempCtx, &EleCtx, sizeof(ELE_DEVICE_CONTEXT));
		
		//close
		ResetAndCloseEle(&EleTempCtx);
	}
	
	//open the other device
	while (ulTempIndex != dwIndex)
	{
		bRet = EleOpenNextDevice(&EleCtx);
		if (!bRet)
		{
			dwRet = EleGetLastError();
			if (dwRet == ELE_NO_MORE_DEVICE)
			{
				//if dwIndex > Total device number,show error
				if (dwIndex > ulTempIndex)
				{
					printf("Device index Error!\n");
					printf("Total device(s): %d\n", ulTempIndex+1);
					printf("Valid index range: 0-%d\n", ulTempIndex);
					getch();
					return FALSE;
				}
				break;
			}
			else
			{
				printf("Open Elite-E device failed! <error code: 0x%08x>\n", dwRet);

				getch();
				return FALSE;
			}			
		}
		
		ulTempIndex++;

		if (ulTempIndex != dwIndex)
		{
			memcpy(&EleTempCtx, &EleCtx, sizeof(ELE_DEVICE_CONTEXT));
			ResetAndCloseEle(&EleTempCtx);
		}
		else
		{
			break;
		}
		
	}
	
	memcpy(pEleDevCtx, &EleCtx, sizeof(ELE_DEVICE_CONTEXT));
	return TRUE;
}
