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

typedef string GLOBAL_STR;
typedef long long GLOBAL_INT;

void translate_cpp(std::vector<std::string> source,long long strokeINT,string now_files,string defs)
{
	now_files+=".cpp";
	ofstream out(now_files.c_str());
	out << "#include <REDL.cpp>" << endl;
	bool sttorc = false;
	
	long long nummert = 0;
	long long nummert2 = 0;
	bool commentation_stranskrip = false;
	
	
// VAR FOR SPECIAL TRANSLATE
	bool linest_if = false;
	bool linest_func = false;
		
// IF / END	
	GLOBAL_INT IFS_NUM = 0;
	GLOBAL_INT END_NUM = 0;
// IF / END	




// FUNCTION / END
	GLOBAL_INT FUN_NUM = 0;
	GLOBAL_INT END_NUM_FUN = 0;
// FUNCTION / END


	for(long long code = 0;code<strokeINT;code++) {
		
		
// STEPS
		bool GLOBAL_BOOL_STEP = false;
// STEPS		




		
// CPPLIB
		bool librarystro = false;
// CPPLIB	








		
		
		
// FUNCTIONS		
		bool funtions_for_dt = false;
		bool end_func = false;
// FUNCTIONS	
		
		GLOBAL_STR STROKEFILE;
		GLOBAL_STR STROKENUM;
		GLOBAL_INT STARTER;

// VAR FOR SPECIAL TRANSLATE		
		bool ignore = false;
		bool datatype = false;



// IF / END		
		bool global_if = false;
		bool end_if_global = false;
		
		bool string_if = false;
		
		bool defaulte_if = false;
		bool defaulte_if_end = false;
		
		bool end_if_func = false;
		
		bool if_start = false;
// IF / END	




// ELSE
		bool els_ab = false;
// ELSE	




// ELSEIF
		bool elif = false;
// ELSEIF


		string linest = trim(source[code]);	
		#include "transkrip.cpp"
 		GLOBAL_STR SINDEX = trim(line);
 		
 		if(findin(coust(STROKEFILE),defs) == 1) {
			GLOBAL_BOOL_STEP = true;
		}
 		
		bool slash1 = false;
		bool slash2 = false;
		
		bool slash11 = false;
		bool slash22 = false;
	
		if(line.length() >= 1 || line != "\n" || line != "\0" || line != "\t" || line != "\r" || line != " ") {
			
			#include "remisvar.cpp"
			
			for(long long rms = 0;rms<=line.length();rms++) {	
				
				if(line[rms] == '\\' && (slash1 == true || slash2 == true)) {
					rms++;	
				}else if(line[rms] == '"' && slash2 == false) {
					slash1 = !slash1;
					nummert++;
				}else if(line[rms] == '\'' && slash1 == false) {
					slash2 = !slash2;
					nummert++;
				}
				
				if(nummert%2 == 0) {
					
					// STANDART REDL 01
					
				
					#include "standart_01/specom.h"
					#include "standart_01/list.h"
					
					#include "standart_01/int.h"
					#include "standart_01/str.h"
					#include "standart_01/bool.h"
					#include "standart_01/float.h"
					#include "standart_01/temp.h"
					
					#include "standart_01/obp.h"
					#include "standart_01/check.h"
					#include "standart_01/cycle.h"
					#include "standart_01/functions.h"
					
					
				}
			
			}
		
			
			
		}
		
		
		#include "standart_01/typecom.h"
		
	
		if(nummert%2 != 0) {
			cout << "fatal error: invalid number of quotes" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		
		
	}
	
	if(IFS_NUM != END_NUM) {
		cout << "fatal error: lost `if` or `cycle` construction commands" << endl;
		cout << "translator: lost `if` or `cycle` construction commands!" << endl;
		out.close();
		stopMachine = true;
		return;
	} 
	if(END_NUM_FUN != FUN_NUM) {
		cout << "fatal error: lost `function` construction commands" << endl;
		cout << "translator: lost `function` construction commands!" << endl;
		out.close();
		stopMachine = true;
		return;
	}
	
	
	out << "int main(int argc, char **argv) {setlocale (LC_ALL,\"\");";
	for(long int x = 0;x<REDLSPECIALNUM;x++) {
		out << "REDLSPECIAL" << x << "(argc,argv);";
	}
	if(itepreter == false) {
		out << "cout << endl << \"----------------\" << endl; system(\"pause\"); }";
	}else {
		out << "return 0;}";
	}
	out.close();
}


void translate_html(std::vector<std::string> source,long long strokeINT,string now_files,string defs)
{

	
	string FILES, ICON, REZ, WIDTH, HEIGHT;
	bool 
	FILES_B = false,
	ICON_B = false,
	REZ_B = false,
	WIDTH_B = false,
	HEIGHT_B = false;
	
	bool sttorc = false;
	
	long long nummert = 0;
	long long nummert2 = 0;
	bool commentation_stranskrip = false;
	

	for(long long code = 0;code<strokeINT;code++) {
		GLOBAL_STR STROKEFILE;
		GLOBAL_STR STROKENUM;
		GLOBAL_INT STARTER;
		
		string linest = trim(source[code]);	
		#include "transkrip.cpp"
 		GLOBAL_STR SINDEX = trim(line);
 		

		
 		
		bool slash1 = false;
		bool slash2 = false;
		
		bool slash11 = false;
		bool slash22 = false;
	
		if(line.length() >= 1 || line != "\n" || line != "\0" || line != "\t" || line != "\r" || line != " ") {
			
			#include "remisvar.cpp"
			
			for(long long rms = 0;rms<=line.length();rms++) {	
				
				if(line[rms] == '\\' && (slash1 == true || slash2 == true)) {
					rms++;	
				}else if(line[rms] == '"' && slash2 == false) {
					slash1 = !slash1;
					nummert++;
				}else if(line[rms] == '\'' && slash1 == false) {
					slash2 = !slash2;
					nummert++;
				}
				
				if(nummert%2 == 0) {
					
					// STANDART REDL 02
					#include "standart_02/index.h"
					#include "standart_02/icon.h"
					#include "standart_02/width.h"
					#include "standart_02/height.h"
					#include "standart_02/rez.h"
				}
			
			}
		}
		

		if(nummert%2 != 0) {
			cout << "fatal error: invalid number of quotes" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			stopMachine = true;
			return;
		}
		
		
	}
	if(FILES_B == false || ICON_B == false || REZ_B == false || WIDTH_B == false || HEIGHT_B == false) {
		cout << "fatal error: compilation conditions not met" << endl;
		cout << "translator: compilation conditions not met!" << endl;
		stopMachine = true;
		return;
	}
	
	
	bool FALSE_T = false;
	bool TRUE_T = false;
	for(long long et = 0;et<=REZ.length();et++) {
		if(REZ[et] == '0') {
			FALSE_T = true;
		}else if(REZ[et] == '1') {
			TRUE_T = true;
		}
	}
	
	ofstream oute("main.js");
		oute << "const {app, BrowserWindow} = require('electron')" << endl;
		oute << "let mainWindow" << endl;
		oute << "function createWindow () {" << endl;
		if(FALSE_T == true) {
			oute << "  mainWindow = new BrowserWindow({width: " << WIDTH << ", height: " << HEIGHT << ",icon: __dirname + '/" << ICON << "',center: false,resizable: false});" << endl;
		}else if(TRUE_T == true) {
			oute << "  mainWindow = new BrowserWindow({width: " << WIDTH << ", height: " << HEIGHT << ",icon: __dirname + '/" << ICON << "',center: false,resizable: true});" << endl;			
		}
		oute << "  mainWindow.setMenuBarVisibility(false)" << endl;
		oute << "  mainWindow.loadFile('" << FILES << "')" << endl;
		oute << "  mainWindow.on('closed', function () {" << endl;
		oute << "    mainWindow = null" << endl;
		oute << "  })" << endl;
		oute << "}" << endl;
		oute << "app.on('ready', createWindow)" << endl;
		oute << "app.on('window-all-closed', function () {" << endl;
		oute << "  if (process.platform !== 'darwin') {" << endl;
		oute << "    app.quit()" << endl;
		oute << "  }" << endl;
		oute << "})" << endl;
		oute << "app.on('activate', function () {" << endl;
		oute << "  if (mainWindow === null) {" << endl;
		oute << "    createWindow()" << endl;
		oute << "  }" << endl;
		oute << "})" << endl;
		oute << "const exec = require('child_process').exec;" << endl;
		oute << "function execute(command, callback) {" << endl;
		oute << "    exec(command, (error, stdout, stderr) => { " << endl;
		oute << "        callback(stdout); " << endl;
		oute << "    });" << endl;
		oute << "};" << endl;
	oute.close();
	
	ofstream outer("package.json");
		outer << "{" << endl;
		outer << " \"name\": \"build\"," << endl;
		outer << " \"productName\": \"build\"," << endl;
		outer << " \"version\": \"0.1.0\"," << endl;
		outer << " \"main\": \"main.js\"," << endl;
		outer << " \"devDependencies\": {" << endl;
		outer << " \"electron\": \"^1.4.3\"," << endl;
		outer << " \"electron-packager\": \"^8.1.0\"" << endl;
		outer << " }," << endl;
		outer << " \"scripts\": {" << endl;
		outer << " \"package-mac\": \"electron-packager . --overwrite --platform=darwin --arch=x64 --icon=" << ICON << " --prune=true --out=release-builds\"," << endl;
		outer << "\"package-win\": \"electron-packager . --overwrite --icon=" << ICON << "\"," << endl;
		outer << "\"package-linux\": \"electron-packager . electron-tutorial-app --overwrite --asar=true --platform=linux --arch=x64 --icon=" << ICON << " --prune=true --out=release-builds\"" << endl;
		outer << " }" << endl;
		outer << "}" << endl; 
	outer.close();
	
	
	
	ofstream outoyz("main.js", std::ios::app);
	
	sttorc = false;
	
	nummert = 0;
	nummert2 = 0;
	commentation_stranskrip = false;
	

	for(long long code = 0;code<strokeINT;code++) {
		GLOBAL_STR STROKEFILE;
		GLOBAL_STR STROKENUM;
		GLOBAL_INT STARTER;
		
		string linest = trim(source[code]);	
		#include "transkrip.cpp"
 		GLOBAL_STR SINDEX = trim(line);
 		

		
 		
		bool slash1 = false;
		bool slash2 = false;
		
		bool slash11 = false;
		bool slash22 = false;
	
		if(line.length() >= 1 || line != "\n" || line != "\0" || line != "\t" || line != "\r" || line != " ") {
			
			#include "remisvar.cpp"
			
			for(long long rms = 0;rms<=line.length();rms++) {	
				
				if(line[rms] == '\\' && (slash1 == true || slash2 == true)) {
					rms++;	
				}else if(line[rms] == '"' && slash2 == false) {
					slash1 = !slash1;
					nummert++;
				}else if(line[rms] == '\'' && slash1 == false) {
					slash2 = !slash2;
					nummert++;
				}
				
				if(nummert%2 == 0) {
					
					// STANDART REDL 02
					#include "standart_02/exec.h"
				}
			
			}
		}
		

		if(nummert%2 != 0) {
			cout << "fatal error: invalid number of quotes" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			stopMachine = true;
			return;
		}
		
		
	}
	outoyz.close();
	
}


