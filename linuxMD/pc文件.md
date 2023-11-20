```
ll-builder export
```

# find . -name *.pc

进入./LuaJIT/files/lib/x86_64-linux-gnu/pkgconfig/luajit.pc

```
user@user-PC:~/Desktop/work/linggo/love/LuaJIT/LuaJIT/files/lib/x86_64-linux-gnu/pkgconfig$ cat luajit.pc
```

```
#Package information for LuaJIT to be used by pkg-config.

majver=2
minver=1
relver=1696795921
version=${majver}.${minver}.${relver}
abiver=5.1

prefix=/runtime
multilib=lib/x86_64-linux-gnu
exec_prefix=${prefix}
libdir=${exec_prefix}/${multilib}
libname=luajit-${abiver}
includedir=${prefix}/include/luajit-${majver}.${minver}

INSTALL_LMOD=${prefix}/share/lua/${abiver}
INSTALL_CMOD=${prefix}/${multilib}/lua/${abiver}

Name: LuaJIT
Description: Just-in-time compiler for Lua
URL: https://luajit.org
Version: ${version}
Requires:
Libs: -L${libdir} -l${libname}
Libs.private: -Wl,-E -lm -ldl
Cflags: -I${includedir}
```

