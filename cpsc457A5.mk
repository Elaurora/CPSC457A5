##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cpsc457A5
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/joshua/Documents/CPSC457Assignment5
ProjectPath            :=C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=joshua
Date                   :=30/11/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="cpsc457A5.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/database.c$(ObjectSuffix) $(IntermediateDirectory)/reader.c$(ObjectSuffix) $(IntermediateDirectory)/writers.c$(ObjectSuffix) $(IntermediateDirectory)/types.c$(ObjectSuffix) $(IntermediateDirectory)/server.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix)main.c

$(IntermediateDirectory)/database.c$(ObjectSuffix): database.c $(IntermediateDirectory)/database.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/database.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/database.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/database.c$(DependSuffix): database.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/database.c$(ObjectSuffix) -MF$(IntermediateDirectory)/database.c$(DependSuffix) -MM database.c

$(IntermediateDirectory)/database.c$(PreprocessSuffix): database.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/database.c$(PreprocessSuffix)database.c

$(IntermediateDirectory)/reader.c$(ObjectSuffix): reader.c $(IntermediateDirectory)/reader.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/reader.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reader.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/reader.c$(DependSuffix): reader.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/reader.c$(ObjectSuffix) -MF$(IntermediateDirectory)/reader.c$(DependSuffix) -MM reader.c

$(IntermediateDirectory)/reader.c$(PreprocessSuffix): reader.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/reader.c$(PreprocessSuffix)reader.c

$(IntermediateDirectory)/writers.c$(ObjectSuffix): writers.c $(IntermediateDirectory)/writers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/writers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/writers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/writers.c$(DependSuffix): writers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/writers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/writers.c$(DependSuffix) -MM writers.c

$(IntermediateDirectory)/writers.c$(PreprocessSuffix): writers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/writers.c$(PreprocessSuffix)writers.c

$(IntermediateDirectory)/types.c$(ObjectSuffix): types.c $(IntermediateDirectory)/types.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/types.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/types.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/types.c$(DependSuffix): types.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/types.c$(ObjectSuffix) -MF$(IntermediateDirectory)/types.c$(DependSuffix) -MM types.c

$(IntermediateDirectory)/types.c$(PreprocessSuffix): types.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/types.c$(PreprocessSuffix)types.c

$(IntermediateDirectory)/server.c$(ObjectSuffix): server.c $(IntermediateDirectory)/server.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/joshua/Documents/CPSC457Assignment5/Assignment5/server.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/server.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/server.c$(DependSuffix): server.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/server.c$(ObjectSuffix) -MF$(IntermediateDirectory)/server.c$(DependSuffix) -MM server.c

$(IntermediateDirectory)/server.c$(PreprocessSuffix): server.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/server.c$(PreprocessSuffix)server.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


