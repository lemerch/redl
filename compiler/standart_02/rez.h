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


if (line.compare(rms, 9, "resizable") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+9] == c) {
			stw = 1;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+9] == c) {
			stw = 1;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			stq = 1;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			stq = 1;
		}
	}
	if(stw == false && stq == false) {
		REZ_B = true;
		string GLOBAL;
		bool ssle1 = false;
		bool ssle2 = false;
		long long numster = 0;
		
		long long y = rms+9;
		
		bool scb1 = false;
		bool scb2 = false;
		
		bool quxz1 = false;
		bool quxz2 = false;
		
		for(;y<=line.length();y++) {
			if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
				y++;
			}else if(line[y] == '"' && ssle2 == false) {
				ssle1 = !ssle1;
				numster++;
			}else if(line[y] == '\'' && ssle1 == false) {
				ssle2 = !ssle2;
				numster++;
			}
			
			if(scb1 == false) {
				if(line[y] != '\n' && line[y] != '\r' && line[y] != ' ' && line[y] != '\t' && line[y] != '\0' &&
				line[y] != '(') {
					cout << "fatal error: command design error, token `(` not found" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			
					stopMachine = true;
					return;
				}
			}
				
			if(numster%2 == 0) {
				if(line[y] == '(' && scb1 == false) {
					scb1 = true;
					y++;
				}
				if(line[y] == ')' && scb1 == true) {
					scb2 = true;	
				}
			}
			
			if(scb1 == true && scb2 == false) {
				GLOBAL+=line[y];
			}
		}
		
		if(scb1 == false || scb2 == false) {
			cout << "fatal error: command design error" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			stopMachine = true;
			return;
		}


		REZ=GLOBAL;
		
		int z = 0;
		for(long long q = 0;q<=REZ.length();q++) {
			if(REZ[q] != '0' && REZ[q] != '1' && REZ[q] != '\0' && REZ[q] != '\r' && REZ[q] != ' ' && REZ[q] != '\n' && REZ[q] != '\t') {
				cout << "fatal error: this function uses type INT (0/1)" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				stopMachine = true;
				return;
			}
			if(REZ[q] == '0') z++;
			if(REZ[q] == '1') z++;
			if(z>1) {
				cout << "fatal error: this function uses type INT (0/1)" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				stopMachine = true;
				return;
			}
		}
		
		break;
	}
}

