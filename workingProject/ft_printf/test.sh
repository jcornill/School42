clear
echo "=====START====="
echo "=====MAKEFILE====="
touch file_makefile.txt
#make | grep "Makefile"
#make all | grep "Makefile"
#make fclean | grep "Makefile" 
make re 2>&1 > file_makefile.txt
make clean 2>&1 >> file_makefile.txt
cat file_makefile.txt | grep " error" > file_test.txt
cat file_makefile.txt | grep "Stop" >> file_test.txt
file=file_test.txt
actualsize=$(wc -c <"$file")
function g {
	echo "\033[032m$1\033[0m"
}
function r {
	echo "\033[031m$1\033[0m"
}
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====ERROR====="
	cat file_test.txt
	exit
else
	g OK
fi
rm file_test.txt
echo "=====COMPILING====="
i=$(find . | grep "ft_printf.h" | cut -f 1 -d "f")
echo "Found ft_printf.h in $i"
gcc main.c -I $i libftprintf.a -o user.out
j=$(cat main.c | grep "ft_printf(" | wc -l | tr -d " ")
sed 's/ft_printf(/printf(/g' main.c > main_ref.c
gcc -w main_ref.c -I $i libftprintf.a -o ref.out
g OK
echo "====STARTING TEST===="
touch file_user.txt
touch file_ref.txt
touch file_diff.txt
echo "Total test to do : $j"
echo "=====simple TEST====="
./user.out "simple" > file_user.txt
./ref.out "simple" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%s TEST====="
./user.out "%s" > file_user.txt
./ref.out "%s" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%d TEST====="
./user.out "%d" > file_user.txt
./ref.out "%d" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%% TEST====="
./user.out "%%" > file_user.txt
./ref.out "%%" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%p TEST====="
./user.out "%p" > file_user.txt
./ref.out "%p" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====multiple TEST====="
./user.out "multiple" > file_user.txt
./ref.out "multiple" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%S TEST====="
./user.out "%S" > file_user.txt
./ref.out "%S" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%D TEST====="
./user.out "%D" > file_user.txt
./ref.out "%D" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%i TEST====="
./user.out "%i" > file_user.txt
./ref.out "%i" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%o TEST====="
./user.out "%o" > file_user.txt
./ref.out "%o" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%O TEST====="
./user.out "%O" > file_user.txt
./ref.out "%O" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%u TEST====="
./user.out "%u" > file_user.txt
./ref.out "%u" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%U TEST====="
./user.out "%U" > file_user.txt
./ref.out "%U" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%x TEST====="
./user.out "%x" > file_user.txt
./ref.out "%x" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
echo "=====%X TEST====="
./user.out "%X" > file_user.txt
./ref.out "%X" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====COMPARE====="
	cat $file
	exit
else
	g OK
fi
#rm file_user.txt
#rm file_ref.txt
#rm ./user.out
#rm ./ref.out
#rm main_ref.c