;X DNEGATE   d1 -- d2     negate double precision
;   XT_SWAP INVERT SWAP INVERT 1 M+ ;
    HEADER(XT_DNEGATE,7,"dnegate",DOCOLON)
        DW XT_SWAP,XT_INVERT,XT_SWAP,XT_INVERT,lit,1,XT_MPLUS
        DW XT_EXIT