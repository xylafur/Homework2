
filename="sort"
casecount=12
# maximum time allowed for each run
timeout="10s"
#       0   1  2  3  4  5  6  7  8  9 10 11 12 9                                                                              
weight=(0  10 10 10 10 10 10 10 10 10 10 10 10)
digits=(0  1  2  3  4  5  6  7  8  8  8  8  8)
algorithm=("0"  "select" "insert" "heap" "merge" "quick" "select" "insert" "heap" "merge" "quick" "merge" "quick")
# base grade is 10 if code can compile successful
baseGrade=10
# color constants                                                                                                  
green="\033[1;92m"
red="\033[1;91m"
yellow="\033[1;93m"
nocolor="\033[0m"

# clean
rm -f bigO.txt *.out *.err *.stderr *.stdout *.diff $filename 2>/dev/null
#Compile the code
g++ -std=c++11 *.cpp -o $filename 2>COMPILE.err
# if the file count does not exit then exit the test
if [ ! -f $filename ]; then
    echo -e "${red}Compile FAILED. See COMPILE.err for more details.${nocolor}"
    echo "0" > GRADE
    exit
else
    rm -f COMPILE.err
fi
# Grade
gradeStats=()
for casenum in `seq 1 1 $casecount`; do
    gradeStats[$casenum]=0
done
grade=$baseGrade
for casenum in `seq 1 1 $casecount`; do
    echo "./$filename \"input=$casenum.txt;digitsPerNode=${digits[$casenum]};algorithm=${algorithm[$casenum]};output=$casenum.out\" 1>$casenum.stdout 2>$casenum.stderr"
    timeout -k $timeout $timeout ./$filename "input=$casenum.txt;digitsPerNode=${digits[$casenum]};algorithm=${algorithm[$casenum]};output=$casenum.out" 1>$casenum.stdout 2>$casenum.stderr
    if [ $? -ne 0 ]; then
        echo -e "        ${red}Program killed due to timeout ($timeout).$nocolor"
        echo "Test case $casenum timed out ($timeout)." >> TIMEOUT
    fi

    diff -iEBwu $casenum.ans $casenum.out > $casenum.diff
    if [ $? -ne 0 ]; then
        echo -e "Test case $casenum        ${red}FAILED$nocolor."
        let gradeStats[$casenum]=gradeStats[$casenum]+1
    else
        echo -e "Test case $casenum        ${green}PASSED$nocolor."
        rm -f $casenum.diff
        let grade=grade+weight[$casenum]
    fi
done
echo $grade > GRADE
echo -e "    ${green}Overall grade is $grade$nocolor"
