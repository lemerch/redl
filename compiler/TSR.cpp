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


std::vector<std::string> source_TSR;
ifstream fileer("REDLCPPlog.txt");
long long numTSR = 0;
while(fileer) {
	string s;
    getline(fileer, s);
    source_TSR.emplace_back(std::move(s));
    numTSR++;
}
fileer.close();

string str_tsr;
string FILE_TSR;
string STRNUM_TSR;

// ERRORS
	bool typs_erno = false;
	bool typs_erno2 = false;
	
	bool func_erno1 = false;
	bool func_erno2 = false;
	
	bool ifnst1 = false;
	
	bool files = false;
// ERRORS

for(long long ost = 0;ost<numTSR;ost++) {
	str_tsr = source_TSR[ost];
	
	
// ERRORS	
	if(findin(str_tsr,"invalid conversion") == 1) {
		typs_erno = true;
	}else if(findin(str_tsr,"was not declared in this scope") == 1) {
		typs_erno2 = true;
	}else if(findin(str_tsr,"too few arguments to function") == 1 || findin(str_tsr,"too many arguments to function") == 1) {
		func_erno1 = true;
	}else if(findin(str_tsr,"variable or field") == 1 && findin(str_tsr,"declared void") == 1) {
		func_erno2 = true;
	}else if(findin(str_tsr,"forbids comparison between") == 1) {
		ifnst1 = true;
	}else if(findin(str_tsr,"No such file or directory") == 1) {
		files = true;
	}
// ERRORS	
	
	
	
	bool extp1 = false,extp2 = false;
	long long nnost = 0;
	for(long long x = 0;x<=str_tsr.length();x++) {
		if(str_tsr[x-2] == '/' && str_tsr[x-1] == '*' && nnost == 0) {
			extp1 = true;
			nnost++;
		}
		if(str_tsr[x-4] == '.' && str_tsr[x-3] == 'r' && str_tsr[x-2] == 'l' && str_tsr[x-1] == 'f' && nnost == 1) {
			extp1 = false;
			extp2 = true;
			nnost++;
		}
		if(str_tsr[x] == '*' && str_tsr[x+1] == '/' && nnost == 2) {
			nnost++;
			break;
		}
		if(extp1 == true) {
			FILE_TSR+=str_tsr[x];
		}else if(extp2 == true) {
			STRNUM_TSR+=str_tsr[x];
		}
	}
	if(nnost == 3) {
		break;
	}
}
if(FILE_TSR != "" && STRNUM_TSR != "") {
	if(typs_erno == true) {
		cout << "fatal error: invalid data type value" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else if(typs_erno2 == true) {
		cout << "fatal error: variable value was not declared or is this command unknown" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else if(func_erno1 == true) {
		cout << "fatal error: arguments are incorrectly specified when calling a function" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else if(func_erno2 == true) {
		cout << "fatal error: variable declared invalid" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else if(ifnst1 == true) {
		cout << "fatal error: incorrect comparison in check" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else if(files == true) {
		cout << "fatal error: no such file or directory" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}else {
		cout << "fatal error: unknown compiler error" << endl;
		cout << "compiler: in line `" << STRNUM_TSR << "`, in file `" << FILE_TSR << "`!" << endl;
	}
}
if(developer == false) {
	system("del REDLCPPlog.txt");
}
