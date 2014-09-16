
/**************************************************************************************************/
/* Copyright (C) software liji, @USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  liji                                                                 */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/14                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by liji JG14225042, 2014/09/14
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* menu program */

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help,&head[1]},
    {"version", "menu program v1.0", NULL, &head[2]},
    {"debug", "this is run program!", NULL,&head[3]},
    {"append", "append!", NULL,&head[4]},
    {"mkdir", NULL, NULL,&head[5]},
    {"account", NULL, NULL,&head[6]},
    {"bell", NULL, NULL,&head[7]},
    {"cd", NULL, NULL,NULL}
};

main()
{    
   /* cmd line begins */
    while(1)
    { 
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}
  
int Help()
{
    ShowAllCmd(head);
    return 0; 
}
