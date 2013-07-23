// test.cpp : Defines the entry point for the console application..
// Author: Pranav Shenoy
// July 2013
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <NuiApi.h>
#include <Python.h>

using namespace std;



int main()

{   
	PyObject *pName, *pModule, *pDict, *pFuncOne, *pValue;
	PyObject *pArgs;
	PyObject *pFuncTwo;






	//Lets the people get into position
	for(int delay = 0; delay <= 100; delay++)
	{
		cout << "Please get into position" << endl;
		system("cls");
	}
	
	//initialize skeleton
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	NUI_SKELETON_FRAME ourframe;
	NuiSkeletonGetNextFrame(0, &ourframe);


	//all initialization is over
	//program functions inside this loop
	while (true)
	{
		NuiSkeletonGetNextFrame(0, &ourframe);
		//cout << "test";
		for (int i=0;i<=5;i++)
		{
			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
			{

				cout << "test2:";
				while (true) {
					NuiSkeletonGetNextFrame(0, &ourframe);
					if (ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y >= .1 ) {
						cout << "wassup:";
											//initialize
						Py_Initialize();	
						//FILE:
						//********************
						// Build name object
						pName = PyString_FromString("py_function");
						// Load module 
						pModule = PyImport_Import(pName);
						Py_DECREF(pName);
						// borrowed reference 
						pDict = PyModule_GetDict(pModule);
						//FUNCTION:
						//********************
						// borrowed reference 
						pFuncOne = PyObject_GetAttrString(pModule, "multiply");
						// borrowed ref
						pFuncTwo = PyObject_GetAttrString(pModule, "test");
						if (PyCallable_Check(pFuncOne)) 
						{
							PyObject_CallObject(pFuncOne, NULL);
						} else 
						{
							cout << "pranav, you suck at this";
							PyErr_Print();
						}
						Py_Finalize();
					}
					//if (ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y <= .1)
					else  {
						cout << "nooo:";
											//initialize
						Py_Initialize();	
						//FILE:
						//********************
						// Build name object
						pName = PyString_FromString("py_function");
						// Load module 
						pModule = PyImport_Import(pName);
						Py_DECREF(pName);
						// borrowed reference 
						pDict = PyModule_GetDict(pModule);
						//FUNCTION:
						//********************
						// borrowed reference 
						pFuncOne = PyObject_GetAttrString(pModule, "multiply");
						// borrowed ref
						pFuncTwo = PyObject_GetAttrString(pModule, "test");
						if (PyCallable_Check(pFuncOne)) 
						{
							PyObject_CallObject(pFuncTwo, NULL);
						} else 
						{
							cout << "pranav, you suck at this?";
							PyErr_Print();
						}
						Py_Finalize();
					}
				}

				/*

				SetCursorPos((int)(1500*ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x) + 300, -(int)(1400*ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y) + 900);
				if ((ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y - ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y >= .1 ) && !isClicking) {
					//input.mi.dx = (int)(64000*ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x) + 30000;
					//input.mi.dy = -(int)(70000*ourframe.SkeletonData[+0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y) + 67000;
					SendInput(1,&input,sizeof(INPUT));
					input.mi.dwFlags=(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTUP);	
					isClicking = true;
				}
				if ((ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y - ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y <= 0 ) && isClicking) {
					//input.mi.dx = (int)(64000*ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x) + 30000;
					//input.mi.dy = -(int)(70000*ourframe.SkeletonData[0].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y) + 67000;
					SendInput(1,&input,sizeof(INPUT));
					input.mi.dwFlags=(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN);
					isClicking = false;
				}

				*/

			}
			
		}
	}
	// Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
		for (int i = 0; i < 5000; i++){
			printf("Func\n");
		}

  

    return 0;
}