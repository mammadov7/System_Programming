for i in {1..64} ; do 
  if [[ $i -eq 9 || $i -eq 19 ]]; then 
    continue
  else 
  kill -$i $1 
  fi;
done