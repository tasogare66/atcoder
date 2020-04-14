#!/bin/sh
exec ruby -S -x $0 "$@"
#! ruby

# snippetのjsonを作る
require 'json'

template_base=ARGV[0]
lib_dir=ARGV[1]
out_file=ARGV[2]

def err_exit(msg)
  STDERR.print("\e[31m" + msg + "\e[0m" + "\n")
  exit(1)
end

def parse_c_src(fpath, result)
  in_section=false
  line_no=0
  #result = Hash.new

  hash_data=Hash.new
  hash_name=""
  clear =  ->(){
    hash_data=Hash.new
    hash_data["body"]=[]
    hash_name=""
  }
  err = ->(in_msg){
    err_exit("#{fpath}:#{line_no}:#{in_msg}")
  }

  File.open(fpath){|f|
    f.each_line do |line|
      line_no+=1
      line.chomp!
      l = line.strip

      if l=="//##template" then
        err.call("parse error.") if(in_section)
        in_section=true
        #clear snippet
        clear.call()
      elsif l=="//##"
        err.call("parse error.") unless(in_section)
        in_section=false
        #add snippet
        result.store(hash_name,hash_data)
      else
        if in_section then
          if l =~ /\/\/key:/ then
            err.call("duplicate \"key:\"") unless(hash_name.empty?)
            hash_name=$' #matchよりも後ろの文字列
          elsif l=~ /\/\/prefix:/ then
            err.call("duplicate \"key:\"") if(hash_data.has_key?("prefix"))
            hash_data["prefix"]=$'
          elsif l=~ /\/\/description:/ then
            err.call("duplicate \"key:\"") if(hash_data.has_key?("description"))
            hash_data["description"]=$'
          else
            hash_data["body"].push line 
          end
        end
      end

    end
  }

  return result
end

def parse_dir_c_src(dir_path,result)
  dir_entries = Dir.glob(dir_path + "/" + "**/*")
  dir_entries.each do |fn|
    if fn =~/\.cpp$|\.hpp$/ then
      parse_c_src(fn, result)
    end
  end
end

out_hash=Hash::new
#parse_c_src(template_base, out_hash)
parse_dir_c_src(lib_dir, out_hash)

File.open(out_file,"w") {|file|
  file.print <<EOS
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	// "Print to console": {
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
EOS
  file.puts(JSON.pretty_generate(out_hash))
}
