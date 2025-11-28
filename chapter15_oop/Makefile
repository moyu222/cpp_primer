# Simple Makefile for chapter15_oop
# Shows variables, explicit dependencies and pattern rules

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Dependency flags for automatic header dependency generation. We keep these
# separate so we can choose to use them only for the main translation unit
# (test_Quote.cpp) and skip generating .d files for the small example programs.
DEPFLAGS = -MMD -MP

# Target executable
TARGET = QuoteTest

# Source files
SRCS = test_Quote.cpp \
	example1_overload_override.cpp \
	example2_inheritance_access.cpp \
	example3_ctor_dtor_order.cpp \
	example4_inline_demo.cpp \
	example4_inline_caller.cpp

# Object files (auto-generated from SRCS)
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean run examples $(EXAMPLES)

EXAMPLES = example1_overload_override example2_inheritance_access example3_ctor_dtor_order example4_inline_demo

all: $(TARGET)

# Link step: depends on object files
$(TARGET): test_Quote.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build test_Quote.o and generate its dependency file
test_Quote.o: test_Quote.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# Generic rule to build other .o from .cpp (examples) without generating .d files
# $@ = target, $< = first prerequisite (the .cpp file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Explicit header dependencies for example programs that include headers
# This avoids generating .d files for all examples but still rebuilds the
# affected example when its header changes.
example4_inline_demo.o: example4_inline_helper.hpp

# Clean generated files
clean:
	rm -f $(OBJS) $(TARGET) $(EXAMPLES) *.d

# Helper to run the program after build
run: $(TARGET)
	./$(TARGET)

# Special case: example4_inline_demo needs TWO source files to demonstrate
# that inline functions in headers can be safely included in multiple translation units
example4_inline_demo: example4_inline_demo.o example4_inline_caller.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Explicit header dependencies for example programs that include headers
# This avoids generating .d files for all examples but still rebuilds the
# affected example when its header changes.
example4_inline_demo.o: example4_inline_helper.hpp
example4_inline_caller.o: example4_inline_helper.hpp

.PHONY: examples help
# examples 现在直接构建所有示例可执行文件
examples: $(EXAMPLES)
	@echo "已构建示例可执行文件：" $(EXAMPLES)

help:
	@echo "可用目标: all (QuoteTest), examples (构建所有示例), <example_name> (单独构建某个示例)"
	@echo "示例: make example1_overload_override"


# Explain common dependencies (for learning):
# - Quote.o depends on Quote.cpp and Quote.hpp (implicit via include)
# - Bulk_quote.o depends on Bulk_quote.cpp and Bulk_quote.hpp and Quote.hpp
# - test_Quote.o depends on test_Quote.cpp and the headers it includes

# Include only the dependency file we generate (test_Quote.d). We intentionally
# do not include *.d for example programs because we don't generate .d for them.
-include test_Quote.d
