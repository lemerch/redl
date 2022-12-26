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

int main(int argc, char **argv) {
	char current_work_dir[FILENAME_MAX];
	string nowdir = _getcwd(current_work_dir, sizeof(current_work_dir));

	{
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
		
		
		
		bool GUIB = false, DEV = false, 
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
		  	cout << "files: the number of arguments should not exceed 4!" << endl;
			return 0;	
		}
		
		for(long long x = 1;x<argc;x++) {
			if(argv[x] == OUT_T) {
				if(argc<x+1) {
					cout << "fatal error: no output file found" << endl;
		  			cout << "files: no output file found from argument `-o`!" << endl;
					return 0;
				}else {
					if(OUT == true) {
						cout << "fatal error: duplicate argument `-o`" << endl;
		  				cout << "files: using one argument is limited to 1!" << endl;
						return 0;
					}
					outnum++;
					OUT = true;
					outerfiles = true;
					output_filename = argv[x+1]; 
					x+=1;
				}
			}else if(argv[x] == GUI_T) {
				if(GUI == true) {
					cout << "fatal error: duplicate argument `-gui`" << endl;
		  			cout << "files: using one argument is limited to 1!" << endl;
					return 0;
				}
				GUI = true;
			}else if(argv[x] == INTER_T) {
				if(INTER == true) {
					cout << "fatal error: duplicate argument `-i`" << endl;
		  			cout << "files: using one argument is limited to 1!" << endl;
					return 0;
				}
				itepreter = true;
			}else if(argv[x] == DEV_T) {
				if(DEV == true) {
					cout << "fatal error: duplicate argument `-d`" << endl;
		  			cout << "files: using one argument is limited to 1!" << endl;
					return 0;
				}
				developer = true;
			}else {
				filenum++;
				fn = argv[x];
				INPUT_F = argv[x];
			}
		
		}
		if((filenum>1 || outnum>1) || (filenum != outnum) && OUT == true) {
			cout << "fatal error: wrong number of files" << endl;
			cout << "files: wrong number of files or unknown arguments!" << endl;
			return 0;
		}
		if(filenum>1 || filenum <1) {
			cout << "fatal error: wrong number of files" << endl;
			cout << "files: wrong number of files or unknown arguments!" << endl;
			return 0;
		}
		if(DEV == true && INTER == true) {
			cout << "fatal error: the use of these two arguments is prohibited" << endl;
			cout << "files: arguments `-d` and `-i` together prohibited!" << endl;
			return 0;
		}
	
	}	
	
	
	if(itepreter == false) {
		cout << "Copyright (C) 1997-2018 Free Software Foundation, Inc.\nAll patents and rights reserved - Open Invention Network,GNU,FSF" << endl;
		cout << "              _ _ " << endl;
		cout << " _ __ ___  __| | |  v0.7B" << endl;
		cout << "| '__/ _ \\/ _` | |" << endl;
		cout << "| | |  __/ (_| | |" << endl;
		cout << "|_|  \\___|\\__,_|_|" << endl << endl;
	}
	
	
	std::vector<std::string> source;
	ifstream fin;
	fin.open("REDLMIDLERLF.rlf");
	if(!fin) {
		cout << "fatal error: " << filename << " not found" << endl;
		cout << "files: <input> file not found" << endl;
		return 0;
	}
	
	if(fn[fn.length()-1] != 'f' && fn[fn.length()-2] != 'l' && 
	fn[fn.length()-3] != 'r' && fn[fn.length()-4] != '.') {
		cout << "fatal error: " << fn << " not does not belong to redl" << endl;
		cout << "files: <input> file not .rlf" << endl;
		return 0;
	}
	
	while (fin) 
	{
	    std::string s;
	    std::getline(fin, s);
	    source.emplace_back(std::move(s));
	    index_stroke++;
	}
	
	fin.close();
	
	
	for(long int x = 0;x<fn.length()-4;x++) {
		filename+=fn[x];
	}
	
	system("direct.bat");
	std::vector<std::string> source_d;
	ifstream file("directredlspecial.txt");
	string directive;
	while(file) {
		string s;
	    getline(file, s);
	    source_d.emplace_back(std::move(s));
	}
	file.close();
	string mono = source_d[0];
	for(long int x = 0;x<mono.length()-1;x++) {
	  	directive += source_d[0][x];	
	}
	string nosterfile = directive;
	system("del directredlspecial.txt");
	directive += "x86_64-w64-mingw32\\bin\\";
  
  
  	string GUIFULE;
	if(GUI == false) {
		translate_cpp(source,index_stroke,filename,nosterfile);
		if(stopMachine == false) {
			ERNOS(source,index_stroke,filename);
		}
	}else {
		if(nowdir.length()<=3) {
			cout << "fatal error: in GUI mode, the file cannot be outside the folder" << endl;
			cout << "files: in GUI mode, the file cannot be outside the folder" << endl;
			return 0;
		}
		translate_html(source,index_stroke,filename,nosterfile);
		if(stopMachine == false) {
			ERNOS_html(source,index_stroke,filename);
		}
	}
	if(stopMachine == true) {
		rm(all_files);
	}else {
		if(GUI == false) {
			string ffn;
			for(long int x = 0;x<fn.length()-4;x++) {
				ffn+=fn[x];
			}
			ffn += ".cpp";
			compile(directive,ffn);
			#include "TSR.cpp"
			if(itepreter == false && FILE_TSR == "" && STRNUM_TSR == "") {
				cout << "job time - " << clock()/1000.0 << " sec." << endl;
			}
		}else {
			system("rmdir /S /Q node_modules 2> log.txt");
			system(("copy \"" + nosterfile + "Nodejs\\Packager\\package-lock.json\" \"" + nowdir + "\" > NUL 2> log.txt").c_str());
			system("mkdir node_modules 2> log.txt");
			system(("xcopy /s/h/e/k/f/c \"" + nosterfile + "Nodejs\\Packager\\node_modules\" \"" + nowdir + "\\node_modules\" > NUL 2> log.txt").c_str());
			system((nosterfile + "Nodejs\\npm.cmd" + " run package-win 2> REDLCPPlog.txt > NUL").c_str());
			#include "TER.cpp"
			if(developer == false) {
				system("del package.json");
				system("del main.js");
				system("del REDLMIDLERLF.rlf");
				system("del package-lock.json");
				system("rmdir /S /Q node_modules");
			}
			if(itepreter == false) {
				cout << endl << "job time - " << clock()/1000.0 << " sec." << endl;
			}else {
				system("build-win32-x64\\build.exe");
				system("rmdir /S /Q build-win32-x64");
			}
		}
	}
	
	return 0;
}

