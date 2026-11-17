/* Target definitions for MiHOS (x86_64-mihos, i686-mihos). */
#undef TARGET_MIHOS
#define TARGET_MIHOS 1

/* Link against the C library. */
#undef LIB_SPEC
#define LIB_SPEC "-lc"

/* Linked before user code (%s: look in the library directories). crt1.o is
   mlibc's entry point (_start), as glibc's on Linux. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt1.o%s crti.o%s crtbegin.o%s"

/* Linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

/* C++ sees the GNU extensions of the C library's headers, as on Linux
   (gnu-user.h): mlibc's own C++ code and libstdc++ expect them. */
#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC "-D_GNU_SOURCE %(cpp)"

/* Predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__mihos__");     \
    builtin_define ("__unix__");      \
    builtin_assert ("system=mihos");  \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");  \
  } while (0);
