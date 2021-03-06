/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
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
#include "php_tipi_ini_demo.h"

/* If you declare any globals in php_tipi_ini_demo.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(tipi_ini_demo)
*/

/* True global resources - no need for thread safety here */
static int le_tipi_ini_demo;

/* {{{ tipi_ini_demo_functions[]
 *
 * Every user visible function must have an entry in tipi_ini_demo_functions[].
 */
const zend_function_entry tipi_ini_demo_functions[] = {
	PHP_FE(confirm_tipi_ini_demo_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(get_demo_init_value,	NULL)
	PHP_FE_END	/* Must be the last line in tipi_ini_demo_functions[] */
};
/* }}} */

/* {{{ tipi_ini_demo_module_entry
 */
zend_module_entry tipi_ini_demo_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"tipi_ini_demo",
	tipi_ini_demo_functions,
	PHP_MINIT(tipi_ini_demo),
	PHP_MSHUTDOWN(tipi_ini_demo),
	PHP_RINIT(tipi_ini_demo),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(tipi_ini_demo),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(tipi_ini_demo),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_TIPI_INI_DEMO_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TIPI_INI_DEMO
ZEND_GET_MODULE(tipi_ini_demo)
#endif

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    PHP_INI_ENTRY("tipi_ini_demo.global_value", "42", PHP_INI_ALL, NULL)
//    STD_PHP_INI_ENTRY("tipi_ini_demo.global_value", "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_tipi_ini_demo_globals, tipi_ini_demo_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_tipi_ini_demo_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_tipi_ini_demo_init_globals(zend_tipi_ini_demo_globals *tipi_ini_demo_globals)
{
	tipi_ini_demo_globals->global_value = 0;
	tipi_ini_demo_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(tipi_ini_demo)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(tipi_ini_demo)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(tipi_ini_demo)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(tipi_ini_demo)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(tipi_ini_demo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "tipi_ini_demo support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_tipi_ini_demo_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_tipi_ini_demo_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "tipi_ini_demo", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto string get_demo_init_value()
    */
PHP_FUNCTION(get_demo_init_value)
{
	RETURN_LONG(INI_INT("tipi_ini_demo.global_value"));
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
