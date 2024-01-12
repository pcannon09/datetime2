OBJS = main.o dt.o

EXE = main

OBJDIR = obj
SRCDIR = src
TSTDIR = test
INCDIR = inc

CPPVERSION = 20

CXXFLAGS = -Wall -Wextra -Wconversion -g -MMD -MP -std=c++$(CPPVERSION)
INCLUDES = -I$(INCDIR)

_OBJS = $(patsubst %,$(OBJDIR)/%,$(OBJS))

# .cpp
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "[ * ] Compiling $@ from $<..."
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)
	@echo "[ OK ]"
	@echo

$(OBJDIR)/%.o: $(TSTDIR)/%.cpp
	@echo "[ * ] Compiling $@ from $<..."
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)
	@echo "[ OK ]"
	@echo

$(EXE): $(_OBJS)
	@echo "[ * ] Linking $@ from $^..."
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@echo "[ OK ]"
	@echo

.PHONY: all clean show_obj reset

all: $(EXE)

clean:
	@echo "[ * ] Cleaning..."
	@rm -f $(EXE)
	@rm -f $(OBJDIR)/*.o
	@rm -f $(OBJDIR)/*.d
	@mkdir -p $(OBJDIR)
	@echo "[ OK ]"

show_obj:
	@echo "[ * ] Finding..."
	@ls $(OBJDIR)
	@echo "[ OK ]"

reset: clean all

