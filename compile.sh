clear
rm output*
g++ -Wall -pedantic -g *.cpp *.h  -o output

#./output algorithm=select digitsPerNode=3 output=misc/output.txt input=misc/input2.txt
echo
#./output algorithm=insert digitsPerNode=4 output=output.txt input=input2.txt
echo
#./output algorithm=merge digitsPerNode=4 output=misc/output.txt input=misc/input2.txt
echo
#./output algorithm=quick digitsPerNode=4 output=misc/output.txt input=misc/input.txt
# need to do stats for quick sort
echo
./output algorithm=heap digitsPerNode=4 output=output.txt input=misc/input2.txt
# need to do stats for heap sort
echo
cat misc/output.txt
