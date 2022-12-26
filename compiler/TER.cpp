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
	if(findin(str_tsr,"error") == 1 || findin(str_tsr,"ERROR") == 1 || findin(str_tsr,"ERR") == 1) {
		typs_erno = true;
	}
// ERRORS	
}
	

if(typs_erno == true) {
	cout << "fatal error: unknown compiler error" << endl;
	cout << "compiler: the error arose because of the electron compiler" << endl;
	return 0;
}
if(developer == false) {
	system("del REDLCPPlog.txt");
}
