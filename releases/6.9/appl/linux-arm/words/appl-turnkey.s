
COLON "appl-turnkey", APPLTURNKEY
  .word XT_DECIMAL, XT_UNAME
  .word XT_DOT_VER, XT_SPACE, XT_ENV_BOARD, XT_TYPE, XT_SPACE, XT_ENV_HOSTNAME, XT_TYPE, XT_CR
  .word XT_BUILD_INFO, XT_TYPE, XT_SPACE,XT_REV_INFO, XT_TYPE,XT_CR

  STRING "Type CTRL-D or CTRL-C to exit"
  .word XT_TYPE
.word XT_EXIT

CONSTANT "cache-start", CACHE_START, CACHESTART
CONSTANT "cache-end", CACHE_END, CACHEEND
