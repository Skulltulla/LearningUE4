@echo off
echo.
echo Delete Unreal Engine Generated Files:
echo. .vs/
echo. Binaries/
echo. Build/
echo. Intermediate/
echo. Saved/
echo. *.sln
echo.
echo WARNING: Files are not moved to Recycle Bin and can't be recovered.
echo.

IF NOT EXIST *.uproject (
echo ERROR: clean.bat should be placed in the project's root directory.
echo.
PAUSE
echo.
exit
)

echo.
choice /c YN /m "Continue"

IF ERRORLEVEL 2 (
echo Nothing Deleted. Goodbye.
) ELSE (

choice /c YN /m "Are you really sure"

if ERRORLEVEL 2 (
echo Nothing Deleted. Goodbye.
) ELSE (

IF EXIST %CD%\.vs (
  echo Deleting .vs
  rmdir /s /q .vs
) else (
  echo Not Found: .vs
)
IF EXIST %CD%\Binaries (
  echo Deleting Binaries
  rmdir /s /q Binaries
) else (
  echo Not Found: Binaries
)
IF EXIST %CD%\Build (
  echo Deleting Build
  rmdir /s /q Build
) else (
  echo Not Found: Build
)
IF EXIST %CD%\Intermediate (
  echo Deleting Intermediate
  rmdir /s /q Intermediate
) else (
  echo Not Found: Intermediate
)
IF EXIST %CD%\Saved (
  echo Deleting Saved
  rmdir /s /q Saved
) else (
  echo Not Found: Saved
)
IF EXIST *.sln (
  echo Deleting *.sln
  del /s /q *.sln
) else (
  echo Not Found: %CD%\*.sln
)
)
)

PAUSE