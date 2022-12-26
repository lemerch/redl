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

if(linest_func == false) {
	if(librarystro == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(end_func == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "}" << endl;
	}else if((els_ab == true || elif == true) && (linest_if == true)) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << "{" << endl;
	}else if(string_if == true && linest_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "void REDLSPECIAL" << REDLSPECIALNUM << "(int argc, char **argv) {" << line << ";}}" << endl;
		REDLSPECIALNUM++;
	}else if(linest_if == true && string_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";}" << endl;
	}else if(defaulte_if_end == true && linest_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "}" << endl;
	}else if(end_if_global == true && linest_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "}}" << endl;
	}else if(defaulte_if == true && linest_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(linest_if == true && global_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "void REDLSPECIAL" << REDLSPECIALNUM << "(int argc, char **argv) {" << line << endl;
		REDLSPECIALNUM++;
	}else if(linest_if == true && global_if == false && defaulte_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";" << endl;
	}else if(datatype == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "void REDLSPECIAL" << REDLSPECIALNUM << "(int argc, char **argv) {" << line << ";" << "}" << endl;
		REDLSPECIALNUM++;
	}else if(datatype == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";" << endl;
		datatype = false;
	}

}else {
	if(librarystro == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(if_start == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(funtions_for_dt == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if((els_ab == true || elif == true) && (linest_if == true)) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << "{" << endl;
	}else if(string_if == true && linest_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";}" << endl;
	}else if(linest_if == true && string_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";}" << endl;
	}else if(defaulte_if_end == true && linest_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << "}" << endl;
	}else if(end_if_global == true && linest_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" <<"}" << endl;
	}else if(defaulte_if == true && linest_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(linest_if == true && global_if == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << endl;
	}else if(linest_if == true && global_if == false && defaulte_if == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";" << endl;
	}else if(datatype == false) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";" << endl;
	}else if(datatype == true) {
		out << "/*" << STROKEFILE << STROKENUM << "*/" << line << ";" << endl;
		datatype = false;
	}
}
