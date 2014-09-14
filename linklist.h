/**************************************************************************************************/
/* Copyright (C) software liji, @USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.h                                                           */
/*  PRINCIPAL AUTHOR      :  liji                                                                 */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/14                                                           */
/*  DESCRIPTION           :  linklist for menu program                                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by liji JG14225042, 2014/09/14
 *
 */


/* data struct and its operations */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;


tDataNode* FindCmd(tDataNode * head, char * cmd);

int ShowAllCmd(tDataNode * head);

