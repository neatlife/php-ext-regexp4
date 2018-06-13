dnl $Id$
dnl config.m4 for extension regexp4

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(regexp4, for regexp4 support,
dnl Make sure that the comment is aligned:
dnl [  --with-regexp4             Include regexp4 support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(regexp4, whether to enable regexp4 support,
dnl Make sure that the comment is aligned:
[  --enable-regexp4           Enable regexp4 support])

if test "$PHP_REGEXP4" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-regexp4 -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/regexp4.h"  # you most likely want to change this
  dnl if test -r $PHP_REGEXP4/$SEARCH_FOR; then # path given as parameter
  dnl   REGEXP4_DIR=$PHP_REGEXP4
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for regexp4 files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       REGEXP4_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$REGEXP4_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the regexp4 distribution])
  dnl fi

  dnl # --with-regexp4 -> add include path
  dnl PHP_ADD_INCLUDE($REGEXP4_DIR/include)

  dnl # --with-regexp4 -> check for lib and symbol presence
  dnl LIBNAME=regexp4 # you may want to change this
  dnl LIBSYMBOL=regexp4 # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $REGEXP4_DIR/$PHP_LIBDIR, REGEXP4_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_REGEXP4LIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong regexp4 lib version or lib not found])
  dnl ],[
  dnl   -L$REGEXP4_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(REGEXP4_SHARED_LIBADD)

  CFLAGS="-std=c99"
  PHP_NEW_EXTENSION(regexp4, RecursiveRegexpRaptor-4/regexp4_utf8.c regexp4.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
