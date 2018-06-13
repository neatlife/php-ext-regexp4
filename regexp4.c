/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_regexp4.h"
#include "RecursiveRegexpRaptor-4/regexp4.h"

/* If you declare any globals in php_regexp4.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(regexp4)
*/

/* True global resources - no need for thread safety here */
static int le_regexp4;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("regexp4.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_regexp4_globals, regexp4_globals)
    STD_PHP_INI_ENTRY("regexp4.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_regexp4_globals, regexp4_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_regexp4_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_regexp4_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "regexp4", arg);

	RETURN_STR(strg);
}

PHP_FUNCTION(regexp4)
{
	char *txt = NULL, *re = NULL;
	size_t txt_len, re_len;
	int match_count = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &txt, &txt_len, &re, &re_len) == FAILURE) {
		return;
	}

	match_count = regexp4(txt, re);

	RETURN_LONG(match_count);
}

PHP_FUNCTION(cpyCatch)
{
	char *str = NULL;
	int index;
	size_t str_len;
	char * catch;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "sl", &str, &str_len, &index) == FAILURE) {
		return;
	}

	catch = cpyCatch(str, index);

	RETURN_STR(catch);
}

PHP_FUNCTION(totCatch)
{
	int total;

	total = totCatch();

	RETURN_LONG(total);
}

PHP_FUNCTION(lenCatch)
{
	int index;
	size_t str_len;
	int len;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &index) == FAILURE) {
		return;
	}

	len = lenCatch(index);

	RETURN_LONG(len);
}

PHP_FUNCTION(gpsCatch)
{
	char *str = NULL;
	int index;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &index) == FAILURE) {
		return;
	}

	str = gpsCatch(index);

	RETURN_STR(str);
}

PHP_FUNCTION(putCatch)
{
	char *newStr = NULL, *putStr = NULL;
	size_t newStr_len, putStr_len;
	int match_count = 0;
	char *result = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &newStr, &newStr_len, &putStr, &putStr_len) == FAILURE) {
		return;
	}

	result = putCatch(newStr, putStr);

	RETURN_STR(result);
}

PHP_FUNCTION(rplCatch)
{
	char *newStr = NULL, *rplStr = NULL;
	size_t newStr_len, rplStr_len;
	int id;
	char* rplCatchResult;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ssl", &newStr, &newStr_len, &rplStr, &rplStr_len, &id) == FAILURE) {
		return;
	}

	rplCatchResult = rplCatch(newStr, rplStr, id);

	RETURN_STR(rplCatchResult);
}

/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_regexp4_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_regexp4_init_globals(zend_regexp4_globals *regexp4_globals)
{
	regexp4_globals->global_value = 0;
	regexp4_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(regexp4)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(regexp4)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(regexp4)
{
#if defined(COMPILE_DL_REGEXP4) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(regexp4)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(regexp4)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "regexp4 support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ regexp4_functions[]
 *
 * Every user visible function must have an entry in regexp4_functions[].
 */
const zend_function_entry regexp4_functions[] = {
	PHP_FE(confirm_regexp4_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(regexp4,	NULL)		/* For testing, remove later. */
	PHP_FE(cpyCatch,	NULL)
	PHP_FE(totCatch,	NULL)
	PHP_FE(lenCatch,	NULL)
	PHP_FE(gpsCatch,	NULL)
	PHP_FE(putCatch,	NULL)
	PHP_FE(rplCatch,	NULL)
	PHP_FE_END	/* Must be the last line in regexp4_functions[] */
};
/* }}} */

/* {{{ regexp4_module_entry
 */
zend_module_entry regexp4_module_entry = {
	STANDARD_MODULE_HEADER,
	"regexp4",
	regexp4_functions,
	PHP_MINIT(regexp4),
	PHP_MSHUTDOWN(regexp4),
	PHP_RINIT(regexp4),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(regexp4),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(regexp4),
	PHP_REGEXP4_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_REGEXP4
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(regexp4)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
