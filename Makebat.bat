@echo off
set Key=HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

set FolderToAdd=%appdata%\redl

For /f "tokens=2*" %%a In ('Reg.exe query "%key%" /v Path^|Find "Path"') do set CurPath=%%~b
reg.exe add "%Key%" /v Path /t REG_EXPAND_SZ /d "%CurPath%;%FolderToAdd%"



set Key=HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

set FolderToAdd=%appdata%\redl\bin

For /f "tokens=2*" %%a In ('Reg.exe query "%key%" /v Path^|Find "Path"') do set CurPath=%%~b
reg.exe add "%Key%" /v Path /t REG_EXPAND_SZ /d "%CurPath%;%FolderToAdd%"


set Key=HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

set FolderToAdd=%appdata%\redl\compiler

For /f "tokens=2*" %%a In ('Reg.exe query "%key%" /v Path^|Find "Path"') do set CurPath=%%~b
reg.exe add "%Key%" /v Path /t REG_EXPAND_SZ /d "%CurPath%;%FolderToAdd%"


set Key=HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

set FolderToAdd=%appdata%\redl\Nodejs

For /f "tokens=2*" %%a In ('Reg.exe query "%key%" /v Path^|Find "Path"') do set CurPath=%%~b
reg.exe add "%Key%" /v Path /t REG_EXPAND_SZ /d "%CurPath%;%FolderToAdd%"


cd C:/Users/%UserName%/AppData/Roaming
del geany
mkdir geany
cd geany 
mkdir colorschemes
mkdir filedefs
mkdir templates


copy %~dp0ide\CONFIG\geany.conf C:\Users\%UserName%\AppData\Roaming\geany
copy %~dp0ide\CONFIG\keybindings.conf C:\Users\%UserName%\AppData\Roaming\geany


copy %~dp0ide\CONFIG\colorschemes\new.conf C:\Users\%UserName%\AppData\Roaming\geany\colorschemes
copy %~dp0ide\CONFIG\filedefs\filetypes.common C:\Users\%UserName%\AppData\Roaming\geany\filedefs
copy %~dp0ide\CONFIG\templates\templates.README C:\Users\%UserName%\AppData\Roaming\geany\templates
copy %~dp0ide\REDL(GEANY).lnk C:\Users\%UserName%\Desktop

cd %appdata%
mkdir redl
cd redl
mkdir !tests
mkdir bin
mkdir compiler
mkdir documentation
mkdir ide
mkdir library
mkdir Nodejs
mkdir rsl
mkdir x86_64-w64-mingw32

cd %~dp0
xcopy /s/h/e/k/f/c %~dp0!tests %appdata%\redl\!tests
xcopy /s/h/e/k/f/c %~dp0bin %appdata%\redl\bin
xcopy /s/h/e/k/f/c %~dp0compiler %appdata%\redl\compiler
xcopy /s/h/e/k/f/c %~dp0documentation %appdata%\redl\documentation
xcopy /s/h/e/k/f/c %~dp0ide %appdata%\redl\ide
xcopy /s/h/e/k/f/c %~dp0library %appdata%\redl\library
xcopy /s/h/e/k/f/c %~dp0Nodejs %appdata%\redl\Nodejs
xcopy /s/h/e/k/f/c %~dp0rsl %appdata%\redl\rsl
xcopy /s/h/e/k/f/c %~dp0x86_64-w64-mingw32 %appdata%\redl\x86_64-w64-mingw32


move %~dp0direct.bat %appdata%\redl
move %~dp0Instruction.txt %appdata%\redl
move %~dp0License.txt %appdata%\redl
move %~dp0Non-RedL-Programs.txt %appdata%\redl

rmdir /S /Q %~dp0!tests
rmdir /S /Q %~dp0bin
rmdir /S /Q %~dp0compiler
rmdir /S /Q %~dp0documentation
rmdir /S /Q %~dp0ide
rmdir /S /Q %~dp0library
rmdir /S /Q %~dp0Nodejs
rmdir /S /Q %~dp0rsl
rmdir /S /Q %~dp0x86_64-w64-mingw32