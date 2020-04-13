# coding: utf-8

CC = "g++"
CPP_SRC = "#{ENV['CPP_SRC']}"   #入力src
TEST_LOG = "./test/log_url"
TEST_OUT = "test.out"
TOOL_DIR = "./tools"
LIB_DIR = "./lib"

def get_url_from_src(fname)
  url=""
  File.open("#{fname}"){|f|
    url=f.gets
  }
  url.chomp!
  url.strip!
  url.sub!(/^\/\//,"")
  url.strip!
  return url
end

def check_url_from_log(fname, src_url)
  if !File.exist?("#{fname}")
    return true
  end
  url=""
  File.open("#{fname}"){|f|
    url=f.gets
  }
  url="" if url.nil?
  url.chomp!
  url.strip!
  return !url.eql?(src_url)
end

desc "サンプルケースのダウンロード,CPP_SRC=agc023_a.cpp"
task :dl_test do
  url=get_url_from_src(CPP_SRC)
  if check_url_from_log(TEST_LOG, url) then
    sh "./ojdl.sh #{url}"
    sh "echo #{url}>#{TEST_LOG}"
  end
end

desc "テスト実行"
task :invoke_test=>[:dl_test, "#{TEST_OUT}"] do
  sh "oj test -c ./#{TEST_OUT}"
end

desc "テスト用の実行ファイルのビルド"
file "test.out" => "#{CPP_SRC}" do
  sh "#{CC} -std=c++17 -O0 -g -I.cache/cxxpch -I. #{CPP_SRC} -o #{TEST_OUT}"
end


desc "ソースファイ提出,CPP_SRC=abc000_a.cpp"
task :submit do
  url=get_url_from_src(CPP_SRC)
  sh "oj submit #{url} #{CPP_SRC}"
end


desc "snippetの作成,更新"
task :make_snippet do
  sh "#{TOOL_DIR}/make_snippet.rb #{LIB_DIR}/template_base.cpp #{LIB_DIR} .vscode/cpp.code-snippets"
end