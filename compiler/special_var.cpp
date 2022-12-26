/***********************************************
*******************************************************************************
**
** Author - Dmitry Terakov <-> Joseph Dotz
**
** Copyright (C) 1997-2018 Free Software Foundation, Inc.
**
** This file is part of the RedL project.  This language is free
** software; you can redistribute it and/or modify it under the
** terms of the GNU General Public License as published by the
** Free Software Foundation; either version 3, or (at your option)
** any later version.

** This file for project RedL is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.

** You should have received a copy of the GNU General Public License
** see the files License respectively in directory redl.  If not, see
** <http://www.gnu.org/licenses/>.
**
** The creator of the entire Redl project is Dmitry Terakov :)
** Thank you for your interest or even helping the RedL project
** Good Luck!!!
**
***********************************************
*******************************************************************************/
#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h> 
#include <dirent.h>
#include <sys/types.h>
#include <direct.h>
using namespace std;


string all_files;

string filename;
string output_filename;
string fn;

long int REDLSPECIALNUM = 0;
bool direct = false;
bool stopMachine = false;

long int GLOBAL_REDACT_FILES = 0;




bool GUI = false;
bool outerfiles = false;
bool itepreter = false;
bool developer = false;
