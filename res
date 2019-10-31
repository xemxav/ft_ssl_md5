  12   13   14   15
|....|....|....|....|

si i > 13 <==> len > 56 <==> len / 4 > 13
 -> il faut ajouter le 0x80 sur l'octet qui suit
  -> si ret != 0 <==> len % 4 != 0 :
  		il faut mettre 0x80 sur l'octet qui suit
  		on est donc dans buf[i], sur l'octet d'index ret
  		on increment byte_count de (4 - ret) * 8
  -> si ret == 0 <==> on met sur le premier octet.
  il faut ensuite hasher ce buf et passer a un suivant vide avec juste la size

  si i < 14 :
