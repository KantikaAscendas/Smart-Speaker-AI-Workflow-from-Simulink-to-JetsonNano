###########################################################################
## Makefile generated for component 'AudioSmartSpeakerOnJetsonNano'. 
## 
## Makefile     : AudioSmartSpeakerOnJetsonNano.mk
## Generated on : Tue May 05 16:51:13 2026
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/AudioSmartSpeakerOnJetsonNano.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = AudioSmartSpeakerOnJetsonNano
MAKEFILE                  = AudioSmartSpeakerOnJetsonNano.mk
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2026a
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2026a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = $(MATLAB_WORKSPACE)/C/Users/KoayXianCong/Documents/MATLAB/Examples/R2026a/deeplearning_shared/AudioSmartSpeakerOnRaspberryPiSimulinkExample
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ARM Cortex-A CMSIS
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
LINUX_TARGET_CUSTOM_LIBS  = -lasound -lsox
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU GCC for NVIDIA Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2026a
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG  = --output_file=
LDOUTPUTFLAG  = --output_file=
XCOMPILERFLAG =  

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm -lstdc++

FORMAT_FOR_ECHO_CMD              = $(strip $(subst >,^>,\
	$(subst <,^<,\
	$(subst |,^|,\
	$(subst &,^&,\
	$(subst ",^",\
	$(subst ^,^^,\
	$1)))))))
FORMAT_FOR_ECHO_SH               = ""'$1'
SHELL_IS_CMD_EXE                := $(if $(findstring "$$SHELL",$(shell echo "$$SHELL")),1,)
FORMAT_FOR_ECHO                  = $(if $(SHELL_IS_CMD_EXE),$(FORMAT_FOR_ECHO_CMD),$(FORMAT_FOR_ECHO_SH))
HASH                             = \#
SEMICOLON                        = ;
UNESCAPE_SEMICOLONS              = $(subst \;,;,$1)
ADD_QUOTES                       = $(foreach aPath,$1,"$(aPath)")

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU GCC for NVIDIA Embedded Processors Assembler
AS = as

# C Compiler: GNU GCC for NVIDIA Embedded Processors C Compiler
CC = gcc

# Linker: GNU GCC for NVIDIA Embedded Processors Linker
LD = gcc

# C++ Compiler: GNU GCC for NVIDIA Embedded Processors C++ Compiler
CPP = g++

# C++ Linker: GNU GCC for NVIDIA Embedded Processors C++ Linker
CPP_LD = g++

# Archiver: GNU GCC for NVIDIA Embedded Processors Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS = -c   $(ASFLAGS_ADDITIONAL) $(INCLUDES)

CFLAGS = -c -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"    -O2 -g

LDFLAGS = -lrt -pthread -ldl -g

SHAREDLIB_LDFLAGS = -shared  -lrt -pthread -ldl -g

CPPFLAGS = -c -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"    -O2 -g

CPP_LDFLAGS = -lrt -pthread -ldl -g

CPP_SHAREDLIB_LDFLAGS = -shared  -lrt -pthread -ldl -g

ARFLAGS = -r

DOWNLOAD_FLAGS = 

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE) -j4

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/AudioSmartSpeakerOnJetsonNano.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/include -I$(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/inc -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis.instrset/CMSIS/Core_A/Include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Include/dsp -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/PrivateInclude -I$(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl -I$(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/utils -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/includes -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_CAN_BITRATE=500000 -DMW_CAN_ALLOWALLMSGS=1 -DMW_SCHED_OTHER=1
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = -D_GNU_SOURCE
DEFINES_OPTS = -DXCP_EXTMODE_SIMULATION_TIME_IN_TICKS -DINTERNAL_XCP_MEM_BLOCK_1_SIZE=128 -DINTERNAL_XCP_MEM_BLOCK_1_NUMBER=1 -DINTERNAL_XCP_MEM_BLOCK_2_SIZE=168 -DINTERNAL_XCP_MEM_BLOCK_2_NUMBER=4 -DINTERNAL_XCP_MEM_BLOCK_3_SIZE=48 -DINTERNAL_XCP_MEM_BLOCK_3_NUMBER=4 -DINTERNAL_XCP_MEM_RESERVED_POOLS_TOTAL_SIZE=988 -DINTERNAL_XCP_MEM_RESERVED_POOLS_NUMBER=5 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=1 -DXCP_MIN_EVENT_NO_RESERVED_POOL=2 -DXCP_MAX_CTO_SIZE=255 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DEXTMODE_XCP_TRIGGER_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DON_TARGET_WAIT_FOR_START=1 -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_SET_MTA_SUPPORT -DTID01EQ=0 -DXCP_EXTMODE_RUN_BACKGROUND_FLUSH
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=200000 -DRT
DEFINES_STANDARD = -DMODEL=AudioSmartSpeakerOnJetsonNano -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/MW_alsa_audio.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/MW_sox_audio_reader.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_abs_f32.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FilteringFunctions/arm_biquad_cascade_df2T_f32.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Source/arm_cl_tables.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/arm_mat_trans_f32.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/arm_mat_trans_q15.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_offset_f32.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_scale_f32.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_scale_f64.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FastMathFunctions/arm_vexp_f32.c $(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/src/mw_arm_sos_f32T.c $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/AudioSmartSpeakerOnJetsonNano.c $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/AudioSmartSpeakerOnJetsonNano_data.c $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rtGetInf.c $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rtGetNaN.c $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rt_nonfinite.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_tcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_tcp.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/utils/MW_nvidia_init.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/src/linuxTimeLogger.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_platform_default.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c

MAIN_SRC = $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_alsa_audio.c.o MW_sox_audio_reader.c.o xcp_ext_mode.c.o arm_abs_f32.c.o arm_biquad_cascade_df2T_f32.c.o arm_cl_tables.c.o arm_mat_trans_f32.c.o arm_mat_trans_q15.c.o arm_offset_f32.c.o arm_scale_f32.c.o arm_scale_f64.c.o arm_vexp_f32.c.o mw_arm_sos_f32T.c.o AudioSmartSpeakerOnJetsonNano.c.o AudioSmartSpeakerOnJetsonNano_data.c.o rtGetInf.c.o rtGetNaN.c.o rt_nonfinite.c.o xcp_ext_common.c.o xcp_ext_classic_trigger.c.o xcp_ext_param_default_tcp.c.o xcp.c.o xcp_standard.c.o xcp_daq.c.o xcp_calibration.c.o xcp_fifo.c.o xcp_transport.c.o xcp_mem_default.c.o xcp_drv_rtiostream.c.o xcp_utils.c.o xcp_frame_tcp.c.o MW_nvidia_init.c.o linuxTimeLogger.c.o rtiostream_interface.c.o rtiostream_tcpip.c.o rtiostream_utils.c.o xcp_platform_default.c.o linuxinitialize.c.o

MAIN_OBJ = ert_main.c.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(LINUX_TARGET_LIBS_MACRO)

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = $(LDFLAGS_CUSTOMLIBFLAGS)

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -march=armv8-a -DARM_MATH_NEON -DARM_MATH_LOOPUNROLL -fPIC -D__GNUC_PYTHON__  -include arm_math.h -include NEMath.h 
CFLAGS_SKIPFORSIL =  
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_CUSTOMLIBFLAGS = -lasound

LDFLAGS += $(LDFLAGS_CUSTOMLIBFLAGS)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_CUSTOMLIBFLAGS = -lasound

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_CUSTOMLIBFLAGS)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -march=armv8-a -DARM_MATH_NEON -DARM_MATH_LOOPUNROLL -fPIC -D__GNUC_PYTHON__  -include arm_math.h -include NEMath.h 
CPPFLAGS_SKIPFORSIL =  
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_CUSTOMLIBFLAGS = -lasound

CPP_LDFLAGS += $(CPP_LDFLAGS_CUSTOMLIBFLAGS)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_CUSTOMLIBFLAGS = -lasound

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_CUSTOMLIBFLAGS)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


prebuild : 


download : $(PRODUCT)


execute : download
	echo $(call FORMAT_FOR_ECHO,### Invoking postbuild tool Execute ...)
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo $(call FORMAT_FOR_ECHO,### Done invoking postbuild tool.)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo $(call FORMAT_FOR_ECHO,### Creating standalone executable "$(PRODUCT)" ...)
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo $(call FORMAT_FOR_ECHO,### Created: "$(PRODUCT)")


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Source/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Source/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Source/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FastMathFunctions/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FastMathFunctions/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FastMathFunctions/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FilteringFunctions/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FilteringFunctions/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FilteringFunctions/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


MW_alsa_audio.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/MW_alsa_audio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_sox_audio_reader.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/realtime/targets/linux/src/MW_sox_audio_reader.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_mode.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_abs_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_abs_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_biquad_cascade_df2T_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FilteringFunctions/arm_biquad_cascade_df2T_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_cl_tables.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/ComputeLibrary/Source/arm_cl_tables.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_mat_trans_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/arm_mat_trans_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_mat_trans_q15.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/MatrixFunctions/arm_mat_trans_q15.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_offset_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_offset_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_scale_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_scale_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_scale_f64.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/BasicMathFunctions/arm_scale_f64.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_vexp_f32.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/3P.instrset/cmsis_dsp.instrset/Source/FastMathFunctions/arm_vexp_f32.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_arm_sos_f32T.c.o : $(MATLAB_ROOT)/toolbox/target/arm_cmsis_crl/math/arm_cortex_a_cmsis_crl/crl/src/mw_arm_sos_f32T.c
	$(CC) $(CFLAGS) -o "$@" "$<"


AudioSmartSpeakerOnJetsonNano.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/AudioSmartSpeakerOnJetsonNano.c
	$(CC) $(CFLAGS) -o "$@" "$<"


AudioSmartSpeakerOnJetsonNano_data.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/AudioSmartSpeakerOnJetsonNano_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.c.o : $(START_DIR)/AudioSmartSpeakerOnJetsonNano_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_common.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_classic_trigger.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_param_default_tcp.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_tcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_standard.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_daq.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_calibration.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_fifo.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_transport.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_mem_default.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_drv_rtiostream.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_utils.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_frame_tcp.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_tcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_nvidia_init.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/utils/MW_nvidia_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linuxTimeLogger.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2026a/toolbox/target/supportpackages/nvidia/sources/src/linuxTimeLogger.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_interface.c.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_tcpip.c.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_utils.c.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_platform_default.c.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_platform_default.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linuxinitialize.c.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo $(call FORMAT_FOR_ECHO,### PRODUCT = $(PRODUCT))
	echo $(call FORMAT_FOR_ECHO,### PRODUCT_TYPE = $(PRODUCT_TYPE))
	echo $(call FORMAT_FOR_ECHO,### BUILD_TYPE = $(BUILD_TYPE))
	echo $(call FORMAT_FOR_ECHO,### INCLUDES = $(INCLUDES))
	echo $(call FORMAT_FOR_ECHO,### DEFINES = $(DEFINES))
	echo $(call FORMAT_FOR_ECHO,### ALL_SRCS = $(ALL_SRCS))
	echo $(call FORMAT_FOR_ECHO,### ALL_OBJS = $(ALL_OBJS))
	echo $(call FORMAT_FOR_ECHO,### LIBS = $(LIBS))
	echo $(call FORMAT_FOR_ECHO,### MODELREF_LIBS = $(MODELREF_LIBS))
	echo $(call FORMAT_FOR_ECHO,### SYSTEM_LIBS = $(SYSTEM_LIBS))
	echo $(call FORMAT_FOR_ECHO,### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS))
	echo $(call FORMAT_FOR_ECHO,### ASFLAGS = $(ASFLAGS))
	echo $(call FORMAT_FOR_ECHO,### CFLAGS = $(CFLAGS))
	echo $(call FORMAT_FOR_ECHO,### LDFLAGS = $(LDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### CPPFLAGS = $(CPPFLAGS))
	echo $(call FORMAT_FOR_ECHO,### CPP_LDFLAGS = $(CPP_LDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### ARFLAGS = $(ARFLAGS))
	echo $(call FORMAT_FOR_ECHO,### MEX_CFLAGS = $(MEX_CFLAGS))
	echo $(call FORMAT_FOR_ECHO,### MEX_CPPFLAGS = $(MEX_CPPFLAGS))
	echo $(call FORMAT_FOR_ECHO,### MEX_LDFLAGS = $(MEX_LDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS))
	echo $(call FORMAT_FOR_ECHO,### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS))
	echo $(call FORMAT_FOR_ECHO,### EXECUTE_FLAGS = $(EXECUTE_FLAGS))
	echo $(call FORMAT_FOR_ECHO,### MAKE_FLAGS = $(MAKE_FLAGS))


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


