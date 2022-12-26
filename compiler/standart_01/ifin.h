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

if(IFIN == true) {
	string VAR,VAL;
	bool VALR = false;
	for(long long x = 0;x<=GLOBAL.length();x++) {
		if (GLOBAL.compare(x, 2, "in") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			if(line[rms+2] == '0' || line[rms+2] == '1' || line[rms+2] == '2' || line[rms+2] == '3' || 
			line[rms+2] == '4' || line[rms+2] == '5' || line[rms+2] == '6' || line[rms+2] == '7' || line[rms+2] == '8' ||
			line[rms+2] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				VALR = true;
				x+=2;
			}
		}
		if (GLOBAL.compare(x, 2, "or") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			if(line[rms+2] == '0' || line[rms+2] == '1' || line[rms+2] == '2' || line[rms+2] == '3' || 
			line[rms+2] == '4' || line[rms+2] == '5' || line[rms+2] == '6' || line[rms+2] == '7' || line[rms+2] == '8' ||
			line[rms+2] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "in" + VAR;
				string newe = "findin(" + VAR + "," + VAL + ") o";
				GLOBAL.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+1;
				VALR = false;
				continue;
			}
		}
		
		if (GLOBAL.compare(x, 3, "and") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			if(line[rms+3] == '0' || line[rms+3] == '1' || line[rms+3] == '2' || line[rms+3] == '3' || 
			line[rms+3] == '4' || line[rms+3] == '5' || line[rms+3] == '6' || line[rms+3] == '7' || line[rms+3] == '8' ||
			line[rms+3] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "in" + VAR;
				string newe = "findin(" + VAR + "," + VAL + ") a";
				GLOBAL.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+2;
				VALR = false;
				continue;
			}
		}
		
		if(x >= GLOBAL.length()) {
			string old = VAL + "in" + VAR;
			string newe = "findin(" + VAR + "," + VAL + ")";
			GLOBAL.replace(x-old.length(), old.length()+1, newe);
			VAL = "";
			VAR = "";
			break;
		}
		
		if(VALR == false) {
			VAL += GLOBAL[x];
		}else {
			VAR += GLOBAL[x];
		}
	}	
}else if(IFINI == true) {
		string VAR,VAL;
	bool VALR = false;
	for(long long x = 0;x<=GLOBAL.length();x++) {
		if (GLOBAL.compare(x, 3, "!in") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			if(line[rms+3] == '0' || line[rms+3] == '1' || line[rms+3] == '2' || line[rms+3] == '3' || 
			line[rms+3] == '4' || line[rms+3] == '5' || line[rms+3] == '6' || line[rms+3] == '7' || line[rms+3] == '8' ||
			line[rms+3] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				VALR = true;
				x+=3;
			}
		}
		if (GLOBAL.compare(x, 2, "or") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			if(line[rms+2] == '0' || line[rms+2] == '1' || line[rms+2] == '2' || line[rms+2] == '3' || 
			line[rms+2] == '4' || line[rms+2] == '5' || line[rms+2] == '6' || line[rms+2] == '7' || line[rms+2] == '8' ||
			line[rms+2] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "!in" + VAR;
				string newe = "findini(" + VAR + "," + VAL + ") o";
				GLOBAL.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+1;
				VALR = false;
				continue;
			}
		}
		
		if (GLOBAL.compare(x, 3, "and") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			if(line[rms+3] == '0' || line[rms+3] == '1' || line[rms+3] == '2' || line[rms+3] == '3' || 
			line[rms+3] == '4' || line[rms+3] == '5' || line[rms+3] == '6' || line[rms+3] == '7' || line[rms+3] == '8' ||
			line[rms+3] == '9') {
				stw = true;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x+3] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "!in" + VAR;
				string newe = "findini(" + VAR + "," + VAL + ") a";
				GLOBAL.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+2;
				VALR = false;
				continue;
			}
		}
		
		if(x >= GLOBAL.length()) {
			string old = VAL + "!in" + VAR;
			string newe = "findini(" + VAR + "," + VAL + ")";
			GLOBAL.replace(x-old.length(), old.length()+1, newe);
			VAL = "";
			VAR = "";
			break;
		}
		
		if(VALR == false) {
			VAL += GLOBAL[x];
		}else {
			VAR += GLOBAL[x];
		}
	}	
}
