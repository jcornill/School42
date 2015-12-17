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
cat file_makefile.txt | grep "Makefile" >> file_test.txt
file=file_test.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====ERROR====="
	cat file_test.txt
	exit
else
	echo "OK"
fi
rm file_test.txt
echo "=====COMPILING====="
i=$(find . | grep "ft_printf.h" | cut -f 1 -d "f")
echo "Found ft_printf.h in $i"
gcc main.c -I $i libftprintf.a -o user.out
j=$(cat main.c | grep "ft_printf(" | wc -l | tr -d " ")
sed 's/ft_printf(/printf(/g' main.c > main_ref.c
gcc -w main_ref.c -I $i libftprintf.a -o ref.out
echo "OK"
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
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%s TEST====="
./user.out "%s" > file_user.txt
./ref.out "%s" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
	fi
echo "=====%d TEST====="
./user.out "%d" > file_user.txt
./ref.out "%d" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%% TEST====="
./user.out "%%" > file_user.txt
./ref.out "%%" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%p TEST====="
./user.out "%p" > file_user.txt
./ref.out "%p" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====multiple TEST====="
./user.out "multiple" > file_user.txt
./ref.out "multiple" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%S TEST====="
./user.out "%S" > file_user.txt
./ref.out "%S" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%D TEST====="
./user.out "%D" > file_user.txt
./ref.out "%D" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
fi
echo "=====%i TEST====="
./user.out "%i" > file_user.txt
./ref.out "%i" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat $file
	exit
else
	echo "OK"
	fi
#rm file_user.txt
#rm file_ref.txt
#rm ./user.out
#rm ./ref.out
#rm main_ref.c
