clear
echo "=====START====="
function g {
	echo "\033[032m$1\033[0m"
}
function r {
	echo "\033[031m$1\033[0m"
}
function funct_comp {
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
}
i=$(find . | grep "ft_printf.h" | cut -f 1 -d "f")
echo "Found ft_printf.h in $i"
echo "=====NORME====="
touch file_norme.txt
find *.c | sed 's/main.c//g' | sed 's/main_ref.c//g' | xargs norminette | grep "Error" > file_norme.txt
norminette $i | grep "Error" >> file_norme.txt
file=file_norme.txt
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	r Fail
	echo "=====ERROR====="
	find *.c | sed 's/main.c//g' | sed 's/main_ref.c//g' | xargs norminette > file_norme.txt
	norminette $i >> file_norme.txt
	cat file_norme.txt
	exit
else
	g OK
fi
rm file_norme.txt
echo "=====MAKEFILE====="
touch file_makefile.txt
#make | grep "Makefile"
#make all | grep "Makefile"
#make fclean | grep "Makefile" 
make re
#2>&1 > file_makefile.txt
make clean 2>&1 >> file_makefile.txt
cat file_makefile.txt | grep " error" > file_test.txt
cat file_makefile.txt | grep "Stop" >> file_test.txt
file=file_test.txt
actualsize=$(wc -c <"$file")
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
rm main_ref.c
gcc -I $i main.c libftprintf.a -o user.out
j=$(cat main.c | grep "ft_printf(" | wc -l | tr -d " ")
sed 's/ft_printf(/printf(/g' main.c > main_ref.c
mv main.c main
gcc -w -I $i main_ref.c -o ref.out
mv main main.c
file=user.out
actualsize=$(wc -c <"$file")
if [ $actualsize -ge 1 ]; then
	g OK
else
	echo "=====ERROR====="
	exit
fi
echo "====STARTING TEST===="
touch file_user.txt
touch file_ref.txt
touch file_diff.txt
echo "Total test to do : $j"
echo "=====simple TEST====="
./user.out "simple" > file_user.txt
./ref.out "simple" > file_ref.txt
funct_comp
echo "=====%s TEST====="
./user.out "%s" > file_user.txt
./ref.out "%s" > file_ref.txt
funct_comp
echo "=====%d TEST====="
./user.out "%d" > file_user.txt
./ref.out "%d" > file_ref.txt
funct_comp
echo "=====%% TEST====="
./user.out "%%" > file_user.txt
./ref.out "%%" > file_ref.txt
funct_comp
echo "=====%p TEST====="
./user.out "%p" > file_user.txt
./ref.out "%p" > file_ref.txt
funct_comp
echo "=====multiple TEST====="
./user.out "multiple" > file_user.txt
./ref.out "multiple" > file_ref.txt
funct_comp
echo "=====%S TEST====="
./user.out "%S" > file_user.txt
./ref.out "%S" > file_ref.txt
funct_comp
echo "=====%D TEST====="
./user.out "%D" > file_user.txt
./ref.out "%D" > file_ref.txt
funct_comp
echo "=====%i TEST====="
./user.out "%i" > file_user.txt
./ref.out "%i" > file_ref.txt
funct_comp
echo "=====%o TEST====="
./user.out "%o" > file_user.txt
./ref.out "%o" > file_ref.txt
funct_comp
echo "=====%O TEST====="
./user.out "%O" > file_user.txt
./ref.out "%O" > file_ref.txt
funct_comp
echo "=====%u TEST====="
./user.out "%u" > file_user.txt
./ref.out "%u" > file_ref.txt
funct_comp
echo "=====%U TEST====="
./user.out "%U" > file_user.txt
./ref.out "%U" > file_ref.txt
funct_comp
echo "=====%x TEST====="
./user.out "%x" > file_user.txt
./ref.out "%x" > file_ref.txt
funct_comp
echo "=====%X TEST====="
./user.out "%X" > file_user.txt
./ref.out "%X" > file_ref.txt
funct_comp
echo "=====%c TEST====="
./user.out "%c" > file_user.txt
./ref.out "%c" > file_ref.txt
funct_comp
echo "=====%C TEST====="
./user.out "%C" > file_user.txt
./ref.out "%C" > file_ref.txt
funct_comp
echo "=====multiple2 TEST====="
./user.out "multiple2" > file_user.txt
./ref.out "multiple2" > file_ref.txt
funct_comp
echo "=====%l% TEST====="
./user.out "%l%" > file_user.txt
./ref.out "%l%" > file_ref.txt
funct_comp
echo "=====%ll% TEST====="
./user.out "%ll%" > file_user.txt
./ref.out "%ll%" > file_ref.txt
funct_comp
echo "=====%h% TEST====="
./user.out "%h%" > file_user.txt
./ref.out "%h%" > file_ref.txt
funct_comp
echo "=====%hh% TEST====="
./user.out "%hh%" > file_user.txt
./ref.out "%hh%" > file_ref.txt
funct_comp
echo "=====%j% TEST====="
./user.out "%j%" > file_user.txt
./ref.out "%j%" > file_ref.txt
funct_comp
echo "=====%z% TEST====="
./user.out "%z%" > file_user.txt
./ref.out "%z%" > file_ref.txt
funct_comp
echo "=====%#% TEST====="
./user.out "%#%" > file_user.txt
./ref.out "%#%" > file_ref.txt
funct_comp
echo "=====%+% TEST====="
./user.out "%+%" > file_user.txt
./ref.out "%+%" > file_ref.txt
funct_comp
echo "=====% % TEST====="
./user.out "% %" > file_user.txt
./ref.out "% %" > file_ref.txt
funct_comp
echo "=====ad1 TEST====="
./user.out "ad1" > file_user.txt
./ref.out "ad1" > file_ref.txt
funct_comp
echo "=====ad2 TEST====="
./user.out "ad2" > file_user.txt
./ref.out "ad2" > file_ref.txt
funct_comp
echo "=====%.1% TEST====="
./user.out "%.1%" > file_user.txt
./ref.out "%.1%" > file_ref.txt
funct_comp
echo "=====%.2% TEST====="
./user.out "%.2%" > file_user.txt
./ref.out "%.2%" > file_ref.txt
funct_comp
echo "=====%.3% TEST====="
./user.out "%.3%" > file_user.txt
./ref.out "%.3%" > file_ref.txt
funct_comp
echo "=====BONUS TEST====="
echo "=====B%b TEST====="
./user.out "B%b"
echo "=====Bcolor TEST====="
./user.out "Bcolor"
echo "=====User TEST====="
./user.out "user" > file_user.txt
./ref.out "user" > file_ref.txt
funct_comp
echo "=====DISPLAY====="
cat file_user.txt
#rm file_user.txt
#rm file_ref.txt
#rm ./user.out
#rm ./ref.out
#rm main_ref.c
