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

if ((line.compare(rms, 2, "//") == 0)) {
	cout << "fatal error: unknown operator <//>" << endl;
	cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
	out.close();
	stopMachine = true;
	return;
}
if (line.compare(2, 2, "in") == 0) {
	bool stw = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[3] == c) {
			stw = true;
		}
	}
	
	if(line[3] == '0' || line[3] == '1' || line[3] == '2' || line[3] == '3' || 
	line[3] == '4' || line[3] == '5' || line[3] == '6' || line[3] == '7' || line[3] == '8' ||
	line[3] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[3] == c) {
			stw = true;
		}
	}
	if(stw == false) {
		cout << "fatal error: `in` command should be not the main" << endl;
		cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		out.close();
		stopMachine = true;
		return;
	}
}
if (line.compare(2, 3, "!in") == 0) {
	bool stw = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[3] == c) {
			stw = true;
		}
	}
	if(line[3] == '0' || line[3] == '1' || line[3] == '2' || line[3] == '3' || 
	line[3] == '4' || line[3] == '5' || line[3] == '6' || line[3] == '7' || line[3] == '8' ||
	line[3] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[3] == c) {
			stw = true;
		}
	}
	if(stw == false) {
		cout << "fatal error: `in` command should be not the main" << endl;
		cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		out.close();
		stopMachine = true;
		return;
	}
}
if(rms>=3) {
	if (line.compare(rms, 6, "elseif") == 0) {
		bool stw = false;
		bool stq = false;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms+6] == c) {
				stw = true;
			}
		}
		if(line[rms+6] == '0' || line[rms+6] == '1' || line[rms+6] == '2' || line[rms+6] == '3' || 
		line[rms+6] == '4' || line[rms+6] == '5' || line[rms+6] == '6' || line[rms+6] == '7' || line[rms+6] == '8' ||
		line[rms+6] == '9') {
			stw = true;
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms+6] == c) {
				stw = true;
			}
		}
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		if(stw == false && stq == false) {
			cout << "fatal error: `elseif` command should be the main" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
	}
	
	
	if (line.compare(rms, 2, "if") == 0) {
		bool stw = false;
		bool stq = false;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms+2] == c) {
				stw = true;
			}
		}
		if(line[rms+2] == '0' || line[rms+2] == '1' || line[rms+2] == '2' || line[rms+2] == '3' || 
		line[rms+2] == '4' || line[rms+2] == '5' || line[rms+2] == '6' || line[rms+2] == '7' || line[rms+2] == '8' ||
		line[rms+2] == '9') {
			stw = true;
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms+2] == c) {
				stw = true;
			}
		}
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		if(stw == false && stq == false) {
			cout << "fatal error: `if` command should be the main" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
	}
	
	if (line.compare(rms, 8, "FUNCTION") == 0) {
		bool stw = false;
		bool stq = false;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms+8] == c) {
				stw = true;
			}
		}
		if(line[rms+8] == '0' || line[rms+8] == '1' || line[rms+8] == '2' || line[rms+8] == '3' || 
		line[rms+8] == '4' || line[rms+8] == '5' || line[rms+8] == '6' || line[rms+8] == '7' || line[rms+8] == '8' ||
		line[rms+8] == '9') {
			stw = true;
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms+8] == c) {
				stw = true;
			}
		}
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms-1] == c) {
				stq = true;
			}
		}
		if(stw == false && stq == false) {
			cout << "fatal error: `FUNCTION` command should be the main" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
	}
	
}

if (line.compare(rms, 4, "skip") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+4] == c) {
			stw = true;
		}
	}
	if(line[rms+4] == '0' || line[rms+4] == '1' || line[rms+4] == '2' || line[rms+4] == '3' || 
	line[rms+4] == '4' || line[rms+4] == '5' || line[rms+4] == '6' || line[rms+4] == '7' || line[rms+4] == '8' ||
	line[rms+4] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+4] == c) {
			stw = true;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	if(stw == false && stq == false) {
		line.replace(rms, 4, "continue");
	}
}

