#pragma once
#include<stdio.h>
#include<stdlib.h>
struct StuinfoA
{
    int xh;
    char xm[10];
    char xy[20];
    char zy[20];
    char bj[20];
    char address[30];
    char phno[12];
    char jg[20];
    char rxsj[12];
    struct StuinfoA* next;
};