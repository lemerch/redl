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

{
	
	for(long long x = 0;x<GLOBAL.length();x++) {
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
				if(GLOBAL[x-1] == c || GLOBAL[x-1] == '!') {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(GLOBAL[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				IFIN = true;
				break;
			}
		}
		
		
		
		
		
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
				IFINI = true;
				break;
			}
		}
		
		
		
		
	}
	
}

{
	
	string VAR;
	long long x = 0;
	bool controll = false;
	for(;x<GLOBAL.length();x++) {
		if(IFIN == false && IFINI == false) {
			if((GLOBAL[x] == '=') || (GLOBAL[x] == '>') || (GLOBAL[x] == '<')) {
				break;
			}
			VAR+=GLOBAL[x];
		}else if(IFIN == true && IFINI == false){
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
					controll = true;
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
					break;
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
					break;
				}
			}
			
			if(controll == true) {
				VAR+=GLOBAL[x];
			}
		}else if(IFIN == false && IFINI == true){
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
					controll = true;
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
					break;
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
					break;
				}
			}
			
			if(controll == true) {
				VAR+=GLOBAL[x];
			}
		}
	}
	VAR = trim(VAR);
	for(;x<GLOBAL.length();x++) {
		if((GLOBAL[x] == ':') && (GLOBAL[x+1] == '<' || GLOBAL[x+1] == '>' || GLOBAL[x+1] == '=')) {
			GLOBAL.replace(x, 1, VAR);
		}
		if ((GLOBAL.compare(x, 3, "in:") == 0) && (IFIN == true || IFINI == true)) {
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
				if(IFIN == true) {
					string VARs = " " + VAR;
					GLOBAL.replace(x+2, 5, VARs);
				}else if(IFINI == true) {
					string VARs = " " + VAR;
					GLOBAL.replace(x+2, 5, VARs);
				}
			}
		}
		
	}

}


if(IFIN == true || IFINI == true) {
	bool sslsh1 = false;
	bool sslsh2 = false;
	long long nummertssl = 0;
	for(long long x = 0;x<=GLOBAL.length();x++) {
		if(GLOBAL[x] == '\\' && (sslsh1 == true || sslsh2 == true)) {
			x++;	
		}else if(GLOBAL[x] == '"' && sslsh2 == false) {
			sslsh1 = !sslsh1;
			nummertssl++;
		}else if(GLOBAL[x] == '\'' && sslsh2 == false) {
			sslsh2 = !sslsh2;
			nummertssl++;
		}
		
		if(nummertssl%2 == 0) {
			if(GLOBAL[x] == '=' || GLOBAL[x] == '>' || GLOBAL[x] == '<') {
				cout << "fatal error: Invalid check statement - `=` or `<` or `>`" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				out.close();
				stopMachine = true;
				return;
			}
		}
	}
}
