src := ${wildcard *.cpp}

all: ${src:.cpp=}
fclean: ; rm -f ${src:.cpp=}
re: fclean all

current_exercise := ex01
run:
	@clear && clang-format -i ${src} && \
	make -s --no-print-directory ${current_exercise} && \
	echo 'Running ${current_exercise}' && \
	echo '########################################\n' && \
	./${current_exercise} && \
	echo '\n########################################' && \
	rm -f ${src:.cpp=}
