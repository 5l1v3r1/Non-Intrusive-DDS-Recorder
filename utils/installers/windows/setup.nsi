# Auto-generated by EclipseNSIS Script Wizard
# 30-nov-2012 15:13:07

Name "eProsima Non-Intrusive DDS Recorder"

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define VERSION 1.0
!define COMPANY eProsima
!define URL www.eprosima.com

# MUI Symbol Definitions
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install-colorful.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall-colorful.ico"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE

# Included files
!include Sections.nsh
!include MUI2.nsh

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ..\..\..\doc\licencias\DDSRECORDER_LICENSE.txt
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile setup.exe
InstallDir $PROGRAMFILES\DDSRecorder
CRCCheck on
XPStyle on
ShowInstDetails show
VIProductVersion 0.1.0.0
VIAddVersionKey ProductName "${NAME}"
VIAddVersionKey ProductVersion "${VERSION}"
VIAddVersionKey CompanyName "${COMPANY}"
VIAddVersionKey CompanyWebsite "${URL}"
VIAddVersionKey FileVersion "${VERSION}"
VIAddVersionKey FileDescription ""
VIAddVersionKey LegalCopyright ""
InstallDirRegKey HKLM "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
SectionGroup "Binaries" SECGRP0000
    Section "x64 binary" SEC0000
        SetOutPath $INSTDIR\bin\x64
        SetOverwrite on
        File ..\..\..\lib\x64Win64VS2010\DDSRecorder.exe
        File ..\..\..\..\CDR\lib\x64Win64VS2010\CDR.dll
        WriteRegStr HKLM "${REGKEY}\Components" "x64 binary" 1
    SectionEnd

    Section "i86 binary" SEC0001
        SetOutPath $INSTDIR\bin\i86
        SetOverwrite on
        File ..\..\..\lib\i86Win32VS2010\DDSRecorder.exe
        File ..\..\..\..\CDR\lib\i86Win32VS2010\CDR.dll
        WriteRegStr HKLM "${REGKEY}\Components" "i86 binary" 1
    SectionEnd
SectionGroupEnd

Section -post SEC0002

    # Copy documentation.
    SetOutPath $INSTDIR\doc
    SetOverwrite on
    File "..\..\..\doc\Users Manual.pdf"
    
    # Copy licensies
    SetOutPath $INSTDIR
    SetOverwrite on
    File /r ..\..\..\doc\licencias\*
    
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

Section /o "-un.i86 binary" UNSEC0001
    RmDir /REBOOTOK $INSTDIR\bin\i86\DDSRecorder.exe
    DeleteRegValue HKLM "${REGKEY}\Components" "i86 binary"
SectionEnd

Section /o "-un.x64 binary" UNSEC0000
    RmDir /REBOOTOK $INSTDIR\lib\x64\DDSRecorder.exe
    DeleteRegValue HKLM "${REGKEY}\Components" "x64 binary"
SectionEnd

Section -un.post UNSEC0002
    DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    DeleteRegValue HKLM "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKLM "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKLM "${REGKEY}"
    RmDir /r /REBOOTOK $INSTDIR\doc
    RmDir /r /REBOOTOK $INSTDIR
SectionEnd

# Section Descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
!insertmacro MUI_DESCRIPTION_TEXT ${SECGRP0000} "eProsima Non-Intrusive DDS Recorder binaries."
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0000} "Binary for x64 platform."
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0001} "Binary for i86 platform."
!insertmacro MUI_FUNCTION_DESCRIPTION_END
