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


string ARGLV;
if(argc == 1) {
	cout << "fatal error: non argument" << endl;
	cout << "redl: not have <input> file" << endl;
	cout << "Instruction:" << endl << endl
		 << " +---------->" << endl
		 << " |  redl test.rlf   --> compile file test.rlf" << endl
		 << " |  redl test.rlf -o test.exe  --> compile test.rlf with output file" << endl
		 << " |  redl test.rlf -i  --> (-i) enable code interpretation mode" << endl
		 << " |  !(Interpretation speed longer than compilation)" << endl
		 << " |  redl test.rlf -gui --> enable GUI MODE" << endl
		 << " +---------->" << endl << endl;
	return 0;
}



bool GUI = false, DEV = false, 
INTER = false, OUT = false;

string 
GUI_T = "-gui",
DEV_T = "-d",
INTER_T = "-i",
OUT_T = "-o";

string INPUT_F,OUTP_F;

long long outnum = 0,filenum = 0;

if(argc>7) {
	cout << "fatal error: number of arguments exceeded" << endl;
  	cout << "preprocess: the number of arguments should not exceed 4!" << endl;
	return 0;	
}

for(long long x = 1;x<argc;x++) {
	if(argv[x] == OUT_T) {
		if(argc<x+1) {
			cout << "fatal error: no output file found" << endl;
  			cout << "preprocess: no output file found from argument `-o`!" << endl;
			return 0;
		}else {
			if(OUT == true) {
				cout << "fatal error: duplicate argument `-o`" << endl;
  				cout << "preprocess: using one argument is limited to 1!" << endl;
				return 0;
			}
			outnum++;
			OUT = true;
			OUTP_F=argv[x+1];
			x+=1;
		}
	}else if(argv[x] == GUI_T) {
		if(GUI == true) {
			cout << "fatal error: duplicate argument `-gui`" << endl;
  			cout << "preprocess: using one argument is limited to 1!" << endl;
			return 0;
		}
		GUI = true;
	}else if(argv[x] == INTER_T) {
		if(INTER == true) {
			cout << "fatal error: duplicate argument `-i`" << endl;
  			cout << "preprocess: using one argument is limited to 1!" << endl;
			return 0;
		}
		INTER = true;
	}else if(argv[x] == DEV_T) {
		if(DEV == true) {
			cout << "fatal error: duplicate argument `-d`" << endl;
  			cout << "preprocess: using one argument is limited to 1!" << endl;
			return 0;
		}
		DEV = true;
	}else {
		filenum++;
		INPUT_F = argv[x];
	}
	ARGLV+=argv[x];
	ARGLV+=" ";
}

if((filenum>1 || outnum>1) || (filenum != outnum) && OUT == true) {
	cout << "fatal error: wrong number of files" << endl;
	cout << "preprocess: wrong number of files or unknown arguments!" << endl;
	return 0;
}
if(filenum>1 || filenum <1) {
	cout << "fatal error: wrong number of files" << endl;
	cout << "preprocess: wrong number of files or unknown arguments!" << endl;
	return 0;
}
if(DEV == true && INTER == true) {
	cout << "fatal error: the use of these two arguments is prohibited" << endl;
	cout << "preprocess: arguments `-d` and `-i` together prohibited!" << endl;
	return 0;
}
if(GUI == true && OUT == true) {
	cout << "fatal error: the use of these two arguments is prohibited" << endl;
	cout << "preprocess: arguments `-gui` and `-o` together prohibited!" << endl;
	return 0;
}/*
if(GUI == true && DEV == true) {
	cout << "fatal error: the use of these two arguments is prohibited" << endl;
	cout << "preprocess: arguments `-gui` and `-d` together prohibited!" << endl;
	return 0;
}


*/

