
COLON "!i", STORE_FLASH
    .word XT_2DROP, XT_EXIT

COLON "c!i", CSTORE_FLASH
    .word XT_2DROP, XT_EXIT

COLON "inflash?", INFLASHQ
    .word XT_FALSE, XT_EXIT

COLON "cacheflush", CACHEFLUSH
    .word XT_EXIT
