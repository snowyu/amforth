\ #require count.frt
\ #require search-name.frt

: (find-name) ( addr len wid -- addr len 0 | nt -1 )
  >r 2dup r> search-name dup if nip nip then ;
 
: find-name ( addr len --  nt|0 ) 
  ['] (find-name) cfg-order map-stack
;
