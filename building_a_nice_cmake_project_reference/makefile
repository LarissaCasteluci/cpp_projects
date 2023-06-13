# ------------------------------------------------
# Generic Makefile
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = project

CXX    = g++
CXXFLAGS   = -g -std=c++11 -lrt -O0 -Wconversion -Wsign-conversion

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.hh)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

INC = include interfaces
ALL_INCLUDES = $(addprefix -I, $(INC))
#ALL_INCLUDES += INCLUDES

default: $(BINDIR)/$(TARGET)

#COMPILING
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(ALL_INCLUDES) $(CXXFLAGS) -c $< -o $@

#LINKING
$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CXX) $(ALL_INCLUDES) $(OBJECTS) $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BINDIR)/$(TARGET)
