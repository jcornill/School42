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
echo "$j test will occurs"
sed 's/ft_printf(/printf(/g' main.c > main_ref.c
gcc -w main_ref.c -I $i libftprintf.a -o ref.out
echo "OK"
echo "====STARTING TEST===="
touch file_user.txt
touch file_ref.txt
touch file_diff.txt
echo "=====SIMPLE TEST====="
./user.out "simple" > file_user.txt
./ref.out "simple" > file_ref.txt
diff file_user.txt file_ref.txt > file_diff.txt
echo "=====COMPARE===="
diff file_user.txt file_ref.txt
#rm file_user.txt
#rm file_ref.txt
#rm ./user.out
#rm ./ref.out
#rm main_ref.c
