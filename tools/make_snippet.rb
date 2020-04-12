#!/bin/sh
exec ruby -S -x $0 "$@"
#! ruby

# snippetのjsonを作る
require 'json'

template_base=ARGV[0]
lib_dir=ARGV[1]

def err(msg)
  STDERR.print(msg+"\n")
  exit(1);
end

def parse_c_src(fpath)
  in_section=false
  line_no=0
  File.open(fpath){|f|
    f.each_line do |line|
      line_no+=1
      l = line.chomp

      if l=="//##template" then
        err("#{fpath}:#{line_no}:parse error.") if(in_section)
        in_section=true
      elsif l=="//##"
        err("#{fpath}:#{line_no}:parse error.") unless(in_section)
        in_section=false
      else
        if in_section then

        end
      end

    end
  }
end

parse_c_src(template_base)
