##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=spacer
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=D:/yourwork/sdl2
ProjectPath            :=D:/yourwork/sdl2/spacer
IntermediateDirectory  :=../build-$(ConfigurationName)/spacer
OutDir                 :=../build-$(ConfigurationName)/spacer
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Brandon
Date                   :=17/01/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)D:\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)D:\SDL2_image-devel-2.0.5-mingw\SDL2_image-2.0.5\x86_64-w64-mingw32\include\SDL2 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_image 
ArLibs                 :=  "mingw32" "SDL2main" "SDL2" "SDL2_image" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)D:\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\lib $(LibraryPathSwitch)D:\SDL2_image-devel-2.0.5-mingw\SDL2_image-2.0.5\x86_64-w64-mingw32\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/mingw64/bin/ar.exe rcu
CXX      := C:/mingw-w64/mingw64/bin/g++.exe
CC       := C:/mingw-w64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/spacer/Player.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/spacer/CSprite.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/spacer/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/spacer/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\spacer" mkdir "..\build-$(ConfigurationName)\spacer"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\spacer" mkdir "..\build-$(ConfigurationName)\spacer"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/spacer/.d:
	@if not exist "..\build-$(ConfigurationName)\spacer" mkdir "..\build-$(ConfigurationName)\spacer"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/spacer/Player.cpp$(ObjectSuffix): Player.cpp ../build-$(ConfigurationName)/spacer/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/yourwork/sdl2/spacer/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/spacer/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/spacer/Player.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/spacer/Player.cpp$(DependSuffix) -MM Player.cpp

../build-$(ConfigurationName)/spacer/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/spacer/Player.cpp$(PreprocessSuffix) Player.cpp

../build-$(ConfigurationName)/spacer/CSprite.cpp$(ObjectSuffix): CSprite.cpp ../build-$(ConfigurationName)/spacer/CSprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/yourwork/sdl2/spacer/CSprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CSprite.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/spacer/CSprite.cpp$(DependSuffix): CSprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/spacer/CSprite.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/spacer/CSprite.cpp$(DependSuffix) -MM CSprite.cpp

../build-$(ConfigurationName)/spacer/CSprite.cpp$(PreprocessSuffix): CSprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/spacer/CSprite.cpp$(PreprocessSuffix) CSprite.cpp

../build-$(ConfigurationName)/spacer/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/spacer/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/yourwork/sdl2/spacer/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/spacer/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/spacer/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/spacer/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/spacer/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/spacer/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/spacer//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


