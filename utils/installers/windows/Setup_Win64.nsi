# Auto-generated by EclipseNSIS Script Wizard
# 19-jun-2013 9:22:42

Name "Non-Intrusive DDS Recorder"

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define COMPANY eProsima
!define URL www.eprosima.com

# MUI Symbol Definitions
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install-colorful.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_SHOWREADME $INSTDIR\README.html
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall-colorful.ico"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE

# Included files
!include Sections.nsh
!include MUI2.nsh
!include EnvVarUpdate.nsh

# Reserved Files
ReserveFile "${NSISDIR}\Plugins\AdvSplash.dll"

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ..\..\..\doc\licencias\DDSRECORDER_LICENSE.txt
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile DDSRecorder_${VERSION}_Win64.exe
InstallDir "$PROGRAMFILES64\eProsima\Non-Intrusive DDS Recorder"
CRCCheck on
XPStyle on
ShowInstDetails show
VIProductVersion "${VERSION}.0"
VIAddVersionKey /LANG=${LANG_ENGLISH} ProductName "Non-Intrusive DDS Recorder"
VIAddVersionKey /LANG=${LANG_ENGLISH} ProductVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyName "${COMPANY}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyWebsite "${URL}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileDescription ""
VIAddVersionKey /LANG=${LANG_ENGLISH} LegalCopyright ""
InstallDirRegKey HKLM "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
Section -Main SEC0000
    # Copy binary
    SetOutPath $INSTDIR\bin
    SetOverwrite on
    File ..\..\..\lib\x64Win64VS2010\DDSRecorder.exe
    # Copy documentation
    SetOutPath $INSTDIR\doc
    File "..\..\..\doc\Release Notes.pdf"
    File "..\..\..\doc\User Manual.pdf"
    File "..\..\..\doc\Installation Manual.pdf"
    # Copy logo
    SetOutPath $INSTDIR\doc\logo
    File "..\..\logo\eProsimaLogo.png"
    # Copy example
    SetOutPath $INSTDIR\examples\HelloWorld
    File "..\..\..\examples\HelloWorld\HelloWorld.db"
    File "..\..\..\examples\HelloWorld\HelloWorld.pcap"
    File "..\..\..\examples\HelloWorld\HelloWorld.idl"
    # Copy licenses
    SetOutPath $INSTDIR
    File ..\..\..\doc\licencias\DDSRECORDER_LICENSE.txt
    File ..\..\..\doc\licencias\LGPLv3_LICENSE.txt
    # Copy README
    File "..\..\..\README.html"
    # Add directory to PATH
    ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\bin"
    WriteRegStr HKLM "${REGKEY}\Components" Main 1
SectionEnd

Section -post SEC0001
    WriteRegStr HKLM "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayName "$(^Name)"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayVersion "${VERSION}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" Publisher "${COMPANY}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" URLInfoAbout "${URL}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayIcon $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoModify 1
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoRepair 1
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKLM "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

# Uninstaller sections
Section /o -un.Main UNSEC0000
    # Delete Readme
    Delete /REBOOTOK $INSTDIR\Readme.html
    # Delete Licenses
    Delete /REBOOTOK $INSTDIR\LGPLv3_LICENSE.txt
    Delete /REBOOTOK $INSTDIR\DDSRECORDER_LICENSE.txt
    # Delete documentation
    Delete /REBOOTOK "$INSTDIR\doc\Installation Manual.pdf"
    Delete /REBOOTOK "$INSTDIR\doc\User Manual.pdf"
    Delete /REBOOTOK "$INSTDIR\doc\Release Notes.pdf"
    # Delete example
    Delete /REBOOTOK "$INSTDIR\examples\HelloWorld\HelloWorld.db"
    Delete /REBOOTOK "$INSTDIR\examples\HelloWorld\HelloWorld.pcap"
    Delete /REBOOTOK "$INSTDIR\examples\HelloWorld\HelloWorld.idl"
    # Delete logo 
    Delete /REBOOTOK "$INSTDIR\doc\logo\eProsimaLogo.png"
    # Delete binary
    Delete /REBOOTOK $INSTDIR\bin\DDSRecorder.exe
    DeleteRegValue HKLM "${REGKEY}\Components" Main
SectionEnd

Section -un.post UNSEC0001
    DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    DeleteRegValue HKLM "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKLM "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKLM "${REGKEY}"
    RmDir /r /REBOOTOK $INSTDIR
SectionEnd

# Installer functions
Function .onInit
    InitPluginsDir
    Push $R1
    File /oname=$PLUGINSDIR\spltmp.jpg "$%EPROSIMADIR%\logo\eProsimaLogoAndNameFinal_wBorder_460.jpg"
    newadvsplash::show 1000 600 400 -1 "$PLUGINSDIR\spltmp.jpg"
    Pop $R1
    Pop $R1
FunctionEnd

# Uninstaller functions
Function un.onInit
    ReadRegStr $INSTDIR HKLM "${REGKEY}" Path
    !insertmacro SELECT_UNSECTION Main ${UNSEC0000}
FunctionEnd

