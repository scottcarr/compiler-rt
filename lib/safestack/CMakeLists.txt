add_custom_target(safestack)

set(SAFESTACK_SOURCES 
  safestack.cc
  dataconf.cc
  malloc.cc)

include_directories(..)

set(SAFESTACK_CFLAGS ${SANITIZER_COMMON_CFLAGS})

#if(APPLE)
#  # Build universal binary on APPLE.
#  add_compiler_rt_runtime(clang_rt.safestack
#    STATIC
#    OS osx
#    ARCHS ${SAFESTACK_SUPPORTED_ARCH}
#    SOURCES ${SAFESTACK_SOURCES}
#            $<TARGET_OBJECTS:RTInterception.osx>
#            $<TARGET_OBJECTS:RTSanitizerCommon.osx>
#            $<TARGET_OBJECTS:RTSanitizerCommonNoLibc.osx>
#    CFLAGS ${SAFESTACK_CFLAGS}
#    PARENT_TARGET safestack)
#else()
#  # Otherwise, build separate libraries for each target.
#  foreach(arch ${SAFESTACK_SUPPORTED_ARCH})
#    add_compiler_rt_runtime(clang_rt.safestack
#      STATIC
#      ARCHS ${arch}
#      SOURCES ${SAFESTACK_SOURCES}
#              $<TARGET_OBJECTS:RTInterception.${arch}>
#              $<TARGET_OBJECTS:RTSanitizerCommon.${arch}>
#              $<TARGET_OBJECTS:RTSanitizerCommonNoLibc.${arch}>
#      CFLAGS ${SAFESTACK_CFLAGS}
#      PARENT_TARGET safestack)
#  endforeach()
#endif()
add_compiler_rt_runtime(clang_rt.safestack
  STATIC
  ARCHS x86_64
  SOURCES ${SAFESTACK_SOURCES}
  $<TARGET_OBJECTS:RTInterception.x86_64>
  $<TARGET_OBJECTS:RTSanitizerCommon.x86_64>
  $<TARGET_OBJECTS:RTSanitizerCommonNoLibc.x86_64>
  CFLAGS ${SAFESTACK_CFLAGS}
  PARENT_TARGET safestack)
