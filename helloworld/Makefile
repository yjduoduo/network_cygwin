#makefileok 
#添加目录为目录名
#v1.2
###############################################################################
#$(shell basename $(COMPILE_DIR))文件名
COMPILE_DIR = $(shell pwd)
TARGET 	= $(shell basename $(COMPILE_DIR))

SUBDIR = .
#SRC_INC_DIR	= $(shell find src -type d)
#SRC_INC	 = $(SRC_INC_DIR:%=-I%)
LOCAL_INC 	= $(SRC_INC) -Iinclude -Iinclude/freetype 
INCPATH 	= $(LOCAL_INC)
#LOCALDIR	= `pwd`
LOCAL_LIBDIR 	= #lib
LOCAL_LIBS 	= #-Llib #-lporting
LIBS = $(LOCAL_LIBS) $(RPATH_LINK) 
SRC 	= $(shell find $(SUBDIR) -name '*.c')
CPPSRC 	= $(shell find $(SUBDIR) -name '*.cpp') 
OBJ 	= $(SRC:%.c=%.o)
CPPOBJ 	= $(CPPSRC:%.cpp=%.o) 
LIBTARGET 	= 
LIBSHAREDTARGET	=

EXECDIR = ../exelibtest


COMPILE_PEFIX = #mips-linux-gnu-
CC = $(COMPILE_PEFIX)gcc
CXX = $(COMPILE_PEFIX)g++
LINK = $(COMPILE_PEFIX)g++
LFLAGS = #-EL #-Wl,-O1
RPATH_LINK = 
DEFINES = #-D_FILE_OFFSET_BITS=64 
CFLAGS = -w -fPIC -g -x c -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O2 -g -Wall -W -D_REENTRANT $(DEFINES)#-EL 
CXXFLAGS = -w -fPIC -g -pipe $(EXTRA_OPTS) $(OPT_CFLAGS) -pipe -O2 -g -Wall -W -D_REENTRANT $(DEFINES)


AR = $(COMPILE_PEFIX)ar rcs
TAR = tar -cf
COMPRESS = gzip -9f
COPY = cp -f
SED = sed
COPY_FILE = $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE = install -m 644 -p
INSTALL_DIR = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE = rm -f
SYMLINK = ln -sf
DEL_DIR = rmdir
MOVE = mv -f
CHK_DIR_EXISTS= test -d
MKDIR = mkdir -p





all:$(TARGET)
	@echo current path is $(shell basename $(COMPILE_DIR))
	@echo "$(COPY_FILE) $(TARGET) $(EXECDIR)"
	@echo "$(MKDIR) $(EXECDIR)"
	@$(MKDIR) $(EXECDIR)
	@$(COPY_FILE) $(TARGET) $(EXECDIR)

	
$(LIBTARGET): $(LIBSHAREDTARGET) $(LIBTARGET) 
	@echo " [AR]	($@)"
	@$(AR) $@ $(OBJ) $(CPPOBJ)

$(TARGET): $(OBJ) $(CPPOBJ) 
	@echo " [LD]	($(TARGET))"
	@echo now file is `pwd`
	@echo "$(LINK) $(LFLAGS) -o $(TARGET) $(OBJ) $(CPPOBJ) $(LIBS)"
	@$(LINK) $(LFLAGS) -o $(TARGET) $(OBJ) $(CPPOBJ) $(LIBS)
	
	
install: all

%.o : %.c
	@echo " [CC]	($@)"
	@echo "	$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@"
	@$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@
%.o : %.cpp
	@echo " [CXX]	($@)"
	@echo "	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@"
	@$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

clean:
	@echo " Cleaning... "
	@echo rm -f $(OBJ) $(CPPOBJ) $(TARGET) $(LIBTARGET) 
	@rm -f $(OBJ) $(CPPOBJ) $(TARGET) $(LIBTARGET) 

