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


string line;
{
	string noe;
	bool slash1 = false;
	bool slash2 = false;
	long long nummert = 0;
	for(long long x = 0;x<=linest.length();x++) {
		if(linest[x] == '\\' && (slash1 == true || slash2 == true)) {
			noe+="\\";
			x++;	
		}else if(linest[x] == '"' && slash2 == false) {
			slash1 = !slash1;
			nummert++;
		}else if(linest[x] == '\'' && slash1 == false) {
			slash2 = !slash2;
			nummert++;
		}
		
		if(nummert%2 == 0) {
			if(linest[x] == '#') {
				break;
			}
			if((linest[x] == '/' && linest[x+1] == '*') && (commentation_stranskrip == false)) {
				commentation_stranskrip = true;
				x+=3;
			}else if((linest[x-2] == '*' && linest[x-1] == '/') && (commentation_stranskrip == true)) {
				commentation_stranskrip = false;
			}
		}
		if(commentation_stranskrip == false) {
			noe+=linest[x];
		}
	}
	
   	long long z = 0;
	for(z;z<noe.length();z++) {
		if(noe[z] == '.' && noe[z+1] == 'r' && noe[z+2] == 'l' && noe[z+3] == 'f') {
			break;
		}
		STROKEFILE+=noe[z];
	}
	z+=4;
	bool start = false;
	for(long long i = z;i<noe.length();i++) {
		if(noe[i] == '/') {
			STARTER = i+1;
			break;
		}
		STROKENUM+=noe[i];
	}

	for(long long i = STARTER;i<noe.length();i++){
		line+=noe[i];
	}


}
STROKEFILE+=".rlf";
line = trim(line);
line = "\t\t" + line;


