make .
cp bin/libft.a test/libftprintf.a
make -C test
./test/ft_printf_tests
