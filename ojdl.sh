#!/bin/bash
problemname=$1
rm -f test/*.in
rm -f test/*.out
rm -f log_url
oj dl "${problemname}"
cat ./test/sample-1.in>input.txt
