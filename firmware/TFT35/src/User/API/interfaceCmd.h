#ifndef _INTERFACECMD_H_
#define _INTERFACECMD_H_

#include "stdint.h"
#include "stdbool.h"

#define CMD_MAX_LIST 20
#define CMD_MAX_CHAR 100

typedef struct 
{
  char    queue[CMD_MAX_LIST][CMD_MAX_CHAR];
  uint8_t index_r ; // Ring buffer read position
  uint8_t index_w ; // Ring buffer write position
//    u8      parsed ;  //
  uint8_t count ;   // Count of commands in the queue  
}QUEUE;

extern QUEUE infoCmd ;
extern QUEUE infoCacheCmd;     //???????????


bool storeCmd(const char * format,...);
void mustStoreCmd(const char * format,...);
void mustStoreCacheCmd(const char * format,...);
bool moveCacheToCmd(void);
void clearCmdQueue(void);
void parseQueueCmd(void);
void sendQueueCmd(void);

#endif

