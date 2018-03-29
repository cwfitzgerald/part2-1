WARNINGS := -fdiagnostics-color=always -Wall -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wdisabled-optimization -Wdouble-promotion -Wextra -Wformat=2 -Winit-self -Wlogical-op -Wno-gnu-zero-variadic-macro-arguments -Wmissing-include-dirs -Wno-sign-conversion -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wredundant-decls -Wshadow -Wstrict-aliasing=1 -Wstrict-null-sentinel -Wstrict-overflow=1 -Wswitch-default -Wundef -Wno-unknown-pragmas -Wuseless-cast -Wno-unknown-warning-option
STANDARD := -std=c++14 $(CXXFLAGS)
DEPENDS   = -MMD -MF $(patsubst %.cpp,depends/%.d,$<)

ifdef DEBUG
OPTIMIZATION := -O0 -g
else
OPTIMIZATION := -O3
endif

.PHONY: all clean

ALL_TARGETS = indent dedent

all: $(ALL_TARGETS)

indent: obj/indent.o obj/funcs.o
	@echo Linking $@
	@$(CXX) $(WARNINGS) $(STANDARD) $(OPTIMIZATION) $^ -o $@

dedent: obj/dedent.o obj/funcs.o
	@echo Linking $@
	@$(CXX) $(WARNINGS) $(STANDARD) $(OPTIMIZATION) $^ -o $@

obj depends:
	@echo Creating Directory $@
	@mkdir -p $@

obj/%.o: %.cpp | obj depends
	@echo Building CXX Object $@
	@$(CXX) $(WARNINGS) $(STANDARD) $(OPTIMIZATION) $(DEPENDS) $< -c -o $@

-include $(wildcard depends/*.d)

clean:
	rm -rf obj
	rm -rf dependss
	rm -f $(ALL_TARGETS)
