# Name of the executable
NAME := megaphone

# Sources
SRC := megaphone.cpp

# Build directory
BUILD_DIR := build

# Compiler & flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Objects & deps in build/
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP := $(OBJ:.o=.d)

# Default target
all: $(NAME)

# Link
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile .cpp -> build/.o (with dep files)
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Ensure build dir exists
$(BUILD_DIR):
	@mkdir -p $@

# Clean object files
clean:
	rm -rf $(BUILD_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Include auto-generated dependency files
-include $(DEP)

.PHONY: all clean fclean re