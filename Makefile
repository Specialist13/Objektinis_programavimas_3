CXX = g++
CXXFLAGS = -O3 -std=c++17 -Iinclude
LDFLAGS_DLL = -shared
DEFINES = -DBUILDING_DLL

# Folders
SRC_DIR = ./source
TEST_DIR = ./tests
GTEST_DIR = ./external/googletest/googletest
GTEST_INC = $(GTEST_DIR)/include
GTEST_SRC = $(GTEST_DIR)/src/gtest-all.cc
GTEST_OBJ = gtest-all.o
GTEST_LIB = libgtest.a

# Output
APP = program.exe
TEST_APP = runTests.exe
DLL = libproject.dll
IMPLIB = libproject.a

# === Build main app ===
all: dll
	$(CXX) $(CXXFLAGS) -Iinclude $(SRC_DIR)/main.cpp libproject.a -o $(APP)

# === Build DLL (excluding main.cpp) ===
dll:
	$(CXX) $(CXXFLAGS) $(DEFINES) $(LDFLAGS_DLL) \
		-Wl,--out-implib,$(IMPLIB) \
		$(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp)) \
		-o $(DLL)

# === Build GoogleTest ===
gtest:
	$(CXX) $(CXXFLAGS) -I$(GTEST_INC) -I$(GTEST_DIR) -c $(GTEST_SRC) -o $(GTEST_OBJ)
	ar rcs $(GTEST_LIB) $(GTEST_OBJ)

# === Run tests ===
test: gtest
	$(CXX) $(CXXFLAGS) -I$(GTEST_INC) $(TEST_DIR)/*.cpp \
		$(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp)) \
		$(GTEST_LIB) -o $(TEST_APP)
	./$(TEST_APP)

# === Clean ===
clean:
	del /Q *.exe *.o *.a *.dll 2>nul || exit 0
