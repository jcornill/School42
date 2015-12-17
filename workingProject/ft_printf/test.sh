clear
echo "=====START====="
echo "=====MAKEFILE====="
#make | grep "Makefile"
#make all | grep "Makefile"
#make fclean | grep "Makefile"
make re | grep "Makefile"
make clean | grep "Makefile"
echo "OK"
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
echo "=====SIMPLE TEST====="
./user.out "simple" > file_user.txt
./ref.out "simple" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
file=file_diff.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	echo "Fail"
	echo "=====COMPARE====="
	cat file_diff.txt
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
	cat file_diff.txt
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
	cat file_diff.txt
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
	cat file_diff.txt
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
	cat file_diff.txt
	exit
else
	echo "OK"
fi

#rm file_user.txt
#rm file_ref.txt
#rm ./user.out
#rm ./ref.out
#rm main_ref.c
