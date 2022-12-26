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


set<string> simb = {
	"+", "-", "/", "%", "*", "=", "(", ")", "[", "]", ">", "<", "$", "!",
	",", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};
set<string> command = {
	"INT", "print", "if", "cycle", "FUNCTION", "true", "false",
	"else", "elseif", "and", "or", "in", "TEMP", "NNUM", "redl",
	"LINT", "END", "end", "skip", "break", "return", "STR", "LSTR",
	"input", "col", "len", "console", "BOOL", "LBOOL", "LTEMP", "FLOAT",
	"LFLOAT",
	
	"cpplib", "cpp"
};
set<string> commander = {
	"INT", "print", "if", "cycle", "FUNCTION", "true", "false",
	"else", "elseif", "and", "or", "in", "TEMP", "NNUM", "redl",
	"LINT", "END", "end", "skip", "break", "return", "STR", "LSTR", 
	"input", "col", "len", "console", "BOOL", "LBOOL", "LTEMP", "FLOAT",
	"LFLOAT",
	
	"cpplib", "cpp", "index", "icon", "width", "height", "resizable", "execute", "js"
};

set<string> all = {
	"+", "-", "/", "%", "*", "=", "(", ")", "[", "]", ">", "<", "$", "!",
	",", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	
	"INT", "print", "if", "cycle", "FUNCTION", "true", "false",
	"else", "elseif", "and", "or", "in", "TEMP", "NNUM", "redl",
	"LINT", "END", "end", "skip", "break", "return", "STR", "LSTR", 
	"input", "col", "len", "console", "BOOL", "LBOOL", "LTEMP", "FLOAT",
	"LFLOAT", "argv", "argc",
	
	"cpplib", "cpp"
};

set<string> guiall = {
	"+", "-", "/", "%", "*", "=", "(", ")", "[", "]", ">", "<", "$", "!",
	",", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "index", "icon", "width", "height", "resizable", "execute", "js"
};

set<string> vars;
set<string> name_func;
set<string> ppod;
set<string> standart;

