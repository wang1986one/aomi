#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif



//Print an array in Hex.
void hexprint(FILE *fp, void *data, int len);

//reset and close specified Elite-E device.
void ResetAndCloseEle(PELE_DEVICE_CONTEXT pEleDevCtx);

//Select and open specified Elite-E device  
BOOL OpenEleByIndex(DWORD dwIndex, PELE_DEVICE_CONTEXT pEleDevCtx);


	
#ifdef __cplusplus
}
#endif

#endif _COMMON_H_





















