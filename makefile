PROJDIR := $(realpath $(CURDIR)/)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/objects

# Name of the final executable
TARGET = bomberman.o

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

# Create the list of directories
DIRS = map player ui
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(SOURCEDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir)))

# Generate the GCC includes parameters by adding -I before each source folder
INCLUDES = $(foreach dir, $(SOURCEDIRS), $(addprefix -I, $(dir)))

# Add this list to VPATH, the place make will look for the source files
VPATH = $(SOURCEDIRS)

# Create a list of *.cpp sources in DIRS
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.cpp))

# Define objects for all sources
OBJS := $(subst $(SOURCEDIRS),$(TARGETDIRS),$(SOURCES:.cpp=.o))
@echo $(OBJS)

# Define dependencies files for all objects

# Name the compiler
CC = g++

# OS specific part
ifeq ($(OS),Windows_NT)
	RM = del /F /Q 
	RMDIR = -RMDIR /S /Q
	MKDIR = -mkdir
	ERRIGNORE = 2>NUL || true
	SEP=
else
	RM = rm -rf 
	RMDIR = rm -rf 
	MKDIR = mkdir -p
	ERRIGNORE = 2>/dev/null
	SEP=/
endif

# Remove space after separator
PSEP = $(strip $(SEP))

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif

# Define the function that will generate each rule
define generateRules
$(1)/%.o: %.cpp
	@ echo Building $$@
	$(HIDE) $(CC) $$(INCLUDES) -o -c -W -Wall -ansi -pedantic -lncurses $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<) -MMD -std=c++20
endef

.PHONY: all clean directories 

all: directories $(TARGET)

$(TARGET): $(OBJS)
	$(HIDE) echo 'Linking $ @'
	$(HIDE) $(CC) $(OBJS) -o -c -W -Wall -ansi -pedantic -lncurses $(TARGET) -std=c++20

# Include dependencies

# Generate rules
$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories: 
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)

# Remove all objects, dependencies and executable files generated during the build
clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo Cleaning done ! 