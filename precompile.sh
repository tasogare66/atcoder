#!/bin/sh -eux
 
pch_dir='./.cache/cxxpch'
header_base='bits/stdc++.h'
header_file="$pch_dir/$header_base"
header_dir=`dirname "$header_file"`
 
[ ! -d "$pch_dir" ] && mkdir -p "$pch_dir" || :
[ ! -d "$header_dir" ] && mkdir -p "$header_dir" || :
 
echo "#include <$header_base>" > "$header_file" \
  && g++ -std=c++17 -g -O0 -x c++-header "$header_file" -o "$header_file.gch" \
  && rm "$header_file"

#g++ -std=c++1y -g -O0 -fsanitize=undefined -x c++-header bits/stdc++.h
