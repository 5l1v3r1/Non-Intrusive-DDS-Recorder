:: This script build DDSRecorder library for any platform.

@echo off

:: Initialize the returned value to 0 (all succesfully)
set errorstatus=0

:: i86 Platform

:: Release Configuration
:: Clean the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Clean /p:Configuration="Release" /p:Platform="Win32"
:: Build the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Build /p:Configuration="Release" /p:Platform="Win32"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

:: Debug Configuration
:: Clean the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Clean /p:Configuration="Debug" /p:Platform="Win32"
:: Build the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Build /p:Configuration="Debug" /p:Platform="Win32"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

:: x64 Platform

:: Release Configuration
:: Clean the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Clean /p:Configuration="Release" /p:Platform="x64"
:: Build the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Build /p:Configuration="Release" /p:Platform="x64"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

:: Debug Configuration
:: Clean the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Clean /p:Configuration="Debug" /p:Platform="x64"
:: Build the visual solution
msbuild "..\..\win32\VS2010\DDSRecorder\DDSRecorder.sln" /t:Build /p:Configuration="Debug" /p:Platform="x64"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

goto :exit

:: Function exit ::
:exit
if %errorstatus%==0 (echo "BUILD SUCCESSFULLY") else (echo "BUILD FAILED")
goto :EOF
