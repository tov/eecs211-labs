; This Nullsoft Scriptable Installer script creates a Windows
; installer for MinGW-w64 with SDL2, but only if given an
; installation of such a thing in the first place. To create
; such an installation, first install this build of MinGW-w64:
;
; http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
;
; Then install the 32-bit versions of the SDL2 library (along with
; image, TTF, and mixer extensions) to the appropriate directories
; in the MinGW installation. No need to fix up paths. Put the MinGW
; directory (containing bin/, lib/, etc. subdirectories) as MinGW/
; relative to this script when running it.

Unicode true
Name "MinGW+SDL2 Installer"
SetCompressor /SOLID lzma
OutFile "MinGW-SDL2.exe"

InstallDir "C:\MinGW"

Page directory
Page instfiles

Section "Install"
  SetOutPath "$INSTDIR"
  File /r ".\MinGW\*"
SectionEnd
