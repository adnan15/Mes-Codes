#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/getAction.o \
	${OBJECTDIR}/getFonctions.o \
	${OBJECTDIR}/lire_xml.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/include/opencv2 `pkg-config --libs opencv` -lOpenNI.jni -lOpenNI -lnimCodecs -lnimMockNodes -lnimRecorder `pkg-config --libs QtCore` `pkg-config --libs QtGui`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/reconpersonne

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/reconpersonne: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/reconpersonne ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/getAction.o: getAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/opencv2 -I/home/abdi/kinect/OpenNI-Bin-Dev-Linux-x86-v1.5.7.10/Include `pkg-config --cflags opencv` `pkg-config --cflags QtCore` `pkg-config --cflags QtGui`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getAction.o getAction.cpp

${OBJECTDIR}/getFonctions.o: getFonctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/opencv2 -I/home/abdi/kinect/OpenNI-Bin-Dev-Linux-x86-v1.5.7.10/Include `pkg-config --cflags opencv` `pkg-config --cflags QtCore` `pkg-config --cflags QtGui`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getFonctions.o getFonctions.cpp

${OBJECTDIR}/lire_xml.o: lire_xml.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/opencv2 -I/home/abdi/kinect/OpenNI-Bin-Dev-Linux-x86-v1.5.7.10/Include `pkg-config --cflags opencv` `pkg-config --cflags QtCore` `pkg-config --cflags QtGui`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lire_xml.o lire_xml.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/opencv2 -I/home/abdi/kinect/OpenNI-Bin-Dev-Linux-x86-v1.5.7.10/Include `pkg-config --cflags opencv` `pkg-config --cflags QtCore` `pkg-config --cflags QtGui`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/reconpersonne

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
